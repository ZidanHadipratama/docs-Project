#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <time.h>

void show_processes(char *username) {
    char command[256];
    sprintf(command, "ps -u %s", username);
    system(command);
}

void kill_processes(char *username) {
    char command[256];
    sprintf(command, "pkill -u %s", username);
    system(command);
}

void stop_monitoring(char *username) {
    char filename[256];
    sprintf(filename, "%s.pid", username);
    FILE *file = fopen(filename, "r");
    if(file == NULL) {
        printf("No monitoring process to stop.\n");
        return;
    }

    pid_t monitor_pid;
    fscanf(file, "%d", &monitor_pid);
    fclose(file);

    kill(monitor_pid, SIGTERM);
    printf("Monitoring stopped.\n");

    remove(filename); 
}

void monitor_user(char *username) {
    pid_t monitor_pid = fork();

    if(monitor_pid == 0) {
        setsid(); 
        close(STDIN_FILENO);
        close(STDOUT_FILENO);
        close(STDERR_FILENO);

        char last_logged_process[256] = "";

        while(1) {
            char filename[256];
            sprintf(filename, "%s.log", username);
            FILE *file = fopen(filename, "a");

            time_t t = time(NULL);
            struct tm *tm = localtime(&t);
            char time_str[64];
            strftime(time_str, sizeof(time_str), "[%H:%M:%S]-[%d:%m:%Y]", tm);

            char command[256];
            printf("username %s", username);
            sprintf(command, "ps -u %s -o pid=,comm=", username);
            FILE *cmd = popen(command, "r");
            char result[256];
            while (fgets(result, sizeof(result), cmd) != NULL) {
                char *newline = strchr(result, '\n');
                if (newline) *newline = '\0'; 
                if(strcmp(result, last_logged_process) != 0) {
                    fprintf(file, "%s-%s-%s\n", time_str, username, result);
                    strcpy(last_logged_process, result);
                }
            }
            pclose(cmd);

            fclose(file);
            sleep(1); 
        }
    } else if(monitor_pid > 0) {
        printf("Monitoring started in background.\n");

        char filename[256];
        sprintf(filename, "%s.pid", username);
        FILE *file = fopen(filename, "w");
        fprintf(file, "%d", monitor_pid);
        fclose(file);
    } else {
        printf("Fork failed!\n");
    }
}

void cancel_user(char *username) {
    pid_t monitor_pid = fork();

    if(monitor_pid == 0) {
        setsid();
        close(STDIN_FILENO);
        close(STDOUT_FILENO);
        close(STDERR_FILENO);

        char last_logged_process[256] = "";

        while(1) {
            char command[256];
            sprintf(command, "ps -u %s -o pid=,comm=", username);
            FILE *cmd = popen(command, "r");
            char result[256];

            kill_processes(username);

            while (fgets(result, sizeof(result), cmd) != NULL) {
                kill_processes(username);
            }
            pclose(cmd);

            sleep(1);
        }
    } else if(monitor_pid > 0) {
        printf("Monitoring started in background.\n");

        char filename[256];
        sprintf(filename, "%s.pid", username);
        FILE *file = fopen(filename, "w");
        fprintf(file, "%d", monitor_pid);
        fclose(file);
    } else {
        printf("Fork failed!\n");
    }
}

int main(int argc, char *argv[]) {
    if(argc < 2) {
        printf("Usage: %s [-k|-v|-s|-c] username\n", argv[0]);
        return 1;
    }

    if(strcmp(argv[1], "-k") == 0) {
        if(argc < 3) {
            printf("Usage: %s [-k|-v|-s|-c] username\n", argv[0]);
            return 1;
        }
        kill_processes(argv[2]);
    } else if(strcmp(argv[1], "-v") == 0) {
        if(argc < 3) {
            printf("Usage: %s [-k|-v|-s|-c] username\n", argv[0]);
            return 1;
        }
        monitor_user(argv[2]);
    } else if(strcmp(argv[1], "-s") == 0) {
        if(argc < 3) {
            printf("Usage: %s [-k|-v|-s|-c] username\n", argv[0]);
            return 1;
        }
        stop_monitoring(argv[2]);
    } else if(strcmp(argv[1], "-c") == 0) {
        if(argc < 3) {
            printf("Usage: %s [-k|-v|-s|-c] username\n", argv[0]);
            return 1;
        }
        cancel_user(argv[2]);
    } else if(strcmp(argv[1], "-k") == 0) {
        if(argc < 3) {
            printf("Usage: %s [-k|-v|-s|-c] username\n", argv[0]);
            return 1;
        }
        stop_monitoring(argv[2]);
    } else {
        show_processes(argv[1]);
    }

    return 0;
}
