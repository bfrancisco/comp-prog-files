db = {
    "Shadow" : {
        "energy_cost": 4,
        "power_level": 6,
        "ability": "null"
    },
    "Gale" : {
        "energy_cost": 3,
        "power_level": 5,
        "ability": "null"
    },
    "Ranger" : {
        "energy_cost": 2,
        "power_level": 4,
        "ability": "null"
    },
    "Anvil" : {
        "energy_cost": 5,
        "power_level": 7,
        "ability": "null"
    },
    "Vexia" : {
        "energy_cost": 2,
        "power_level": 3,
        "ability": "null"
    },
    "Guardian" : {
        "energy_cost": 6,
        "power_level": 8,
        "ability": "null"
    },
    "Thunderheart" : {
        "energy_cost": 5,
        "power_level": 6,
        "ability": "Phalanx"
        # If the location this card is played at has 4 friendly cards, including this one, then its power is doubled. Note that other buffs the card receives are not doubled.
    },
    "Frostwhisper" : {
        "energy_cost": 1,
        "power_level": 2,
        "ability": "null"
    },
    "Voidclaw" : {
        "energy_cost": 1,
        "power_level": 3,
        "ability": "null"
    },
    "Ironwood" : {
        "energy_cost": 1,
        "power_level": 3,
        "ability": "null"
    },
    "Zenith" : {
        "energy_cost": 6,
        "power_level": 4,
        "ability": "Centered Focus"
        # If this card is played at the center location, +5 power.
    },
    "Seraphina" : {
        "energy_cost": 1,
        "power_level": 1,
        "ability": "Celestial Healing"
        # Seraphina grants +1 power to each friendly card at this location, other than itself. This includes other Seraphina cards.
    }
}


location = [[[], []] for i in range(3)]
for li in range(3):
    inp = [input().split() for _ in range(2)]

    for p in range(2):
        for i in range(1, len(inp[p])):
            hero = inp[p][i]
            location[li][p].append(hero)

power = [[0, 0] for i in range(3)]
for li in range(3):
    for p in range(2):
        for hero in location[li][p]:
            power[li][p] += db[hero]["power_level"]
            if db[hero]["ability"] == "Phalanx" and len(location[li][p]) == 4:
                power[li][p] += db[hero]["power_level"]
            elif db[hero]["ability"] == "Centered Focus" and li == 1:
                power[li][p] += 5
            elif db[hero]["ability"] == "Celestial Healing":
                power[li][p] += len(location[li][p])-1

w1, w2 = 0, 0
sm1, sm2 = 0, 0
for score1, score2 in power:
    if score1 > score2: w1 += 1
    elif score2 > score1: w2 += 1

    sm1 += score1
    sm2 += score2

if w1 > w2:
    print("Player 1")
elif w1 < w2:
    print("Player 2")
elif sm1 > sm2:
    print("Player 1")
elif sm1 < sm2:
    print("Player 2")
else:
    print("Tie")
        