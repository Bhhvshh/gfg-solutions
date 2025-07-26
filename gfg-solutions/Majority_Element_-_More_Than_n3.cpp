// Problem: Majority_Element_-_More_Than_n3
// Description: Given an array arr[] consisting of n integers, the task is to find all the array elements which occurs more than floor(n/3) times. Note: The returned array of majority elements should be sorted. Examples: Input: arr[] = [2, 2, 3, 1, 3, 2, 1, 1]
Output: [1, 2]
Explanation: The frequency of 1 and 2 is 3, which is more than floor n/3 (8/3 = 2).
Input: arr[] = [-5, 3, -5]
Output: [-5]
Explanation: The frequency of -5 is 2, which is more than floor n/3 (3/3 = 1). Input: arr[] = [3, 2, 2, 4, 1, 4]
Output: []
Explanation: There is no majority element.
Constraint:
1 ≤ arr.size() ≤ 106
-105 ≤ arr[i] ≤ 105
// GeeksforGeeks Solution

for(int i = 0;i<arr.size();i++){
            
            if( m1==arr[i]){
                c1++;
                m1 = arr[i];
            }
            else if( m2==arr[i]){
                c2++;
                m2 = arr[i];
            }
            
            else if(c1==0){
                c1++;
                m1 = arr[i];
                
            }
            else if(c2==0){
                c2++;
                m2 = arr[i];
                
            }
            else{
                if(c2<=c1){
                    c2--;
                    
                }
                else c1--;
            }
        }
        vector<int> ans;
        int cv1 = 0,cv2=0;
        for(auto x:arr) if(x==m1) cv1++;
        for(auto x:arr) if(x==m2) cv2++;
        if(cv1>arr.size()/3)ans.push_back(m1);
        if(cv2>arr.size()/3)ans.push_back(m2);
        
        sort(ans.begin(),ans.end());
        
        return ans;