#include <cstdio>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void Valid_order(vector<uint64_t>& A) {
    uint64_t i {1};
    stack<uint64_t> myStack;
    for(auto& A_i : A){
        if(myStack.empty()){ myStack.push(i++); }
        while(myStack.top() != A_i && i <= A.size())
        { 
            myStack.push(i++); 
        }
        if(myStack.top() == A_i)
        { 
            myStack.pop(); 
        }
        else
        { 
            cout << "NO" << "\n";
            break;
        }
    }
    if(myStack.empty()){
        cout << "YES" << "\n";    
    }
        
    return;
}

int main() {
    uint64_t queries {};
    cin >> queries;
    for(uint64_t i = 0; i < queries; i++){
        uint64_t n {};
        cin >> n;
        vector<uint64_t> A(n);
        for(auto& A_i : A) { cin >> A_i; }
        Valid_order(A);    
    }
    return 0;
}
