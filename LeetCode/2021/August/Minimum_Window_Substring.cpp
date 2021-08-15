class Solution {
public:
    string minWindow(string s, string t) {
        int len = INT_MAX,start = 0,j=0,count=t.length();
        vector<int> now(125);
        for(auto c:t)
            now[c]++;
        for(int i=0;i<s.length();i++){
            if(now[s[i]]>0)
                count--;
            now[s[i]]--;
            while(!count and i>=j){
                if(i-j+1<len){
                    len = i - j + 1;
                    start = j;
                }
                now[s[j]]++;
                if(now[s[j++]]>0)
                    count++;
            }
            
        }
        return (len==INT_MAX)?"":s.substr(start,len);
    }
};