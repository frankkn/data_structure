#ifndef _QUEUE_H_
#define _QUEUE_H_

struct Node{
  struct Node* lchild;
  int data;
  struct Node* rchild;
};

struct Queue
{
  int size;
  int front;
  int rear;
  struct Node* *Q; // *Q points to array, and Node* point to Node(value in array)
};

void create(struct Queue *q, int size){
  q->size = size;
  q->front = q->rear = 0;
  q->Q = (struct Node**)malloc(q->size*sizeof(struct Node*)); // Q1
}

void enqueue(struct Queue *q, struct Node* x){ // insert element at rear
  if((q->rear)+1 % (q->size) == q->front){
    printf("Queue is full.");
  }else{
    q->rear = q->rear +1;
    q->Q[q->rear] = x;
  }
}

struct Node* dequeue(struct Queue *q){ // delete element at front
  struct Node* x;
  if(q->front == q->rear){
    printf("Queue is empty.");
  }else{
    q->front = q->front +1 % q->size;
    x = q->Q[q->front];
  }
  return x;
}

int isEmpty(struct Queue q){
  return q.front==q.rear; // Q2
}
#endif