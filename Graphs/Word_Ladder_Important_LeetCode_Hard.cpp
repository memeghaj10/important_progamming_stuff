/*

A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:

Every adjacent pair of words differs by a single letter.
Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
sk == endWord
Given two words, beginWord and endWord, and a dictionary wordList, return the number of words in the shortest transformation sequence from beginWord to endWord, or 0 if no such sequence exists.

 

Example 1:

Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
Output: 5
Explanation: One shortest transformation sequence is "hit" -> "hot" -> "dot" -> "dog" -> cog", which is 5 words long.
Example 2:

Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
Output: 0
Explanation: The endWord "cog" is not in wordList, therefore there is no valid transformation sequence.
 

Constraints:

1 <= beginWord.length <= 10
endWord.length == beginWord.length
1 <= wordList.length <= 5000
wordList[i].length == beginWord.length
beginWord, endWord, and wordList[i] consist of lowercase English letters.
beginWord != endWord
All the words in wordList are unique.

*/



class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        int n=wordList.size();
        
        set<string> st;
        
        for(int i=0;i<n;i++) {
            st.insert(wordList[i]);
        }
        
        queue<string> q1,q2;
        
        int c=0;
        
        if(st.find(endWord)==st.end()) {
            return 0;
        }
        
        q1.push(beginWord);
        
        while(!q1.empty()) {
            
            string r=q1.front();
            q1.pop();
            
            if(q1.empty()) {
                c++;
            }
            
            if(endWord==r&&!q1.empty()) {
                return c+1;
            }
            
            else if(endWord==r&&q1.empty()) {
                return c;
            }
                       
            
            
            for(int i=0;i<r.size();i++) {
                string temp=r;
               for(char c1='a';c1<='z';c1++) {
                        temp[i]=c1;
                        string g=temp;
                       // cout<<g<<endl;
                        if(st.find(g)!=st.end()) {
                            q2.push(g);
                            st.erase(g);
                        }
                    
                }
                
            }
            
            if(q1.empty()) {
              
                while(!q2.empty()) {
                    q1.push(q2.front());
                    q2.pop();
                }
            }            
            
        }
        
        
        return 0;
    }
};