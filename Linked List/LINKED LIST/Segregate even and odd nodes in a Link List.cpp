Segregate even and odd nodes in a Link List :-
-----------------------------------------------------------
Given a link list of size N, modify the list such that all the even numbers appear before all the odd numbers in the modified list. The order of appearance of numbers within each segregation should be same as that in the original list.
Example 1:
Input: 
N = 7
Link List = 
17 -> 15 -> 8 -> 9 -> 2 -> 4 -> 6 -> NULL

Output: 8 2 4 6 17 15 9
============================================

App 1:-
------
Algorithm: 
…1) Get pointer to the last node. 
…2) Move all the odd nodes to the end. 
……..a) Consider all odd nodes before the first even node and move them to end. 
……..b) Change the head pointer to point to the first even node. 
……..b) Consider all odd nodes after the first even node and move them to the end. 
 
void segregateEvenOdd(Node **head_ref)
{
    Node *end = *head_ref;
    Node *prev = NULL;
    Node *curr = *head_ref;
 
    /* Get pointer to the last node */
    while (end->next != NULL)
        end = end->next;
 
    Node *new_end = end;
 
    /* Consider all odd nodes before the first
     even node and move then after end */
    while (curr->data % 2 != 0 && curr != end)
    {
        new_end->next = curr;
        curr = curr->next;
        new_end->next->next = NULL;
        new_end = new_end->next;
    }
 
    // 10->8->17->17->15
    /* Do following steps only if
    there is any even node */
    if (curr->data%2 == 0)
    {
        /* Change the head pointer to
        point to first even node */
        *head_ref = curr;
 
        /* now current points to
        the first even node */
        while (curr != end)
        {
            if ( (curr->data) % 2 == 0 )
            {
                prev = curr;
                curr = curr->next;
            }
            else
            {
                /* break the link between
                prev and current */
                prev->next = curr->next;
 
                /* Make next of curr as NULL */
                curr->next = NULL;
 
                /* Move curr to end */
                new_end->next = curr;
 
                /* make curr as new end of list */
                new_end = curr;
 
                /* Update current pointer to
                next of the moved node */
                curr = prev->next;
            }
        }
    }
 
    /* We must have prev set before executing
    lines following this statement */
    else prev = curr;
 
    /* If there are more than 1 odd nodes
    and end of original list is odd then
    move this node to end to maintain
    same order of odd numbers in modified list */
    if (new_end != end && (end->data) % 2 != 0)
    {
        prev->next = end->next;
        end->next = NULL;
        new_end->next = end;
    }
    return;
}
================================================================
Efficient approach:-
Method 2 
The idea is to split the linked list into two: one containing all even nodes and other containing all odd nodes. And finally, attach the odd node linked list after the even node linked list. 
To split the Linked List, traverse the original Linked List and move all odd nodes to a separate Linked List of all odd nodes. At the end of loop, the original list will have all the even nodes and the odd node list will have all the odd nodes. To keep the ordering of all nodes same, we must insert all the odd nodes at the end of the odd node list. And to do that in constant time, we must keep track of last pointer in the odd node list.



class Solution{
public:
    Node* divide(int N, Node *head){
        if(head==NULL or head->next==NULL)
        return head;
        
        Node *oddhead = NULL;
        Node *evenhead = NULL;
        Node *lastseenodd = NULL;
        Node *lastseeneven = NULL;
        
        Node *curr = head;
        while(curr != NULL){
            int val = curr->data;
            if(val%2 == 0)            // when even
            {
                if(evenhead == NULL) {
                    evenhead = curr;
                    lastseeneven = curr;
                    }
                    
                else {
                    lastseeneven->next = curr;
                    lastseeneven = lastseeneven->next;
                }
                
            }
            
            else {
                if(oddhead == NULL) {
                    oddhead = curr;
                    lastseenodd = curr;
                    }
                    
                else {
                    lastseenodd->next = curr;
                    lastseenodd = lastseenodd->next;
                }
                
            }
            
            curr=curr->next;
        }
        
        if(oddhead == NULL or evenhead == NULL)                     ///VVVVVVVVVVIMP if given list fully odd / even then just return                                                                                                                              head
        return head;
        
        if(evenhead != NULL)                        // and in all these previous checks are important
        head = evenhead;
        
        if(oddhead != NULL)
        lastseeneven->next = oddhead;
        
        if(lastseenodd != NULL)
        lastseenodd->next = NULL;
        
        return head;
    }
};