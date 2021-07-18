Remove loop in Linked List :-
----------------------------------
Given a linked list of N nodes such that it may contain a loop.

A loop here means that the last node of the link list is connected to the node at position X. If the link list does not have any loop, X=0.

Remove the loop from the linked list, if it is present.  

Input:
N = 3
value[] = {1,3,4}
X = 2
Output: 1
Explanation: The link list looks like
1 -> 3 -> 4
     ^    |
     |____|    
A loop is present. If you remove it 
successfully, the answer will be 1. 

------------------------------------------------------------------

 void removeLoop(Node* head)
    {
        Node *sp = head;
        Node *fp = head;
        
        while(sp and fp  and fp->next ){
            sp=sp->next;
            fp=fp->next->next;
            
            if(sp == fp)
            break;
        }
                                                             --------------------> upto this detecting loop part..from here sp and fp pts to looping position
      

     if(sp == head) {                             --------------------> if looping position is head position...then traverse till sp->next != head 
        while(sp->next != head) {                                           and find the last node and put null after that.
            sp = sp->next;
        }
        
        sp->next = NULL;
        }
        
        
         if(sp == fp){                                 ---------------> if sp is not a head position then this will happen..(note.if sp = head then                                                     definitely after traversal in the above loop sp value changed then it would not be fp (sp != fp)
            sp = head;
            while(sp->next != fp->next) {                  -----> Floyd algorithm note (we are comparing with nexts only)
                sp = sp->next;
                fp = fp->next;
            }
            
            fp->next = NULL;                                   ----> dont forget
        }
               
    }
    };