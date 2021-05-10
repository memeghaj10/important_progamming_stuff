class Solution {
public:
    int countPrimes(int n) {
        
        if(n<=1) {
            return 0;
        }
        
        int sieve[n];
        memset(sieve,0,sizeof(sieve));
        
        for(int i=2;i*i<n;i++) {
            if(sieve[i]==1) {
                continue;
            }
            
            for(int j=i*i;j<n;j+=i) {
                sieve[j]=1;
            }
        }
        
        int c=count(sieve,sieve+n,0);
        
        
        return c-2;
    }
};