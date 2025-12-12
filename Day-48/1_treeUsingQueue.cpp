#include <iostream>
using namespace std;

struct node{
    char val;
    node *left, *right;
    node(char x){
        val = x;
        left = nullptr;
        right = nullptr;
    }
};

struct queue{
    node* *arr;
    int size, b, f;
    queue(int n){
        arr = new node*[n];
        size = n;
        b = -1;
        f = -1;
    }
    bool isEmpty(){
        return b == f;
    }
    bool isFull(){
        return (b+1)%size == f;
    }
    void enqueue(node *n){
        if(isFull()){
            cout<<"Queue Full"<<endl;
            return;
        }
        b = (b+1)%size;
        arr[b] = n;
        return;
    }
    node* dequeue(){
        if(isEmpty()) {
            cout<<"Queue Empty"<<endl;
            return nullptr;
        }
        f = (f+1)%size;
        return arr[f];
    }
};  

class tree{
public:
    node *root;
    tree(){root = nullptr;}
    void create();
    void preorder(node* root);
    void inorder(node* root);
    void postorder(node* root);
    void levelorder();
    int Height(node* root);
};

void tree::create(){
    node *p, *r;
    queue q(100);
    char x;
    cout<<"Enter root value: ";
    cin>>x;
    root = new node(x);
    q.enqueue(root);
    while(!q.isEmpty()){
        p = q.dequeue();
        cout<<"Enter left child of "<<p->val<<" : ";
        cin>>x;
        if(x!='0'){
            r = new node(x);
            p->left = r;
            q.enqueue(r);
        }
        cout<<"Enter right child of "<<p->val<<" : ";
        cin>>x;
        if(x!='0'){
            r = new node(x);
            p->right = r;
            q.enqueue(r);
        }
    }
    return;
}

void tree::preorder(node* root){
    if(root){
        cout<<root->val<<" ";
        preorder(root->left);
        preorder(root->right);
    }
    return;
}

void tree::inorder(node* root){
    if(root){
        inorder(root->left);
        cout<<root->val<<" ";
        inorder(root->right);
    }
    return;
}

void tree::postorder(node* root){
    if(root){
        postorder(root->left);
        postorder(root->right);
        cout<<root->val<<" ";
    }
    return;
}

void tree::levelorder(){
    node *p;
    queue q(100);
    q.enqueue(root);
    while(!q.isEmpty()){
        p = q.dequeue();
        cout<<p->val<<' ';
        if(p->left) q.enqueue(p->left);
        if(p->right) q.enqueue(p->right);
    }
    return;
}

int tree::Height(node* root){
    if(!root) return 0;
    int x = Height(root->left);
    int y = Height(root->right);
    if(root==this->root) return max(x,y);
    return max(x,y)+1;
}

int main(){
    tree t;
    t.create();
    t.preorder(t.root);
    cout<<endl;
    t.inorder(t.root);
    cout<<endl;
    t.postorder(t.root);
    cout<<endl;
    t.levelorder();
    cout<<endl;
    cout<<t.Height(t.root);
}