#include <iostream>
#include <stdio.h>
using namespace std;

struct TreeNode {
	int data;
	TreeNode* left, * right;
};

TreeNode* insert(int data,TreeNode* root) {
	if (root == NULL) {
		//cout << "create!!" << endl;
		root = new TreeNode();
		root->data = data;
		root->left = NULL;
		root->right = NULL;
		return root;
	}

	if (data < root->data) {
		//cout << data <<" go to left!" << endl;
		root->left = insert(data, root->left);
	}
	else {
		//cout << data << " go to right!" << endl;
		root->right = insert(data, root->right);
	}

	return root;
}

void postorder(TreeNode* root) {
	if (root == NULL) return;
	postorder(root->left);
	postorder(root->right);
	cout << root->data<<endl;
}

int main() {
	TreeNode* root = NULL;
	int data;
	while (cin>>data) {
		if (data == EOF) break;
		root = insert(data,root);
	}
	postorder(root);
	
}