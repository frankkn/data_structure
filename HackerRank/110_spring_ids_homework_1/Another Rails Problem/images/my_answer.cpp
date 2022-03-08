#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void Valid_order(vector<uint64_t>& A)
{
    uint64_t i {1};
    queue<uint64_t> myQueue;
    for(auto& A_i : A)
    {
        if(i == A_i)
        {
            i++; // move A to B without entering station
        }else{
            while(i != A_i && myQueue.front() != A_i && i <= A.size())
            {
                myQueue.push(i++); // move to station one by one
            }
            if(i != A_i) // the only possible coach is the front of the station
            {
                if(myQueue.front() != A_i){ // invalid coach
                    cout << "NO" << "\n";
                    return;
                }else{ // valid coach
                    myQueue.pop();
                }
            }
            else // move A to B without entering station
            {
                i++;
            }
        }
    }
    cout << "YES" << "\n";
}

int main() {
    uint64_t queries {};
    cin >> queries;
    for(uint64_t i = 0; i < queries; ++i){
        uint64_t n {};
        cin >> n;
        vector<uint64_t> A(n);
        for(auto& A_i : A) { cin >> A_i; }
        Valid_order(A);    
    }
    return 0;
}