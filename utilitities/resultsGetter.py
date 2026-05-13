import requests

contest_id = 1794
url = f"https://codeforces.com/api/contest.standings?contestId={contest_id}"
response = requests.get(url).json()
rows = response["result"]["rows"]
problems = response["result"]["problems"]

# Count solvers per problem
solve_counts = [0] * len(problems)
for row in rows:
    for i, result in enumerate(row["problemResults"]):
        if result["points"] > 0:
            solve_counts[i] += 1

for i, problem in enumerate(problems):
    print(f'{problem["index"]}: {solve_counts[i]} solves')
    try:
        print(f'{problem["index"]}: {problem['rating']} rating')
    except:
        pass