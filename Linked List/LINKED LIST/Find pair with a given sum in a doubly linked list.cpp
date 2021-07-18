Find pair with a given sum in a doubly linked list
---------------------------------------------------------------
You are given a sorted doubly linked list of size N, consisting of positive integers and also provided a number K. Your task is to find out whether there exists a pair in the doubly linked list with sum K or not. If there exists a pair then you can return TRUE else return FALSE.
=======================================

simple two ptr approach thats it
----------------------------------------------



bool findPair(Node* head, int k)
{
    if(head == NULL or head->next == NULL)
        return false;
   Node *first = head;
    Node *second = head;
    bool found = false;
    while(second->next != NULL)
        second = second->next;
    
    while(first != second and second->next != first){   termination condition vvvvvvvvvimp whnt they meet or first crossed second
        
        
        if((first->data + second->data) == k)  {
            found = true;
            break; }
        else {
            if((first->data + second->data) < k)
                first = first->next;
        	else
                second = second->prev;
        }
    }
    
    return found;
        
        
        
       }
