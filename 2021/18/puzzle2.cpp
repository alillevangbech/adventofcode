#include <algorithm>
#include <bits/stdc++.h>
#include <iterator>
#include <queue>
#include <regex>
#include <string>
#include "../util.h"
using namespace std;
#define n 6
#define COUNT 10
struct node {
	public:
	// data == -1 -> root
	int data;
	struct node *parent;
	struct node *left;
	struct node *right;
	node() : data(-1) { parent = NULL; left = NULL; right = NULL; }
};
node* parse(string s);
void vector_inorder(node* ptr, vector<node*>& v);
ll magnitude(node* ptr);
void vector_depth_inorder(node* ptr, vector<node*> &v, int depth);
bool vector_depth_inorder_reset(node* ptr, vector<node*> &v);
void vector_split_inorder(node* ptr, vector<node*> &v);
bool vector_split_inorder_reset(node* ptr, vector<node*> &v);
void delete_tree(node* root);
node* add(node* ptr1, node* ptr2);
void print2D(node *root);
ll mag_two(node* root1, node* root2);

int main() 
{
	ll mag = 0, mag_tmp = 0;
	auto input = read_input();
	for (int i = 0; i < input.size(); i++) {
		for (int j = 0; j < input.size(); j++) {
			if (i == j) continue;
			node* root1 = parse(input[i]);
			node* root2 = parse(input[j]);
			mag_tmp = mag_two(root1,root2);
			//cout << input[i] << "\t" << input[j] << "\t" << mag_tmp << endl;
			if (mag_tmp > mag) {
				mag = mag_tmp;
			}
		}
	}
	cout << mag << endl;
	return 0;
}

node* parse(string s) {
	node* ptr = new node();
	bool number = false;
	for (int i = 0; i < s.size(); i++) {
		if (10 > s[i] - '0' && s[i] - '0' >= 0) {
			int ii = i;
			while (10 > s[i+1] - '0' && s[i+1] - '0' >= 0) {
				i++;
			}
			ptr->data = stoi(s.substr(ii, i - ii+1));
			continue;
		}

		if (s[i] == '[') {
			ptr->left = new node();
			ptr->left->parent = ptr;
			ptr = ptr->left;
			continue;
		}


		if (s[i] == ',') {
			ptr = ptr->parent;
			ptr->right = new node();
			ptr->right->parent = ptr;
			ptr = ptr->right;
			continue;
		}

		if (s[i] == ']') {
			ptr = ptr->parent;
			continue;
		}
	}

	//prune(ptr);
	return ptr;
};

void vector_inorder(node* ptr, vector<node*> &v)
{
    if (ptr == NULL) return;

	vector_inorder(ptr->left,v);
	if (ptr->data != -1)
		v.push_back(ptr);
	vector_inorder(ptr->right,v);
}

bool vector_depth_inorder_reset(node* ptr, vector<node*> &v) {
	//cout << "vector_depth_inorder_reset" << endl;
	bool change = false;
	vector<node*> v_depth;
	vector_depth_inorder(ptr, v_depth, 0);
	v.clear();
	vector_inorder(ptr, v);
	for (int j = 0; j < v.size(); j++ ) {
		for (int i = 0; i < v_depth.size(); i++) {
			if (v[j]->parent == v_depth[i]) {
				change = true;
				if (j - 1 >= 0) {
					v[j-1]->data += v[j]->data;
				}
				
				if (j + 2 < v.size()) {
					v[j+2]->data += v[j+1]->data;
				}
				
//				cout << "left: " << v[j]->data << "; right: " << v[j+1]->data << endl;

				if (v[j]->parent == NULL)
					cout << "NULL here" << endl;
				if (v_depth[i] == NULL)
					cout << "NULL here" << endl;

				v[j]->parent->left = NULL;
				v[j]->parent->right = NULL;
				v[j]->parent->data = 0;
				delete v[j];
				delete v[j+1];
				return change;
			}
		}
	}
	return change;
}
void vector_depth_inorder(node* ptr, vector<node*> &v, int depth)
{
    if (ptr == NULL) return;

	vector_depth_inorder(ptr->left,v,depth+1);
	if (ptr->data != -1 && depth == 5) {
		v.push_back(ptr->parent);
	}
	vector_depth_inorder(ptr->right,v,depth+1);
}

bool vector_split_inorder_reset(node* ptr, vector<node*> &v)
{
	//cout << "vector_split_inorder_reset" << endl;
	bool change = false;
	vector<node*> v_split;
	vector_split_inorder(ptr, v_split);
	v.clear();
	vector_inorder(ptr, v);
	for (int i = 0; i < v_split.size(); i++) {
		for (int j = 0; j < v.size(); j++ ) {
			if (v[j] == v_split[i]) {
				change = true;
				int data = v[j]->data;
				v[j]->left = new node();
				v[j]->left->data = data/2;
				v[j]->left->parent = v[j];
				
				v[j]->right = new node();
				v[j]->right->data = data % 2 == 0 ? data/2 : data/2 + 1;
				v[j]->right->parent = v[j];

				v[j]->data = -1;
				return change;
			}
		}
	}
	return change;
}

void vector_split_inorder(node* ptr, vector<node*> &v)
{
    if (ptr == NULL) return;

	vector_split_inorder(ptr->left,v);
	if (ptr->data != -1 && ptr->data >= 10)
		v.push_back(ptr);
	vector_split_inorder(ptr->right,v);
}

node* add(node* ptr1, node* ptr2) {
	node* ret = new node();
	ret->left = ptr1;
	ptr1->parent = ret;
	ret->right = ptr2;
	ptr2->parent = ret;
	return ret;
}

void delete_tree(node* root) {
	if (root == NULL) return;

	delete_tree(root->left);
	delete_tree(root->right);

	delete root;
}

void print2DUtil(node *root, int space)
{
    // Base case
    if (root == NULL)
        return;
 
    // Increase distance between levels
    space += COUNT;
 
    // Process right child first
    print2DUtil(root->right, space);
 
    // Print current node after space
    // count
    cout<<endl;
    for (int i = COUNT; i < space; i++)
        cout<<" ";
    cout<<root->data<<","<<(root->parent == NULL ? 'N' : 'V')<<"\n";
 
    // Process left child
    print2DUtil(root->left, space);
}
 
// Wrapper over print2DUtil()
void print2D(node *root)
{
    // Pass initial space count as 0
    print2DUtil(root, 0);
}

ll magnitude(node* ptr) {
    if (ptr == NULL) return 0;

	ll left = magnitude(ptr->left);
	ll right = magnitude(ptr->right);

	if (left == 0 && right == 0)
		return ptr->data;

	// check if pair
	if (left != 0 && ptr->left->data != -1 && right != 0 && ptr->right->data != -1) {
		return ptr->left->data*3 + ptr->right->data*2;
	}

	return left*3 + right*2;
}

ll mag_two(node* root1, node* root2) {
	node* root = add(root1, root2);
	vector<node*> v;
	int count = 1;
	while (count > 0) {
		count = 0;

		if (vector_depth_inorder_reset(root,v)) {
			count++;
		} else {
			if (vector_split_inorder_reset(root,v))
				count++;
		}
	}
	ll mag = magnitude(root);
	delete_tree(root);
	return mag;
}
