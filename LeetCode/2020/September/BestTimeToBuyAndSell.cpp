class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        if(prices.size()==0) {
            return 0;
        }     
        
        int n=prices.size();
        
        int a[n];
        
        vector<int> v;
        v=prices;
        
        sort(v.begin(),v.end(),greater<int>());
        
        map<int,int> mp;
        
        for(int i=0;i<prices.size();i++) {
            mp[prices[i]]=i;
        }
        
        int j=0;
        
        for(int i=0;i<v.size();i++) {
            int h=mp[v[i]];
            
            if(j<=h) {
                for(int k=j;k<=h;k++) {
                         a[k]=v[i];
                    }
                j=h+1;
            }
        }
        
        
        for(int i=0;i<n;i++) {
            a[i]=a[i]-prices[i];
        }
        
        int y=*max_element(a,a+n);
        
        if(y<0) {
            return 0;
        }
        
        else {
            return y;
        }
        
            
        
        
    }
};