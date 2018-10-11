#pragma once
#include <string>
using namespace std;

template< class t>
class node
{
	public:
		t value;
		string color;
		node<t>*left;
		node<t>*right;
		node<t>* parent;
		node();
		node(t);
		~node();
};

template<class t>
class Red_Black_Tree
{
	node<t>* root;
	public:
		Red_Black_Tree();
		void check(node<t>*);
		void insert(t);
		void right_rotation(node<t>*,bool);
		void left_rotation (node<t>*,bool);
		node<t>* findmin(node<t>*);
		void del(t);
		void solve_double_black(node<t>*,node<t>*,node<t>*);
		node<t>* find(t);
		~Red_Black_Tree();

};

