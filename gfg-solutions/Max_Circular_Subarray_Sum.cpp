class Solution {
  public:
    int maxCircularSum(vector<int> &arr) {
        // code here
        int last = 0;
        int ans = INT_MIN;
        int count = 0;
        int sum = 0, n = arr.size();
        for(int i = 0;i<n;i++){
            int id = i%n;
            sum+=arr[id];
            // count++;
            //  while(count > n){
            //     sum-=arr[(last++)%n];
            //     count--;
                
                
                
            // }
            if(sum<=arr[id]){
                sum=arr[id];
                count = 1;
                last = id;
            }
           
            // cout << sum<<endl;
            
            ans = max(ans,sum);
            
        }
        int totalsum   = 0;
        for(auto x:arr) totalsum+=x;
        
        // vector<int> v(n);
        int l = 0;
        int curr= 0;
        int max_ = INT_MIN;
        for(int i = 0;i<n;i++){
            if(l==i) totalsum-=arr[l++];