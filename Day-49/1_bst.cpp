#include <bits/stdc++.h>
using namespace std;

struct node{
    node *left, *right;
    int val;
    node(int n){
        val = n;
        left = nullptr;
        right = nullptr;
    }
};

class bst{
public:
    node *root;

    bst(){root = nullptr;}
    void traverse(node * root);
    void insert(node* &root, int n);
    void del(node* root, int n);
    node* search(node* root, int n);
};

void bst::insert(node* &root, int n){
    if(root == nullptr){
        root = new node(n);
        return;
    }
    if(root->val == n) return;
    if(root->val>n) insert(root->left,n);
    else insert(root->right,n);
    return;
}

void bst::del(node* root, int n){
    node* root = search(root,n);
    node *temp;
    if(!temp->right && !temp->left)
    while(temp->left) temp = temp->left;

}

void bst::traverse(node *root){
    if(root){
        traverse(root->left);
        cout<<root->val<<' ';
        traverse(root->right);
    }
    return;
}

node* bst::search(node *root, int n){
    if(root){
        if(root->val == n) return root;
        if(root->val > n) return search(root->left,n);
        else return search(root->left,n);
    }
    return nullptr;
}

int main(){
    bst t;
    int n;
    while(true){
        cin>>n;
        if(n==-1) break;
        t.insert(t.root, n);
    }
    t.traverse(t.root);
}