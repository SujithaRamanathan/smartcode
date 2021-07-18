Reverse a linked list 
------------------------

Given a linked list of N nodes. The task is to reverse this list.
===================================================================================

Iterative solution :-
------------------------
Initialize three pointers prev as NULL, curr as head and next as NULL.
Iterate through the linked list. In loop, do following. 
// Before changing next of current, 
// store next node 
next = curr->next
// Now change next of current 
// This is where actual reversing happens 
curr->next = prev 
// Move prev and curr one step forward 
prev = curr 
curr = next

finally,make change to head.
============================================
struct Node* reverseList(struct Node *head)
    {
        struct Node *prev = NULL;
        struct Node *curr = head;
        struct Node *next = NULL;
        
        while(curr != NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        head = prev;
        
        return head;
    }

-----------------------------------------------------------------------
Recursive:-
