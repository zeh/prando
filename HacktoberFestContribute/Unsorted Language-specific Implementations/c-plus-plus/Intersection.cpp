#include <string>
#include <vector>
#include <iostream>

class Node;

class LinkedList
{

public:
	static Node *head1, *head2;

public:
	class Node
	{

	public:
		int data = 0;
		Node *next;

		virtual ~Node()
		{
			delete next;
		}

		Node(int d);
	};

/* lists head1 and head2 */ // Commented out this line, it was open indicating code, while it should've been a comment
public:
	virtual int getNode();

	virtual int _getIntesectionNode(int d, Node *node1, Node *node2);

	virtual int getCount(Node *node);

	static void main(std::vector<std::wstring> &args);
};

Node *head1, *LinkedList::head2;

LinkedList::Node::Node(int d)
{
	data = d;
	next = nullptr;
}

int LinkedList::getNode()
{
	int c1 = getCount(head1);
	int c2 = getCount(head2);
	int d;

	if (c1 > c2)
	{
		d = c1 - c2;
		return _getIntesectionNode(d, head1, head2);
	}
	else
	{
		d = c2 - c1;
		return _getIntesectionNode(d, head2, head1);
	}
}

int LinkedList::_getIntesectionNode(int d, Node *node1, Node *node2)
{
	int i;
	Node *current1 = node1;
	Node *current2 = node2;
	for (i = 0; i < d; i++)
	{
		if (current1 == nullptr)
		{
			return -1;
		}
		current1 = current1->next;
	}
	while (current1 != nullptr && current2 != nullptr)
	{
		if (current1->data == current2->data)
		{
			return current1->data;
		}
		current1 = current1->next;
		current2 = current2->next;
	}

	return -1;
}

int LinkedList::getCount(Node *node)
{
	Node *current = node;
	int count = 0;

	while (current != nullptr)
	{
		count++;
		current = current->next;
	}

	return count;
}

void LinkedList::main(std::vector<std::wstring> &args)
{
	LinkedList *list = new LinkedList();

	list->head1 = new Node(3);
	list->head1->next = new Node(6);
	list->head1->next->next = new Node(15);
	list->head1->next->next->next = new Node(15);
	list->head1->next->next->next->next = new Node(30);

	list->head2 = new Node(10);
	list->head2->next = new Node(15);
	list->head2->next->next = new Node(30);

	std::wcout << L"The node of intersection is " << list->getNode() << std::endl;

}
