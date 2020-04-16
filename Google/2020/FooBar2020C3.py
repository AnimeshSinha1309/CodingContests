def solution(l):
    divisors = [
        [i for i in range(idx) if el % l[i] == 0]
        for idx, el in enumerate(l)
    ]
    triples = 0
    for z in range(len(l)):
        for y in divisors[z]:
            triples += len(divisors[y])
    return triples

if __name__ == "__main__":
    print(solution([1, 2, 3, 4, 5, 6]))
