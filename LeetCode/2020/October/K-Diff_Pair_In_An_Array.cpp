class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        
        map<int,int> mp;
        
        
        for(int i=0;i<nums.size();i++) {
            mp[nums[i]]++;
        }
        
        int c=0;
        
        sort(nums.begin(),nums.end());
        
        set<pair<int,int>> s;
        
        for(int i=0;i<nums.size();i++) {
           if(nums[i]!=-10) {
                if(k!=0) {
                    if(mp[k+nums[i]]>0) {
                        pair<int,int> p;
                         p = make_pair(nums[i],k+nums[i]);
                        
                        if(s.find(p)==s.end()) {
                            s.insert(p);
                            c++;
                             mp[k+nums[i]]--;
                            mp[nums[i]]--;
                             nums[i]=-10;
                        }
                    }
                }
               
                else if(k==0) {
                    
                    pair<int,int> p;
                    p = make_pair(nums[i],k+nums[i]);
                    
                    if(s.find(p)==s.end()) {
                        
                        if(mp[nums[i]]>=2) {
                        s.insert(p);
                        mp[nums[i]]-=2;
                        nums[i]=-10;                        
                        c++;
                        }
                    }
                }
               
           }
        }
        
        
    return c;
        
        
    }
};