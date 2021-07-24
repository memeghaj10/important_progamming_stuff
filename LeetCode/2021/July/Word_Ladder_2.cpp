class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        
        int n=wordList.size();
        
        set<string> st;
        
        for(int i=0;i<n;i++) {
            st.insert(wordList[i]);
        }
        
        vector<vector<string>> ans;
        
        if(st.find(endWord)==st.end()) {
            return ans;
        }
        
        queue<vector<string>> q;
        q.push({beginWord});
        
        map<string,bool> mp;
        for(auto x:wordList) {
            mp[x]=false;
        }
        
        int f=0;
        
        while(!q.empty()) {
            
            n=q.size();
            
            while(n--) {
                
                vector<string> v=q.front();
                q.pop();
                
                string r=v.back();
                mp[r]=true;
                
                if(r==endWord) {
                    f=1;
                    ans.push_back(v);
                }
                
                for(int i=0;i<r.size();i++) {
                    
                    char t=r[i];
                    
                    for(char c='a';c<='z';c++) {
                        
                        if(c!=t) {
                            r[i]=c;
                            
                            if(st.find(r)!=st.end()&&mp[r]==false) {
                                
                                v.push_back(r);
                                q.push(v);
                                v.pop_back();
                                
                            }
                            
                        }
                        
                        r[i]=t;
                        
                    }
                    
                }
                
                
            }
            
            if(f) {
                break;
            }
            
        }
        
        return ans;
         
    }
};