Rotate doubly Linked List
-----------------------------------
Given a doubly linked list, rotate the linked list counter-clockwise by P nodes. Here P is a given positive integer and is smaller than the count of nodes(N) in a linked list.
Input:
1
6 2
1 2 3 4 5 6

Output:
3 4 5 6 1 2
============================================
Approch:-
i) split the list at kth node
 make first half next as null
 make first of seconf haf a newhead and set prev of that NULL

ii) then traverse the list from that newhead to find the last node for attaching the first half

iii) attach first half
 lastnode->next = head (since head is pting to first node of first half)
head->prv = temp;
---------------------------------------

struct node*update(struct node*start,int p)
{
    if(start == NULL or start->next == NULL)                  // corner cases are really important
    return start;
    
    struct node *temp = start;
    int n = 0;
    while(temp != NULL) {       // get the count
        n++;
        temp = temp->next;
    }    
   
    
    p = p%n;   // to avoid issues if k>n
    if(p==0)                       vvvvimp
    return start;
    
    struct node *node = start;
    while(node != NULL and p>1) {                    p > 1 then only we can at that kth node vvvvvvvvvvvvimp
    node = node->next;                 // dont forget to p--
    p--;
    }
    
    struct node *newhead;                // remaining here all the same stuff explained above
    newhead = node->next;
    newhead->prev = NULL;
    
    node->next = NULL;
    
    temp = newhead;
    while(temp->next != NULL){
        temp = temp->next;
    }
    
    temp->next = start;
    start->prev = temp;
    
    
    return newhead;
    
  }