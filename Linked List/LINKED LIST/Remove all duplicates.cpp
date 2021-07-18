Remove all duplicates:-
============================
Input: head = [1,2,3,3,4,4,5]
Output: [1,2,5]
============================
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        
       ListNode  *dummy = new ListNode;
 
    // dummy node points
    // to the original head
    dummy -> next = head;
     
    // Node pointing to last
    // node which has no duplicate.
    ListNode *prev = dummy;
     
    // Node used to traverse
    // the linked list.
    ListNode  *current = head;
 
    while(current != NULL)
    {
        // Until the current and
        // previous values are
        // same, keep updating current
        while(current -> next != NULL &&
              prev -> next -> val == current -> next -> val)
            current = current -> next;
 
        // if current has unique value
        // i.e current is not updated,
        // Move the prev pointer to
        // next node
        if (prev -> next == current)
            prev = prev -> next;
 
        // when current is updated
        // to the last duplicate
        // value of that segment,
        // make prev the next of current
        else
            prev -> next = current -> next;
 
        current = current -> next;
    }
 
    // update original head to
    // the next of dummy node
    head = dummy -> next;
return head;
 
    }
};