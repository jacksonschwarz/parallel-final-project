import random

random.seed(5)

def fill(size):
    return [[0 for i in range(size)] for i in range(size)]

amount_of_vertices = 5

x = random.randint(1, amount_of_vertices)
y = random.randint(1, amount_of_vertices)
points = [((x, y),(y, x)) for i in range(amount_of_vertices)]

matrix = fill(amount_of_vertices)

for point in points:
    matrix[point[0]-1][point[1]-1] = 1

f = open("matrix.txt", "w")

for row in matrix:
    f.write(" ".join([str(c) for c in row]) + "\n")

