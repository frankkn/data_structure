#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Node
{
public:
  Node (uint64_t key = 0): key_{key}, left_{nullptr}, right_{nullptr}, left_subtree_size_{0} {}
    
  ~Node ()
  {
    delete left_;
    delete right_;
  }

//private:
  uint64_t key_;
  Node* left_;
  Node* right_;
  uint64_t left_subtree_size_;
  friend class BST;
};

class BST
{
public:
  BST (): root_{nullptr} {}
  ~BST () { delete root_; }

  void Insert (uint64_t key)
  {
    if (root_)
    {
      Node* node {root_};
      while (node)
      {
        if (key < node->key_)
        { 
          if (node->left_)
          {
            node->left_subtree_size_ += 1;
            node = node->left_;
          }
          else
          {
            node->left_subtree_size_ += 1;
            node->left_ = new Node{key};
            break;
          }
        }
        else if (key > node->key_) 
        { 
          if (node->right_) { node = node->right_; }
          else{node->right_ = new Node{key}; break; }
        }
        else { break; }
      }
    }
    else{ root_ = new Node{key}; }
    return;
  }
  
  uint64_t Rank (uint64_t key) const // key is the kth (1 to n) smallest and return k 
  {
    Node* node {root_};
    uint64_t rank {};
    while (node)
    {
      if (key < node->key_) { node = node->left_; }
      else if (key > node->key_) 
      { 
        rank += node->left_subtree_size_ + 1;
        node = node->right_; 
      }
      else 
      { 
        rank += node->left_subtree_size_ + 1;
        break;
      }
    }
    return rank;
  }

private:
  Node* root_;
};

int main() {
    uint64_t len = 0;
    cin >> len;
    vector<uint64_t> nums(len);
    for(auto& val: nums){
        cin >> val;
    }
    
    uint64_t res {};
    
    BST bst;
    uint64_t node_count {};
    for(auto const& node: nums)
    {
        node_count++;
        bst.Insert(node);
        res += (node_count - bst.Rank(node));
    }
    
    cout << res;
    
    return 0;
}