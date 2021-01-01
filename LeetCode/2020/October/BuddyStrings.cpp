class Solution {
public:
    bool buddyStrings(string A, string B) {
        
        if(A.size()!=B.size()) {
            return false;
        }
        
        
        else {
            
            int cnt=0;
            
            for(int i=0;i<A.size();i++) {
                if(A[i]!=B[i]) {
                    cnt++;
                }
            }
          
            if(cnt!=2 and cnt!=0) {
                return false;
            }
            
           if(A==B) {
                map<char,int> mp;
            
            int f=1;
            
            for(int i=0;i<A.size();i++){
                mp[A[i]]++;s
                if(mp[A[i]]>1) {
                    return true;
                    
                    
                }
            }
            
               
               if(f==1) {
                   return false;
               }
           }
            //char a='0',b='0',c='0',d='0';
            
           vector<int> id;
            
            for(int i=0;i<A.size();i++) {
                if(A[i]!=B[i]) {
                    id.push_back(i);
                }
            }
            
            
            return id.size()==2&&A[id[0]]==B[id[1]]&&A[id[1]]==B[id[0]];
            
            
        }
        
    }
};