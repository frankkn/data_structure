#include <algorithm>
#include <fstream>
#include <iostream>
#include <queue>
#include <vector>

class Heap
{
  public:
    int top(){
      if(A.size() == 0)
      {
        return 0;
      }
      else
      {
        return A.at(0); // return A[0]
      }
    }

    void push (int key)
    {
      A.push_back(key);
      int i = A.size() - 1;
      while (i && key > A[(i - 1) / 2])
      {
        A[i] = A[(i - 1) / 2];
        i = (i - 1) / 2;
      }
      A[i] = key;
      return;      
    }

    void pop ()
    {
      if (A.size() == 0)
      {
        return;
      }
      A[0] = A.back();
      int tmp = A[0];
      A.pop_back();
      int i = 0;
      int j = 2*i+1;
      while(j <= A.size()-1)
      {
        if(j < A.size()-1)
        {
          if(A[j] < A[j+1])
          {
            j = j+1;
          }
        }
        if(A[i] < A[j])
        {
          A[i] = A[j];
          i = j;
        }
        else
        {
          break;
        }
        j = 2*i+1;
      }
      A[i] = tmp;
    }

    /*ostream &operator<<(ostream &s, class-name ob) {
      第一個參數是ostream型態的參數，也就是輸出串流，傳回這個串流給cout的話，就可以顯示輸出至串流中的資訊。
      第二個參數是要輸出的物件，實作時將指定輸出的資訊。
        // 實作
        return s;
    }*/
    friend std::ostream& operator<< (std::ostream& out, Heap heap) 
    {
      for (auto const& x : heap.A)
      {
        out << x << " ";
      }
      out << "\n";
      return out;
    }

private:
  std::vector<int> A; // store heap elements

};

int main ()
{
  Heap h;
  h.push(5);
  h.push(10);
  h.push(30);
  h.push(20);
  h.push(15);
  h.push(35);
  h.push(25);
  std::cout << h;

  h.pop();
  std::cout << h; // std::operator<<(std::cout, h)

  return 0;
}

/*
void Insert(vector<int>& v, int key){
  auto size = v.size();
  v.push_back(key);
  while(size > 0 && key > v[size % 2 == 0? size/2-1:size/2]){
    v[size] = v[size % 2 == 0? size/2-1:size/2];//assign parent value to child  
    size = size % 2 == 0? size/2-1:size/2; // ptr move to parent
  }
  v[size] = key; // root = key
}

void CreateHeap(vector<int>& v, int A[], int n){
  for(int i = 0; i < n; i++){
    Insert(v,A[i]);
  }
}

int Delete(int A[], int n){
  int max_element = A[0];
  A[0] = A[n-1];
  A[n-1] = max_element;
  int i = 0;
  int j = 2*i+1;
  while(j < n-1){
    
    if(j+1 < n-1){  
      if(A[j+1]>A[j]){
        j = j+1;
      }
    }
    if(A[j] > A[i]){
      swap(A[i],A[j]);
      i = j; 
    }else{
      break;
    }
    j = 2*i+1;
  }
  return max_element;
} 

void Heapify(int A[], int n){
  int j = 0;
  for(int i = (n/2)-1; i >= 0; i--){ //index of last parent:(n/2)-1
    j = 2*i+1;
    while(j < n-1){
      if(A[j+1]>A[j]){
        j=j+1;
      }
      if(A[j]>A[i]){
        swap(A[i],A[j]);
        i = j;
        j = 2*i+1;
      }else{
        break;
      }
    }
  }
}

void HeapSort(int A[], int n){
  for(int i = 0; i < n; i++){
    Delete(A,n-i);
  }
}

void swap(int &a, int &b){
  int c = a;
  a=b;
  b=c;
}

template <class T>
void Print(T& vec, int n){
    cout << "Max Heap: [" << flush;
    for (int i=0; i<n; i++){
        cout << vec[i] << flush;
        if (i < n-1){
            cout << ", " << flush;
        }
    }
    cout << "]" << endl;
}
 
int main() {

  int A[]={5,10,30,20,35,40,15};

  Heapify(A, sizeof(A)/sizeof(int)); // create Heap  
  Print(A, sizeof(A)/sizeof(int));

  HeapSort(A,sizeof(A)/sizeof(int)); // HeapSort 
  Print(A,sizeof(A)/sizeof(int));

  int B[] = {40,30,35,20,25,10,15};
  Delete(B, sizeof(B)/sizeof(int)); // delete max_element and put it in the end of array
  Print(B, sizeof(B)/sizeof(int));

    return 0;
}*/