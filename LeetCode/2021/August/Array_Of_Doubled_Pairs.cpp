class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        
        map<int,int> mp;
        sort(arr.begin(),arr.end());
        
        int n=arr.size();
        
        for(int i=0;i<n;i++) {
            mp[arr[i]]++;
        }
        
        for(int i=0;i<n;i++) {
            if(mp[arr[i]]>0) {
                if(mp[arr[i]*2]>=1) {
                    mp[arr[i]*2]--;
                    mp[arr[i]]--;
                }
                
                else if(mp[arr[i]/2]>=1&&arr[i]%2==0) {
                    mp[arr[i]/2]--;
                    mp[arr[i]]--;
                }
                
                else {
                    return 0;
                }
            }
        }
        
                       
        return 1;
    }
};