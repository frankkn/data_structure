#include <cstdlib> 
#include <iostream>
#include <queue>
#include <vector>
using namespace std;


int main() {
    uint64_t n {};
    cin >> n;
    
    vector<uint64_t> R(n);
    for(auto& R_i : R){ cin >> R_i;}
    
    vector<uint64_t> P(n);
    for(auto& P_i : P){ cin >> P_i;}
    
    priority_queue<uint64_t> Max_heap;
    for(auto& R_i : R)
    {
        Max_heap.push(R_i);
    }
    
    priority_queue<uint64_t,vector<uint64_t>,greater<uint64_t>> Min_heap;
    for(auto& P_i : P)
    {
        Min_heap.push(P_i);
    }
    
    for(uint64_t i = 0; i < n; ++i)
    {
        uint64_t r = Max_heap.top();Max_heap.pop();
        uint64_t p = Min_heap.top();Min_heap.pop();
        uint64_t d = r/2;
        Max_heap.push(r-d);
        Min_heap.push(p+d);
    }
    
    uint64_t d = abs(double(Max_heap.top()) - double(Min_heap.top()));
    cout << d;
    
    return 0;
}
