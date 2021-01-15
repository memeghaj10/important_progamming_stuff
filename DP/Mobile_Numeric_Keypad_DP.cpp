#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution{


	public:
	long long getCount(int n)
	{
	    
	    
	        
        char keypad[4][3] = {{'1','2','3'},
                            {'4','5','6'},
                            {'7','8','9'},
                            {'*','0','#'}};
	        
	    
	    if(keypad==NULL||n<=0) {
                return 0;
            }

            if(n==1) {
                return 10;
            }

            int r[] = {0,-1,0,1,0};
            int c[] = {0,0,-1,0,1};

           long long int dp[10][n+1];

            for(int i=0;i<=9;i++) {
                dp[i][0]=0;
                dp[i][1]=1;
            }


            for(int k=2;k<=n;k++) {

                for(int i=0;i<4;i++) {
                    for(int j=0;j<3;j++) {

                        if(keypad[i][j]!='*'&&keypad[i][j]!='#') {


                            int num=keypad[i][j]-'0';
                            dp[num][k]=0;


                            for(int move=0;move<5;move++) {

                                int ro=r[move]+i;
                                int co=c[move]+j;

                                if(ro<=3&&ro>=0&&co>=0&&co<=2&&keypad[ro][co]!='*'&&keypad[ro][co]!='#') {
                                    int nextNum=keypad[ro][co]-'0';
                                    dp[num][k]+=dp[nextNum][k-1];
                                }

                            }

                        }

                    }
                }

            }



            long long total=0;

            for(int i=0;i<=9;i++) {
                total+=dp[i][n];
            }

            return total;

	}


};

// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

       

	    Solution ob;
	    cout << ob.getCount(n) << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends