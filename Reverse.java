
class Reverse {
  static class Node {

      int data;
      Node next;

      Node(int d) {
          data = d;
          next = null;
      }
  }

  static Node head;
  Node reversed(Node node) {
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


  void print(Node node) {
      while (node != null) {
          System.out.print(node.data + " ");
          node = node.next;
      }
  }

  public static void main(String[] args) {
      Reverse l = new Reverse();
      l.head = new Node(1);
      l.head.next = new Node(2);
      l.head.next.next = new Node(3);
      l.head.next.next.next = new Node(4);
      head = l.reversed(head);
      System.out.println("Reversed");
      l.print(head);
  }
}
