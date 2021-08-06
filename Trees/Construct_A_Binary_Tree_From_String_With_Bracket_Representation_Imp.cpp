
/*

Given a string s consisting of parentheses {‘(‘ and ‘)’} and integers, the task is to construct a Binary Tree from it and print its Preorder traversal.

Examples:

Input: S = “1(2)(3)”
Output: 1 2 3
Explanation: The corresponding binary tree is as follows:
            1
          /   \                      
        2     3                       

Input: “4(2(3)(1))(6(5))”
Output: 4 2 3 1 6 5
Explanation:
The corresponding binary tree is as follows:

              4
           /     \                  
         2       6          
      /  \     /                        
   3    1   5                       

*/


/*

Solution :  

Update the character at position 0 as root of the binary tree and initialize a stack stk.
Iterate in the range [1, N-1] using the variable i: 
If ‘(‘ is encountered, push the root to the stack stk.
Otherwise, if ‘)’ is encountered update root as the topmost element of the stack and pop the topmost element.
Otherwise, if the character is a number, then, branch into the part that is null (left or right).
At the end of the above steps, return the root node of the binary tree.

*/

Node* constructTree(string s) {

    Node* root=new Node(s[0]-'0');

    stack<Node*> st;

    for(int i=1;i<s.size();i++) {

        if(s[i]=='(') {
            st.push(root);
        }

        else if(s[i]==')') {
            root=st.top();
            st.pop();
        }

        else {

            if(root->left==NULL) {
                Node* left=new Node(s[i]-'0');
                root->left=left;
                root=root->left;
            }

            else if(root->right==NULL) {
                Node* right=new Node(s[i]-'0');
                root->right=right;
                root=root->right;
            }

        }

    }

    return root;

}