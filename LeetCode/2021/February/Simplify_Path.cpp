class Solution {
public:
    string simplifyPath(string path) {
        string s="";
        stack<string> st;
        for(int i=1;i<path.length();i++){
           while(path[i]!='/'&&i<path.length()){
               s+=path[i];
               i++;
           }          
            
            if(s==".."){
                    
                    if(!st.empty())
                    st.pop();
                 s="";   
                }
                if(s=="."){
                 s="";
                    continue;        
                }
                    
            if(s!=""){
                st.push(s);
            }
           s="";
        }
        string ans="";
        if(st.size()>0){
            stack<string> rev;
            
        while(!st.empty()){
            rev.push(st.top());
            st.pop();
        }
    
            while(!rev.empty()){
            ans+="/"+rev.top();
            rev.pop();
        }
        return ans;
        }
    
        return "/";
    }
};