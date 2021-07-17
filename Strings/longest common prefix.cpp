 Longest Common Prefix
===========================
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

 Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
 
===============================================================

vvvvsimple(two functions)
=================

string longestCommonPrefix(vector<string>& strs) {
        
       string prefix;
        prefix = strs[0];        // initialize prefix with str
        
        for(int i=1;i<strs.size();i++)
            prefix = prefixtill(prefix,strs[i]);  // comparing with prefix and the next str
        
        return (prefix);        .// notice ' ( )' becoz it tells the condition if there is string return or just " ".
    }
    
===================================================================================================    
    string prefixtill(string s1,string s2){
        int n = s1.length();
        int m = s2.length();
        
        string res;
        int i,j;
        
        for(i=0,j=0;i<n and j<m;i++,j++) {              // checking two strings
            
            if(s1[i] != s2[j])
                break;
            res.push_back(s1[i]);             // we can also push bac in string too
    
            }
        return (res);        
    }