class Node(object):
	def __init__(self, data, next):
		self.data = data
		self.next = next

class SingleList(object):

	head = None
	tail = None

	def printList(self):
		print "Link List:"
		current_node = self.head
		while current_node is not None:
			print current_node.data, " --> ",
			current_node = current_node.next
		print None

	def add(self, data):
    		node = Node(data, None)
    		if self.head is None:
        		self.head = self.tail = node
    		else:
        		self.tail.next = node
    		self.tail = node
	def insert(self, before, nextdata):
    #nextdata is to be inserted before 'before'
    #before is actually a data
    #but it has dif name in this def to avoid confusion with 'data'
    		current_node = self.head
    		previous_node = None
    		while current_node is not None:
        		if current_node.data == before:
            			if previous_node is not None:
                			temp_node = current_node
                			current_node = Node(nextdata, temp_node)
                			previous_node.next = current_node
            			else:
                			new_node = Node(nextdata, current_node)
                			self.head = new_node
            			break
        		previous_node = current_node
        		current_node = current_node.next

	def remove(self, node_value):
    		current_node = self.head
    		previous_node = None
    		while current_node is not None:
        		if current_node.data == node_value:
            # if this is the first node (head)
            			if previous_node is not None:
                			previous_node.next = current_node.next
            			else:
                			self.head = current_node.next
        # needed for the next iteration
        		previous_node = current_node
        		current_node = current_node.next


s= SingleList()
s.add(1)
s.add(29)
s.add(56)


s.printList()
s.remove(3)
s.remove(29)
s.printList()

