
import java.util.*;
class Node{
  int data;
  Node next,prev;
  Node(int data){
    this.data = data;
    this.next = this.prev = null;
  }
}
class Doubly{
  Node head;
  Doubly(){
    this.head = null;
  }
  void insert(int data){
    Node n = new Node(data);
    if(head == null){
      head =n;
      n.next = null;
    }
    else{
      Node t =head;
      while(t.next!=null){
        t= t.next;
      }
      t.next = n;
      n.prev = t;
      n.next = null;
    }
  }
  void print(){
    Node t =head;
    if(head == null){
      System.out.println("linked list is empty");
    }
    else{
    while(t.next!= null){
      System.out.print(t.data + " ");
      t = t.next;
    }
    System.out.print(t.data + " ");
    System.out.println();
  }
}

void delete_data(int data){
  Node t = head;
  while(t.next!=null){
    if(t.data == data){
      if(t==head){
        head = t.next;
        break;
      }else{
        t.next.prev = t.prev;
        t.prev.next = t.next;
        break;
      }
    }
    else{
      t = t.next;
    }
    if(t.next == null){
      t.prev.next =null;
    }
  }
}
public static void main(String[] args){
  Doubly q = new Doubly();
  Scanner Sc = new Scanner(System.in);
  q.insert(15);
  q.insert(20);
  q.insert(25);
  q.insert(30);
  q.print();
  System.out.println("after inserting the data: ");
  q.print();
  System.out.println("after deleting the data: ");
  q.delete_data(25);
  q.print();
}
}
