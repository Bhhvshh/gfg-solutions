// Problem: Farthest_Smaller_Right
// Description: You are given an array arr[]. For each element at index i (0-based indexing), find the farthest index j to the right (i.e., j > i) such that arr[j] < arr[i]. If no such index exists for a given position, return -1 for that index. Return the resulting array of answers. Examples: Input: arr[] = [2, 5, 1, 3, 2]
Output: [2, 4, -1, 4, -1]
Explanation: arr[0] = 2: Farthest smaller element to the right is arr[2] = 1.
arr[1] = 5: Farthest smaller element to the right is arr[4] = 2.
arr[2] = 1: No smaller element to the right → -1.
arr[3] = 3: Farthest smaller element to the right is arr[4] = 2.
arr[4] = 2: No elements to the right → -1.
Input: arr[] = [2, 3, 5, 4, 1] Output: [4, 4, 4, 4, -1]
Explanation: arr[4] is the farthest smallest element to the right for arr[0], arr[1], arr[2] and arr[3]. Constraints:
1 ≤ arr.size() ≤ 106
1 ≤ arr[i] ≤ 106
// GeeksforGeeks Solution

class Solution {
  public:
    vector<int> farMin(vector<int>& arr) {
        // code here
        
         vector<pair<int,int>> small;
         vector<int> ans(arr.size());
         for(int i = arr.size() - 1;i>=0;i--){
             if(small.empty()) ans[i] = -1;
             else{
                 
                 ans[i] = helper(small,arr[i]);
                 
             }
             
             if(small.empty() || small.back().first>arr[i]) small.push_back({arr[i],i});
             
         }
         
         
         return ans;
         
         
    }
    
    int helper(vector<pair<int,int>> &s, int &f){
        
        int l = 0, r= s.size() - 1;
        int res = -1;
        
        while(l<=r){
            int mid = l + ((r-l)>>1);
            if(s[mid].first<f){
                res = s[mid].second;
                r = mid - 1;
                
            }
            else l = mid +1;