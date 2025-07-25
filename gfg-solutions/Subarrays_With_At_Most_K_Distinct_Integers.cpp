// Problem: Subarrays_With_At_Most_K_Distinct_Integers
// Description: You are given an array arr[] of positive integers and an integer k, find the number of subarrays in arr[] where the count of distinct integers is at most k. Note: A subarray is a contiguous part of an array. Examples: Input: arr[] = [1, 2, 2, 3], k = 2Output: 9Explanation: Subarrays with at most 2 distinct elements are: [1], [2], [2], [3], [1, 2], [2, 2], [2, 3], [1, 2, 2] and [2, 2, 3].
Input: arr[] = [1, 1, 1], k = 1Output: 6
Explanation: Subarrays with at most 1 distinct element are: [1], [1], [1], [1, 1], [1, 1] and [1, 1, 1].
Input: arr[] = [1, 2, 1, 1, 3, 3, 4, 2, 1], k = 2Output: 24
Explanation: There are 24 subarrays with at most 2 distinct elements.
Constraints:
1 ≤ arr.size() ≤ 2*104
1 ≤ k ≤ 2*104
1 ≤ arr[i] ≤ 109
// GeeksforGeeks Solution

class Solution {
  public:
    int countAtMostK(vector<int> &arr, int k) {
        // code here
        
        unordered_map<int,int> umap;
        int count = 0, ans = 0;
        
        for(int i = 0, l = 0;i<arr.size();i++){
          count+=(umap[arr[i]]++==0);
          while(count>k)  count-= (umap[arr[l++]]--==1);
          ans+= (i-l+1);
        }
        
        
        return ans;
    }
};