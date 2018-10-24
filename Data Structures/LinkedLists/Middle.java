import java.util.*;

class Node {
	int data;
	Node next;
	public Node() {
		this.data = data;
		this.next = null;
	}
	public Node(int d) {
		this.data = d;
	}
}

class Linked {
	Node head;
	Linked() {
		head = null;
	}

	void insertAtEnd(int data) {
		Node n = new Node(data);
		if(head == null) {
			head = n;
		} else {
				Node temp;
				for(temp = head; temp.next != null; temp = temp.next);
				temp.next = n;
				n.next = null;
		}
	}
	void middleElement() {
		Node temp;
		int l = 1;
		for(temp = head; temp.next != null; temp = temp.next) {
			l++;
		}
		int pos = l/2;
		int i;
		for(temp = head, i = 0; temp.next.next != null && i <= pos - 1;temp = temp.next, i++);
		System.out.println(temp.data);
	}
}

class Middle {
    public static void main(String[] args) {
		Scanner Sc = new Scanner(System.in);
		Linked ll = new Linked();
        int size;
        System.out.println("Enter the size:");
        size = Sc.nextInt();
        for( int s = 0; s < size; s++) {
            System.out.println("Enter the data");
            int data = Sc.nextInt();
            ll.insertAtEnd(data);
        }
        System.out.print("Element in the middle of the linked list is: ");
		ll.middleElement();
    }
}    

