f = open('input.txt', 'r')
valid_intervals = []
ids = []
fresh_ids = 0

#Aggregate intervals & ids to check
for line in f:
    line = line.strip()
    if '-' in line:
        vals = line.split('-')
        valid_intervals.append([int(vals[0]), int(vals[1])])
    elif line:
        ids.append(int(line))
    
#Merge intervals
valid_intervals.sort()  # sort by start
merged_intervals = []
cur_start, cur_end = valid_intervals[0]

for s, e in valid_intervals[1:]:
    if s <= cur_end:
        cur_end = max(cur_end, e)
    else:
        merged_intervals.append([cur_start, cur_end])
        cur_start, cur_end = s, e

merged_intervals.append([cur_start, cur_end])

#Count valid ids
for interval in merged_intervals:
    fresh_ids += interval[1] - interval[0] + 1

print(fresh_ids)