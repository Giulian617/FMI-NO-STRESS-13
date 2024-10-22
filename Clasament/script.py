import csv
import os
import json
import subprocess

FORMULAR = "categorized_formular.csv"
FMI_1 = "fmi_1.csv"
FMI_OPEN = "fmi_open.csv"
OPEN = "open.csv"

def parse_responses():
    responses = []
    with open(FORMULAR, "r") as file:
        reader = csv.DictReader(file)
        for row in reader:
            responses.append(row)
    return responses

def main():
    responses = parse_responses()
    result = subprocess.run(["curl", "https://kilonova.ro/api/contest/818/leaderboard"], capture_output=True, text=True)
    leaderboard = json.loads(result.stdout)

    for file in [FMI_1, FMI_OPEN, OPEN]:
        # Create the file and write the csv header
        with open(file, "w") as f:
            f.write("Loc_categorie,Loc_clasament,Nume,Username Kilonova,Punctaj\n")
    
    loc_clasament = 0
    for entry in leaderboard["data"]["entries"]:
        loc_clasament += 1
        points = entry["total"]
        username = entry["user"]["name"]

        for response in responses:
            if response["kn_username"] != username:
                continue
            
            name = response["name"]
            if response["category"] == "FMI_1":
                with open(FMI_1, "r") as file:
                    loc_categorie = len(file.readlines())
                with open(FMI_1, "a") as f:
                    f.write(f"{loc_categorie},{loc_clasament},{name},{username},{points}\n")
            elif response["category"] == "FMI_OPEN":
                with open(FMI_OPEN, "r") as file:
                    loc_categorie = len(file.readlines())
                with open(FMI_OPEN, "a") as f:
                    f.write(f"{loc_categorie},{loc_clasament},{name},{username},{points}\n")
            else:
                with open(OPEN, "r") as file:
                    loc_categorie = len(file.readlines())
                with open(OPEN, "a") as f:
                    f.write(f"{loc_categorie},{loc_clasament},{name},{username},{points}\n")

if __name__ == "__main__":
    main()