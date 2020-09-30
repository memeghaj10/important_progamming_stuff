class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        
        vector<string> vs;
        
        for(int i=1;i<=8;i++) {
            string s="";
            s+=('0'+i);
            
            for(int j=i+1;j<=9;j++) {
                s+=('0'+j);
                vs.push_back(s);
            }         
        }
        
        vector<int> v;
        
        for(int i=0;i<vs.size();i++) {
            v.push_back(stoi(vs[i]));
        }
        
        sort(v.begin(),v.end());
        
        vector<int> vp;
        
        for(int i=0;i<v.size();i++) {
            if(v[i]>=low&&v[i]<=high) {
                vp.push_back(v[i]);
            }
        }
        
        
        return vp;       
        
    }
};