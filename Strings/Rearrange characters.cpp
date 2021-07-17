Rearrange characters:-
==========================

Given a string S with repeated characters. The task is to rearrange characters in a string such that no two adjacent characters are the same. 
Note: The string has only lowercase English alphabets and it can have multiple solutions. Return any one of them.

Example 1:

Input : 
str = "geeksforgeeks"
Output: 1
Explanation:
All the repeated characters of the 
given string can be rearranged so 
that no adjacent characters in the 
string is equal. Any correct 
rearrangement will show a output of 1.
Example 2:

Input : 
str = "bbbbb"
Output: 0
========================================================
Approach:-

to fill all the even positions of the result string first, with the highest frequency character. If there are still some even positions remaining, fill them first. Once even positions are done, then fill the odd positions. This way, we can ensure that no two adjacent characters are the same.

TIME COMPLEXITY:-

O(N)


=============================================================
CODE:-
char getMaxCountChar(const vector<int>& count){ // function return char with maximum frequency
        int max = 0;
        char ch;
        
        for(int i=0;i<26;i++){
            if(count[i] > max){
                max = count[i];
                ch = 'a' + i;
            }
        }
        return ch;
    }
 

   string rearrangeString(string str)                
    {
        int n = str.size();    // if input string is an empty string
        if(!n) 
        return "";
        
        vector<int> count(26,0);
        for(auto ch : str)
        count[ch-'a']++;
        
        char ch_max = getMaxCountChar(count);
        int maxcount = count[ch_max - 'a'];
        
        if(maxcount > (n+1)/2)       // VVIMP (if its possible to fill alternatively)
        return "-1";
        
        string res(n, ' ');
        int ind = 0;
        
        while(maxcount){                // filling the max freq char in even positions
            res[ind] = ch_max;
            ind = ind + 2;
            maxcount--;
        }
        
        count[ch_max - 'a'] = 0;       // after filled that we have to make it 0..to avoid repetition 

        
        for(int i=0;i<26;i++){           // filling remaining
            while(count[i] > 0){
                ind = (ind >= n) ? 1:ind;           // VVVIMP that if we reach end start filling from odd positions by maing ind = 1;
                res[ind] = 'a' + i;
                ind += 2;
                count[i]--;   // VVVimp
            }
        }
        return res;
        
        
     }
===================================================