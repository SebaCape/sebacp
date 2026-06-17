f = open('input.txt')
spans = []
invalid_sum = 0

for line in f.readlines():
    ranges = line.split(',')
    for r in ranges:
        span = r.split('-')
        spans.append(span)

for s in spans:
    for n in range(int(s[0]), int(s[1]) + 1):
        nstr = str(n)
        length = len(nstr)
        for i in range(1, length // 2 + 1):
            if length % i == 0 and (nstr[0: i] * (length // i)) == nstr:
                invalid_sum += n
                break

print(invalid_sum)