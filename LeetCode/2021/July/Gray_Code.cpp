class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result;
        result.push_back(0);
        
        unordered_set<int> isPresent;
        
        isPresent.insert(0);
        grayCodeHelper(result,n,isPresent);
        
        return result;
        
    }
    
    
private:
    
    bool grayCodeHelper(vector<int> &result, int n,unordered_set<int> &isPresent) {
        
        if(result.size()==(1<<n)) {
            return true;
        }
        
        int current=result[result.size()-1];
        for(int i=0;i<n;i++) {
            
            int next=current^(1<<i);
            if(isPresent.find(next)==isPresent.end()) {
                isPresent.insert(next);
                result.push_back(next);
                
                if(grayCodeHelper(result,n,isPresent)) {
                    return true;
                }
                
                isPresent.erase(next);
                result.pop_back();
            }
            
        }
        
        return false;
        
    }
    
};
