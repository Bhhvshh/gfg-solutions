// Problem: Trail_of_ones
// Description: Given an integer n, the task is to count the number of binary strings of length n that contains at least one pair of consecutive 1's.
Note:&nbsp;A binary string is a sequence made up of only 0's and 1's.
Examples:
Input: n = 2
Output: 1
Explanation: There are 4 strings of length 2, the strings are 00, 01, 10, and 11. Only the string 11 has consecutive 1's.
Input: n = 3
Output: 3
Explanation: There are 8 strings of length 3, the strings are 000, 001, 010, 011, 100, 101, 110 and 111. The strings with consecutive 1's are 011, 110 and 111.
Input: n = 5
Output: 19
Explanation: There are 19 strings having at least one pair of consecutive 1's.
Constraints:
2 ≤ n ≤ 30
// GeeksforGeeks Solution

class Solution {
  public:
    int countConsec(int n) {
        // code here
       
        
        int count1  = 0, count2 = 0;
        int sone = 0, endone = 0;
        helper(n/2,1,1,false,count1,endone);
        helper(n/2,1,0,false,count2,endone);
        sone = endone;
       
        
        
        if(n%2){
            int possible = (1<<(n/2 + 1));
            
            return 2*(count1+count2)*possible - 2*(count1+count2)*(count1+count2) + sone*((1<<(n/2))-(count1+count2)) +endone*((1<<(n/2))-(count1+count2)) - sone*endone;
        }
        else{
            
            
            int possible = (1<<(n/2));
            return 2*(count1+count2)*possible - (count1+count2)*(count1  + count2) + sone*endone ;
            
        }
        
        
        
        
        
    }
    
    
    void helper(int n,int id,int last,bool flag,int &count,int &endone){
        if(id==n){ count+=flag;
        if(last && !flag) endone++;
        
        return;}