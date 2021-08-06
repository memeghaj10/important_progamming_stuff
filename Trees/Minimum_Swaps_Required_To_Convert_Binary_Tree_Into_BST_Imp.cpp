/*

Given the array representation of Complete Binary Tree i.e, if index i is the parent, index 2*i + 1 is the left child and index 2*i + 2 is the right child. The task is to find the minimum number of swap required to convert it into Binary Search Tree.

Solution :-

The idea is to use the fact that inorder traversal of Binary Search Tree is in increasing order of their value. 
So, find the inorder traversal of the Binary Tree and store it in the array and try to sort the array. The minimum number of swap required to get the array sorted will be the answer. Please refer below post to find minimum number of swaps required to get the array sorted.
Minimum number of swaps required to sort an array
Time Complexity: O(n log n).

*/

vector<int> v;
int ans=0;

void inorder(Node* root) {

    if(!root) {
        return;
    }

    inorder(root->left);
    v.push_back(root->data);
    inorder(root->right);
}

int min_swaps(vector<int> v) {

    int n=v.size();

    pair<int,int> arr[n];

    for(int i=0;i<n;i++) {
        arr[i].first=v[i];
        arr[i].second=i;
    }

    sort(arr,arr+n);

    vector<int> vis(n,0);
    int s=0;

    for(int i=0;i<n;i++) {
        if(vis[i]||arr[i].second==i) {
            continue;
        }

        int cycle=0;
        int j=i;
        while(!vis[j]) {
            vis[j]=1;
            j=arr[j].second;
            cycle++;
        }

        if(cycle>0) {
            s+=(cycle-1);
        }
    }

    return ans=s;

}

void util(Node* root) {

    inorder(root);

    min_swaps(v);

    return ans;
}