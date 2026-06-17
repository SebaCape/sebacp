import math

with open("input1.txt") as f:
    instructions = f.readlines()

val = 50
password = 0

for i in instructions:
    start = val

    distance = int(i[1:])
    if i[0] == 'L':
        val -= distance
    else:
        val += distance

    end = val

    if end - start == 0:
        password += 1
    else:
        password += abs(math.ceil(end / 100) - math.ceil(start / 100))

    val %= 100

print(password)