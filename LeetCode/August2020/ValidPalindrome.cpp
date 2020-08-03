class Solution {
        public:
    bool isPalindrome(string s) {
        vector<char> v;
        for(int i=0;i<s.size();i++) {
            if(s[i]>=65&&s[i]<=90) {
                v.push_back(s[i]+32);
            }
            
            else if(s[i]>=97&&s[i]<=122) {
                v.push_back(s[i]);
            }
            
            else if(s[i]>=48&&s[i]<=57) {
                v.push_back(s[i]);
            }
        }


       string a="",b="";


       for(int i=0;i<v.size();i++) {
        a+=v[i];
       }

       for(int j=v.size()-1;j>=0;j--) {
        b+=v[j];
       }

       if(a==b) {
        return true;
       }

       else {
        return false;
       }
       
    }
};