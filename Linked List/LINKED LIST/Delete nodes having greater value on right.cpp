Delete nodes having greater value on right:-
------------------------------------------------------
Given a singly linked list, remove all the nodes which have a greater value on its following nodes.
------------------------------
app 1) Brute force

pick every element and  check if there is greater elemnt in the right by make use of two loops.

==========================
App 2:- simple & efficient:-

i) reverse the given list
ii) then traverse the list and make some changes.. 
max variable..check if next node is greter then update max else change link simplyyy
------------------------------------------------------------------------------------------------------
class Solution
{
    public:
    Node *reverse(Node* head){
        Node *curr = head;
         Node *prev = NULL;
          Node *next = NULL;
          
          while(curr){
              next = curr->next;
              curr->next = prev;
              prev = curr;
              curr = next;
          }
          
          head = prev;
          return head;
    }
    Node *compute(Node *head)
    {
       if(head == NULL or head->next==NULL)
       return head;
       
       head = reverse(head);
       Node *temp = head;
       int max = temp->data;            initialise max with first node data
       
       while(temp->next){
           if(temp->next->data >= max){
               max = temp->next->data;
               temp = temp->next;
           }
           
           else 
           temp->next = temp->next->next;
       }
       
       head = reverse(head);        // dont forget to reverse vvvvvvvvvvvimpppppppp
       return head;
    }
    
};
   
