/*

A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:

Every adjacent pair of words differs by a single letter.
Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
sk == endWord
Given two words, beginWord and endWord, and a dictionary wordList, return all the shortest transformation sequences from beginWord to endWord, or an empty list if no such sequence exists. Each sequence should be returned as a list of the words [beginWord, s1, s2, ..., sk].

 

Example 1:

Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
Output: [["hit","hot","dot","dog","cog"],["hit","hot","lot","log","cog"]]
Explanation: There are 2 shortest transformation sequences:
"hit" -> "hot" -> "dot" -> "dog" -> "cog"
"hit" -> "hot" -> "lot" -> "log" -> "cog"
Example 2:

Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
Output: []
Explanation: The endWord "cog" is not in wordList, therefore there is no valid transformation sequence.
 

Constraints:

1 <= beginWord.length <= 5
endWord.length == beginWord.length
1 <= wordList.length <= 1000
wordList[i].length == beginWord.length
beginWord, endWord, and wordList[i] consist of lowercase English letters.
beginWord != endWord
All the words in wordList are unique.

*/



class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        
        int n=wordList.size();
        
        set<string> st;
        
        for(int i=0;i<n;i++) {
            st.insert(wordList[i]);
        }
        
        vector<vector<string>> ans;
        
        if(st.find(endWord)==st.end()) {
            return ans;
        }
        
        queue<vector<string>> q;
        q.push({beginWord});
        
        map<string,bool> mp;
        for(auto x:wordList) {
            mp[x]=false;
        }
        
        int f=0;
        
        while(!q.empty()) {
            
            n=q.size();
            
            while(n--) {
                
                vector<string> v=q.front();
                q.pop();
                
                string r=v.back();
                mp[r]=true;
                
                if(r==endWord) {
                    f=1;
                    ans.push_back(v);
                }
                
                for(int i=0;i<r.size();i++) {
                    
                    char t=r[i];
                    
                    for(char c='a';c<='z';c++) {
                        
                        if(c!=t) {
                            r[i]=c;
                            
                            if(st.find(r)!=st.end()&&mp[r]==false) {
                                
                                v.push_back(r);
                                q.push(v);
                                v.pop_back();
                                
                            }
                            
                        }
                        
                        r[i]=t;
                        
                    }
                    
                }
                
                
            }
            
            if(f) {
                break;
            }
            
        }
        
        return ans;
         
    }
};