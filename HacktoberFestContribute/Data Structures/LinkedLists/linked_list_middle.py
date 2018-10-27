#!/usr/bin/env python3

#Our node class.
class Node:
    def __init__(self, value, next_node):
        self.value = value
        self.next_node = next_node

    def __repr__(self):
        if self.next_node == None:
            return repr(self.value)
        return "{} {}".format(self.value, self.next_node)

    value = None
    next_node = None

#Make a linked list, given something like an array.
def make_linked_list(iterable):
    head = Node(iterable[0], None)
    tail = head
    for element in iterable[1:]:
        new_node = Node(element, None)
        tail.next_node = new_node
        tail = new_node
    return head, tail #We won't use it here, but might as well return the tail

#We won't use it, but have it anyways. You can use it if this was a doubly linked list.
def get_tail(node):
    while node.next_node != None:
        node = node.next_node
    return node

def get_middle(head):
    #start both runners at the beginning of the list
    fast_runner = slow_runner = head
    while fast_runner.next_node != None and fast_runner.next_node.next_node != None:
        #Every time, the fast runner moves two spaces and the slow runner moves one.
        #This means that when the fast runner falls off, the slow runner is in the middle.
        slow_runner = slow_runner.next_node
        fast_runner = fast_runner.next_node.next_node
    return slow_runner

head, tail = make_linked_list([8,6,7,5,3,0,9])
print(head)
print(tail)
print(get_middle(head).value)
