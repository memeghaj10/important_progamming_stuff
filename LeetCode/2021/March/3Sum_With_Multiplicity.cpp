#define mod 1000000007

class Solution {
public:
    int threeSumMulti(vector<int>& a, int target) {
        
        int n=a.size();
        
        sort(a.begin(),a.end());
        
        int c=0;
        
        for(int i=0;i<n;i++) {
            
            int t=target-a[i];
            
            int j=i+1;
            int k=n-1;
            
            while(j<k) {
                
                if(a[j]+a[k]>t) {
                    k--;
                }
                
                else if(a[j]+a[k]<t) {
                    j++;
                }
                
                else if(a[j]!=a[k]) {
                    int left=1;
                    int right=1;
                    
                    while(j+1<k&&a[j]==a[j+1]) {
                        j++;
                        left++;
                    }
                    
                    while(k-1>j&&a[k]==a[k-1]) {
                        k--;
                        right++;
                    } 
                    
                    c+=(left*right);
                    c=c%mod;
                    j++;
                    k--;                    
                }
                
                else {
                    
                    c+=(k-j+1)*(k-j)/2;
                    c=c%mod;
                    break;
                    
                }
                
            }
            
        }
        
        
        return c%mod;
        
        
    }
};