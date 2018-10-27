#include "Red_Black_Tree.h"
template <class t>
node<t>::node()
{
	left = right = parent = 0;
	value = 0;
	color = "red";
}
template<class t>
node<t>::node(t v)
{
	value = v;
	left = right = parent = 0;
	color = "red";
}
template<class t>
node<t>::~node()
{
	
}

template<class t>
Red_Black_Tree<t>::Red_Black_Tree()
{
	root = 0;
}


template <class t>
void Red_Black_Tree<t>::insert(t v)
{
	node<t>* neww = new node<t>(v);
	if (root == 0)
	{
		neww->color = "black";
		root = neww;
	}
	else
	{
		node<t>*temp = root;
		while(temp!=0)
		{
			if(v>temp->value)
			{
				if (temp->right == 0) { neww->parent = temp; temp->right = neww; break; }
				else temp = temp->right;
			}
			else
			{
				if (temp->left == 0) { neww->parent = temp;  temp->left = neww; break; }
				else temp = temp->left;
			}
		}
		check(neww);
	}
}

template<class t>
void Red_Black_Tree<t>::right_rotation(node<t>*nodee,bool change)
{
	node<t>* p = nodee->parent;
	node<t>* grandp = nodee->parent->parent;
	node<t>* rightt = nodee->right;
	nodee->parent = grandp;
	if (grandp != 0)
	{
		if (grandp->right == p)grandp->right = nodee;
		else grandp->left = nodee;
	}
	else root = nodee;
	nodee->right = p;
	p->parent = nodee;
	p->left = rightt;
	if (rightt != 0)rightt->parent = p;
	if (change)
	{
		cout << "Changing color nodee = " << nodee->value << " p = " << p->value << endl;
		nodee->color = "black";
		p->color = "red";
	}
}

template<class t>
void Red_Black_Tree<t>::left_rotation(node<t>*nodee,bool change)
{
	node<t>* p = nodee->parent;
	node<t>* grandp = nodee->parent->parent;
	node<t>* leftt = nodee->left;
	nodee->parent = grandp;
	if (grandp != 0)
	{
		if (grandp->right == p)grandp->right = nodee;
		else grandp->left = nodee;
	}
	else root = nodee;
	nodee->left = p;
	p->parent = nodee;
	p->right = leftt;
	if (leftt != 0)leftt->parent = p;
	if (change)
	{
		cout << "Changing color nodee = " << nodee->value << " p = " << p->value << endl;
		nodee->color = "black";
		p->color = "red";
	}
}

template<class t>
void Red_Black_Tree<t>::solve_double_black(node<t>*nodee,node<t>*p,node<t>*sib)
{
	while (1)
	{
		if (p==0)
		{
			cout << " case 1 " << endl;
			if (nodee == 0)root = 0;
			else nodee->color = "black";
			return;
		}
		if(p->color=="black"&&sib!=0&&sib->color=="red"&&(sib->left==0||sib->left->color=="black")&&(sib->right==0||sib->right->color=="black"))
		{
			cout << " case 2 " << endl;
			//case 2
			sib->color = "black";
			p->color = "red";
			cout << " old p = " << p->value << " old  p left = " << p->left->value << endl;
			if (p->right == sib)left_rotation(sib, 0);
			else right_rotation(sib, 0);
			if (p->left == nodee)sib = p->right;
			else sib = p->left;
			cout << " p = " << p->value << " p left = " << p->left->value << " sib = "<<sib->value<<endl;
		}
		if (p->color == "black"&&sib!=0&&sib->color == "black" && (sib->left == 0 || sib->left->color == "black") && (sib->right == 0 || sib->right->color == "black"))
		{
			cout << " case 3 " << endl;
			// case 3
			sib->color = "red";
			nodee = nodee->parent;
			p = nodee->parent;
			if (p != 0)
			{
				if (p->right == nodee)sib = p->left;
				else sib = p->right;
			}
			continue;
		}
		if (p->color == "red"&&sib!=0&&sib->color == "black" && (sib->left == 0 || sib->left->color == "black") && (sib->right == 0 || sib->right->color == "black"))
		{
			cout << " case 4 " << endl;
			//case 4
			sib->color = "red";
			p->color = "black";
			return;
		}
		if (p->color == "black"&&sib!=0&&sib->color == "black"&&sib->left != 0 && sib->left->color == "red" && (sib->right == 0 || sib->right->color == "black"))
		{
			cout << " case 5 " << endl;
			//case 5
			sib->color = "red";
			sib->left->color = "black";
			if (p->right == sib)right_rotation(sib, 0);
			else left_rotation(sib, 0);
			sib = sib->parent;
		}
		if (sib->color=="black"&&sib!=0&&sib->right!=0&&sib->right->color=="red")
		{
			cout << " case  6" << endl;
			//case 6
			sib->color = p->color;
			sib->right->color = "black";
			p->color = "black";
			if(p->right==sib)left_rotation(sib, 0);
			else right_rotation(sib, 0);
			return;
		}

	}
}


template<class t>
node<t>* Red_Black_Tree<t>::findmin(node<t>* nodee)
{
	node<t>* temp = nodee;
	while (temp->left != 0)
	{
		temp = temp->left;
	}
	return temp;
}


template<class t>
void Red_Black_Tree<t>::del(t v)
{
	node<t>*nodee = find(v);
	if (nodee->left != 0 && nodee->right == 0)
	{
		cout << "1" << endl;
		if (nodee->color == "red")
		{
			nodee->left->parent = nodee->parent;
			if (nodee->value > nodee->parent->value)nodee->parent->right = nodee->left;
			else nodee->parent->left = nodee->left;
		}
		else
		{
			if (nodee->left->color == "red")
			{
				nodee->left->color = "black";
				nodee->left->parent = nodee->parent;
				if (nodee->value > nodee->parent->value)nodee->parent->right = nodee->left;
				else nodee->parent->left = nodee->left;
			}
			else
			{
				node<t>*sib;
				nodee->left->parent = nodee->parent;
				if (nodee->parent != 0)
				{
					if (nodee->value > nodee->parent->value)
					{
						nodee->parent->right = nodee->left;
						sib = nodee->parent->left;
					}
					else
					{
						nodee->parent->left = nodee->left, sib = nodee->parent->right;
					}
				}
				node<t>*leftt = nodee->left;
				delete nodee;
				solve_double_black(leftt,leftt->parent,sib);
			}
		}
		delete nodee;
	}
	else if (nodee->left == 0 && nodee->right != 0)
	{
		cout << "2" << endl;
		if (nodee->color == "red")
		{
			nodee->right->parent = nodee->parent;
			if (nodee->value > nodee->parent->value)nodee->parent->right = nodee->right;
			else nodee->parent->left = nodee->right;
		}
		else
		{
			if (nodee->right->color == "red")
			{
				nodee->right->color = "black";
				nodee->right->parent = nodee->parent;
				if (nodee->value > nodee->parent->value)nodee->parent->right = nodee->right;
				else nodee->parent->left = nodee->right;
			}
			else
			{
				node<t>* sib;
				nodee->right->parent = nodee->parent;
				if (nodee->parent != 0)
				{
					if (nodee->value > nodee->parent->value)
					{
						nodee->parent->right = nodee->right;
						sib = nodee->parent->left;
					}
					else
					{
						nodee->parent->left = nodee->right;
						sib = nodee->parent->right;
					}
				}
				node<t>*rightt = nodee->right;
				delete nodee;
				solve_double_black(rightt, rightt->parent,sib);
			}
		}
		delete nodee;
	}
	else if(nodee->left!=0&&nodee->right!=0)
	{
		cout << "3" << endl;
		node<t>* mn = findmin(nodee->right);
		t v = mn->value;
		del(mn->value);
		nodee->value = v;
	}
	else
	{
		cout << "4" << endl;
		node<t>*sib;
		if (nodee->parent->right == nodee)
		{
			sib = nodee->parent->left;
			nodee->parent->right = 0;
		}
		else
		{
			sib = nodee->parent->right;
			nodee->parent->left = 0;
		}
		solve_double_black(nodee->right,nodee->parent,sib);
		delete nodee;
	}
}


template<class t>
void Red_Black_Tree<t>::check(node<t>* nodee)
{
	cout << "checking " << nodee->value << endl;
	if (nodee->parent!=0&&nodee->parent->color == "black")return;
	else
	{
		node<t>*grandp = nodee->parent->parent;
		node<t>* sib;
		if (grandp->right == nodee->parent)sib = grandp->left;
		else sib = grandp -> right;
		if(sib!=0&&sib->color=="red")
		{
			cout << " no rotation " << endl;
			nodee->parent->color = "black";
			sib->color = "black";
			if (grandp == root)return;
			grandp->color = "red";
			check(grandp);
		}
		else
		{
			if (nodee->parent->left == nodee&&grandp->left == nodee->parent)cout<<"LL"<<endl,right_rotation(nodee, 1); 
			else if (nodee->parent->right == nodee&&grandp->left == nodee->parent)
			{
				cout << "RL" << endl;
				left_rotation(nodee, 0);
				right_rotation(nodee, 1);
			}
			else if (nodee->parent->right == nodee&&grandp->right == nodee->parent)cout<<"RR"<<endl,left_rotation(nodee, 1);
			else
			{
				cout << "LR" << endl;
				right_rotation(nodee, 0);
				left_rotation(nodee, 1);
			}
		}
	}
	return;
}

template<class t>
node<t>* Red_Black_Tree<t>::find(t v)
{
	node<t>*temp = root;
	while (temp != 0)
	{
		cout << " node value  = "<<temp->value<<" color = "<<temp->color << endl;
		if (v > temp->value)temp = temp->right;
		else if (v < temp->value)temp = temp->left;
		else return temp;
	}
	return 0;
}
template<class t>
Red_Black_Tree<t>::~Red_Black_Tree()
{

}
