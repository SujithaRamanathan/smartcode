
Intersection Point in Y Shapped Linked Lists 
========================================
Given two singly linked lists of size N and M, write a program to get the point where two linked lists intersect each other.

 Example 1:
----------------
Input:
LinkList1 = 3->6->9->common
LinkList2 = 10->common
common = 15->30->NULL
Output: 15
Explanation:
Y ShapedLinked List
---------------------------------------------------------
NAIVE APPROACHES:-
--------------------------------i) pick a element in longer ll and traverse the shorter list and find if any reference equal to the reference of the picked element.
O(M X N) 

ii)hashing
--------------
here,we have to hash the addresses of longer list
traverse the shorter list
while traversing,
   check whether its already in map
	if yes,retrun that address;
	else
	return NULL.

--------------------------------------

iii) Efficient one(but lengthier code)
take count of each ll.
find the difference(lets the difference be K)
firstly in longer one move k positions ahead.
after that traverse both the lists simultaneously.
definitely ,at some point they would collide(even if no intersection, they atleast points to null ultimately)

---------------------------------------------------------------------------
iv) above approach is simplified:-
=============================

make two ptrs p1 and p2 (pointing list1 and list2 respectively) traverse simultaneously.
we know that p1 reaches null first (if its pointing to shorter list),then we make p1 pointing to head of 2nd list.(vvvimp 2nd one)
if p2 reaches null make that point to head1.

once both are changed, simultaneously, traverse two lists.at some point they collide at the required answer.
-----------------------------------------------------------------------------

intuition:- we have covered the difference while p2 reaches null
-------------------------------------------------------------------------------

int intersectPoint(Node* head1, Node* head2)
{
    Node *d1 = head1;
    Node *d2 = head2;
    
    while(d1 != d2) {
        d1 = (d1==NULL) ? head2 : d1->next;        d1 --------  make pting to head2222222
        d2 = (d2==NULL) ? head1  : d2->next;        d2-----------        head1111111111111111                             
    }
    
    return d1->data;
}