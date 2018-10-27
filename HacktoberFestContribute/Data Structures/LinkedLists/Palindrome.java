import java.util.*;

class Node {
	int data;
	Node next;
	public Node() {
		this.data = data;
		this.next = null;
	}
	public Node(int data) {
		this.data = data;
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
	
	boolean palindrome() {
		int i = 0;
		int j;
        Node front;
        Node rear;
        int cnt = 1;
        Node temp = head;
        while(temp.next != null) {
            cnt ++;
            temp = temp.next;
        }

        while(i != cnt/2) {
            front = rear = this.head;
            for(j = 0; j < i; j++ ) {
                front = front.next;
            }
            for(j = 0; j < cnt - i - 1; j++) {
                rear = rear.next;
            }
            if(front.data != rear.data) {
                return false;
            } else {
                i++;
            }
        }
        return true;
    }
}

class Palindrome {
public static void main(String[] args) {
		Scanner Sc = new Scanner(System.in);
		Linked ll = new Linked();
		System.out.println("Enter the size:");
		int size;
		size = Sc.nextInt();
		for(int s = 0; s < size; s++) {
            System.out.print("Enter the data:");
            int data = Sc.nextInt();
            ll.insertAtEnd(data);
        }
		boolean st = ll.palindrome();
		if(st == true) {
			System.out.println("Linked list is a palindrome");
		} else {
			System.out.println("Linked list is not palindrome");
		}
    }
}
