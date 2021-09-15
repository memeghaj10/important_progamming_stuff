class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        vector <int> bigEven(arr.size(),1);
        vector <int> bigOdd(arr.size(), 1);
        
        for (int i=1; i<arr.size(); ++i){          
            if (arr[i]==arr[i-1]) continue; //note: in this case, bigEven[i] == bigOdd[i] == 1
            if (arr[i]>arr[i-1]) bigEven[i] = bigOdd[i-1] + 1; //note: bigOdd[i] remains 1
            else bigOdd[i] = bigEven[i-1] + 1; //case arr[i]<arr[i-1]
        }    
        return max(*max_element(bigEven.begin(), bigEven.end()), *max_element(bigOdd.begin(), bigOdd.end()));
    }
};