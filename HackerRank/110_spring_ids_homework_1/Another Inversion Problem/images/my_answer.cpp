#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

template <typename Iterator>
void MergeSort (Iterator begin, Iterator end)
{
  auto size {std::distance(begin, end)};
  if (size > 1)
  {
    auto middle {std::next(begin, size / 2)};
    MergeSort(begin, middle);
    MergeSort(middle, end);
    std::inplace_merge(begin, middle, end);
  }
  return;
}

int main() {
    uint64_t len_A, len_B, len_C;
    cin >> len_A >> len_B >> len_C;
    vector<uint64_t> A(len_A), B(len_B), C(len_C);
    
    for (auto& A_i : A) { cin >> A_i; }
    MergeSort(A.begin(), A.end());
    
    for (auto& B_i : B) { cin >> B_i; }
    MergeSort(B.begin(), B.end());
    
    for (auto& C_i : C) { cin >> C_i; }
    MergeSort(C.begin(), C.end());
    
    auto it_A {A.begin()}, it_C {C.begin()};
    uint64_t count {};

    for (auto it_B {B.begin()}; it_B != B.end(); it_B++)
    {
        while (it_A != A.end() && *it_A <= *it_B) { ++it_A; }
        while (it_C != C.end() && *it_C <= *it_B) { ++it_C; }
        count += (distance(it_A, A.end()) * distance(it_C, C.end()));
    }
    
    
    cout << count ;
    return 0;
}