class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        
        sort(products.begin(),products.end());
        
        string s="";
        
        int i=0;
        
        vector<vector<string>> ans;
        
        while(i<searchWord.size()) {
            
            s+=searchWord[i];
            i++;
            
            vector<string> temp;
            
            auto it=lower_bound(products.begin(),products.end(),s);
            
            int u=3;
            
            while(it!=products.end()&&u>0) {
                string r=*it;
                if(r.substr(0,s.size())!=s) {
                    break;
                }
                temp.push_back(*it);
                it++;
                u--;
            }
            
            ans.push_back(temp);
            
        }
        
        return ans;
        
    }
};