with open('digit.in', 'r') as f:
    n_ = int(f.readline())

n = bin(n_)[2:]

ways = [1, 0]

for digit in n:
    next_ways = [0, 0]
    cur_value = int(digit)
    for carry in [0, 1]:
        for set_value in [0, 1, 2]:
            out_value = (cur_value + carry * 2) - set_value
            if out_value not in [0, 1]: continue
            next_ways[out_value] += ways[carry]
    ways = next_ways

with open('digit.out', 'w') as f:
    f.write(str(ways[0]))
