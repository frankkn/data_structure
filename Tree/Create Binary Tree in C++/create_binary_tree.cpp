#include <iostream>
#include <queue>
using namespace std;

class Node{
public:
  Node* lchild;
  int data;
  Node* rchild;
};



class Tree{
private:
  Node* root;
public:
  Tree();
  void CreateTree();
  void Preorder(Node* p);
  void Preorder() {Preorder(root);}// Passing Private Parameter in Constructor
  void Inorder(Node* p);
  void Inorder() {Inorder(root);}
  void Postorder(Node* p);
  void Postorder() {Postorder(root);}
  void Levelorder(Node* p);
  void Levelorder() {Levelorder(root);}
  int Height(Node* p);
  int Height()  {return Height(root);}
};

Tree::Tree(){
  root = NULL;
}

void Tree::CreateTree(){
  Node* p;
  Node* t;
  queue<Node*> q;
  root = new Node;
  int val;
  cout<<"Enter the root value:";
  cin>>val;
  root->data = val;
  root->lchild = root->rchild = NULL;
  q.push(root);
  while(!q.empty()){
    p = q.front();
    q.pop();
    cout<<"Enter the left child of "<<p->data<<":";
    cin>>val;
    if(val != -1){
      t = new Node;
      t->data = val;
      t->lchild = t->rchild = NULL;
      p->lchild = t;
      q.push(t);
    }

    cout<<"Enter the right child of "<<p->data<<":";
    cin>>val;
    if(val != -1){
      t = new Node;
      t->data = val;
      t->lchild = t->rchild = NULL;
      p->rchild = t;
      q.push(t);
    }
  }
}

void Tree::Preorder(Node* p){
  if(p){
    cout<<p->data<<" ";
    Preorder(p->lchild);
    Preorder(p->rchild);
  }
}

void Tree::Inorder(Node* p){
  if(p){
    Inorder(p->lchild);
    cout<<p->data<<" ";
    Inorder(p->rchild);
  }
}

void Tree::Postorder(Node* p){
  if(p){
    Postorder(p->lchild);
    Postorder(p->rchild);
    cout<<p->data<<" ";
  }
}

void Tree::Levelorder(Node* p){
  queue<Node*> q;
  cout<< p->data << " ";
  q.push(p);
  while(!q.empty()){
    p = q.front();
    q.pop();
    if(p->lchild){
      cout<< p->lchild->data <<" ";
      q.push(p->lchild);
    }
    if(p->rchild){
      cout<< p->rchild->data <<" ";
      q.push(p->rchild);
    }
  }
}



int main(){
  Tree t;
  
  t.CreateTree();
  cout << endl;
  
  cout << "Preorder: " << flush;
  t.Preorder();
  cout << endl;

  cout << "Inorder: " << flush;
  t.Inorder();
  cout << endl;

  cout << "Postorder: " << flush;
  t.Postorder();
  cout << endl;

  cout << "Levelorder: " << flush;
  t.Levelorder();
  cout << endl;

  return 0;
}