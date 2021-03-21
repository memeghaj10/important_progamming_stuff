class Solution {
public:
    bool reorderedPowerOf2(int N) {
        
        vector<string> v;
        
        for(int i=0;i<=32;i++) {
            long long int p=pow(2,i);
            v.push_back(to_string(p));
        }
        
        string r=to_string(N);
        
        for(int i=0;i<v.size();i++) {
            string y=v[i];
            sort(y.begin(),y.end());
            string x=r;
            sort(x.begin(),x.end());
            
            if(x==y) {
                return 1;
            }
        }
        
        return 0;
    }
};