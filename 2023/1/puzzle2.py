import sys
data = sys.stdin.readlines()

m = {
    "one": 1,
    "two": 2,
    "three": 3,
    "four": 4,
    "five": 5,
    "six": 6,
    "seven": 7,
    "eight": 8,
    "nine": 9,
}

s = 0
for line in data:
    line = line.rstrip()

    digits = []
    for i in range(len(line)):
        if line[i].isdigit():
            digits.append((i, line[i]))
        else:
            if line[i:i+3] in m:
                digits.append((i, m[line[i:i+3]]))
            elif line[i:i+4] in m:
                digits.append((i, m[line[i:i+4]]))
            elif line[i:i+5] in m:
                digits.append((i, m[line[i:i+5]]))

    fkey = lambda x: x[0]
    print(digits)
    first = min(digits, key=fkey)
    last = max(digits, key=fkey)
    
    print(line, first[1], last[1])
    s += int(str(first[1]) + str(last[1]))
print(s)
