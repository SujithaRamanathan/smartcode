Minimum Window Substring
==========================
Given a string corpus and a string target, find the minimum window (substring) which contain all the characters that are found in target.
The time complexity of the solution should be in order of O(n).
NOTE: substring and  sub-sequence are different thing

Input: corpus = "whoopiepiesmakemyscalegroan"  target = "roam"

Output: "myscalegro" 
================================================================
Brute force (easy to understand)( will made many duplicate searches)

l r
||
aaat

1111
aaat

 l
 |
aaat   here,we have reset the right ptr again since now left has been changed no.
 |
 r

Finally,
aaat
1234

no of substrings = n(n+1)
                   -------
		     2

================================================================

bool stringContainsAllCharacters(string searchString, string t)
    {
      // Hash Map for storing the character frequency
      unordered_map<char,int> requiredCharacters;
      
      // Store the frequency of all the characters of string t
      for (int i = 0; i < t.size(); i++)
      {
        requiredCharacters[t[i]]++;
      }
      
      // Traverse the searchString
      for (int i = 0; i < searchString.size(); i++)
      {
        char curChar = searchString[i];
        
        // If the curChar is present in the HashMap
        // Decrese its frequency by 1
        if(requiredCharacters.find(curChar)!=requiredCharacters.end())
        {
          requiredCharacters[curChar]--;
        }
      }
      
      // If any character's frequency is still greater than 0
      // It means we have a character in t that is not present in searchString
      // We return false
      for(auto it:requiredCharacters)
      {
        if(it.second>0)
          return false;
      }
      
      // Else we return true
      return true;
      
      
    }
  
    
    
    string minWindow(string searchString, string t) {
      
      int n=searchString.size();
      
      // It contains the min length seen so far
      int minWindowLengthSeenSoFar = n+1;
      // It contains the minimum length substring
      string minWindow= "";
      
      // The nested for loop help us generate all the substrings
      for(int left=0; left<n; left++)
      {
        for(int right=0; right<n; right++)
        {
          // Generate the substring
          string windowSnippet= searchString.substr(left,right+1);
          
          // Check if the generated char contains all the characters of target
          bool windowContainsAllChars = stringContainsAllCharacters(windowSnippet, t);
          
          // If it is a valid substring
          // And the length is less than the minimum so far
          // Update the answer
          if (windowContainsAllChars && windowSnippet.size() < minWindowLengthSeenSoFar) 
          {
            minWindowLengthSeenSoFar = windowSnippet.size();
            minWindow = windowSnippet;
          }
        }
      }
      
      return minWindow;






=======================================================================================================================================================


EFFICIENT SOLUTION:- O(S + T):-
==================================


HERE,EXACTLY TWO TOUCHES FOR EACH ELEMENT BY START AND END POINTER;
HERE,WE HAVE TWO WHILE LOOPS
1st one is for expanding the window in case we don't get satisfied...
2nd one checking window contains t and contracting the window ....

IMPORTANT NOTE:-
-----------------
IN CASE OF FINDING ALL T CHARS - TRY TO EXPAND THE WINDOW WITH END PTR MOVING FORWARD(OUTWARDS)(EXPANSION)
IN CASE WE GOT THE WINDOW - TRY TO MINIMISE THE WINDOW WITH START PTR MOVING FORWARD (INWARDS)
(CONTRACTION)

        vector<int> table(128, 0);
      
      // Store the frequency of characters in string t
      for(auto character : t) {
        table[character]++;
      }
      
      int start = 0;
      int end = 0;
      int counter = t.size();
      int startMin = 0;
      int minimum = INT_MAX;
      
      // Here we use the 2 pointer approach
      while(end < searchString.size()) {
          if(table[searchString[end]] > 0) {
            counter--;
          }
          
          table[searchString[end]]--;
          end++;
          
          while(counter == 0) {
            if(end - start < minimum) {
                startMin = start;
                minimum = end - start;
            }
            
            table[searchString[start]]++;   //incase of removing 1st char,check whether that                                             //contributed to t
            
            if(table[searchString[start]] > 0) {
              counter++;
            }
            start++;
          }
      }
      
      // Case when no substring satisfies
      if(minimum == INT_MAX) {
          return "";
      }
      
      return searchString.substr(startMin, minimum);

===========================================================================================


