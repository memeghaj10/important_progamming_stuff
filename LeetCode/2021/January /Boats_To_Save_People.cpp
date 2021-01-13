class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        
        int n=people.size();
        
        int boat=0;
        
        sort(people.begin(),people.end());
        
       int i=0;
        int j=n-1;
        
        
        while(i<=j) {
            
                if(people[i]+people[j]<=limit) {
                    people[i]=-1;
                    people[j]=-1;
                    i++;
                    j--;
                    boat++;
                }
            
                else {
                    j--;                    
                }
            
        }
        
        for(int i=0;i<n;i++) {
            if(people[i]!=-1) {
                boat++;
            }
        }
        
        
        return boat;
    }
};