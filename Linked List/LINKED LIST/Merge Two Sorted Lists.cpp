 Merge Two Sorted Lists:-
=======================
Merge two sorted linked lists and return it as a sorted list. The list should be made by splicing together the nodes of the first two lists.

----------------------------------------------------------------------------------------


class Solution {
public:
    ListNode* mergeTwoLists(ListNode* a, ListNode* b) {
        
       
    ListNode* result = NULL;
 
    /* Base cases */
    if (a == NULL)
        return (b);
    else if (b == NULL)
        return (a);
 
    /* Pick either a or b, and recur */
    if (a->val <= b->val) {
        result = a;
        result->next = mergeTwoLists(a->next, b);
    }
    else {
        result = b;
        result->next = mergeTwoLists(a, b->next);
    }
 
    return result;
}
        