// Problem: Gold_Mine_Problem
// Description: Given a gold mine called mat[][]. Each field in this mine contains a positive integer which is the amount of gold in tons. Initially, the miner can start from any row in the first column. From a given cell, the miner can move -

to the cell diagonally up towards the right
to the right
to the cell di
// GeeksforGeeks Solution

class Solution {
  public:
    int maxGold(vector<vector<int>>& mat) {
        // code here
        for(int i = 1;i<mat[0].size();i++){
            for(int j = 0;j<mat.size();j++){
                int maxtake = mat[j][i-1];
                if(j>0) maxtake = max(maxtake,mat[j-1][i-1]);
                if(j<mat.size()-1) maxtake = max(maxtake,mat[j+1][i-1]);
                mat[j][i]+=maxtake;
            }
        }
        
        int ans = 0;
        
        for(int i = 0;i<mat.size();i++){
            ans = max(ans,mat[i][mat[0].size()-1]);
        }
        
        return ans;
    }
};