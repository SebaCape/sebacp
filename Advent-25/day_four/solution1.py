f = open('input.txt', 'r')
grid = f.readlines()
for i in range(len(grid)):
    grid[i] = grid[i].rstrip()

ROWS = len(grid)
COLS = len(grid[0])
valid_rolls = 0

def get_adjacent(row, col):
    count = 0

    for r in range(row - 1, row + 2):
        for c in range(col - 1, col + 2):
            if c < 0 or c >= COLS or r < 0 or r >= ROWS or (r == row and c == col):
                continue
            elif grid[r][c] == '@':
                count += 1
            
    return count

for row in range(ROWS):
    for col in range(COLS):

        if grid[row][col] == '@' and get_adjacent(row, col) < 4:
            valid_rolls += 1

print(valid_rolls)