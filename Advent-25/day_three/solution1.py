f = open('input.txt', 'r')
lines = f.readlines()

jolt_sum = 0

for bank in lines:
    bank = bank.strip()
    cur_max = 0
    max_idx = 0
    for i in range(len(bank) - 1):
        if int(bank[i]) > cur_max:
            cur_max = int(bank[i])
            max_idx = i

    jolt_sum += cur_max * 10
    cur_max = 0

    for j in bank[max_idx + 1: len(bank)]:
        if int(j) > cur_max:
            cur_max = int(j)

    jolt_sum += cur_max


print(jolt_sum)