class Solution {
public:
   unordered_map<string,bool> memoize;
    bool recursion(string s,unordered_set<string> &dict){
        if(dict.count(s))return true;
        if(memoize.count(s)) return memoize[s];
        for(int i=0;i<s.size();i++){
            if(dict.count(s.substr(0,i+1)) && recursion(s.substr(i+1),dict)){
                // memoize[s]=true;
                return true;
            }
        }
        memoize[s]=false;
        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict;
        for(string i:wordDict){
            dict.insert(i);
        }
        return recursion(s,dict);
        
    }
};