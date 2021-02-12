class Solution {
public:
    int numberOfSteps (int num) {
        
        int c=0;
        
        while(num!=0) {
            if(num%2==0) {
                num/=2;
                c++;
                continue;
            }
            
            else {
                num--;
                c++;
                continue;
            }
        }
        
        
        return c;
        
    }
};