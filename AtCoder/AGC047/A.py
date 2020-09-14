n = int(input().strip())
count_2, count_5 = [], []

for i in range(n):
    x = input().strip()
    if '.' not in x:
        count_2.append(0)
        count_5.append(0)
    else:
        decimal = x.split('.')[1]
        freq_10 = len(decimal)
        decimal = int(decimal)
        freq_2, freq_5 = 0, 0
        while decimal % 2 == 0: 
            freq_2 += 1
            decimal /= 2
        while decimal % 5 == 0: 
            freq_5 += 1
            decimal /= 5
        count_2.append(freq_2 - freq_10)
        count_5.append(freq_5 - freq_10)


