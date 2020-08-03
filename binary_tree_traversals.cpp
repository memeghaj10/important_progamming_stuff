
/*
This is a CPP program to traverse a binary tree in Pre-Order, Post-order and In-order traversals

*/


#include<bits/stdc++.h>

using namespace std;

struct node{  //creating the structure of the node
	int data;
	struct node* left,right;   // defining the left & right art of the node
	node(int data) {  // constructor for the node, if created with some given data;
		this->data=data; // the 'this' pointer is used to point the object to itself.
		left=right=NULL;
	}
}

void Postorder(struct node* n) {   ///function for the Postorder traversal
	if(n==NULL) {
		return ;  // if no node is present
	}

	Postorder(n->left); // else first traverse to the left-most node
	Postorder(n->right); // then to its right-part
	cout<<n->data<<" "; // in the mean process, print the node that has been traversed

}


void Inorder(struct node* n) { //function for the Inorder traversal of the tree. 
	if(n==NULL) {
		return ; // if no node is further present, we return to the last called function
	}

	Inorder(n->left); // else first traverse to the left part
	cout<<n->data<<" "; // while print the node traversed
	Inorder(n->right); // them traverse the righh part of the node


}

void Preorder(struct node* n) {  //function for Pre-order Traversal

	if(n==NULL) { // if no node is present, then return back to the last called fucntion
		return ;
	}

	cout<<node->data<<" "; // first print the traversed node
	Preorder(n->left); // then traverse the left-part of it
	Preorder(n->right); // after left, traverse to the right-part of it


}

int main( ) {

struct node *root = new node(1); // creating a new sample tree

root->left=new node(2); // adding children to the root
root->right=new node(3);
root->left->left=new node(4);
root->left->right=new node(5);

cout<<"Pre-order traveral of the tree is: "<<endl;
Preorder(root); // pre-order traversal of the tree

cout<<endl<<"Inorder traversal of the tree is: "<<endl;
Inorder(root); // in-order traversal of the tree

cout<<endl<<"Postorder traversal of the tree is: "<<endl;
Postorder(root);// post-order traversal of the tree

	return 0;
}