Intersection of two sorted Linked lists 
---------------------------------------------------
Given two lists sorted in increasing order, create a new list representing the intersection of the two lists. The new list should be made with its own memory — the original lists should not be changed.

Example 1:

Input:
L1 = 1->2->3->4->6
L2 = 2->4->6->8
Output: 2 4 6
Explanation: For the given first two
linked list, 2, 4 and 6 are the elements
in the intersection.

===============================================================

AS simple as that :)
---------------------------

Again two ptrs:-
-----------------------
p1 for list1
p2 for list2

if p1 dta == p2dta
then simply create a new node contains that common data and if its the first one make a head pts to that node or else simple connect..

if p1dat < p2dta
since its a sorted list move only p1

else
move only p2
==============================================

be careful in creating a node,creating head, prev for traversing and connecting nodes,
---------------------------------------------------------------------------------------------------

Node* findIntersection(Node* head1, Node* head2)
{
    Node *p1 = head1;
    Node *p2 = head2;
    Node *head = NULL;
    Node *prev;
    
    while(p1 and p2){
        if(p1->data == p2->data){
            if(head == NULL){
                Node *temp = new Node(p1->data);
                head = temp;
                prev = temp;
                
            }
            else {
                 Node *temp = new Node(p1->data);
                prev->next = temp;
                prev = prev->next;
                
            }
            
            p1 = p1->next;
            p2 = p2->next;
        }
        
        else {
            if(p1->data < p2->data)
            p1 = p1->next;
            
            else
            p2 = p2->next;
        }
        
        }
        
        return head;
}