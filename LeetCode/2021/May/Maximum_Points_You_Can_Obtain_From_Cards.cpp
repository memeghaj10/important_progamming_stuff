class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        
        int sum=accumulate(cardPoints.begin(),cardPoints.end(),0);
        
        int n=cardPoints.size();
        
        int w=0;
        
        for(int i=0;i<n-k;i++) {
            w+=cardPoints[i];
        }
        
        int prev=0;
        
        int ans=sum-w;
        
        for(int i=n-k;i<cardPoints.size();i++) {
            w-=cardPoints[prev];
            prev++;
            w+=cardPoints[i];
            ans=max(ans,sum-w);
        }
        
        return ans;
        
    }
};