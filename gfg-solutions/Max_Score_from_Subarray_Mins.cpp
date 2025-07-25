class Solution {
  public:
    int maxSum(vector<int> &arr) {
        // code here
        int ans = INT_MIN;
        for(int i = 0;i<arr.size() - 1;i++)
           ans = max(ans,arr[i] + arr[i+1]);
           
        return ans;
    }
};