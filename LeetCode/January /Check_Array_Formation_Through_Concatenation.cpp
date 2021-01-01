class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        
        int n=arr.size();
        int ans=1;
        
        vector<int> aux(n,0);
        
        for(int i=0;i<pieces.size();i++) {
            
            int k=pieces[i].size();
            
            int find=0;
            
            for(int j=0;j<n;j++) {
                if(arr[j]==pieces[i][0]) {
                    if(j+k-1<n) {
                        vector<int> f;
                        for(int g=j;g<=j+k-1;g++) {
                            f.push_back(arr[g]);
                        }
                        if(f==pieces[i]) {
                            ans*=1;
                            find=1;
                        }
                        else {
                            ans*=0;
                        }
                    }
                    else {
                        ans*=0;
                        break;
                    }
                }
            }
            
            ans*=find;
        }
        
        return ans;
        
    }
};