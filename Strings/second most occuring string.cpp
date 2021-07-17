Second most repeated string in a sequence :-
============================================
Given a sequence of strings, the task is to find out the second most repeated (or frequent) string in the given sequence.

Note: No two strings are the second most repeated, there will be always a single string.

Example 1:

Input:
N = 6
arr[] = {aaa, bbb, ccc, bbb, aaa, aaa}
Output: bbb
Explanation: "bbb" is the second most 
occurring string with frequency 2.

â€‹Example 2:

Input: 
N = 6
arr[] = {geek, for, geek, for, geek, aaa}
Output: for
Explanation: "for" is the second most
occurring string with frequency 2.
======================================================================

VVVV simple:-

make use of hash map:-(traversing the map can be find here)
==================================================================


string secFrequent (string arr[], int n)
    {
        unordered_map<string,int>occ;
        
        for(int i=0;i<n;i++)   // store all the strings and its occurences
        occ[arr[i]]++;
        
        int first = INT_MIN;
        int second = INT_MIN;
        for(auto it = occ.begin();it != occ.end();it++) {      // find the second largest occurence
           if(it->second > first) {
               second = first;
               first = it->second;
           }
           
           else if(it->second > second and it->second != first)
           second = it->second;
        }
    
        for(auto it = occ.begin();it != occ.end();it++){             // return the corresponding str which have second most occurence
            if(it->second == second )
            return it->first;
        }
        
        
        
    }