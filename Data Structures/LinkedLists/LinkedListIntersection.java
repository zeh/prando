import java.util.*;

class LinkedListIntersection
{
	class Node
	{
		int data;
		Node next;

		public Node()
		{
			data = 0;
			next = null;
		}

		public Node(int data)
		{
			this.data = data;
			next = null;
		}

		public Node(Node x)
		{
			data = x.data;
			next = x.next;
		}

		@Override
		public int hashCode()
		{
			return data;
		}

		@Override
		public boolean equals(Object obj)
		{
			if (obj instanceof Node)
			{
				Node n = (Node)obj;
				return data == n.data;
			}
			else
				return false;
		}
	}

	Node head;

	public LinkedListIntersection()
	{
		head = null;
	}

	public void insertAtFront(int x)
	{
        Node n = new Node(x);
        n.next = head;
        head = n;
    }

    public boolean intersection(LinkedListIntersection other)
    {
    	Set<Node> nodes = new HashSet<>();
    	// Add all nodes of this LinkedList to a Set
    	for(Node t = head; t != null; t = t.next)
    		nodes.add(t);

    	// Check if the other LinkedList has any common Node
    	for(Node t = other.head; t != null; t = t.next)
    		if (nodes.contains(t))
    			return true;
    	return false;
    }

    public void display()
    {
        for (Node t = head; t != null; t = t.next) {
            System.out.print(t.data + " ");
        }
        System.out.println();
    }

	public static void main(String[] args)
	{
		LinkedListIntersection l1, l2, l3;
		l1 = new LinkedListIntersection();
		l2 = new LinkedListIntersection();
		l3 = new LinkedListIntersection();

		l1.insertAtFront(10);
		l1.insertAtFront(20);
		l1.insertAtFront(30);
		l1.insertAtFront(40);
		l1.insertAtFront(50);

		l2.insertAtFront(1);
		l2.insertAtFront(2);
		l2.insertAtFront(3);
		l2.insertAtFront(4);
		l2.insertAtFront(5);

		l3.insertAtFront(5);
		l3.insertAtFront(10);
		l3.insertAtFront(15);
		l3.insertAtFront(20);
		l3.insertAtFront(25);

		System.out.print("LinkedList l1: ");
		l1.display();
		System.out.print("LinkedList l2: ");
		l2.display();
		System.out.print("LinkedList l3: ");
		l3.display();

		System.out.println("l1 intersection l2 = " + l1.intersection(l2));
		System.out.println("l1 intersection l3 = " + l1.intersection(l3));
		System.out.println("l2 intersection l3 = " + l2.intersection(l3));
	}
}