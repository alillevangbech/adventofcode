import sys
import functools
import itertools
import re

data = sys.stdin.readlines()
data = [s.rstrip() for s in data]

RMV = r'Card\s*'
DIGIT = r'\s+'

def acc(n):
    if n == 0: return 0
    if n == 1: return 1
    res = 1;
    while n-1 > 0:
        res *= 2
        n -= 1;
    return res



s = 0
for line in data:
    parse = line.split(":")
    id = int(re.sub(RMV, "", parse[0]))
    all = parse[1].split("|")

    winners = set([int(x) for x in re.split(DIGIT, all[0].strip())])
    mynumbers = set([int(x) for x in re.split(DIGIT, all[1].strip())])
    
    #  winners
    mywinners = mynumbers.intersection(winners)
    s += acc(len(mywinners))
print(s)
    

    

