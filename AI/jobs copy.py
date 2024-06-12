import random
import math

# Define faculties and skills
# Faculty and degree
faculties = {
    "fteic": ["ELC", "BIOMED", "TekKom", "TC", "SI", "IT"],
    "ftirs": ["MSN", "TekKim", "TekFis", "TekIn", "TekMat"],
    "ftspk": ["TekSip", "Arsi", "TekLi", "PWK", "GeoMat", 'GeoFis'],
    "fkbd": ["DesPro", "DesIn", "DKV", "ManBis", "StudPen", "ManTek"],
    "ftk": ["TekPal", "SisPal", "TekLa", "TekTrans"],
    "fsad": ["MTK", "FIS", "Stat", "Kim", "Bio", "Akt"]
}

# Skills
skills = {
    "Science": ["Biology", "Physics", "Chemistry", "Astronomy", "Geology"],
    "Marine": ["Marine Biology", "Oceanography", "Marine Engineering", "Maritime Law", "Diving"],
    "Industry Engineering": ["Manufacturing", "Logistics", "Energy", "Agriculture", "Pharmaceuticals"],
    "IT": ["Programming", "Web Development", "Cloud Computing", "Database Management", "Cybersecurity"],
    "Civil": ["Structural Engineering", "Geotechnical Engineering", "Transportation Engineering", "Environmental Engineering", "Construction Management"],
    "Creative": ["Writing", "Art", "Music", "Film", "Photography"]
}

# Generate candidates random. Memiliki gelar, umur(bilangan bulat 1-10), banyaknya pengalamana (bilangan bulat 1-10), dan skill yang dimiliki (3 item)
all_degrees = [degree for faculty in faculties.values() for degree in faculty]
all_skills = [skill for group in skills.values() for skill in group]
candidates = [
    {"ID": i, 
     "Degree": random.choice(all_degrees), 
     "Age": random.randint(20, 50), 
     "Experience": random.randint(1, 10), 
     "Skills": random.sample(all_skills, 3)}
    for i in range(10000)
]

print("Kandidat pekerja")
for i in candidates:
    print(i)

prioritize_degree = "y"

# Input Program
print("Please enter the job requirements:")
degree = input("Degree: ")
age = int(input("Age: "))
experience = int(input("Experience: "))
skills = input("Skills (comma-separated): ").split(',')
prioritize_degree = input("Prioritize Degree? (y/n):")

job_requirements = {"Degree": degree, "Age": age, "Experience": experience, "faculty": "none", "Skills": skills}

degree_to_faculty = {degree: faculty for faculty, degrees in faculties.items() for degree in degrees}

# Define job requirements
# job_requirements = {"Degree": "TekLi", "Age": 20, "Experience": 2, "faculty": "none", "Skills": ["Art", "Biology", "Cloud Computing"]}

job_requirements["faculty"] = degree_to_faculty[job_requirements["Degree"]]

# Define cost function with weights
def cost(candidate):
    # Define weights
    weights = {"skills": 4, "degree": 1, "experience": 2, "age": 3}

    degree_cost = 0 if candidate["Degree"] == job_requirements["Degree"] else (1 if candidate["Degree"] in job_requirements["faculty"] else 2)
    age_cost = abs(candidate["Age"] - job_requirements["Age"])
    experience_cost = 0 if candidate["Experience"] > job_requirements["Experience"] else 1
    skills_cost = len(set(job_requirements["Skills"]) - set(candidate["Skills"]))

    # Return weighted cost
    return weights["skills"] * skills_cost + weights["degree"] * degree_cost + weights["experience"] * experience_cost + weights["age"] * age_cost

# Define neighbor function
def get_neighbors(candidate, num_neighbors=10):
    if prioritize_degree == "n":
        neighbors = [c for c in candidates if any(skill in c["Skills"] for skill in job_requirements["Skills"])]
        if not neighbors:
            neighbors = [c for c in candidates if any(skill in c["Skills"] for skill in job_requirements["Skills"])]
    else:
        neighbors = [c for c in candidates if c["Degree"] in degree_to_faculty[candidate["Degree"]] or any(skill in c["Skills"] for skill in candidate["Skills"])]
    return random.sample(neighbors, min(num_neighbors, len(neighbors)))

# Define simulated annealing function
def simulated_annealing():
    current_candidate = random.choice(candidates)
    T = 10000
    T_min = 0.001
    alpha = 0.99

    while T > T_min:
        neighbors = get_neighbors(current_candidate)
        next_candidate = random.choice(neighbors)
        delta_cost = cost(next_candidate) - cost(current_candidate)

        print("------------------------------------")
        print("Current Candidate ID: ", current_candidate["ID"])
        print("Current Candidate Cost: ", cost(current_candidate))
        print("Current Candidate Degree: ", current_candidate["Degree"])

        print("Next Candidate ID: ", next_candidate["ID"])
        print("Next Candidate Cost: ", cost(next_candidate))
        print("Next Candidate Degree: ", next_candidate["Degree"])
        print("delta_cost", delta_cost)
        
        if delta_cost < 0 or random.random() < math.exp(-delta_cost / T):
            current_candidate = next_candidate

        T = T * alpha

    return current_candidate

# Run simulated annealing and print best candidate
best_candidate = simulated_annealing()
print("Best candidate:", best_candidate)