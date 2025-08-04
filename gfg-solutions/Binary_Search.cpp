// Problem: Binary_Search
// Description: Given a sorted array arr[] and an integer k, find the position(0-based indexing) at which k is present in the array using binary search. If k doesn't exist in arr[] return -1. Note: If multiple occurrences are there, please return the smallest index. Examples: Input: arr[] = [1, 2, 3, 4, 5], k = 4
Output: 3
Explanation: 4 appears at index 3.
Input: arr[] = [11, 22, 33, 44, 55], k = 445
Output: -1
Explanation: 445 is not present. Input: arr[] = [1, 1, 1, 1, 2], k = 1
Output: 0
Explanation: 1 appears at index 0.
Constraints:
1 ≤ arr.size() ≤ 105
1 ≤ arr[i] ≤ 106
1 ≤ k ≤ 106
// GeeksforGeeks Solution

class Solution {
  public:
    int binarysearch(vector<int> &arr, int k) {
        // code here
        int l = 0, r = arr.size()-1;
        int result = -1;
        while(l<=r){
            int mid = l + ((r-l)>>1);
            if(arr[mid]==k) result  = mid;
            if(arr[mid]>=k){
                r = mid -1;
            }
            else l = mid +1;
        }
        
        
        return result;
    }
};