class Solution {
public:
    vector<int> beautifulArray(int n) {
        vector<int> beautiful = {1}; // start with the one element
        while(beautiful.size()<n){ // loop until we get the beautiful array of desired size
            vector<int> curr;
            // first push all odd elements, then even elements
            // find all the odd numbers which is less than or equal to n
            for(auto num:beautiful){
                if(num*2-1<=n)
                    curr.push_back(num*2-1);
            }
            // find all the even numbers which is less than or equal to n
            for(auto num:beautiful){
                if(num*2<=n){
                    curr.push_back(num*2);
                }
            }
            beautiful = curr;
        }
        return beautiful;
    }
};