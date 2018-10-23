class nthNodeFromEnd{ 
    Node head; 
    class Node { 
        int data; 
        Node next; 
        Node(int d) { 
            data = d; 
            next = null; 
        } 
    } 
    void printNthFromLast(int n) { 
        int len = 0; 
        Node temp = head; 
  
        while (temp != null){ 
            temp = temp.next; 
            len++; 
        } 
        if (len < n) 
            return; 
        
        temp = head; 
        
        for (int i = 1; i < len-n+1; i++) 
            temp = temp.next; 
  
        System.out.println(temp.data); 
    } 
    public void push(int new_data) 
    { 
        Node new_node = new Node(new_data); 
        new_node.next = head; 
        head = new_node; 
    } 
    public static void main(String [] args) 
    { 
        nthNodeFromEnd llist = new nthNodeFromEnd(); 
        llist.push(20); 
        llist.push(4); 
        llist.push(15); 
        llist.push(35); 
        llist.printNthFromLast(3); 
    } 
    }
