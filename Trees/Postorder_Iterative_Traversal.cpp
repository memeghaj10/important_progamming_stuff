
// User function Template for C++

/* Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};*/
vector<int> postOrder(Node* node) {
    
    if(!node) {
        return {};
    }
    
    vector<int> ans;
    
    stack<Node*> st;
    stack<int> st1;
    
    st.push(node);
    
    while(!st.empty()) {
        
        Node *r=st.top();
        st.pop();
        
        st1.push(r->data);
        
        if(r->left) {
            st.push(r->left);
        }
        
        if(r->right) {
            st.push(r->right);
        }
        
    }
    
    
   while(!st1.empty()) {
       ans.push_back(st1.top());
       st1.pop();
   }
    
    return ans;
}