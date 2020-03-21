#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> tree[26];

typedef struct Node {
	char label;
	Node *left,*right;
	Node() {
		left = NULL;
		right = NULL;
	}
}Node;

void preorder(Node* root) {
	if (root != NULL) {
		cout << root->label;
		preorder(root->left);
		preorder(root->right);
	}
}

void inorder(Node* root) {
	if (root != NULL) {
		inorder(root->left);
		cout << root->label;
		inorder(root->right);
	}
}

void postorder(Node* root) {
	if (root != NULL) {
		postorder(root->left);
		postorder(root->right);
		cout << root->label;
	}
}

int main() {
	Node* tree = new Node[26];

	cin >> N;
	for (int i = 0; i < N; i++) {
		char root, left, right;
		cin >> root >> left >> right;
		tree[root - 'A'].label = root;
		if (left != '.') {
			tree[left - 'A'].label = left;
			tree[root - 'A'].left = &tree[left - 'A'];
		}
		if (right != '.') {
			tree[right - 'A'].label = right;
			tree[root - 'A'].right = &tree[right - 'A'];
		}
	}
	preorder(&tree[0]);
	cout << endl;
	inorder(&tree[0]);
	cout << endl;
	postorder(&tree[0]);
	return 0;
}