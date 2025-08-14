// Problem: Count_Reverse_Pairs
// Description: You are given an array arr[] of positive integers, find the count of reverse pairs. A pair of indices (i, j) is said to be a reverse pair if both the following conditions are met: 0 ≤ i < j < arr.size()
arr[i] > 2 * arr[j] Examples:
Input: arr[] = [3, 2, 4, 5, 1, 20]
Output: 3
Explanation:
The Reverse pairs are (0, 4), arr[0] = 3, arr[4] = 1, 3 > 2*1 (2, 4), arr[2] = 4, arr[4] = 1, 4 > 2*1 (3, 4), arr[3] = 5, arr[4] = 1, 5 > 2*1 Input: arr[] = [5, 4, 3, 2, 2]
Output: 2
Explanation:
The Reverse pairs are
(0, 3), arr[0] = 5, arr[3] = 2, 5 > 2*2
(0, 4), arr[0] = 5, arr[4] = 2, 5 > 2*2
Constraints:
1 ≤ arr.size() ≤ 5*104
1 ≤ arr[i] ≤ 109
// GeeksforGeeks Solution

return sum;
        
    }
    void update(int id,int val){
        id++;
        while(id<t.size()){
            t[id]+=val;
            id+= (id & (-id));
            
        }
    }
};
class Solution {
  public:
    int countRevPairs(vector<int> &arr) {
        // Code here
        
        int ans = 0;
        
        vector<long long> tmp;
        for(auto x:arr) tmp.push_back(2*x);
        
        bit bit(arr.size());
        sort(tmp.begin(),tmp.end());
        
        for(int i = arr.size()-1;i>=0;i--){
            int idx = lower_bound(tmp.begin(),tmp.end(),arr[i]) - tmp.begin();
            
            if(idx)ans+= bit.getsum(idx-1);
            // cout << ans <<endl;
            int updateidx = lower_bound(tmp.begin(),tmp.end(),2*arr[i]) -tmp.begin();
            bit.update(updateidx,1);
            
        }
        
        return ans;
    }
};