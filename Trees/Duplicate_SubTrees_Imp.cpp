/*

Given a binary tree of size N, your task is to that find all duplicate subtrees from the given binary tree.

Example:

Input : 

Output : 2 4
         4
Explanation: Above Trees are two 
duplicate subtrees.i.e  and 
Therefore,you need to return above trees 
root in the form of a list.
Your Task:
You don't need to take input. Just complete the function printAllDups() that takes the root node as a parameter and returns an array of Node*, which contains all the duplicate subtree.
Note: Here the Output of every Node printed in the Pre-Order tree traversal format.


Constraints:
1<=T<=100
1<=N<=100

*/


#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
}; 

// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}

void preorder(Node* root){
    if(!root){
        return ;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}


 // } Driver Code Ends
//function Template for C++

/*
Structure of the node of the binary tree is as
struct Node {
	int data;
	struct Node* left, *right;
};
*/
// you are required to complete this function
// the function and return an vector of Node
// which contains all the duplicate sub-tree

    vector<Node*> ans;
    
    string dfs(Node* root,map<string,bool>& mp) {
        
        if(!root) {
            return "$";
        }
        
        string s="$"+to_string(root->data);
        s+="$";
        s+=dfs(root->left,mp);
        s+="$";
        s+=dfs(root->right,mp);
        
        if(mp.find(s)==mp.end()) {
            mp[s]=false;
        }
        
        else {
           if(mp[s]==false) {
                ans.push_back(root);
           }
            mp[s]=true;
        }
        
        return s;
    }

vector<Node*> printAllDups(Node* root)
{
        map<string,bool> mp;
        
        dfs(root,mp);
        vector<Node*> r=ans;
        ans.clear();
        return r;
}

// { Driver Code Starts.
int main()
{
    int t;
	scanf("%d ",&t);
    while(t--)
    {
        string treeString;
		getline(cin,treeString);
		Node* root = buildTree(treeString);
		vector<Node*> res = printAllDups(root);
		
		for(int i=0;i<res.size();i++){
		    preorder(res[i]);
		    cout<<endl;
		}
    }
    return 0;
}


  // } Driver Code Ends