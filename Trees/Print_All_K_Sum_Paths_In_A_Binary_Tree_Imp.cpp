/*

A binary tree and a number k are given. Print every path in the tree with sum of the nodes in the path as k. 
A path can start from any node and end at any node and must be downward only, i.e. they need not be root node and leaf node; and negative numbers can also be there in the tree.
Examples: 
 

Input : k = 5  
        Root of below binary tree:
           1
        /     \
      3        -1
    /   \     /   \
   2     1   4     5                        
        /   / \     \                    
       1   1   2     6    
                       
Output :
3 2 
3 1 1 
1 3 1 
4 1 
1 -1 4 1 
-1 4 2 
5 
1 -1 5 

*/

void printVector(vector<int>& v,int i) {
    for(int j=i;j<v.size();j++) {
        cout<<v[j]<<" ";
    }
    cout<<endl;
}


void printKPathUtil(node* root,vector<int>& path,int k) {

if(!root) {
    return;
}

path.push_back(root->data);

//check if k sum path is in left_subtree

printKPathUtil(root->left,path,k);

//check if k sum path is in right_subtree

printKPathUtil(root->right,path,k);

int f=0;

for(int j=path.size()-1;j>=0;j--) {
    f+=path[j];
    if(f==k) {
        printVector(path,j);
    }
}

//remove the current element from the path

path.pop_back();

}


void printKPath(node* root,int k) {
    vector<int> path;
    printKPathUtil(root,path,k);
}