class Node:
    def __init__(self, value):
        self.value = value
        self.neighbours = set()
    #O(1) to look up and insert on average
    #O(n) in the worst case
        
def are_nodes_linked(node1, node2):
    #node1 and node2 are linked if there is a path from node1 to node2
    #assume that the graph is undirected
    return node2 in node1.neighbours 

d
    