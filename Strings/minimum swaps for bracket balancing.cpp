Minimum Swaps for Bracket Balancing :-
===========================================
You are given a string S of 2N characters consisting of N ‘[‘ brackets and N ‘]’ brackets. A string is considered balanced if it can be represented in the for S2[S1] where S1 and S2 are balanced strings. We can make an unbalanced string balanced by swapping adjacent characters. Calculate the minimum number of swaps necessary to make a string balanced.
Note - Strings S1 and S2 can be empty.

 

Example 1:

Input  : []][][
Output : 2
Explanation :
First swap: Position 3 and 4
[][]][
Second swap: Position 5 and 6
[][][]

 

Example 2:

Input : [[][]]
Output : 0 
Explanation:
String is already balanced.
======================================================

vvvvsimple

We can initially go through the string and store the positions of ‘[‘ in a vector say ‘pos‘. 
Initialize ‘p’ to 0. 
We shall use p to traverse the vector ‘pos’. 
Similar to the naive approach, we maintain a count of encountered 
‘[‘ brackets. 
When we encounter a ‘[‘ we increase the count and increase ‘p’ by 1. 
When we encounter a ‘]’ we decrease the count.
 If the count ever goes negative, this means we must start swapping. 
The element pos[p] tells us the index of the next ‘[‘. 
We increase the sum by pos[p] – i, where i is the current index. 
We can swap the elements in the current index and pos[p] and reset the count to 0 and increment p so that it pos[p] indicates to the next ‘[‘.
Since we have converted a step that was O(N) in the naive approach, to an O(1) step, our new time complexity reduces. 

Time Complexity = O(N) 
Extra Space = O(N)

================================================================



int minimumNumberOfSwaps(string s){
        int n = s.length();
        vector<int>pos;    // creating a pos array for maintaining [ positions so that we can easily swap no
        
        for(int i=0;i<n;i++) {
        if(s[i]=='[')
        pos.push_back(i);
        }
        
        int sum = 0;
        int p = 0;
        int count = 0;
        
        for(int i=0;i<n;i++){
            if(s[i] == '['){
            count++;
            p++;    // inc p vvvvvvimp
            }
            else if(s[i]==']')
            count--;
            
            if(count < 0){
                sum += pos[p] - i;   // vvimp
                swap(s[i],s[pos[p]]);
                p++;
                
                count = 1;
            }
            }
        return sum;
    }