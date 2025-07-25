class Solution {
  public:
    int countValid(int n, vector<int>& arr) {
        // code here
        vector<int> digit (10);
        int count = 0;
        for(auto x:arr){
            if(digit[x]==0){
                count++;
                digit[x] = 1;
            }
        }
        // cout << 9*pow(10,n-1) << endl;
        // cout << (digit[0] ? 10 - count : 10 - count + 1)*pow(10-count, n-1) << endl;
        
        return 9*pow(10,n-1) -(digit[0] ? 10 - count : 10 - count - 1)*pow(10-count, n-1);
    }
};