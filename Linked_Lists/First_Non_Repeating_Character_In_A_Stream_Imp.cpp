/*

Given an input stream of A of n characters consisting only of lower case alphabets. The task is to find the first non repeating character, each time a character is inserted to the stream. If there is no such character then append '#' to the answer.
 

Example 1:

Input: A = "aabc"
Output: "a#bb"
Explanation: For every character first non
repeating character is as follow-
"a" - first non-repeating character is 'a'
"aa" - no non-repeating character so '#'
"aab" - first non-repeating character is 'b'
"aabc" - first non-repeating character is 'b'
Example 2:

Input: A = "zz"
Output: "z#"
Explanation: For every character first non
repeating character is as follow-
"z" - first non-repeating character is 'z'
"zz" - no non-repeating character so '#'
 

Your Task:
You don't need to read or print anything. Your task is to complete the function FirstNonRepeating() which takes A as input parameter and returns a string after processing the input stream.
 

Expected Time Complexity: O(26 * n)
Expected Space Complexity: O(26)
 

Constraints:
1 <= n <= 105

*/

class Solution {
	public:
	
	    struct Node {
          int data;
          struct Node *next;
          Node(int x) {
            data = x;
            next = NULL;
          }
        };
	
		string FirstNonRepeating(string A){
		   
		   Node* p=new Node(-1);
		   set<int> st;
		   
		   string ans="";
		   
		   for(int i=0;i<A.size();i++) {
		       
		       int c=A[i]-'a';
		       
		        Node* curr=p;
		        
		        int f=0;
		        
		        while(curr&&curr->next) {
		            if(curr->next->data==c) {
		                curr->next=curr->next->next;
		                f=1;
		                break;
		            }
		            curr=curr->next;
		        }
		        
		        if(!f&&st.find(c)==st.end()) {
		            Node* t=new Node(c);
		            curr->next=t;
		            st.insert(c);
		        }
		        
		        if(p->next==NULL) {
		            ans+='#';
		        }
		        
		        else {
		            ans+=('a'+p->next->data);
		        }
		       
		   }
		   
		   return ans;
		  
		  
		}

};