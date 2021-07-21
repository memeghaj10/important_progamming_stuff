class Solution {
public:
    string pushDominoes(string dominoes) {
        
        vector<pair<int,char>> vp;
        
        
        int n=dominoes.size();
        
        for(int i=0;i<n;i++) {
            if(dominoes[i]!='.') {
                vp.push_back(make_pair(i,dominoes[i]));
            }
        }
        
        if(vp.size()==0) {
            return dominoes;
        }
        
        set<int> dot,left,right;
        
        for(int i=0;i<vp.size()-1;i++) {
            
            if(vp[i].second!=vp[i+1].second) {
                int u=vp[i+1].first-vp[i].first-1;
                if(u==1) {
                    dot.insert(vp[i+1].first+1);
                }
                
                else if(u>1) {
                    if(vp[i].second=='L') {
                      continue;
                    }
                    
                    else {
                        int t=u/2;
                        int j=vp[i].first+1;
                        while(t) {
                            right.insert(j);
                            j++;
                            t--;
                        }
                        
                        t=u/2;
                        j=vp[i+1].first-1;
                        while(t) {
                            left.insert(j);
                            j--;
                            t--;
                        }
                    }
                }
            }
            
            else {
                
                    for(int j=vp[i].first;j<=vp[i+1].first;j++) {
                        dominoes[j]=vp[i].second;
                    }
                
            }
            
        }
        
        for(int i=0;i<dominoes.size();i++) {
            if(dominoes[i]=='.') {
                    
                    if(left.find(i)!=left.end()) {
                        dominoes[i]='L';
                    }
                
                    else if(right.find(i)!=right.end()) {
                        dominoes[i]='R';
                    }
                
            }
        }
        
        if(vp[0].second=='L') {
            for(int j=vp[0].first;j>=0;j--) {
                dominoes[j]='L';
            }
        }
        
        if(vp[vp.size()-1].second=='R') {
            for(int j=vp[vp.size()-1].first;j<n;j++) {
                dominoes[j]='R';
            }
        }
        
        return dominoes;
        
    }
};