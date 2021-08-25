class Solution {
public:
    bool judgeSquareSum(int c) {
        
     for(long long int i=0;i<=c;i++) {
         long long int j;
        if(i*i<=c) {
                j= sqrt(c-i*i);
        }
        
         else {
             break;
         }
         if(j*j+i*i==c) {
             return 1;
         }
     }
        
        return 0;
        
    }
};