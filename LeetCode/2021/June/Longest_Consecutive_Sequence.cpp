class Solution {
public:
    
    int par(int i,vector<int>& parent) {
        if(i==parent[i]) {
            return i;
        }
        return parent[i]=par(parent[i],parent);
    }
    
    
    void unions(int a,int b,vector<int>& parent,vector<int>& size) {
        
        a=par(a,parent);
        b=par(b,parent);
        
        if(a==b) {
            return;
        }
        if(size[a]>size[b]) {
            parent[b]=a;
            size[a]+=size[b];
        }
        else {
            parent[a]=b;
            size[b]+=size[a];
        }
        
    }
    
    int longestConsecutive(vector<int>& a) {
        
        if(a.size()==0) {
            return 0;
        }
        
        int n=a.size();
        map<int,int> mp;
        
        vector<int> parent(n,0);
        vector<int> size(n,0);
        
        for(int i=0;i<n;i++) {
            parent[i]=i;
            size[i]=1;
        }
        
        for(int i=0;i<n;i++) {
          
            if(mp.count(a[i])) {
                continue;
            }
            
            if(mp.count(a[i]-1)) {
                unions(mp[a[i]-1],i,parent,size);
            }
            
            if(mp.count(a[i]+1)) {
                unions(mp[a[i]+1],i,parent,size);
            }
            
            mp[a[i]]=i;
            
        }
        
        return *max_element(size.begin(),size.end());
        
    }
};