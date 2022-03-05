#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int Search(vector<int>& A, int key){
    return binary_search(A.begin(), A.end(), key);
}

int Predecessor(vector<int>&A, int key){
    vector<int>::iterator low,it,prev;
    low = lower_bound(A.begin(), A.end(), key);
    it = A.begin();
    if(it == low){
        return 0;
    }
    while(it!=low){
        prev = it;
        it++;
    };
    return *prev;
}
   
int Successor(vector<int>& A, int key){
    vector<int>::iterator up;
    up = upper_bound(A.begin(), A.end(), key);
    return *up;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n = 0;
    cin>>n;
   
    vector<int> A(n,0);
    for(int i=0; i<n; i++){
        cin>>A[i];
    }
   
    int m = 0;
    cin>>m;
   
    vector<vector<int>> queries(m,vector<int>(2));
    for(int i=0; i<m; i++){
        for(int j=0; j<2; j++){
            cin>>queries[i][j];
        }
    }
    sort(A.begin(),A.end());
   
    //vector<int> ans;
    for(int i = 0; i < m; i++){
        if(queries[i][0] == 1){
            //ans.push_back(Search(A, queries[i][1]));
            cout<<Search(A, queries[i][1])<<endl;
        }else if(queries[i][0] == 2){
            //ans.push_back(Predecessor(A, queries[i][1]));
            cout<<Predecessor(A, queries[i][1])<<endl;
        }else{
            //ans.push_back(Successor(A, queries[i][1]));
            cout<<Successor(A, queries[i][1])<<endl;
        }
    }
    /*
    for(const auto& x:ans){
        cout<<x<<endl;
    }*/
    return 0;
}