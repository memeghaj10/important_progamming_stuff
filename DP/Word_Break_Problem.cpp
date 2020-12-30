//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

int wordBreak(string A, vector<string> &B);

// User code will be pasted here

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        cout<<wordBreak(line, dict)<<"\n";
    }
}
// } Driver Code Ends


//User function template for C++

// A : given string to search
// B : vector of available strings

int wordBreak(string A, vector<string> &B) {
   
   if(A.size()==0) {
       return 1;
   }
   
   int n=A.size();
   
   int dp[n+1];
   
   memset(dp,0,sizeof(dp));
   
   vector<int> trav_index;
   
   trav_index.push_back(-1);
   
   for(int i=0;i<n;i++) {
       int f=0;
       
      for(int j=trav_index.size()-1;j>=0;j--) {
          string h=A.substr(trav_index[j]+1,i-trav_index[j]);
          
          for(int l=0;l<B.size();l++) {
              if(B[l]==h) {
                  f=1;
                  break;
              }
          }
      }
      
      if(f==1) {
          dp[i]=1;
          trav_index.push_back(i);
      }
       
   }
   
   
   return dp[n-1];
   
}