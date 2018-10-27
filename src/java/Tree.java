
import java.util.*;


class Node {
  Node left;
  Node right;
  int data;

  Node(int data) {
    this.data = data;
    this.right = this.left = null;
  }
}
class BinaryTree {

  Node root;

    BinaryTree() {
        root = null;
    }

    void add(int key) {
       root = insert(root, key);
    }
    Node insert(Node root, int key) {

        if (root == null) {
            root = new Node(key);
            return root;
        }

        if (key < root.data)
            root.left = insert(root.left, key);
        else if (key > root.data)
            root.right = insert(root.right, key);
        return root;
    }
    void display()  {
       print(root);
    }

    // A utility function to do inorder traversal of BST
    void print(Node root) {
        if (root != null) {
            print(root.left);
            System.out.println(root.data);
            print(root.right);
        }
    }
    void del(int key)
    {
        root = delete(root, key);
    }


    Node delete(Node root, int key)
    {
        if (root == null)
        return root;

        if (key < root.data)
            root.left = delete(root.left, key);
        else if (key > root.data)
            root.right = delete(root.right, key);
        else
        {
            if (root.left == null)
                return root.right;
            else if (root.right == null)
                return root.left;

            root.data = small(root.right);
            root.right = delete(root.right, root.data);
        }

        return root;
    }

    int small(Node root)
    {
        int min = root.data;
        while (root.left != null)
        {
            min = root.left.data;
            root = root.left;
        }
        return min;
    }

}

class Tree {
  public static void main(String[] args) {
    BinaryTree s = new BinaryTree();
    s.add(50);
    s.add(60);
    s.add(70);
    s.add(80);
    s.display();
    s.del(60);
    s.display();

  }
}
