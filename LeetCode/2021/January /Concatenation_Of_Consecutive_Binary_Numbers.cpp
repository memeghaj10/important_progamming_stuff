class Solution {
public:
    int concatenatedBinary(int n) {
                
        
            long long  int M = 1000000007;//modulo operator
            long long  int d1=0,res;
        for(long long int i=1;i<=n;i++){
            d1=((d1<<(int(log2(i))+1))%M+i)%M;//shifting the bits to left side 
           
            
        }
      
     
        return d1;
        
    }
};