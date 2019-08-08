import random
import networkx as nx

import matplotlib.pyplot as plt 

g = nx.erdos_renyi_graph(20, 0.5)

f = open("matrix.txt", "w")


mat = nx.adjacency_matrix(g).todense().tolist()

plt.show()
for row in mat:
    f.write(" ".join([str(x) for x in row]) + "\n")

