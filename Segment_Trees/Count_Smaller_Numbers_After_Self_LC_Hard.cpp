/*

You are given an integer array nums and you have to return a new counts array. The counts array has the property where counts[i] is the number of smaller elements to the right of nums[i].

 

Example 1:

Input: nums = [5,2,6,1]
Output: [2,1,1,0]
Explanation:
To the right of 5 there are 2 smaller elements (2 and 1).
To the right of 2 there is only 1 smaller element (1).
To the right of 6 there is 1 smaller element (1).
To the right of 1 there is 0 smaller element.
Example 2:

Input: nums = [-1]
Output: [0]
Example 3:

Input: nums = [-1,-1]
Output: [0,0]
 

Constraints:

1 <= nums.length <= 105
-104 <= nums[i] <= 104

*/


/*


Solution:


For a particular element in nums, located at index i, we want to count how many of the numbers on the right side of index i are smaller than nums[i]. Notice that the value of the smaller numbers must be in the range (-\infty, \text{nums[i]}-1](−∞,nums[i]−1].

Hence, if we can find the count of each number in the range (-\infty, \text{nums[i]}-1](−∞,nums[i]−1] on the right side of index i, then the answer will be the sum of those counts.

Therefore, for each index i, we need a query to find the sum of those counts. Recall that the segment tree and the binary indexed tree are two data structures that are generally helpful when solving range query problems.

Since we need counts of values, we can use an approach similar to bucket sort, where we have buckets of values and buckets[value] stores the count of value. For each value, we increment buckets[value] by 1. With this approach, the number of elements smaller than nums[i] is the range sum of (-\infty, \text{num}-1](−∞,num−1] in buckets.

With the help of a segment tree or binary indexed tree, we can perform the range sum query in logarithmic time.



With the given constraint -10^4 <= nums[i] <= 10^4, we can initialize buckets from -10^4 to 10^4.

Wait, there is a problem: Usually, we store buckets in an array, so the indices of buckets are non-negative. However, here we need to store some negative values. How can we resolve this problem?

There are two solutions:

Use a map rather than an array.
Shift all numbers to non-negative.
Both solutions work, and here we have chosen the second one since it is easier to implement. Interested readers are welcome to try the first one on their own.

To shift all numbers to non-negative, we simply add a constant. Here we chose the constant offset = 10^4 and increase each number by offset:

nums[i] = nums[i] + offset
The smallest number -10^4 becomes 0 under this shift.



Note that while querying a particular index, we only need to consider elements that are on the right side of the index. Therefore we need to make sure that when we query an index, say i, only elements from index i+1 to the end of the array are present in the buckets.

To achieve this, we need to traverse nums from right to left, while performing range sum queries and updating the counts.

Similarly, with the help of a segment tree or binary indexed tree, we can perform the updates in logarithmic time.


Algorithm

Implement the segment tree. Since the tree is initialized with all zeros, only update and query need to be implemented. Set offset = 10^4.

Iterate over each num in nums in reverse. For each num:

Shift num to num + offset.
Query the number of elements in the segment tree smaller than num.
Update the count of num in the segment tree.
Return the result.

*/


class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        
        int offset=1e4;
        int size=2*1e4+1;
        vector<int> tree(size*2);
        vector<int> result;
        
        for(int i=nums.size()-1;i>=0;i--) {
            int smaller_count=query(0,nums[i]+offset,tree,size);
            result.push_back(smaller_count);
            update(nums[i]+offset,1,tree,size);
        }
        
        reverse(result.begin(),result.end());
        return result;
        
    }
    
    void update(int index,int value,vector<int>& tree,int size) {
        
        index+=size;
        tree[index]+=value;
        while(index>1) {
            index/=2;
            tree[index]=tree[index*2]+tree[index*2+1];
        }
        
    }
    
    int query(int left,int right,vector<int>& tree,int size) {
        
        int result=0;
        left+=size;
        right+=size;
        
        while(left<right) {
            
            if(left%2) {
                result+=tree[left];
                left++;
            } 
            
            left/=2;
            
            if(right%2) {
                right--;
                result+=tree[right];
            }
            
            right/=2;
            
        }
        
        return result;
    }
    
};