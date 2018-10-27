# Defining Node class  
class Node: 

    # This is a constructor to initialise the node object 
    def __init__(self, data): 
        self.data = data 
        self.next = None
  
class LinkedList: 
  
    # This is the function to initialise head 
    def __init__(self): 
        self.head = None
  
    # This is the function to reverse the linked list 
    def reverseLinkedList(self): 
        previousNode = None
        currentNode = self.head 
        # This is the loop to swap and hence effectively reverse the linked list at the end of the loop
        while(currentNode is not None): 
            nextNode = currentNode.next
            currentNode.next = previousNode
            previousNode = currentNode
            currentNode = nextNode
        self.head = previousNode
          
    # This is the function to insert a new node at the beginning 
    def push(self, newData): 
        newNode = Node(newData) 
        newNode.next = self.head 
        self.head = newNode 
  
    # This is the function to print the linked LinkedList 
    def printList(self): 
        temporaryNode = self.head 
        while(temporaryNode): 
            print(temporaryNode.data)
            temporaryNode = temporaryNode.next
        
LList = LinkedList() 
LList.push(100) 
LList.push(45) 
LList.push(6) 
LList.push(20) 
LList.push(73)
  
print("Given Linked List")
LList.printList() 
LList.reverseLinkedList() 
print("\nReversed Linked List")
LList.printList() 

'''Explanation:
The reverseLinkedList method initially sets previousNode as None, 
currentNode as head and nextNode as the next node of currentNode.
It then iterates through the linked list until it reaches the end of the linked list, 
i.e. currentNode is None (this is the loop’s exit condition).
During each iteration, it sets the next node of currentNode to previousNode for traversal and then
then, sets previousNode as currentNode, currentNode as nextNode for swapping
and then nextNode as its next node (this is the loop’s iteration process).
Once the current becomes None, it sets the head pointer to the previousNode, 
which was the tail of the linked list initially.  '''
