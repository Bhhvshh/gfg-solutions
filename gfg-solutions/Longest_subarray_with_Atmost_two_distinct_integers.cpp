// Problem: Longest_subarray_with_Atmost_two_distinct_integers
// Description: Given an array arr[] consisting of positive integers, your task is to find the length of the longest subarray that contains at most two distinct integers. Examples: Input: arr[] = [2, 1, 2]
Output: 3
Explanation: The entire array [2, 1, 2] contains at most two distinct integers (2 and 1). Hence, the length of the longest subarray is 3.
Input: arr[] = [3, 1, 2, 2, 2, 2]
Output: 5
Explanation: The longest subarray containing at most two distinct integers is [1, 2, 2, 2, 2], which has a length of 5.
Constraints:
1 ≤ arr.size() ≤ 105
1 ≤ arr[i] ≤ 105
// GeeksforGeeks Solution

class Solution {
  public:
    int totalElements(vector<int> &arr) {
        // code here
        
        int count =  0;
        unordered_map<int,int> umap;
        int ans = 0;
        for(int  i = 0,l = 0;i<arr.size();i++){
            if(umap[arr[i]]++==0) count++;
            while(l<i && count>2){
                if(umap[arr[l++]]--==1) count--;
               
            }
            
            ans = max(ans,i-l+1);
            
        }
        
        return ans;
    }
};