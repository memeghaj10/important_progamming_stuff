class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        int l1=0;
        if(x!=1) {
           l1=log(bound)/log(x);
        }
        
        int l2=0;
        
        if(y!=1) {
             l2=log(bound)/log(y);
        }
        
        set<int> st;
        
        for(int i=0;i<=l1;i++) {
            for(int j=0;j<=l2;j++) {
                if(pow(x,i)+pow(y,j)<=bound) {
                    st.insert(pow(x,i)+pow(y,j));
                }
            }
        }
        
        vector<int> v;
        
        for(auto x:st) {
            v.push_back(x);
        }
        
        return v;
        
    }
};