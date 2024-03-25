from LinkedLists import LL, Node

def are_nodes_linked(node1, node2):
    return node1.neighbours.contains(node2)  # Check if node2 is a neighbour of node1

def get_node_by_str(nodes, node_str):
    for node in nodes:
        if node.value == node_str:
            return node  # Return the node with the given value
    return None

def are_airports_linked(airports, airport1_str, airport2_str):
    airport1 = get_node_by_str(airports, airport1_str)
    airport2 = get_node_by_str(airports, airport2_str)
    if airport1 is None or airport2 is None:
        return False  # If either airport is not found, return False
    return are_nodes_linked(airport1, airport2)  # Check if the airports are linked

def make_airport_graph1():
    airports = LL()

    yyz = LL()
    yyz.insert(0, "YYZ")
    yyz.insert(1, "YVR")
    yyz.insert(2, "YUL")

    yvr = LL()
    yvr.insert(0, "YVR")
    yvr.insert(1, "YYZ")
    yvr.insert(2, "YUL")
    yvr.insert(3, "Whitehorse")

    yul = LL()
    yul.insert(0)

    yul = Node("YUL")
    whitehorse = Node("Whitehorse")

    yyz.neighbours = set([yvr, yul])  # Set the neighbours of YYZ
    yvr.neighbours = set([yyz, yul, whitehorse])  # Set the neighbours of YVR
    yul.neighbours = set([yyz, yvr])  # Set the neighbours of YUL
    whitehorse.neighbours = set([yvr])  # Set the neighbours of Whitehorse

    airport_dict = {}
    for airport in [yyz, yvr, yul, whitehorse]:
        airport_dict[airport.value] = airport  # Create a dictionary with airport values as keys

    return airport_dict

if __name__ == '__main__':
    airports = make_airport_graph1()
    print("Toronto (YYZ) is connected to Montreal (YUL)?", are_airports_linked(airports, "YYZ", "YUL"))
