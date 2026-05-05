import requests
import bs4
from bs4 import BeautifulSoup
import time
import math

contest_id = 2227  # CHANGE THIS

# ----------------------------
# STEP 1: Scrape standings
# ----------------------------
handles = []
page = 1

while True:
    url = f"https://codeforces.com/contest/{contest_id}/standings/page/{page}"
    res = requests.get(url, headers={"User-Agent": "Mozilla/5.0"})
    
    if res.status_code != 200:
        break
    
    soup = BeautifulSoup(res.text, "lxml")
    print(soup)
    rows = soup.select("tr[data-participantid]")
    
    if not rows:
        break
    
    for row in rows:
        user = row.select_one(".rated-user")
        if user:
            handles.append(user.text.strip())
    
    print(f"Scraped page {page}, total handles: {len(handles)}")
    page += 1
    time.sleep(0.5)

print(f"Total handles: {len(handles)}")

# ----------------------------
# STEP 2: Fetch ratings
# ----------------------------
ratings = {}

def chunks(lst, size):
    for i in range(0, len(lst), size):
        yield lst[i:i + size]

for chunk in chunks(handles, 100):  # CF limit ~100 handles/request
    handles_str = ";".join(chunk)
    url = f"https://codeforces.com/api/user.info?handles={handles_str}"
    
    try:
        data = requests.get(url).json()
        for user in data["result"]:
            ratings[user["handle"]] = user.get("rating", 0)
    except:
        pass
    
    time.sleep(0.5)

print(f"Ratings fetched: {len(ratings)}")

# ----------------------------
# STEP 3: Build distribution
# ----------------------------
rating_list = [r for r in ratings.values() if r > 0]
rating_list.sort(reverse=True)

n = len(rating_list)

def percentile(p):
    idx = int(p * n)
    return rating_list[min(idx, n - 1)]
print(rating_list)
# ----------------------------
# STEP 4: Output key percentiles
# ----------------------------
print("\nPercentile → Rating")
for p in [0.01, 0.02, 0.05, 0.10, 0.25, 0.50]:
    print(f"{int(p*100)}%: {percentile(p)}")