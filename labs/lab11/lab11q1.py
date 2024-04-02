from queue import Queue


class Node:
    def __init__(self, value):
        self.value = value
        self.neighbours = set() # O(1) to look up and insert on average
                                # O(n) in the worst case

def are_nodes_linked(node1, node2):
    # node1 and node2 are linked if there is an edge between
    # node1 and node2
    # Assume graph is undirected
    return node2 in node1.neighbours  # don't need to check that node1 is in node2.neighbours


def get_node_by_str(nodes, node_str):
    return nodes.get(node_str, None)
    # for node in nodes:
    #     if node.value == node_str:
    #         return node
    # return None


def breadth_first_search(graph, start_key):
    visited = set()  # Initialize the set of visited nodes
    ds = Queue()  # Initialize the queue
    ds.put(start_key)  # Add the start node to the queue
    visited.add(start_key)  # Mark the start node as visited
    while not ds.empty():
        node = ds.get()  # Get the first node in the queue
        print(node)
        for neighbor in graph[node]:  # Iterate over the neighbors of the current node
            if neighbor not in visited:  # Check if the neighbor has not been visited
                ds.put(neighbor)  # Add the neighbor to the queue
                visited.add(neighbor)

def depth_first_search(graph, start_key):
    visited = set()  # Initialize the set of visited nodes
    ds = []  # Initialize the stack
    ds.append(start_key)  # Add the start node to the stack
    visited.add(start_key)  # Mark the start node as visited
    while ds: 
        node = ds.pop() # Get the last node in the stack
        print(node) 
        for neighbor in graph[node]: 
            if neighbor not in visited: # Check if the neighbor has not been visited
                ds.append(neighbor) # Add the unvisited neighbor to the stack
                visited.add(neighbor) # Mark the neighbor as visited


graph = {
    1: [3,6],
    2: [3,4],
    3: [1,2,4,5],
    4: [2,3,5],
    5: [3,4,6],
    6: [1,5]
}
print(breadth_first_search(graph, 1))
print(depth_first_search(graph, 1))