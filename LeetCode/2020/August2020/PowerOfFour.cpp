class Solution {
public:
    bool isPowerOfFour(int64_t num) {
        
        if(num<=3&&num!=1) {
            return false;
        }
        
        if(num==1) {
            return true;
        }
        
       if(num%2==0) {
            int64_t h=0;
           
           while(num%4==0) {
               num=num/4;
                   h++;
           }
           
           if(num==1) {
               return true;
           }
           
           else {
               return false;
           }
       }
        
        else {
            return false;
        }
    }
};