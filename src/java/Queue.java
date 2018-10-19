import java.util.*;
class Node
{
    int key;
    Node ptr;

        public Node(int data) {
        this.key = data;
        this.ptr = null;
    }
}

class QueueLink
{
    Node front;
    Node rear;
    public QueueLink() {
        this.front = this.rear = null;
    }

    void push(int data)
    {

        Node newnode = new Node(data);


        if (this.rear == null)
        {
           this.front = this.rear = newnode;
           return;
        }

        this.rear.ptr = newnode;
        this.rear = newnode;
    }

    Node pop()
    {
        if (this.front == null)
           System.out.println("Empty");

        Node temp = this.front;
        this.front = this.front.ptr;

        if (this.front == null)
           this.rear = null;
           return temp;

    }
}



public class Queue
{
    public static void main(String[] args)
    {
        QueueLink q = new QueueLink();
        q.push(10);
        q.push(20);
        q.pop();
        q.pop();
        q.push(30);
        q.push(40);
        q.push(50);
      System.out.println("Dequeued element is:"+ q.pop().key);
    }
  }
