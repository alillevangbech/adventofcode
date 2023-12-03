import sys
data = sys.stdin.readlines()

s = 0
for line in data:
    line = line.rstrip()
    digits = [(i, c) for i,c in enumerate(line) if c.isdigit()]
    fkey = lambda x: x[0]

    first = min(digits, key=fkey)
    last = max(digits, key=fkey)
    
    print(line, first[1], last[1])
    s += int(first[1] + last[1])
print(s)
