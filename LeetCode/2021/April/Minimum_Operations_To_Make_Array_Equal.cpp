class Solution {
public:
    int minOperations(int n) {
        
            vector<int> a(n);
        
            int sum=0;
        
            for(int i=0;i<n;i++) {
                a[i]=(2*i+1);
                sum+=a[i];
            }
        
            int y=sum/n;
        
            int c=0;
        
            for(int i=0;i<n/2;i++) {
                c+=(abs(y-a[i]));
            }
        
        return c;
        
    }
};