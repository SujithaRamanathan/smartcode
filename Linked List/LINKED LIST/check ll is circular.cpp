check if ll is Circular
----------------------------

simpy,check head == NULL (empty ll) return true; coz thats also a circular ll.
else
traverse from next node if it reaches NULL ,then false
if it reaches head again,then true
============================================================ 

bool isCircular(Node *head)
{
    if(head == NULL)
    return true;
    struct Node *curr = head->next;   // imp
    
    while(curr != NULL and curr != head)
    curr = curr->next;
    
    return (curr==head);
}
