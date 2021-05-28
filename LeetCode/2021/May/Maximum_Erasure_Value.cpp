class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        
        int i=0;
        int j=0;
        
        int n=nums.size();
        
        if(n==1) {
            return nums[0];
        }
        
        set<int> st;
        
        int sum=0;
        int ans=nums[0];
        
        sum+=nums[i];
        
        st.insert(nums[i]);
        
        
        while(j>=i&&j+1<n)  {
            j++;
            cout<<sum<<endl;
            if(st.find(nums[j])!=st.end()) {
                
                while(nums[i]!=nums[j]) {
                    sum-=nums[i];
                    st.erase(nums[i]);
                    i++;                    
                }
                
                sum-=nums[i];
                st.erase(nums[i]);
                i++;
                
                sum+=nums[j];
                st.insert(nums[j]);
                ans=max(ans,sum);
                
            }
            
            else {                
                sum+=nums[j];
                st.insert(nums[j]);
                //j++;
                ans=max(ans,sum);
            }
            
        }       
        
        return ans;
        
        
    }
};