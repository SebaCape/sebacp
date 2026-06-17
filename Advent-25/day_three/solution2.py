f = open('input.txt', 'r')
lines = f.readlines()

jolt_sum = 0

for bank in lines:
    bank = bank.strip()
    max_idx = -1
    for digit in range(11, -1, -1):
        cur_max = 0
        for i in range(max_idx + 1, len(bank) - digit):
            if int(bank[i]) > cur_max:
                cur_max = int(bank[i])
                max_idx = i

        jolt_sum += cur_max * (10 ** digit)
        cur_max = 0



print(jolt_sum)