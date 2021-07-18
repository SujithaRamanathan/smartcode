Nth node from end of linked list 
============================
Given a linked list consisting of L nodes and given a number N. The task is to find the Nth node from the end of the linked list.

Example 1:

Input:
N = 2
LinkedList: 1->2->3->4->5->6->7->8->9
Output: 8
N = 5
LinkedList: 10->5->100->5                      // this is the special case that n = 5..but the length of list itself is 4 
Output: -1
================================
3 methods
i) printing len - n + 1 node's data
ii) double ptr approach
iii) recursion
------------------------------------------
Approach 2:- Efficient:-
steps
======

create a dummy node and make dummy->next point to head
also create fp,sp pointing to that dummy node.
then move fp till n from beginning (see i = 1 when start)
after reaching n ,then move both sp and fp simultaneouslt till fp reahes last node(while (fp->next != NULL)
on breaking of while loop,sp will point to the node just after that the nth node from last present.
so,return sp->next->data.
----------------------------------------------------
int getNthFromLast(Node *head, int n)
{
       Node *dummy = new Node(0);
       dummy->next = head;
        Node *fp = dummy; 
         Node *sp = dummy;
         
         Node *temp = head;
   int len =0;
    while (temp != NULL) {
        temp = temp->next;
        len++;
    }
    
    if(n>len)
    return -1;
    
    for(int i=1;i<=n;i++)
    fp= fp->next;
    
    while(fp->next != NULL){
        sp = sp->next;
        fp = fp->next;
    }
    
    return sp->next->data;            // in case of deleting make sp->next = sp->next->next
    
}
================================================
recursion:-

void printNthFromLast(struct Node* head, int n)
{
    static int i = 0;
    if (head == NULL)        go upto dead end null
        return;
    printNthFromLast(head->next, n);
    if (++i == n)           then on returninf make a count and check whether its that nth node if yes  just print its data
        printf("%d", head->data);
}

==================================================