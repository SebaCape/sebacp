with open("input1.txt") as f:
    instructions = f.readlines()

val = 50
password = 0

for i in instructions:
    distance = int(i[1:])
    if i[0] == 'L':
        val -= distance
    else:
        val += distance

    val %= 100

    if val == 0:
        password += 1

print(password)