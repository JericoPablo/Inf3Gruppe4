'''
Created on 20.04.2015

@author: Tugrul
'''

class Node:
    def __init__(self, data=None):
        self.data = data
        self.left = None
        self.right = None

    def __repr__(self):
        return "{%s, %i, %i}" % (str(self.data), id(self.left), id(self.right))
    
class BTree:
    def __init__(self):
        self.root = None

    def add(self, data):
        if self.root == None:
            self.root = Node(data)
        else:
            curnode = self.root
            lastnode = self.root
            while curnode != None:
                lastnode = curnode
                if data < curnode.data:
                    curnode = curnode.left
                    direction = -1      
                else:
                    curnode = curnode.right
                    direction = +1      
            if direction == -1:
                lastnode.left = Node(data)
            else:
                lastnode.right = Node(data)

    def _prchilds(self, node):
        if node != None:
            return "(%s, %s %s)" % (self._prchilds(node.left), node, self._prchilds(node.right))
        

    def __repr__(self):
        return self._prchilds(self.root)

t = BTree()
t.add(1)
t.add(2)
t.add(44)
t.add(17)
t.add(21)
print(t)