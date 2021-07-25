class Solution {
private:
    int countValidInteger(int number,int limit){
        if(number>limit) return 0;
        
        if(number & 1){
            return 1 + countValidInteger((number << 1) | 0, limit);
        }else{
            return 1 + countValidInteger((number << 1) | 0, limit) + countValidInteger((number << 1) | 1, limit);
        }
    }
public:
    int findIntegers(int n) {
        return 1+countValidInteger(1,n);
    }
};