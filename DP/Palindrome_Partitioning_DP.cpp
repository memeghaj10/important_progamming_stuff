
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends








// User function Template for C++

class Solution{
public:
    int dp[1001][1001];
    set<string> st;
    
    bool ispalin(string s) {
        int start=0;
        int end=s.size()-1;
       while (start < end) { 
        if (s[start] != s[end]) 
            return false; 
        start++; 
        end--; 
    } 
    return true; 
    }
    
    
    int check(string s,int i,int j) {
        
        if(i>j) {
            return 0;
        }
        
        
        if(st.find(s.substr(i,j-i+1))!=st.end()) {
            return 0;
        }
        
        else {
            if(ispalin(s.substr(i,j-i+1))) {
                st.insert(s.substr(i,j-i+1));
                return 0;
            }
        }
        
        if(dp[i][j]!=-1) {
            return dp[i][j];
        }
        
        int mn=INT_MAX;
        
        for(int k=i;k<=j-1;k++) {
            int left,right;
            if(dp[i][k]!=-1) {
                left=dp[i][k];
            }
            else {
                left=check(s,i,k);
                dp[i][k]=left;
            }
            if(dp[k+1][j]!=-1) {
                right=dp[k+1][j];
            }
            else {
                right=check(s,k+1,j);
                dp[k+1][j]=right;
            }
            
            int a=left+right+1;
            
            if(a<=mn) {
                mn=a;
            }
        }
        
        return dp[i][j]=mn;
     
    }
    

    int palindromicPartition(string str)
    {
        memset(dp,-1,sizeof(dp));
        
        int n=str.size();
        return check(str,0,n-1);
        
    }
};




// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}  // } Driver Code Ends