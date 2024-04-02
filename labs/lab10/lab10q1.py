#Question 1
import LinkedLists as LL
class LL:
   def __init__(self):
       self.head = None




   def insert(self, loc, element):
       new_node = Node(element)  # data: element, next: None
       if loc == 0:
           new_node.next = self.head
           self.head = new_node
       else:
           cur = self.head
           for i in range(loc-1):
               cur = cur.next
           new_node.next = cur.next
           cur.next = new_node
       
   def delete(self, loc):
       if loc == 0:
           self.head = self.head.next 
       else:
           cur = self.head
           for i in range(loc-1):
               cur = cur.next
           # cur is the node before the node that we want to delete
           cur.next = cur.next.next




class Node:
   def __init__(self, data):
       self.data = data
       self.next = None






# def get_neighbours(Link):
#     neigh = []
#     if Link.head == None:
#         return neigh
#     else:
#         neigh.append(Link.head.data)
#         point = Link.head.next
#         while point.next != None:
#             neigh.append(point.data)
#             point = point.next


def are_linked(Link1, Link2):
   Node1 = Link1.head.data
   point = Link2.head.next
   while point != None:
       if Node1 == point.data:
           return True
       else:
           point = point.next
   if point == Node1:
       return True
   return False
   
if __name__ == "__main__":
   Node1 = Node(1)
   Node2 = Node(2)
   Node3 = Node(3)
   Node4 = Node(4)


   Link = LL()
   Link.insert(0, Node1)
   Link.insert(1, Node3)
   Link.insert(2, Node4)
   Link.insert(3, Node2)


   Link2 = LL()
   Link2.insert(0,Node2)
   Link2.insert(1,Node3)
   Link2.insert(2, Node1)


   Link3 = LL()
   Link3.insert(0,Node3)
   Link3.insert(1,Node2)
   Link3.insert(2, Node1)


   Link4 = LL()
   Link4.insert(0,Node4)
   Link4.insert(1, Node1)


   print(are_linked(Link, Link2))
   print(are_linked(Link2, Link4))