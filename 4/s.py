import re


with open('input.txt') as f:
    data = f.read()

passports = []
for block in data.split('\n\n'):
    parsed = re.findall(r'(\w+):(\S+)', block)
    passports.append({m[0]: m[1] for m in parsed})


print(len(passports))
# Part one
required = {'byr', 'iyr', 'eyr', 'hgt', 'hcl', 'ecl', 'pid'}


def is_valid(passport):
    return not any(required - passport.keys())


print(sum(map(is_valid, passports)))


