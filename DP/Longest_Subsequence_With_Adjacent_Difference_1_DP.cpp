/*

Q: Given an array of n size, the task is to find the longest subsequence such that difference between adjacents is one.

Time Complex: O(n*n)

*/







// Initial Template for C++


#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


// User function Template for C++

class Solution{
public:
    int longestSubsequence(int n, int a[])
    {
        int dp[n];
        memset(dp,0,sizeof(dp));
        
        dp[0]=1;
        
        for(int i=1;i<n;i++)
         {
             dp[i]=1;
             for(int j=0;j<i;j++) {
                 if(abs(a[j]-a[i])==1) {
                     dp[i]=max(dp[j]+1,dp[i]);
                 }
             }
         }
        
        return *max_element(dp,dp+n);
        
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int A[N];
        for(int i = 0;i < N;i++)
            cin>>A[i];
        
        Solution ob;
        cout<<ob.longestSubsequence(N, A)<<endl;
    }
    return 0;
}  // } Driver Code Ends