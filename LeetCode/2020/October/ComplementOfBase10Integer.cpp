class Solution {
public:
    int bitwiseComplement(int N) {
        
        if(N==0) {
            return 1;
        }
        
        int y = log2(N)+1;
        
        return ((1<<y)-1)^N;
        
    }
};