class NumArray {
public:
    
    vector<int> ar;
    vector<int> st;

    
    void build(vector<int>& st,int si,int l,int r,vector<int>& ar) {
        
        if(l==r) {
            st[si]=ar[l];
        }
        
        else {
            
            int mid=(l+r)/2;
            build(st,2*si+1,l,mid,ar);
            build(st,2*si+2,mid+1,r,ar);
            
            st[si]=st[2*si+1]+st[2*si+2];            
        }
        
    }
    
    
    void updateST(vector<int>& st,int si,int sl,int sr,int pos,int diff) {
        
        if(pos<sl||pos>sr) {
            return ;
        }
        
        st[si]+=diff;
        
        if(sl!=sr) {
            int mid=(sl+sr)/2;
        
            updateST(st,2*si+1,sl,mid,pos,diff);
            updateST(st,2*si+2,mid+1,sr,pos,diff);
        
        } 
    }
    
    int getSum(vector<int>& st,int si,int sl,int sr,int l,int r) {
        
        if(sl>=l&&sr<=r) {
            return st[si];
        }
        
        if(sr<l||sl>r) {
            return 0;
        }
        
        int mid=(sl+sr)/2;
        
        return getSum(st,2*si+1,sl,mid,l,r)+getSum(st,2*si+2,mid+1,sr,l,r);
        
    }
    
    NumArray(vector<int>& nums) {
        
        
        int n=nums.size();
        st=vector<int>(4*n);
        ar=nums;
        build(st,0,0,ar.size()-1,ar);
        
        for(int i:st) {
            cout<<i<<" ";
        }
        
    }
    
    void update(int index, int val) {
        
        int diff=val-ar[index];
        ar[index]=val;
        
        updateST(st,0,0,ar.size()-1,index,diff);
        
    }
    
    int sumRange(int left, int right) {
        
        //return 0;
        return getSum(st,0,0,ar.size()-1,left,right);
        
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */