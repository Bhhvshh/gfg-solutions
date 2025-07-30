// Problem: ASCII_Range_Sum
// Description: Given a string s consisting of lowercase English letters, for every character whose first and last occurrences are at different positions, calculate the sum of ASCII values of characters strictly between its first and last occurrence.
Return all such non-zero sums (order does not matter). Examples: Input: s = "abacab"
Output: [293, 294]
Explanation: characters 'a' and 'b' appear more than once:
'a' : between positions 1 and 5 → characters are b, a, c and ascii sum is 98 + 97 + 99 = 294.
'b' : between positions 2 and 6 → characters are a, c, a and ascii sum is 97 + 99 + 97 = 293. Input: s = "acdac"
Output: [197, 199]
Explanation: characters 'a' and 'c' appear more than once:
'a' : between positions 1 and 4 → characters are c, d and ascii sum is 99 + 100 = 199.
'c' : between positions 2 and 5 → characters are d, a and ascii sum is 100 + 97 = 197.
Constraints:
1 ≤ s.size() ≤ 105
// GeeksforGeeks Solution

class Solution {
  public:
    vector<int> asciirange(string& s) {
        // code here
        
        vector<pair<int,int>> vp(26,{-1,-1});
        int n = s.size();
        for(int i = 0;i<n;i++){
            if(vp[s[i]-'a'].first==-1){
                vp[s[i]-'a'].first = i;
                vp[s[i]-'a'].second = i;
            }
            else{
                vp[s[i]-'a'].second = i;
                
            }
        }
        vector<int> res;
        
        for(auto x:vp){
              int curr = 0;
                for(int i = x.first+1;i<x.second;i++){
                    curr+=s[i];
                    
                }
           if(curr)
            res.push_back(curr);
            
            
        }
        
        return res;
    }
};