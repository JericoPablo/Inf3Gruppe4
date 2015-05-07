'''
Created on 05.05.2015

@author: Tugrul
'''


class Node:
    def __init__(self, value):
        '''
        Constructor
        '''
        self.value = value
        self.leftChild = None
        self.rightChild = None
        
    def insert(self, data):
        if self.value == data:
            'if there is a Node with the same value it inserts it on the right side/ right child'              
            self.rightChild = Node(data)
        
        elif self.value > data:
            'if the data/value of the new node is lower it checks if there is any left child if it has a left child it inserts it there if not it creats a new left child'
            if self.leftChild:
                self.leftChild.insert(data)
            else:
                self.leftChild = Node(data)
                
        else:
            if self.rightChild:
                'if the data/value of the new node is higher it checks if there is any right child if it has a right child it inserts it there if not it creats a new right child'
                self.rightChild.insert(data)
            else:
                self.rightChild = Node(data)
                
    
    def find(self, data):
        'recursive method to find the Node'
        if(self.value == data):
            'checking if the Node is found'
            return True
        elif self.value > data:
            'if its lower then the value it just can be on the left side - BS-Tree Concept!'
            if self.leftChild:
                return self.leftChild.find(data)
            else:
                'it not here'
                return False
        else:
            'else its on the right side'
            if self.rightChild:
                return self.rightChild.find(data)
            else:
                'its not here'
                return False
    
    def preOrder(self):
        'to preorder the Nodes'
        if self:
            print (str(self.value))
            if self.leftChild:
                self.leftChild.preOrder()
            if self.rightChild:
                self.rightChild.preOrder()
     
    def delete(self, data):
        'delete the node with the given key and return the root node of the tree'
        if self.value == data:
            'found the node we need to delete'
            
            if self.rightChild and self.leftChild: 
                
                'get the successor node and its parent'
                [psucc, succ] = self.rightChild.find(self)
                
                'splice out the successor'
                '(we need the parent to do this)' 
                
                if psucc.leftChild == succ:
                    psucc.leftChild = succ.rightChild
                else:
                    psucc.rightChild = succ.rightChild
                                
                'reset the left and right children of the successor'
                
                succ.leftChild = self.leftChild
                succ.rightChild = self.rightChild
                
                return succ                
                
            else:
                if self.leftChild:
                    'promote the left subtree'
                    return self.leftChild 
                else:
                    'promote the right subtree'
                    return self.rightChild    
        else:
            'key should be in the left subtree'
            if self.value > data:          
                if self.leftChild:
                    self.leftChild = self.leftChild.delete(data)
                    'else the key is not in the tree'
                 
                    
            else:
                'key should be in the right subtree'                       
                if self.rightChild:
                    self.rightChild = self.rightChild.delete(data)
                    
        return self           
                
                


class Tree:
    
    def __init__(self):
        self.root = None
    
    def insert(self, data):
        self.nodeValue = str(data)
        assert type(data) is int, "Node is not an integer, its a B-Tree please insert an int value. False Value: " +self.nodeValue
        'to call the recursive funktion in Node'
        if self.root:
            'checking if there is already a B-Tree if there is one we call the recursive method to insert a Node'
            self.root.insert(data)
            assert self.find(data), 'could not add the Node you want to'
        else:
            'if not then we are creating a root node/ a new B-Tree'
            self.root = Node(data)
            assert self.find(data), 'could not create a new B-Tree/root Node'
            
    
    def find(self, data):
        assert type(data) is int, 'please search for an integer'
        'funktion to call the recursive funktion in Node Class'
        if self.root:
            'checking if there is any root Node if not there is no B-Tree'
            return self.root.find(data)
        else:
            'it couldnt find the Node - there is no Node with the value we R searching for'
            return False
    
    def delete(self, data):
        assert self.find(data), 'there is no Node with that value to delete'
        'delete the node with the given key if it exists '
        if self.root:
            self.root = self.root.delete(data)
            assert not self.find(data), 'try again, it could not delete the Node you want to'
    
    def preOrder(self):
        print("-- PreOrder --")
        self.root.preOrder()
        print("-- End Of PreOrder --")
   
           
if __name__ == '__main__':
    pass
          
bst = Tree()
bst.insert(14)
bst.insert(-1)
bst.insert(1)
bst.insert(2)
bst.insert(-2)
bst.insert(-2)
bst.insert(30)
bst.insert(148)
bst.insert(9)
bst.preOrder()
print(bst.find(30))
bst.delete(30)
print("                                    ")
print("------------- geloescht -------------")
bst.preOrder()
print(bst.find(30))


        
            
                