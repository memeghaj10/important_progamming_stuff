class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
      
        set<int> st;
        
        for(auto s:deadends) {
            st.insert(stoi(s));
        }
        
        queue<pair<int,int>> q;
        q.push({0,0});
        
        vector<int> vis(10000,0);
        vis[0]=1;
        
        while(!q.empty()) {          
                
                int node=q.front().first;
                int level=q.front().second;
                q.pop();
            
                if(st.find(node)!=st.end()) {
                    continue;
                }
            
                string r=to_string(node);
                
                string x="0000"+r;
                while(x.size()>4) {
                    x.erase(x.begin());
                }
            
                if(x==target) {
                    return level;
                }
                
            
                for(int i=0;i<x.size();i++) {
                    
                    int num=x[i]-'0';
                    int n1=(num+1==10)?0:num+1;
                    int n2=(num-1==-1)?9:num-1;
                 
                    string s1,s2;
                    
                    s1=x;
                    s2=x;
                    
                    s1[i]='0'+n1;
                    s2[i]='0'+n2;
                    
                    if(!vis[stoi(s1)]) {
                        q.push({stoi(s1),level+1});
                        vis[stoi(s1)]=1;
                    }
                    
                    if(!vis[stoi(s2)]) {
                        q.push({stoi(s2),level+1});
                        vis[stoi(s2)]=1;
                    }
                    
                }           
                        
        }
        
        return -1;
        
    }
};