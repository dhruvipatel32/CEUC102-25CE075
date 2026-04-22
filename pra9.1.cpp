#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> v;
    int n, x;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> x;
        v.push_back(x);
    }

    // -------- METHOD 1: std::reverse --------
    vector<int> v1 = v;
    reverse(v1.begin(), v1.end());

    cout << "\nUsing std::reverse(): ";
    for (int val : v1)
        cout << val << " ";

    // -------- METHOD 2: Manual using iterators --------
    vector<int> v2 = v;

    auto start = v2.begin();
    auto end = v2.end() - 1;

    while (start < end) {
        swap(*start, *end);
        start++;
        end--;
    }

    cout << "\nManual reversal: ";
    for (auto it = v2.begin(); it != v2.end(); it++)
        cout << *it << " ";

    return 0;
}
