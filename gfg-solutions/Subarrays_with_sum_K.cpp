// Problem: Subarrays_with_sum_K
// Description: Given an unsorted array arr[] of integers, find the number of subarrays whose sum exactly equal to a given number k. Examples: Input: arr[] = [10, 2, -2, -20, 10], k = -10
Output: 3
Explaination: Subarrays: arr[0...3], arr[1...4], arr[3...4] have sum exactly equal to -10.
Input: arr[] = [9, 4, 20, 3, 10, 5], k = 33
Output: 2
Explaination: Subarrays: arr[0...2], arr[2...4] have sum exactly equal to 33. Input: arr[] = [1, 3, 5], k = 0
Output: 0
Explaination: No subarray with 0 sum.
Constraints:
1 ≤ arr.size() ≤ 105
-103 ≤ arr[i] ≤ 103
-105 ≤ k ≤ 105
// GeeksforGeeks Solution

class Solution {
  public:
    int cntSubarrays(vector<int> &arr, int k) {
        // code here
        unordered_map<int,int> umap;
        umap[0] = 1;
        
        int sum = 0;
        int ans = 0;
        for(int i = 0;i<arr.size();i++){
            sum+=arr[i];
            ans+=umap[sum-k];
            umap[sum]++;
            
        }
        
        
        return ans;
    }
};