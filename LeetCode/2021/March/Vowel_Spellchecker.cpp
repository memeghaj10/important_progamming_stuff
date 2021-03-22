class Solution {
public:
    
    string lower(string s) {
        string g="";
        for(int i=0;i<s.size();i++) {
            if(s[i]<96) {
                g+=s[i]+32;
            }
            else {
                g+=s[i];
            }
        }
        return g;        
    }
    
    string vowel(string s) {
        
            string g=lower(s);
        
            string h="";
        
            for(int i=0;i<g.size();i++) {
                if(g[i]=='a'||g[i]=='e'||g[i]=='i'||g[i]=='o'||g[i]=='u') {
                    h+='*';
                }
                else {
                    h+=g[i];
                }
            }
        
        return h;
        
    }
    
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        
        int n=wordlist.size();
        int m=queries.size();
        
       map<string,vector<string>> mp1;
        map<string,vector<string>> mp2;
        
        vector<string> answer(m);
        
        for(int i=0;i<n;i++) {
            mp1[lower(wordlist[i])].push_back(wordlist[i]);
            mp2[vowel(wordlist[i])].push_back(wordlist[i]);
        }
        
        
        for(int i=0;i<m;i++) {
            string r="";
            if(mp1.find(lower(queries[i]))!=mp1.end()) {
                vector<string> v=mp1[lower(queries[i])];
                if(find(v.begin(),v.end(),queries[i])!=v.end()) {
                    r=queries[i];
                }
                else {
                    r=mp1[lower(queries[i])][0];
                }
            }
            
            else if(mp2.find(vowel(queries[i]))!=mp2.end()) {
                vector<string> v=mp2[vowel(queries[i])]; 
                if(find(v.begin(),v.end(),queries[i])!=v.end()) {
                    r=queries[i];
                }
                else {
                    r=mp2[vowel(queries[i])][0];
                }
            }
            
            answer[i]=r;
        }
        
        return answer;
        
    }
};