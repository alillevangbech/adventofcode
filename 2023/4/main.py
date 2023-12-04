import sys
import functools
import itertools
import re

data = sys.stdin.readlines()
data = [s.rstrip() for s in data]

RMV = r'Card\s*'
DIGIT = r'\s+'

s = 0
games = {}
for line in data:
    parse = line.split(":")
    id = int(re.sub(RMV, "", parse[0]))
    all = parse[1].split("|")

    winners = set([int(x) for x in re.split(DIGIT, all[0].strip())])
    mynumbers = set([int(x) for x in re.split(DIGIT, all[1].strip())])
    mywinners = mynumbers.intersection(winners)

    games[id] = len(mywinners)
    #  winners

copies = {n: 1 for n in games}
tmps = {n: 1 for n in games}
l = len(games)
while True:
    count = 0
    print(tmps)
    for k,v in games.items():
        cps = tmps[k]
        if cps == 0: continue

        tmps[k] -= 1
        for x in range(1,v+1):
            tmps[k+x] += 1
            copies[k+x] += 1
            count += 1
    if count == 0:
        break
print(sum(copies.values()))







    

