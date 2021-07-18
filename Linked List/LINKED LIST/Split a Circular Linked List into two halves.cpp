Split a Circular Linked List into two halves
----------------------------------------------------
Given a Cirular Linked List of size N, split it into two halves circular lists. If there are odd number of nodes in the given circular linked list then out of the resulting two halved lists, first list should have one node more than the second list. The resultant lists should also be circular lists and not linear lists.
-------------------------------------------------------------------------------------

Eg:- 1 -> 2 -> 3 -> 4                       1 -> 2              |||ly for 3 and 4
        ^                     ^                       ^      ^
        |--------------|                        |---|

Approach:-
-------------------
1) Store the mid and last pointers of the circular linked list using tortoise and hare algorithm.
2) Make the second half circular.
3) Make the first half circular.
4) Set head (or start) pointers of the two linked lists.

===========================================================


void splitList(Node *head, Node **head1_ref, Node **head2_ref)
{
    
    
    Node *fp = head;
    Node *sp = head;
    
    if(head == NULL)
    return;
    
    while(fp->next != head and fp->next->next != head) {        if  fp->next->next == head (list contains even no of nodes) otherwise                                                                                                               odd
        sp = sp->next;
        fp = fp->next->next;
    }
    
    if(fp->next->next == head)                   // if even ,then last node would be fp->next so storing that..
    fp = fp->next;
    
    *head1_ref = head;          // setting 1st half head
    
    
    if(head->next != head)     // note this condition
    
    *head2_ref = sp->next;            // setting 2nd half head
    
    fp->next = sp->next; // second half circular                  
    
    sp->next = head; // first half circular                     
    
    
}