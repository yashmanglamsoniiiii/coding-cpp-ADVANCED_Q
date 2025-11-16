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

static int idx=-1;
Node* buildtree(vector<int> preorder){
    idx++;
    if(preorder[idx]==-1){
        return NULL;
    }

    Node* root=new Node(preorder[idx]);
    root->left=buildtree(preorder);
    root->right=buildtree(preorder);
    return root;
}

void preordert(Node* root){
    if (root==NULL){
        return;
    }

    cout<<root->data<<" ";
    preordert(root->left);
    preordert(root->right);
}

void levelOrder(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(q.size()>0){
        Node* curr=q.front();
        q.pop();

        if (curr==NULL){
            if(!q.empty()){
                cout<<endl;
                // q.pop();
                q.push(NULL);
                continue;
            }else break;
        }
        cout<<curr->data<<" ";

        if (curr->left!=NULL){
            q.push(curr->left);
        }

        if (curr->right!=NULL){
            q.push(curr->right);
        }
    }
}

void inordert(Node* root){
    if (root==NULL){
        return;
    }

    inordert(root->left);
    cout<<root->data<<" ";
    inordert(root->right);
}

void postordert(Node* root){
    if (root == NULL ) return;

    postordert(root->left);
    postordert(root->right);
    cout<<root->data<<" ";
}

int count(Node* root){
    if (root==NULL ) return 0;

    int leftcount=count(root->left);
    int rightcount=count(root->right);

    return leftcount+rightcount+1;
}

int heightmax(Node* root){
    if (root==NULL) return 0;

    int lh=heightmax(root->left);
    int rh=heightmax(root->right);
    return max(lh,rh) +1;
}

int sum(Node* root){
    if (root==NULL){
        return 0;
    }


    int ls=sum(root->left);
    int rs=sum(root->right);
    return ls+rs+root->data;
}


int search(vector<int> &inorder, int left, int right, int &val){
    for(int i=left;i<=right;i++){
        if (inorder[i]==val){
            return i;
        }
    }
    return -1;
}
Node* buildtreeip(vector<int> &preorder, vector<int> &inorder, int &preidx, int left,int right){
    if (left> right){
        return NULL;
    }

    Node* root=new Node(preorder[preidx]);
    int inidx=search(inorder, left,right,preorder[preidx]);
    preidx++;

    root->left=buildtreeip(preorder,inorder,preidx,left,inidx-1);
    root->right=buildtreeip(preorder,inorder,preidx,inidx+1,right);

    return root;
}

int main(){
    // vector<int> preorder={1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    // Node* root=buildtree(preorder);
    // inordert(root);
    // cout<<endl;
    // levelOrder(root);

    vector<int> preorder={2,5,6,10,12,14,15};
    vector<int> inorder={10,5,2,6,14,12,15};
    int preidx=0;
    Node* root=buildtreeip(preorder,inorder, preidx, 0, inorder.size()-1);// 0 no as &int -> int

    inordert(root);
}