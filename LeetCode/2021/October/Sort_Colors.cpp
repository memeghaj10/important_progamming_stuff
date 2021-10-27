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