import sys
import functools

data = sys.stdin.readlines()
data = [s.rstrip() for s in data]

games = []
for line in data:
    parse = line.split(":")
    id = int(parse[0].split(" ")[1])
    sets = parse[1].split(";")
    game = (id, [])
    for s in sets:
        balls = s.split(",")
        d = {}
        for ball in balls:
            tmp = ball.strip().split(" ")
            d[tmp[1]] = int(tmp[0])
        game[1].append(d)
    games.append(game)


rules = {
    'red': 12,
    'green': 13,
    'blue': 14,
}

possible = [(game[0], [g.get('red', 0) <= 12 and
             g.get('green',0) <= 13 and
             g.get('blue',0) <= 14 
             for g in game[1]]) for game in games]
possible = [p for p in possible if all(p[1])]

print(functools.reduce(lambda x,y: x+y, [p[0] for p in possible]))
