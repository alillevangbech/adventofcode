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

possible = [(
              functools.reduce(max, [p.get('green',0) for p in game[1]]),
              functools.reduce(max, [p.get('red',0) for p in game[1]]),
              functools.reduce(max, [p.get('blue',0) for p in game[1]])
            ) for game in games]


print(sum([x[0]*x[1]*x[2] for x in possible]))

