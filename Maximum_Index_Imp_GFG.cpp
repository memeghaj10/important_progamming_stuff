/*

Maximum Index 
Medium Accuracy: 42.72% Submissions: 48951 Points: 4


Given an array A[] of N positive integers. The task is to find the maximum of j - i subjected to the constraint of A[i] <= A[j].
 

Example 1:

Input:
N = 2
A[] = {1, 10}
Output:
1
Explanation:
A[0]<=A[1] so (j-i) is 1-0 = 1.
Example 2:

Input:
N = 9
A[] = {34, 8, 10, 3, 2, 80, 30, 33, 1}
Output:
6
Explanation:
In the given array A[1] < A[7]
satisfying the required 
condition(A[i] <= A[j]) thus giving 
the maximum difference of j - i 
which is 6(7-1).
 

Your Task:
The task is to complete the function maxIndexDiff() which finds and returns maximum index difference. Printing the output will be handled by driver code.


Constraints:
1 ≤ N ≤ 107
0 ≤ A[i] ≤ 1018


Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

*/


#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution{
    public:
        
    // arr[]: input array
    // n: size of array
    // Function to find the maximum index difference.
    int maxIndexDiff(int arr[], int n) 
    { 
        
        stack<pair<int,int>> st;
        
        st.push({arr[n-1],n-1});
        
        vector<int> ans(n);
        ans[n-1]=0;
        
        for(int i=n-2;i>=0;i--) {
            
            if(st.top().first>=arr[i]) {
                ans[i]=st.top().second-i;
            }
            
            else {
                stack<pair<int,int>> sec;
                while(!st.empty()&&st.top().first<arr[i]) {
                    sec.push(st.top());
                    st.pop();
                }
                
                if(!st.empty()&&st.top().first>=arr[i]) {
                    ans[i]=st.top().second-i;
                }
                
                else {
                    st.push(make_pair(arr[i],i));
                }
                
                while(!sec.empty()) {
                    st.push(sec.top());
                    sec.pop();
                }
                
            }
            
        }
        
        return *max_element(ans.begin(),ans.end());
        
    }
};

// { Driver Code Starts.
  
/* Driver program to test above functions */
int main() 
{
    int T;
    //testcases
    cin>>T;
    while(T--){
        int num;
        //size of array
        cin>>num;
        int arr[num];
        
        //inserting elements
        for (int i = 0; i<num; i++)
            cin>>arr[i];
        Solution ob;
        
        //calling maxIndexDiff() function
        cout<<ob.maxIndexDiff(arr, num)<<endl;    
        
    }
    return 0;
}   // } Driver Code Ends