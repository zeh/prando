// Java program to get intersection point of two linked list

class LinkedList {

    static Node head1, head2;

    static class Node {

        int data;
        Node next;

        Node(int d) {
            data = d;
            next = null;
        }
    }

    public int getElement(Node node, int n) {
    	//Function that returns the nth element of the given linked list
    	Node current = node;
    	int count = 0;
    	int size = getCount(node);
    	//Check if the given position is valid
    	if(n >= size || n < 0) {
    		System.out.println("Invalid position");
    		return -1;
    	}

    	while(current != null && count < n) {
    		count++;
    		current = current.next;
    	}
    	return current.data;
    }

    public void printMiddle(Node list) {
    	int size = getCount(list);
    	 /*If the size of the list is even then print the two elements around the middle
    	 otherwise just print a single element
    	 if the list is empty don't do anything*/
    	int middle = size/2;
    	if(size % 2 == 0 && size > 0) {
    		System.out.printf("%d %d\n", getElement(list, middle - 1), getElement(list, middle));
    	}
    	else if(size % 2 == 1) {
    		System.out.printf("%d\n", getElement(list, middle));
    	}
    }

    /*function to get the intersection point of two linked
    lists head1 and head2 */
    int getNode() {
        int c1 = getCount(head1);
        int c2 = getCount(head2);
        int d;

        if (c1 > c2) {
            d = c1 - c2;
            return _getIntesectionNode(d, head1, head2);
        } else {
            d = c2 - c1;
            return _getIntesectionNode(d, head2, head1);
        }
    }

    /* function to get the intersection point of two linked
     lists head1 and head2 where head1 has d more nodes than
     head2 */
    int _getIntesectionNode(int d, Node node1, Node node2) {
        int i;
        Node current1 = node1;
        Node current2 = node2;
        for (i = 0; i < d; i++) {
            if (current1 == null) {
                return -1;
            }
            current1 = current1.next;
        }
        while (current1 != null && current2 != null) {
            if (current1.data == current2.data) {
                return current1.data;
            }
            current1 = current1.next;
            current2 = current2.next;
        }

        return -1;
    }

    /*Takes head pointer of the linked list and
    returns the count of nodes in the list */
    int getCount(Node node) {
        Node current = node;
        int count = 0;

        while (current != null) {
            count++;
            current = current.next;
        }
        return count;
    }

    public static void main(String[] args) {
        LinkedList list = new LinkedList();

        // creating first linked list
        list.head1 = new Node(3);
        list.head1.next = new Node(6);
        list.head1.next.next = new Node(15);
        list.head1.next.next.next = new Node(15);
        list.head1.next.next.next.next = new Node(30);

        // creating second linked list
        list.head2 = new Node(10);
        list.head2.next = new Node(15);
        list.head2.next.next = new Node(30);

        System.out.println("The node of intersection is " + list.getNode());

        System.out.println(list.getElement(list.head1, 4));

        System.out.println("Printing middle");
        list.printMiddle(list.head2);
        System.out.println(list.head1.data);
    }
}
