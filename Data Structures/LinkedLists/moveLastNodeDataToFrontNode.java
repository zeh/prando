class LinkedList 
{ 
    Node head;
   
    class Node 
    { 
        int data; 
        Node next; 
        Node(int d) {data = d; next = null; } 
    } 
  
    void moveToFront() 
    { 
           if(head == null || head.next == null)  
              return; 
  
        Node secLast = null; 
        Node last = head; 
  
        while (last.next != null)   
        { 
           secLast = last; 
           last = last.next;  
        } 
  
        secLast.next = null; 
  
        last.next = head; 
  
        head = last; 
    }                  
  
    /* Inserts a new Node at front of the list. */
    public void push(int new_data) 
    { 
        Node new_node = new Node(new_data); 
        new_node.next = head; 
        head = new_node; 
    } 
  
    /* Function to print linked list, uncomment if required*/
    /*void printList() 
    { 
        Node temp = head; 
        while(temp != null) 
        { 
           System.out.print(temp.data+" "); 
           temp = temp.next; 
        }   
        System.out.println(); 
    } */
  

     /* Stub to test above functions */
    public static void main(String args[]) 
    { 
        LinkedList llist = new LinkedList(); 
 
        llist.push(5); 
        llist.push(4); 
        llist.push(3); 
        llist.push(2); 
        llist.push(1); 
          
        System.out.println("Initial Linked List "); 
        llist.printList(); 
          
        llist.moveToFront(); 
          
        System.out.println("Linked List after moving last to front "); 
        llist.printList(); 
    } 
}
