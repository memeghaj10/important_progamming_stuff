/*

Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.

 

Example 1:

Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
Example 2:

Input: nums = [2,0,1]
Output: [0,1,2]
Example 3:

Input: nums = [0]
Output: [0]
Example 4:

Input: nums = [1]
Output: [1]

*/


class Solution {
public:
    void sortColors(vector<int>& a) {
        
      
        int lo=0;
        int hi=a.size()-1;
        int mid=0;
        
        while(mid<=hi) {
            
           if(a[mid]==0) {
               swap(a[lo],a[mid]);
               lo++;
               mid++;
           } 
            
           else if(a[mid]==1) {
                mid++;
            }
            
           else if(a[mid]==2) {
               swap(a[mid],a[hi]);
               hi--;
           }
            
        }
        
        
    }
};