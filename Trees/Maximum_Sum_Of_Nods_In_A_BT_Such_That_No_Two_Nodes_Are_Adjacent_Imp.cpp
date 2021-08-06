/*

Given a binary tree with a value associated with each node, we need to choose a subset of these nodes such that the sum of chosen
nodes is maximum under a constraint that no two chosen node in the subset should be directly connected that is,
if we have taken a node in our sum then we can’t take any of its children in consideration and vice versa. 

*/

/*

We can solve this problem by considering the fact that both node and its children can’t be in sum at the same time, so when we take a node into our sum we will call recursively for its grandchildren or if we don’t take this node then we will call for all its children nodes and finally we will choose maximum from both of the results. 
It can be seen easily that the above approach can lead to solving the same subproblem many times, for example in the above diagram node 1 calls node 4 and 5 when its value is chosen and node 3 also calls them when its value is not chosen so these nodes are processed more than once. We can stop solving these nodes more than once by memoizing the result at all nodes. 
In the below code, a map is used for memoizing the result which stores the result of the complete subtree rooted at a node in the map so that if it is called again, the value is not calculated again instead stored value from the map is returned directly. 

*/

int getSumGrandChildren(Node* root,map<Node*,int>& mp) {

    int sum=0;

    if(root->left) {
        sum+=getMaxSumUtil(root->left->left,mp)+getMaxSumUtil(root->left->right,mp);
    }

    if(root->right) {
        sum+=getMaxSumUtil(root->right->left,mp)+getMaxSumUtil(root->right->right,mp);
    }

    return sum;

}

int getMaxSumUtil(Node* root,map<Node*,int>& mp) {

    if(!root) {
        return 0;
    }

    if(mp.find(root)!=mp.end()) {
        return mp[root];
    }

    int incl=root->data+getSumGrandChildren(root,mp);
    int excl=getMaxSumUtil(root->left,mp)+getMaxSumUtil(root->right,mp);

    return mp[root]=max(excl,incl);

}


int getMaxSum(Node* root) {
    if(!root) {
        return 0;
    }

    map<Node*,int> mp;
    
    return getMaxSumUtil(root,mp);
}