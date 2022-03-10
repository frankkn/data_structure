#include <iostream>
#include <vector>
#include <set>
#include <ctime>
#include <iomanip>

class Node
{
public:
  Node (uint64_t key = 0): key_{key}, left_{nullptr}, right_{nullptr}, left_subtree_size_{0} {}
  
  ~Node ()
  {
    delete left_;
    delete right_;
  }

private:
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

  Node* Search (uint64_t key) const
  {
    Node* node {root_};
    while (node)
    {
      if (key < node->key_) { node = node->left_; }
      else if (key > node->key_) { node = node->right_; }
      else { break; }
    }
    return node;
  }

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

  void Delete (uint64_t key)
  {    
    Node* parent {nullptr};
    Node* node {root_};
    while (node)
    {
      if (key < node->key_) 
      { 
        parent = node;
        --parent->left_subtree_size_;
        node = node->left_; 
      }
      else if (key > node->key_) 
      { 
        parent = node;
        node = node->right_; 
      }
      else 
      { 
        if (node->left_ && node->right_)
        {
          // substitute node->key_ with predecessor->key_
          Node* predecessor {node->left_};
          parent = node;
          while (predecessor->right_)
          {
            parent = predecessor;
            predecessor = predecessor->right_;
          }
          {
            --(node->left_subtree_size_);
            node->key_ = predecessor->key_;
          }
          if (predecessor == parent->right_) { parent->right_ = predecessor->left_; }
          else { node->left_ = nullptr; }
          node = predecessor;
        }
        else if (node->left_ || node->right_)
        {
          Node* temp {node};
          node = ((node->left_) ? node->left_ : node->right_);
          if (parent)
          {
            if (temp == parent->left_) { parent->left_ = node; }
            else { parent->right_ = node; }
          }
          else { root_ = node; }
          parent = node = temp;
        }
        else
        {
          if (node == parent->left_) { parent->left_ = nullptr; }
          else { parent->right_ = nullptr; }
        }
        {
          node->left_ = node->right_ = nullptr; // disconnect subtree of node from node
          delete node;
        }
        break;
      }
    }
    return;
  }

  Node* Min () const
  {
    Node* node {root_};
    while (node && node->left_){ node = node->left_; }
    return node;
  };

  Node* Max () const
  {
    Node* node {root_};
    while (node && node->right_){ node = node->right_; }
    return node;
  };
  
  uint64_t Predecessor (uint64_t key) const{
    Node* node { root_ };
    Node* pred { nullptr };
    key--; 
    while (node)
    {
      if (key < node->key_) { node = node->left_; }
      else if (key > node->key_) 
      {
        pred = node; 
        node = node->right_; 
      }
      else { break; }
    }
    return ((pred) ? pred->key_ : 0);
  };

  uint64_t Successor (uint64_t key) const
  {
    Node* node { root_ };
    Node* succ { nullptr };
    key++; 
    while (node)
    {
      if (key < node->key_) 
      {
        succ = node;
        node = node->left_; 
      }
      else if (key > node->key_) { node = node->right_; }
      else { break; }
    }
    return ((succ) ? succ->key_ : 0);
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

  uint64_t Select (uint64_t k) const
  {
    Node* node {root_};
    while (node)
    {
      auto count {node->left_subtree_size_ + 1};
      if (count < k)
      {
        node = node->right_;
        k -= count;
      }
      else if (count > k)
      {
        node = node->left_;
      }
      else
      {
        return node->key_;
      }
    }
    return 0;
  }

  void InOrder (std::vector<uint64_t>& in_order, std::vector<uint64_t>& left_subtree_size) const
  {
    InOrder(in_order, left_subtree_size, root_);
    return;
  }

  friend std::ostream& operator<< (std::ostream& out, BST const& bst)
  {
    std::vector<uint64_t> in_order;
    std::vector<uint64_t> left_subtree_size;
    bst.InOrder(in_order, left_subtree_size);
    out << "In-order sequence:" << std::setw(1) ;
    for (auto const& key : in_order)
    {
        out << std::setw(2) << key << " ";
    }
    out << "\n";
    out << "Left subtree size:";
    for (auto const& x : left_subtree_size)
    {
        out << std::setw(2) << x << " ";
    }
    out << "\n";
    return out;
  }

  bool isValidBST(Node* root)
  {
    return isValidBST(root, 0 , UINT64_MAX);
  }

  bool isValidBST(Node* root, uint64_t min_val, uint64_t max_val)
  {
    if(!root) { return true; };
    if(root->key_ <= min_val || root->key_ >= max_val)
    {
     return false; 
    }
    return isValidBST(root->left_, min_val, root->key_) && isValidBST(root->right_, root->key_, max_val);
  }

//private:
  Node* root_;

  void InOrder (std::vector<uint64_t>& in_order, std::vector<uint64_t>& left_subtree_size, Node* node) const
  {
    if (node)
    {
      InOrder(in_order, left_subtree_size, node->left_);
      //in_order.push_back({node->key_, node->left_subtree_size_});
      in_order.push_back(node->key_);
      left_subtree_size.push_back(node->left_subtree_size_);
      InOrder(in_order, left_subtree_size, node->right_);
    }
    return;
  }
};


int main (int argc, char** argv)
{
  BST bst;
  uint64_t key;
  srand(time(0));
  std::vector<uint64_t> nodes;
  for(int i = 0; i < 10; ++i)
  {
    uint64_t random_number =  rand() % 89 + 10;
    nodes.push_back(random_number);
  }
  for(auto const& node: nodes)
  {
    bst.Insert(node);
  }
  std::cout << bst;
  std::cout << "This BST is valid or not: " << bst.isValidBST(bst.root_);

  return 0;  
}


