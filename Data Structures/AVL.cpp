#include <bits/stdc++.h>
using namespace std;
#define ll long long

/*
 * AVL Tree node structure: 
 * data, left child, right child,height of node(leaf at height 1)
 * total nodes counts total nodes in subtree including itself.
 */ 
typedef struct AVLnode
{
    ll data;
    AVLnode *left;
    AVLnode *right;
    ll height;
    ll total_node;
} node;

node *root = NULL;

/*
 *creation of node by memory allocation and initial values
 */
node *create_node(ll data)
{
    node *n = (node *)malloc(sizeof(node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    n->height = 1;
    n->total_node = 1;
    return n;
}

/*
 * returns height of given node if node exist
 * else give zero as height.
 */ 
ll getHeight(node *n)
{
    if (n == NULL)
        return 0;
    else
        return n->height;
}

/*
 * computes height of given node from heights of it's childs.
 */
ll computeTotalHeight(node *n)
{
    return max(getHeight(n->left), getHeight(n->right)) + 1;
}

/*
 * give stored total node in node if node exist.
 * else gives zero.
 */
ll getTotalnode(node *n)
{
    if (n == NULL)
        return 0;
    else
        return n->total_node;
}

/*
 *computes how many nodes are there under given node.
 */ 
ll computeTotalNode(node *n)
{
    return getTotalnode(n->left) + getTotalnode(n->right) + 1;
}
/*
 * computes balance factor from heights of left and right subtrees
 */
ll computeBalFact(node *n)
{
    ll l_h = getHeight(n->left);
    ll r_h = getHeight(n->right);
    return (l_h - r_h);
}

/*
 * Left Rotate : 
 * performs link changes in given node and it's right child
 * updates height and total nodes for modified nodes.
 */ 
node *Lrotate(node *n)
{
    node *store_rc = n->right;
    node *store_lcor = store_rc->left;
    store_rc->left = n;
    n->right = store_lcor;
    n->height = computeTotalHeight(n);
    n->total_node = computeTotalNode(n);
    store_rc->height = computeTotalHeight(store_rc);
    store_rc->total_node = computeTotalNode(store_rc);
    return store_rc;
}

/*
 * Right Rotate : 
 * performs link changes in given node and it's left child
 * updates height and total nodes for modified nodes.
 */
node *Rrotate(node *n)
{
    node *store_lc = n->left;
    node *store_rcol = store_lc->right;
    store_lc->right = n;
    n->left = store_rcol;
    n->height = computeTotalHeight(n);
    n->total_node = computeTotalNode(n);
    store_lc->height = computeTotalHeight(store_lc);
    store_lc->total_node = computeTotalNode(store_lc);
    return store_lc;
}

/*
 * Performs balancing on given node by deciding which 
 * rotation is needed. decision is taken by parent and 
 * childs balance factors : e.g.
 * -2 -1 : Left Rotation 
 * -2  1 : Right Rotate left child then Left rotate on given node
 *  2  1 : Right Rotation
 *  2 -1 : Left Rotate Right child then Right Rotate on given node
 */ 
node *do_balancing(node *n, ll balanceFact)
{
    if (balanceFact == -2)
    {
        ll balanceFactc = computeBalFact(n->right);
        if (balanceFactc == -1)
            return Lrotate(n);                  //LL
        else if (balanceFactc == 1)
        {                                       //RL
            n->right = Rrotate(n->right);
            return Lrotate(n);
        }
    }
    else if (balanceFact == 2)
    {
        ll balanceFactc = computeBalFact(n->left);
        if (balanceFactc == -1)
        {                                       //LR
            n->left = Lrotate(n->left);
            return Rrotate(n);
        }
        else if (balanceFactc == 1)
            return Rrotate(n);                  //RR
    }
    return n;
}

/*
 * Insert data d to tree rooted at r.
 */ 
node *insert(node *r, ll d)
{
    if (r == NULL)
        return create_node(d);  //new node creation at leaf level
    if (d == r->data)
        return r;               //if node already exist
    if (d > r->data)
        r->right = insert(r->right, d); //traversing to right place
    else
        r->left = insert(r->left, d);   //traversing to right place

    r->height = computeTotalHeight(r);      //correcting height of node
    r->total_node = computeTotalNode(r);    //comuting total node of given node
    ll balanceFact = computeBalFact(r);     //finding balance factor
    //if balance factor is not proper then do balancing.
    if (balanceFact > 1 || balanceFact < -1) 
        r = do_balancing(r, balanceFact);
    return r;
}

/**
 * Delete node with key d from AVL tree rooted at root r
 */ 
node *deleteNode(node *r, ll d)
{
    if (r == NULL)
        return r;   //if node is not found then return null.   
    if (d > r->data)
        r->right = deleteNode(r->right, d); //traversing is AVL tree
    else if (d < r->data)
        r->left = deleteNode(r->left, d);   //traversing in AVL tree
    else if (d == r->data)                  //node found with data d.
    {
        //if node has no child then simply make it NULL and free the space.
        if (r->left == NULL && r->right == NULL)
        {
            node *tmp = r;
            r = NULL;
            free(tmp);
        }
        else if (r->left == NULL || r->right == NULL)
        {
            /*
             * if it has one child then copy all data of child to parent and 
             * then free the child node.
             */
            node *child;
            if (r->left != NULL)
                child = r->left;
            else
                child = r->right;

            r->data = child->data;
            r->left = child->left;
            r->right = child->right;
            r->height = child->height;
            r->total_node = child->total_node;

            free(child);
        }
        else
        {
            /*
             * if node has both child then find inOrder SUC 
             * and copy data of inorder successor to given node
             * and then delete that successor node. 
             */
            node *ino_suc = r->right;
            while (ino_suc->left != NULL)
                ino_suc = ino_suc->left;
            r->data = ino_suc->data;
            r->right = deleteNode(r->right, ino_suc->data);
        }
    }
    // if tree becomes null then return r here only.(only one node case)
    if (r == NULL)
        return r;

    /*
     * do balancing and data updation after delete 
     * operation id necessary
     */
    r->height = computeTotalHeight(r);
    r->total_node = computeTotalNode(r);
    ll balanceFact = computeBalFact(r);
    if (balanceFact > 1 || balanceFact < -1)
        r= do_balancing(r, balanceFact);
    return r;
}

/*
 * Simple recursive search of node in AVL tree
 */
bool search_node(node *root, ll d)
{
    if (root == NULL)
        return false;
    else if (root->data == d)
        return true;
    else if (root->data < d)
        return search_node(root->right, d);
    else
        return search_node(root->left, d);
    return false;
}

/*
 * find kth minimum by checking total nodes in left 
 * and right subtree and find kth element accordingly.
 */
ll kth_minimum(node *r, ll y)
{
    int r_pos = r->total_node - getTotalnode(r->right);
    if (y == r_pos)
        return r->data;
    else if (y < r_pos)
        return kth_minimum(r->left, y);
    else
        return kth_minimum(r->right, y - r_pos);
}

void print_kth_min(node *r, ll y)
{
    ll kth_elem = kth_minimum(r, y);
    cout << kth_elem << endl;
    r = deleteNode(r, kth_elem);
}

int main()
{
    ios_base::sync_with_stdio(false);
    ll n, m;
    cin >> n >> m;
    vector<ll> d(n);
    ll tmp_data;
    for (ll i = 0; i < n; i++)
    {
        cin >> tmp_data;
        root = insert(root, tmp_data);
    }
    while (m--)
    {
        ll x, y;
        cin >> x >> y;
        switch (x)
        {
        case 1:
            root = insert(root, y);
            break;
        case 2:
            search_node(root, y) ? cout << "1" << endl : cout << "0" << endl;
            break;
        case 3:
            print_kth_min(root, y);
            break;
        }
    }
    return 1;
}
