class Solution {
public:
    int hammingWeight(uint32_t n) {
            
                  int c=0;
                  while(n>0) {
                     if(n%2==1) {
                         c++;
                        }
                     n/=2;
                }
        
        
        return c;
    }
};