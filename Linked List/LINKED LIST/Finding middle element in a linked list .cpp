Finding middle element in a linked list 
---------------------------------------------
Given a singly linked list of N nodes. The task is to find the middle of the linked list. For example, if given linked list is 1->2->3->4->5 then the output should be 3.
If there are even nodes, then there would be two middle nodes, we need to print the second middle element. For example, if given linked list is 1->2->3->4->5->6 then the output should be 4.

Example 1:

Input:
LinkedList: 1->2->3->4->5
Output: 3 
Explanation: 
Middle of linked list is 3.
Example 2: 

Input:
LinkedList: 2->4->6->7->5->1
Output: 7 
Explanation: 
Middle of linked list is 7.
===================================================================

 so here. its very vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvEASYEASY.....:)   :)
---------------------------------------

Using two ptr approach:-
============================

int getMiddle(Node *head)
{
   Node *fp = head;
   Node *sp = head;
   
   while(fp != NULL and fp->next != NULL){        when fp reaches null ,then sp will be at middle position 
       sp = sp->next;
       fp = fp->next->next;
       
   }
   
   return sp->data;                        vvv imp data va return panrom
}