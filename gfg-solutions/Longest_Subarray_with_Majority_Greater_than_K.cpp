// Problem: Longest_Subarray_with_Majority_Greater_than_K
// Description: Given an array arr[] and an integer k, the task is to find the length of longest subarray in which the count of elements greater than k is more than the count of elements less than or equal to k. Examples: Input: arr[] = [1, 2, 3, 4, 1], k = 2
Output: 3
Explanation: The subarray [2, 3, 4] or [3, 4, 1] satisfy the given condition, and there is no subarray of length 4 or 5 which will hold the given condition, so the answer is 3.
Input: arr[] = [6, 5, 3, 4], k = 2
Output: 4
Explanation: In the subarray [6, 5, 3, 4], there are 4 elements > 2 and 0 elements <= 2, so it is the longest subarray.
Constraints:
1 ≤ arr.size() ≤ 106 1 ≤ arr[i] ≤ 106
0 ≤ k ≤ 106
// GeeksforGeeks Solution

class Solution {
  public:
    int longestSubarray(vector<int> &arr, int k) {
        // Code here
        int greatk = 0, lessk = 0;
        // queue<pair<int,int>> k;
        unordered_map<int,int> umap;
        umap[0] = 1;
        int ans = 0;
        
        for(int i = 0;i<arr.size();i++){
            if(arr[i]>k) greatk++;
            else lessk++;
            
            if(greatk>lessk) ans = max(ans,i+1);
            else if(umap[greatk-lessk-1]) ans = max(ans,i-umap[greatk-lessk-1]+2);
            
            
            if(umap[greatk-lessk]==0) umap[greatk-lessk] = i+2;
            
            
           
        }
        
        return ans;
        
        
    }
};