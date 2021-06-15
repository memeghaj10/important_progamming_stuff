class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        
        int sum=0;
        sum=accumulate(matchsticks.begin(),matchsticks.end(),0);
        
        if(sum%4!=0) {
            return false;
        }
        
        int x=sum/4;
        
        int n=matchsticks.size();
        
        if(n<4) {
            return false;
        }
        
        vector<int> vis(n,0);
        
        return backtrack(matchsticks,vis,x,0,0,4);
        
    }
    
    bool backtrack(vector<int>& matchsticks,vector<int> visited,int target,int curr_sum,int i,int k) {
        
        if(k==1) {
            return true;
        }
        
        if(curr_sum==target) {
            return backtrack(matchsticks,visited,target,0,0,k-1);
        }
        
        for(int j=i;j<matchsticks.size();j++) {
            
            if(visited[j]||curr_sum+matchsticks[j]>target) {
                continue;
            }
            
            visited[j]=1;
            if(backtrack(matchsticks,visited,target,curr_sum+matchsticks[j],j+1,k)) {
                return true;
            }
            visited[j]=0;
            
        }
        
        return false;
        
    }
    
    
};