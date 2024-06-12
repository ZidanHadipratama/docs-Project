#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

void write_pid_to_file(const char *filename, pid_t pid, const char *setup) {
    FILE *file = fopen(filename, "a");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }
    fprintf(file, "%d %s\n", pid, setup); 
    fclose(file);
}

void kill_processes(const char *filename, const char *setup) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    FILE *temp = fopen("temp", "w");
    if (temp == NULL) {
        perror("Error opening temporary file");
        return;
    }

    char line[100];
    while (fgets(line, sizeof(line), file)) {
        char line_copy[100];
        strncpy(line_copy, line, sizeof(line_copy));
        char *token = strtok(line, " \n");
        pid_t pid = atoi(token);
        token = strtok(NULL, " \n");
        if (setup == NULL || strcmp(token, setup) == 0) {
            kill(pid, SIGTERM);
        } else {
            fprintf(temp, "%s", line_copy);
        }
    }

    fclose(file);
    fclose(temp);

    remove(filename);
    rename("temp", filename);
}

int open_apps_from_args(int argc, char *argv[]){
    if(daemon(1, 0) == -1) { 
        perror("Failed to start daemon");
        return 1;
    }

    for(int i = 2; i < argc; i+=2) {
        int num_instances = atoi(argv[i+1]);

        for(int j = 0; j < num_instances; j++) {
            pid_t pid = fork();

            if(pid == 0) { 
                char *args[] = {argv[i], NULL};
                execvp(args[0], args);
            } else if(pid < 0) {
                printf("Failed to fork for %s\n", argv[i]);
                return 1;
            } else {
                write_pid_to_file("pidFile", pid, "args");
            }
        }
    }

    for(int i = 2; i < argc; i+=2) {
        int num_instances = atoi(argv[i+1]);
        for(int j = 0; j < num_instances; j++) {
            wait(NULL);
        }
    }

    return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_LINE_LENGTH 100
#define MAX_TOKENS 2

int open_apps_from_file(const char *filepath){
    FILE *file = fopen(filepath, "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        char *tokens[MAX_TOKENS];
        char *token = strtok(line, " \n");
        int i = 0;
        while (token != NULL && i < MAX_TOKENS) {
            tokens[i++] = token;
            token = strtok(NULL, " \n");
        }

        if (i == MAX_TOKENS) {
            int num_windows = atoi(tokens[1]);
            for (int j = 0; j < num_windows; j++) {
                pid_t pid = fork();
                if (pid == 0) {
                    execlp(tokens[0], tokens[0], NULL);
                    perror("execlp failed");
                    return 1;
                } else {
                    write_pid_to_file("pidFile", pid, filepath);
                }
            }
        }
    }

    fclose(file);
    return 0;
}

int main(int argc, char *argv[]) {
    if(argc < 2 || (strcmp(argv[1], "-a") != 0 && strcmp(argv[1], "-f") != 0 && strcmp(argv[1], "-k") != 0)) {
        printf("Usage: %s -a <app1> <num1> <app2> <num2> ... <appN> <numN>\n", argv[0]);
        printf("Usage: %s -f <filename>\n", argv[0]);
        printf("Usage: %s -k [-f <filename>]\n", argv[0]);
        return 1;
    }

    if(strcmp(argv[1], "-f") == 0){
        open_apps_from_file(argv[2]);
    } else if(strcmp(argv[1], "-a") == 0){
        open_apps_from_args(argc, argv);
    } else if(strcmp(argv[1], "-k") == 0){
        if(argc > 2 && strcmp(argv[2], "-f") == 0){
            kill_processes("pidFile", argv[3]);
        } else if (argc > 2 && strcmp(argv[2], "-f") != 0){
            printf("Usage: %s -k [-f <filename>]\n", argv[0]);
            return 1;
        }
        else {
            kill_processes("pidFile", NULL);
        }
    }

    return 0;
}
