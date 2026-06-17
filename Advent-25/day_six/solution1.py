f = open('input.txt', 'r')

#Parse numbers and symbols from file
numbers = []
symbols = []
op_sum = 0
ROWS, COLS = len(numbers), len(numbers[0])

for line in f.readlines():
    line.strip()
    if '+' not in line:
        numbers.append(line.split())
    else:
        symbols = line.split()

#Loop through all number operations

        