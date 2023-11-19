import networkx as nx
import matplotlib.pyplot as plt
import sys

INF = sys.maxsize

# Define the adjacency matrix
graph = [
        [ 0, 3, 2, 1, 4 ], 
        [ 3, 0, 5, 6, 7 ], 
        [ 2, 5, 0, 8, 9 ], 
        [ 1, 6, 8, 0, 10 ], 
        [ 4, 7, 9, 10, 0 ]  
    

]

# Create a graph
G = nx.Graph()

# Add nodes and edges to the graph
num_nodes = len(graph)
G.add_nodes_from(range(num_nodes))

for i in range(num_nodes):
    for j in range(i + 1, num_nodes):
        weight = graph[i][j]
        if weight != INF:
            G.add_edge(i, j, weight=weight)

# Draw the graph
pos = nx.spring_layout(G)  # Positions nodes using Fruchterman-Reingold force-directed algorithm
labels = nx.get_edge_attributes(G, 'weight')
nx.draw(G, pos, with_labels=True, node_size=500, node_color='lightblue', font_weight='bold', font_size=10)
nx.draw_networkx_edge_labels(G, pos, edge_labels=labels)
plt.title('Graph Visualization')
plt.show()
