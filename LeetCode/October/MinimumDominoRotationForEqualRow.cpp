class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        
        map<int,int> mp;
        
        for(int i=0;i<A.size();i++) {
            mp[A[i]]++;
            mp[B[i]]++;
        }
        
        
        vector<int> v;
        
        for(auto x:mp) {
          //  cout<<x.first<<" "<<x.second<<endl;
            if(x.second>=A.size()) {
              //  cout<<x.first<<endl;
                int y=0;
                int v1=0;
                int flag=0;
                for(int i=0;i<A.size();i++) {
                    if(A[i]==x.first&&B[i]!=x.first) {
                        y++;
                    }
                    else if(A[i]!=x.first&&B[i]==x.first) {
                       v1++;
                    }
                    else if(A[i]!=x.first&&B[i]!=x.first) {
                        flag=1;
                        break;
                    }
                }
                if(flag==0) {
                 //   cout<<v1<<" "<<y;
                    v.push_back(min(v1,y));
                }
            }
        }
        
        if(v.size()==0) {
            return -1;
        }
        
        return *min_element(v.begin(),v.end());
    
        
    }
};