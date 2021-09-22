class Solution {
public:
    int ans;
    int max_poss;
    
    void recur(int i,string s,vector<string> arr) {
        
           if(ans==max_poss) {
               return ;
           }
        
            bool _isvalid=isValid(s);
        
            if(_isvalid) {
                ans=max(ans,(int)s.size());
            }
        
            if(i==arr.size()||!_isvalid) {
                return;
            }
        
            for(int i1=i;i1<arr.size();i1++) {
                recur(i1+1,s+arr[i1],arr);
            }
    }
    
    bool isValid(string s) {
            
        set<char> st;
        
        for(char c:s) {
            if(st.find(c)!=st.end()) {
                return 0;
            }
            st.insert(c);
        }
        
        return 1;
        
    }
    
    
    
    int maxLength(vector<string>& arr) {
        
        ans=0;
        max_poss=0;
        int n=arr.size();
        
        for(auto s:arr) {
            max_poss+=s.size();
        }
       
        recur(0,"",arr);
        
        return ans;
    }
};