class Solution {
public:
    
    
    bool static cmp(const int &a,const int &b) {
        string x=to_string(a);
        string y=to_string(b);
        
        return x+y>y+x;
    }
    
    string largestNumber(vector<int>& nums) {
        
        if(nums.size()==0) {
            return "";
        }
        
        sort(nums.begin(),nums.end(),cmp);
        
        string res;
        
        for(auto x:nums) {
            res+=to_string(x);
        }
        
        while(res[0]=='0'&&res.size()>=2) {
            res.erase(res.begin());
        }
        
        return res;
        
        
    }
};