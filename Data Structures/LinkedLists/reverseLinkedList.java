class LinkedList { 
  
    static Node head; 
  
    static class Node { 
  
        int data; 
        Node next; 
  
        Node(int d) { 
            data = d; 
            next = null; 
        } 
    } 
  
    /* Function to reverse the linked list */
    Node reverse(Node node) { 
        Node prev = null; 
        Node current = node; 
        Node next = null; 
        while (current != null) { 
            next = current.next; 
            current.next = prev; 
            prev = current; 
            current = next; 
        } 
        node = prev; 
        return node; 
    } 
  
    // prints content of a linked list 
    void printList(Node node) { 
        while (node != null) { 
            System.out.print(node.data + " "); 
            node = node.next; 
        } 
    } 
  
    public static void main(String[] args) { 
        LinkedList list = new LinkedList(); 
        list.head = new Node(73); 
        list.head.next = new Node(27); 
        list.head.next.next = new Node(9); 
        list.head.next.next.next = new Node(56); 
        list.head.next.next.next.next = new Node(11); 
        list.head.next.next.next.next.next = new Node(20); 
          
        System.out.println("Given Linked list"); 
        list.printList(head); 
        head = list.reverse(head); 
        System.out.println(""); 
        System.out.println("Reversed linked list "); 
        list.printList(head); 
    } 
} 
 
/*
Explanation:
We initialize three pointers prev as NULL, curr as head and next as NULL.
Then we iterate trough the linked list. 
During each iteration, before changing the next of current,
we store the next node as next = curr->next
and then change the next of current.
The real reversal happens when we change next of current
and then shift to the next node by changing prev = curr and curr = next.
Finally, we return the previous node, prev, as the head of the linked list.
**/
