/*

Given an integer array nums and two integers lower and upper, return the number of range sums that lie in [lower, upper] inclusive.

Range sum S(i, j) is defined as the sum of the elements in nums between indices i and j inclusive, where i <= j.

 

Example 1:

Input: nums = [-2,5,-1], lower = -2, upper = 2
Output: 3
Explanation: The three ranges are: [0,0], [2,2], and [0,2] and their respective sums are: -2, -1, 2.
Example 2:

Input: nums = [0], lower = 0, upper = 0
Output: 1



Constraints:

1 <= nums.length <= 104
-231 <= nums[i] <= 231 - 1
-3 * 104 <= lower <= upper <= 3 * 104



*/



/*

hint:-

let sums[k]=sum_of_all_elements[0,k];

thus we have to calcualte count of lower <= (sums[i]-sums[j]) <= upper

it can be re-written as :  lower+sums[j] <= sums[i] <=upper+sums[j];

so count_of_such_sums[i] over all possible j's is the asnwer.



*/


class SegTree {
    
public:
    long min;
    long max;
    int count;
    SegTree *left;
    SegTree *right;
    
    SegTree (long min,long max,int count) {
        this->min=min;
        this->max=max;
        this->count=count;
        left=right=NULL;
    }
    
};



class Solution {

    SegTree *root;
    
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
     
        
        int n=nums.size();
            
        if(!n) {
            return 0;
        }
        
        unordered_set<long> st;
        
        long tmpsum=0;
        
        vector<long> sums;
        
        for(auto num:nums) {        //calculating distinct prefix sums, from the array.
            tmpsum+=num;
            st.insert(tmpsum);
        }
        
        for(auto x:st) {
            sums.push_back(x);
        }
        
        sort(sums.begin(),sums.end());
        
        root=build(sums,0,sums.size()-1);
        
        int count=0;
        
        for(int i=nums.size()-1;i>=0;i--) {
            modify(root,tmpsum);
            tmpsum-=nums[i];
            count+=query(root,lower+tmpsum,upper+tmpsum);
        }
        
        return count;
    }
    
    
    SegTree* build(vector<long> &sums,int start,int end) {
        SegTree *root=new SegTree(sums[start],sums[end],0);
        
        if(start==end) {
            return root;
        }
        
        else {
            int mid=(start+end)/2;
            root->left=build(sums,start,mid);
            root->right=build(sums,mid+1,end);
            return root;
        }
    }
    
    
    void modify(SegTree *root,long value) {
        if(root==NULL||value<root->min||value>root->max) {
                return;
        }
        
        root->count++;
        
        if(root->min==root->max) {
            return ;
        }
        
        else {
            modify(root->left,value);
            modify(root->right,value);
        }
    }
    
    int query(SegTree *root,long min,long max) {
        
        if(root==NULL||max<root->min||min>root->max) {
            return 0;
        }
        if(min<=root->min&&max>=root->max) {
            return root->count;
        }
        return query(root->left,min,max)+query(root->right,min,max);
        
    }
    
};