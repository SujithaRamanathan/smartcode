Given a sequence of words, print all anagrams together :-
=========================================================
A simple method is to create a Hash Table. Calculate the hash value of each word in such a way that all anagrams have the same hash value. Populate the Hash Table with these hash values. Finally, print those words together with same hash values.

Method 2:-  
==========
Time complexity:-
-----------------------------
upper bound is O(NMLogM)
 
Algo:-
=========
1)make use of map which stores string as key and vector of strings as value.

qn) { tac, god,act,dog,cat}

2)Traverse the vector
do:
    *) s = a[i];
    *)sort s;
    *) keep s as key and store the cur string a[i] as value
eg:-
 s = tac
sort --> act
m[act] = { "tac"}

 s = god
sort --> dgo
m[dgo] = { "god"}

 s = act
sort --> act
m[act] = { "tac","act"}

 s = dog
sort --> dgo
m[act] = { "god","dog"}

 s = cat
sort --> act
m[act] = { "tac","act","cat"}


FINALLY IN MAP:-

-----------------------------------
act  === "tac","act","cat"     |
dgo === "god","dog"           |
-----------------------------------

print this ....
===========================================
vector<vector<string> > Anagrams(vector<string>& s) 
{
    
    //processing & grouping
    map<string,vector<string>> m;
    for(int i =0;i<s.size();i++) {
        string str = s[i];
        sort(str.begin(),str.end());
        m[str].push_back(s[i]);
    }
        
      // extracting the output in necessary order
      int idx =0;
      vector<vector<string>> ans(m.size());
      for(auto x:m) {
          auto v = x.second;
          for(int i=0;i<v.size();i++)
          ans[idx].push_back(v[i]);
      idx++;
          
      }
    return ans;
}

=======================================================









	