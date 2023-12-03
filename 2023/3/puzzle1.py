import sys
import functools
import itertools

data = sys.stdin.readlines()
data = [s.rstrip() for s in data]

DOT = '.'

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
        if lineidx > 0 and scansymbol(data[lineidx-1], idx):
            return True
        if lineidx < l-1 and scansymbol(data[lineidx+1], idx):
            return True
    return scansymbol(data[lineidx], start-1) or scansymbol(data[lineidx], end)

def scansymbol(line, idx):
    try:
        c = line[idx]
        return not c.isdigit() and c != DOT
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
            found = scan(data, lineidx, i, i+lens)
            if found:
                print(val)
                near_number.append(val)
            else:
                not_near_number.append(val)
print(sum(near_number))



