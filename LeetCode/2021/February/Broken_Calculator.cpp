	class Solution {
public:
    int brokenCalc(int X, int Y) {
        
        if(X>=Y) {
            return X-Y;
        }
        
        
        int ans=0;
        
        
        while(Y>X) {
            
            if(Y%2) {
                Y++;
                ans++;
            }
                
            Y=Y/2;
            
            ans++;
            
        }
        
        if(X>=Y) {
            return ans+X-Y;
        }
        
        else {
            return ans;
        }
        
    }
};