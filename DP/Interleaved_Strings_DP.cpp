#include <bits/stdc++.h>
using namespace std;

bool isInterleave(string A, string B, string C);
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		string a,b,c;
		cin>>a;
		cin>>b;
		cin>>c;
		cout<<isInterleave(a,b,c)<<endl;
	}
	// your code goes here
	return 0;
}// } Driver Code Ends


/*You are required to complete this method */
bool isInterleave(string A, string B, string C) 
{
    int m=A.size();
    int n=B.size();
    
    if(m+n!=C.size()) {
        return false;
    }
    
    int dp[m+1][n+1];
    
    memset(dp,0,sizeof(dp));
    
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++) {
            if(i==0&&j==0){
                dp[i][j]=1;
            }
            
            else if(i==0) {
                if(B[j-1]==C[j-1]) {
                    dp[i][j]=dp[i][j-1];
                }
            }
            
            else if(j==0) {
                if(A[i-1]==C[i-1]) {
                    dp[i][j]=dp[i-1][j];
                }
            }
            
            
                
                
             else if(A[i-1]==C[i+j-1]&&B[j-1]!=C[i+j-1]) {
                    dp[i][j]=dp[i-1][j];
                }
                
            else if(A[i-1]!=C[i+j-1]&&B[j-1]==C[i+j-1]) {
                    dp[i][j]=dp[i][j-1];
                }
                
            else if(A[i-1]==C[i+j-1]&&B[j-1]==C[i+j-1]) {
                    dp[i][j]=(dp[i-1][j]||dp[i][j-1]);
                }
                
            
            
        }
    }
    
    return dp[m][n];
}
