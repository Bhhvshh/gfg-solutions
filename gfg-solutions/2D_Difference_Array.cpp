// Problem: 2D_Difference_Array
// Description: You are given a 2D integer matrix mat[][] of size n × m and a list of q operations opr[][]. Each operation is represented as an array [v, r1, c1, r2, c2], where: v is the value to be added
(r1, c1) is the top-left cell of a submatrix
(r2, c2) is the bottom-right cell of the submatrix (inclusive) For each of the q operations, add v to every element in the submatrix from (r1, c1) to (r2, c2). Return the final matrix after applying all operations. Examples: Input: mat[][] = [[1, 2, 3], opr[][] = [[2, 0, 0, 1, 1], [-1, 1, 0, 2, 2]] [1, 1, 0], [4,-2, 2]]
Output: [[3, 4, 3], [2, 2, -1], [3, -3, 1]] Explanation: Constraint:
1 ≤ n×m, q ≤ 105
0 ≤ r1 ≤ r2 ≤ n - 1
0 ≤ c1 ≤ c2 ≤ m - 1
-104 ≤ mat[i][j], v ≤ 104
// GeeksforGeeks Solution

class Solution {
  public:
    vector<vector<int>> applyDiff2D(vector<vector<int>>& mat,
                                    vector<vector<int>>& opr) {
        // code here
        int n = mat.size(), m = mat[0].size();
        
        vector<vector<int>> pre(n,vector<int>(m));
        
        for(auto &x:opr){
            int v = x[0], r1 = x[1], c1 = x[2], r2 = x[3], c2 = x[4];
            
            for(int i = r1;i<=r2;i++){
                pre[i][c1] += v;
                if(c2+1<m){
                    pre[i][c2+1] -= v;
                }
                
            }
            
        }
        
        for(int i = 0;i<n;i++){
            
            for(int j = 0;j<m;j++){
                pre[i][j]  += ((j>0)? pre[i][j-1]:0);
                mat[i][j]+=pre[i][j];
                
                
            }
        }
        
        return mat;
        
        
        
    }
    
};