import numpy as py 
from LinkedLists import LL, Node

def get_node_by_str(nodes, node_str):
    cur = nodes.head
    while cur is not None:
        if cur.value == node_str:
            return cur.head  # Return the node if the value matches
        cur = cur.next
        
    return None  # Return None if the node is not found

def are_airports_linked(airports, airport1_str, airport2_str):
    airport1 = get_node_by_str(airports, airport1_str)

    if airport1 == None:
        return False  # Return False if airport1 is not found

    cur = airport1.head
    while cur.next is not None:
        if cur.data.upper() == airport2_str:
            return True  # Return True if airport2 is found in the linked list
    
    return False  # Return False if airport2 is not found in the linked list

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

    yyz.neighbours = set([yvr, yul])
    yvr.neighbours = set([yyz, yul, whitehorse])
    yul.neighbours = set([yyz, yvr])
    whitehorse.neighbours = set([yvr])


    airport_dict = {}
    for airport in [yyz, yvr, yul, whitehorse]:
        airport_dict[airport.value] = airport
    
    return airport_dict