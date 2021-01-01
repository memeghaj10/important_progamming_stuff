class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        
       //ort(timeSeries.begin(),timeSeries.end());
        
        if(timeSeries.size()==0) {
            return 0;
        }
        
       
        
        int c=0;
        
       int y=timeSeries[0];
        
        for(int i=1;i<timeSeries.size();i++) {
            if(y+duration-1>=timeSeries[i]) {
                c+=(timeSeries[i]-timeSeries[i-1]);
                y=timeSeries[i];
            }
            
            else {
                c+=(duration);
                y=timeSeries[i];
            }
        
        }
        
        c+=(duration);
        
        return c;
    }
};