class circleQueue:
    def __init__(self, size):
        self.size = size
        self.dat = [None] * self.size
        self.first = 0
        self.last = 0

    def enqueue(self, item):
        if self.last == self.first and self.dat[self.last] == None:
            self.dat[self.last] = item
        else: 
            self.last = (self.last + 1) % self.size
            self.dat[self.last] = item

    def dequeue(self):
        self.dat[self.first] = None
        self.first = (self.first + 1) % self.size
        return self.dat[self.first]

    def __lt__(self, other):
        # Iterate through each element in the queue
        for i in range(self.size):
            # If both elements are None, continue to the next iteration
            if self.dat[i] is None and other.dat[i] is None:
                continue
            elif self.dat[i] is None:
                return True
            elif other.dat[i] is None:
                return False
            elif self.dat[i] < other.dat[i]:
                return True
            elif self.dat[i] > other.dat[i]:
                return False
        # If all elements are equal, self is not less than other
        return False

    def __str__(self):
        return str(self.dat)

    


# Create two queue instances
q1 = circleQueue(5)
q2 = circleQueue(5)

# Scenario 1: q1 is less than q2
q1.enqueue(1)
q1.enqueue(4)
q1.enqueue(3)

q2.enqueue(1)
q2.enqueue(3)
q2.enqueue(4)
print(f"q1: {q1}, q2: {q2}")
print("q1 < q2:", q1 < q2)  


