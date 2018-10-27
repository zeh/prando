/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/**
 * headA - Linked List A
 * headB - Linked List B
 *
 * return - NULL if no interection, else intersection ListNode 
 * */
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    
    unordered_set<ListNode*>set;

    ListNode* ptr = headA;

    // Insert all the ListNode in the set
    while(ptr) {
       	set.insert(ptr);
    	ptr = ptr->next;
    }

    ptr = headB;
    while(ptr) {
    	// if any ListNode in headB is in set, then it is in headA linkedList
    	// intersectin found
        if(set.find(ptr) != set.end()) {
        	return ptr;
        }
    	ptr = ptr->next;
    }
    return NULL;
}