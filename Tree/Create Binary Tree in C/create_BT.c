#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

struct Node *root=NULL;

void TreeCreate(){
  struct Node *p, *t;
  int val;
  struct Queue q;
  create(&q, 100);

  printf("Enter the root value: ");
  scanf("%d", &val);
  root = (struct Node*)malloc(sizeof(struct Node));
  root->lchild = root->rchild = NULL;
  root->data = val;
  enqueue(&q, root);
  while(!isEmpty(q)){
    p = dequeue(&q);
    printf("Enter the data of left child of %d.(Enter -1 if it is Null.)", p->data);
    scanf("%d", &val);
    if(val != -1){
      t = (struct Node*)malloc(sizeof(struct Node));
      t->data = val;
      t->lchild = t->rchild = NULL;
      p->lchild = t;
      enqueue(&q, t);
    }
    printf("Enter the data of right child of %d.(Enter -1 if it is Null.)", p->data);
    scanf("%d", &val);
    if(val != -1){
      t = (struct Node*)malloc(sizeof(struct Node));
      t->data = val;
      t->lchild = t->rchild = NULL;
      p->rchild = t;
      enqueue(&q, t);
    }
  }
}

void Preorder(struct Node* p){
  if(p){
    printf("%d ",p->data);
    Preorder(p->lchild);
    Preorder(p->rchild);
  }
}

void Inorder(struct Node *p)
{
  if(p)
  {
  Inorder(p->lchild);
  printf("%d ",p->data);
  Inorder(p->rchild);
  }
}

void Postorder(struct Node *p)
{
  if(p)
  {
  Postorder(p->lchild);
  Postorder(p->rchild);
  printf("%d ",p->data);
  }
}

int main()
{
  TreeCreate();
  
  printf("\nPreorder: ");
  Preorder(root);
  printf("\nInorder: ");
  Inorder(root);
  printf("\nPostorder: ");
  Postorder(root);

  return 0; 
}