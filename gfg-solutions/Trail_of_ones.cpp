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