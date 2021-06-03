class Solution {
public:
    
    const long long int mod=1000000007;
    
    int maxArea(int h, int w, vector<int>& hor, vector<int>& vert) {
                
        int n=hor.size();
        int m=vert.size();
        
        sort(hor.begin(),hor.end());
        sort(vert.begin(),vert.end());
        
        int max_hor=hor[0];
        int max_vert=vert[0];
        
        for(int i=1;i<n;i++) {
            max_hor=max(max_hor,hor[i]-hor[i-1]);
        }
        max_hor=max(max_hor,h-hor[n-1]);
        
        for(int i=1;i<m;i++) {
            max_vert=max(max_vert,vert[i]-vert[i-1]);
        }
        max_vert=max(max_vert,w-vert[m-1]);
        
        return max_hor%mod*max_vert%mod;
        
    }
};