// Problem: Cutting_Binary_String
// Description: You are given a binary string s consisting only of characters '0' and '1'. Your task is to split this string into the minimum number of non-empty substrings such that:

Each substring represents a power of 5 in decimal (e.g., 1, 5, 25, 125, ...).
No substring should have leading zeros.

Return the m
// GeeksforGeeks Solution

class Solution {
  public:
    int cuts(string s) {
        // code here
        
        vector<int> dp(s.size(),-1);
        int ans = helper(0,s,dp);
        return (ans!=INT_MAX) ? ans: -1;
        
    }
    
    bool powerof5(int num){
        if(num==1) return true;
        int base = 5;
        while(base<num){
            base*=5;
            
        }
        
        return base==num;
    }
    
    int helper(int id,string &s,vector<int> &dp){
        if(id==s.size()) return 0;
        
        if(dp[id]!=-1) return dp[id];
        
        int curr = 0;
        int ans = INT_MAX;
        
        if(s[id]=='0') return dp[id] = ans;
        
        for(int i =  id;i<s.size();i++){
            curr<<=1;
            curr+=(s[i]=='1');
            if(curr!=0 && (powerof5(curr))){
                int next = helper(i+1,s,dp);
                
                if(next!=INT_MAX) ans = min(ans,1+next);