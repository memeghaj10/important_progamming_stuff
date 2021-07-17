class Solution {
public:
    vector<int> threeEqualParts(vector<int>& arr) {
        int count = 0;
        for (auto i:arr)
        {
            if(i == 1)
                count++;
        }
        if(count == 0)
            return {0,2};
        if(count%3 != 0)
            return {-1,-1};
        int p1 = 0;
        int p2 = 0;
        int p3 = 0;
        count = count/3;
        int temp = 0;
        for(int i = 0;i<arr.size();i++)
        {  if(arr[i] == 1)
          { if(temp == 0)
              p1 = i;
            else if(temp == count)
                p2 = i;
             else if(temp == 2*count)
                p3 = i;
           temp++;
          }
        
        }

        int oldp2 = p2;
        int oldp3 = p3;
        while(p1<oldp2 and p2<oldp3 and p3<arr.size())
        {
            if(arr[p1] != arr[p2] or arr[p2] != arr[p3])
                return {-1,-1};
            p1++;
            p2++;
            p3++;
        }
        if(p3 == arr.size())
        {
            return {p1-1,p2};
        }
        return {-1,-1};
    }
};