import sys
import functools
import itertools

data = sys.stdin.readlines()
data = [s.rstrip() for s in data]

DOT = '.'
STAR = '*'

def parsenumber(line, current, iter):
    number = ""
    while line[current].isdigit():
        number += line[current]
        current = next(iter, None)
        if current == None:
            break
    return int(number), len(number)

    
def scan(data, lineidx, start, end):
    l = len(data)
    print("line", lineidx)
    for idx in iter(range(start-1,end+1)):
        print(idx)
        if lineidx > 0:
            found = scansymbol(data[lineidx-1], idx)
            if found:
                return True, lineidx-1, idx
        if lineidx < l-1:
            found = scansymbol(data[lineidx+1], idx)
            if found:
                return True, lineidx+1, idx

    found = scansymbol(data[lineidx], start-1)
    if found:
        return True, lineidx, start-1


    found = scansymbol(data[lineidx], end)
    if found:
        return True, lineidx, end
    
    return False, -1, -1

def scansymbol(line, idx):
    try:
        c = line[idx]
        return c == STAR
    except:
        return False

near_number = []
not_near_number = []
for lineidx, line in enumerate(data):
    it = iter(range(len(line)))
    for idx in it:
        if line[idx].isdigit():
            i = idx
            val, lens = parsenumber(line, idx, it)
            found, x, y = scan(data, lineidx, i, i+lens)
            if found:
                print(val)
                near_number.append((val, x, y))

coordinates = set([(x[1], x[2]) for x in near_number])
s = 0
for cor in coordinates:
    l = [x for x in near_number if x[1] == cor[0] and x[2] == cor[1]]
    if len(l) == 2:
        s += l[0][0] * l[1][0]
print(s)


