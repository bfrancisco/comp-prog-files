import io,os
input = io.BytesIO(os.read(0,os.fstat(0).st_size)).readline

class Node:
    def __init__(self, data):
        self.data = data  
        self.next = None  
        self.prev = None  

    def get_data(self):
        return self.data
class Sentinel_DLL:
    # Create the sentinel node, which is before the first node
    # and after the last node.
    def __init__(self):
        self.sentinel = Node(None)
        self.sentinel.next = self.sentinel
        self.sentinel.prev = self.sentinel

    # Return a reference to the first node in the list, if there is one.
    # If the list is empty, return None.
    def first_node(self):
        if self.sentinel.next == self.sentinel:
            return None
        else:
            return self.sentinel.next

    # Insert a new node with data after node x.
    def insert_after(self, x, data):
        y = Node(data)   # make a new Node object.

        # Fix up the links in the new node.
        y.prev = x
        y.next = x.next

        # The new node follows x.
        x.next = y

        # And it's the previous node of its next node.
        y.next.prev = y

    # Insert a new node at the end of the list.
    def append(self, data):
        last_node = self.sentinel.prev
        self.insert_after(last_node, data)

    # Insert a new node at the start of the list.
    def prepend(self, data):
        self.insert_after(self.sentinel, data)

    # Delete node x from the list.
    def delete(self, x):
        # Splice out node x by making its next and previous
        # reference each other.
        x.prev.next = x.next
        x.next.prev = x.prev

    # Find a node containing data, and return a reference to it.
    # If no node contains data, return None.
    def find(self, data):
        # Trick: Store a copy of the data in the sentinel,
        # so that the data is always found.
        self.sentinel.data = data

        x = self.first_node()
        while x.data != data:
            x = x.next

        # Restore the sentinel's data.
        self.sentinel.data = None

        # Why did we drop out of the while-loop?
        # If we found the data in the sentinel, then it wasn't
        # anywhere else in the list.
        if x == self.sentinel:
            return None     # data wasn't really in the list
        else:
            return x        # we found it in x, in the list

    #  Return the string representation of a circular, doubly linked
    #  list with a sentinel, just as if it were a Python list.
    def __str__(self):
        s = "["

        x = self.sentinel.next
        while x != self.sentinel:  # look at each node in the list
            if type(x.data) == str:
                s += "'"
            s += str(x.data)        # concatenate this node's data
            if type(x.data) == str:
                s += "'"
            if x.next != self.sentinel:
                s += ", "   # if not the last node, add the comma and space
            x = x.next

        s += "]"
        return s
    
n, k = map(int, input().split())
a = list(map(int, input().split()))
b = []
lst = Sentinel_DLL()
for i in range(n):
    b.append([a[i], i])
    lst.append([a[i], i])
b.sort(reverse=True)


#print(lst)
#print(b)
db = {} # val : node reference
node = lst.first_node()
while node.get_data() != None:
    db[node.get_data()[0]] = node
    node = node.next

out = [0 for i in range(n)]
purge = set()
x = 0
for ele in b:
    val, ind = ele
    if val in purge:
        continue
    #print(ele.get_data())
    ognode = db[val]
    out[ind] = x+1
    purge.add(val)

    node = ognode
    for _ in range(k):
        if node.prev.get_data() == None: # if sentinel
            break
        node = node.prev
        out[node.get_data()[1]] = x+1
        purge.add(node.get_data()[0])
    left = node

    node = ognode
    for _ in range(k):
        if node.next.get_data() == None: # if sentinel
            break
        node = node.next
        out[node.get_data()[1]] = x+1
        purge.add(node.get_data()[0])
    right = node

    # delete left to right
    left.prev.next = right.next
    right.next.prev = left.prev
    
    # reverse x
    x = 1 - x

print(*out, sep='')