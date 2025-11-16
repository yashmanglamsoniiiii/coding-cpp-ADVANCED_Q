#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int value){
        data=value;
        left=right=NULL;
    }
};

Node* insert(Node* root, int val){
    if (root==NULL) {
        return  new Node(val);
    }

    if (val<root->data){
        root->left=insert(root->left,val);
    }else{
        root->right=insert(root->right,val);
    }

    return root;
}
Node* buildbst(vector<int> &arr){//int arr[] also fine.
    Node* root=NULL;
    for (int val: arr){
        root=insert(root,val);
    }

    return root;
}

void inorder(Node* root){
    if (root==NULL) return;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);

}

int maxkey(Node* root){
    if (root==NULL){
        return -1;
    }

    Node* curr=root;
    while(curr->right!=NULL){
        curr=curr->right;
    }

    return curr->data;
}




// Given the access to the pointer of tbe root of a biaary search tree, write a function to return 5
// the po inter of parent node to a node having key value. If a node with l~ey value does not
// exist □ the tree the□ ret1tr1L\!ULL. In case if the key is on root node, return root pointer.
// bstnode-1: Pt1re1ttOf( iltt key ) 
Node* ParentOf(Node* root, int key) {
    if (root == NULL) return NULL;

    // If the key is at the root, return root itself
    if (root->data == key) return root;

    Node* current = root;

    while (current != NULL) {
        // Check if left or right child has the key
        if ((current->left && current->left->data == key) ||
            (current->right && current->right->data == key)) {
            return current; // Found the parent
        }

        // Move left or right based on BST property
        if (key < current->data)
            current = current->left;
        else
            current = current->right;
    }

    return NULL; // Key not found
}

int main(){
    vector<int> arr={1,2,3,4,5,6};
    Node* root=buildbst(arr);
    inorder(root);
}