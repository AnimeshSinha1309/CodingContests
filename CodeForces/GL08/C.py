from matplotlib import pyplot as plt
import seaborn as sns
data = [
    [0, 0],
    [1, 0],
    [2, 0],
    [0, 1],
    [0, 2],
    [1, 2],
    [2, 1],
    [2, 2],
    [3, 2],
    [4, 2],
    [2, 3],
    [2, 4],
    [3, 4],
    [4, 3],
    [4, 4],
    [5, 4],
    [6, 4],
    [4, 5],
    [4, 6],
    [5, 6],
    [6, 5],
    [6, 6],
    [7, 6],
    [8, 6],
    [6, 7],
    [6, 8],
    [7, 8],
    [8, 7],
    [8, 8],
    [9, 8],
    [10, 8],
    [8, 9],
    [8, 10],
    [9, 10],
    [10, 9],
    [5, 5],
]

grid = [[0 for i in range(15)] for j in range(15)]
for el in data:
    grid[el[0]][el[1]] = 1

sns.heatmap(grid)
plt.show()