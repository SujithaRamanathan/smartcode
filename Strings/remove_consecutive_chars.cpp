Remove Consecutive Characters
================================

Given a string S delete the characters which are appearing more than once consecutively.

			TWO KINDS OF PROBLEMS
				/    \
                               /      \

		
	Recursively remove all         remove consequent
	subsequent chars                chars

===================================================================

Example 1:

Input:
S = aabb
Output:  ab 
Explanation: 'a' at 2nd position is
appearing 2nd time consecutively.
Similiar explanation for b at
4th position.
============================================

a)RECURSIVE SOLUTION (JTK) (O(N2))

aabcca   S = aabcca
        /
       abcca     S = abcca        
       /
      bcca       S = abcca
      /
     cca         S = abcca
     /
    ca           S = abca
   /
  a              S = abca (Output String)
 /
empty string

Below is the implementation of the above approach: 
 
// Recursive Program to remove consecutive
// duplicates from string S.
#include <bits/stdc++.h>
using namespace std;
 
// A recursive function that removes
// consecutive duplicates from string S
void removeDuplicates(char* S)
{
    // When string is empty, return
    if (S[0] == '\0')
        return;
 
    // if the adjacent characters are same
    if (S[0] == S[1]) {
         
        // Shift character by one to left
        int i = 0;
        while (S[i] != '\0') {
            S[i] = S[i + 1];
            i++;
        }
 
        // Check on Updated String S
        removeDuplicates(S);
    }
 
    // If the adjacent characters are not same
    // Check from S+1 string address
    removeDuplicates(S + 1);
}

===============================================================================


b)ITERATIVE SOLUTION(O(N) BEST)
------------------------------------------
        int n = s.length();
        // don't forget to add base condition
        if(n<2)
        return s;
       
         int j =0;
        for(int i =1;i<n;i++){
            if(s[j] != s[i]) { // when different moving to left
                j++;
                s[j] = s[i];
            }
        }

        j++;
        s[j]='\0';   // indicating last as null 
        int id ;
        for(int i=0;i<n;i++){
            if(s[i] == '\0') {
                id = i;          // find null position
                break;
            }
        }
        string ans;
        int pos=0;
        ans = s.substr(pos,pos+(id)); //copy from first upto null without null in another ans string
        return ans;
