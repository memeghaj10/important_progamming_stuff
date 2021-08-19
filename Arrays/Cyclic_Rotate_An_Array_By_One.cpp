/*

You don't need to read input or print anything. Your task is to complete the function rotate() which takes the array A[] and its size N as inputs and modify the array.

 

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

 

Constraints:
1<=N<=105
0<=a[i]<=105

*/


//User function Template for C++

void rotate(int arr[], int n)
{
    
    int last=arr[n-1];
    
    for(int i=n-1;i>=1;i--) {
        arr[i]=arr[i-1];
    }
    
    arr[0]=last;
    
}