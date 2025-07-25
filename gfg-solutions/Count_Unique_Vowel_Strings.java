// Problem: Count_Unique_Vowel_Strings
// Description: You are given a lowercase string s, determine the total number of distinct strings that can be formed using the following rules:

Identify all unique vowels (a, e, i, o, u) present in the string.
For each distinct vowel, choose exactly one of its occurrences from s. If a vowel appears multiple times
// GeeksforGeeks Solution

class Solution {
  public:
  vector<int> vowels = {'a','e','i','o','u'};
  
  vector<int> fact = {0,1,2,6,24,120};


    int vowelCount(string& s) {
        // code here
        vector<int> umap(26);
        int ans = 0;
        
        for(auto x:s){
            umap[x-'a']++;
            
        }
        
        for(auto x:vowels)
           ans+= (umap[x-'a']>0);
           
        ans = fact[ans];
        
        int multi = 1;
         for(auto x:vowels)
           if(umap[x-'a']) multi*=umap[x-'a'];
           
         return ans*multi;
    }
};