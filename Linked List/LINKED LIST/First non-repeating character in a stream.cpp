First non-repeating character in a stream:-
====================================
Given an input stream of A of n characters consisting only of lower case alphabets. The task is to find the first non repeating character, each time a character is inserted to the stream. If there is no such character then append '#' to the answer.
 
Example 1:

Input: A = "aabc"
Output: "a#bb"
Explanation: For every character first non
repeating character is as follow-
"a" - first non-repeating character is 'a'
"aa" - no non-repeating character so '#'
"aab" - first non-repeating character is 'b'
"aabc" - first non-repeating character is 'b'
================================================================================
simple approach:- O(1) time complexity
=====================================
class Solution {
	public:
	
	
	struct node {   // this is for creating that node of dll
                    char a;                       // vvvvvimp
                    struct node *next, *prev;
                  };

	

            void appendNode(struct node** head_ref, struct node** tail_ref, char x)
                   {
    struct node* temp = new node;
    temp->a = x;
    temp->prev = temp->next = NULL;
 
    if (*head_ref == NULL) {
        *head_ref = *tail_ref = temp;
        return;
    }
    (*tail_ref)->next = temp;
    temp->prev = *tail_ref;
    *tail_ref = temp;
      }
	
	
   void removeNode(struct node** head_ref,struct node** tail_ref, struct node* temp)
    {
    if (*head_ref == NULL)
        return;
 
    if (*head_ref == temp)
        *head_ref = (*head_ref)->next;
    if (*tail_ref == temp)
        *tail_ref = (*tail_ref)->prev;
    if (temp->next != NULL)
        temp->next->prev = temp->prev;
    if (temp->prev != NULL)
        temp->prev->next = temp->next;
 
    delete (temp);
    }
	
string FirstNonRepeating(string stream)
     {
         
         string s="";
    
        struct node* inDLL[26]; // to store addresses of node ...to check atleast once occured
 
          bool repeated[26];       // to store true or false ....to check two or more times occured..
 
           struct node *head = NULL, *tail = NULL;   // to form doubly link list
    
     for (int i = 0; i < 26; i++) {
        inDLL[i] = NULL;
        repeated[i] = false;                  // initialise all with NULL and false
    }
 
    
    
    for (int i = 0; stream[i]; i++) {         // check and do the things
         
         char b = stream[i];
         int x = b - 'a';                 // this step is important
           
           if (!repeated[x]) {   // if two times not occured
            
            if (inDLL[x] == NULL) {     // if not atlest one time occured
                appendNode(&head, &tail, stream[i]);
                inDLL[x] = tail;
            }
            else                                // if occured more than one times
            {
                removeNode(&head, &tail, inDLL[x]);     //remove node 
                inDLL[x] = NULL;                            // retrieve the address
                repeated[x] = true;              // again make as true
            } 
        }
 
        
            if (head != NULL)                 // if head != NULL 
            s += head->a;                 // then append the head node which is the leftmost non-repeating
            else
            s += '#';                    // if not like that then just append #
}

return s;
	
     }	
};