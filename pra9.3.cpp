#include <iostream>
#include <set>
#include <vector>
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

    // Insert into set (removes duplicates automatically)
    set<int> s(v.begin(), v.end());

    cout << "\nUnique elements (sorted): ";
    for (auto it = s.begin(); it != s.end(); it++) {
        cout << *it << " ";
    }

    // Convert back to vector
    vector<int> uniqueVec(s.begin(), s.end());

    cout << "\n\nConverted back to vector: ";
    for (int val : uniqueVec)
        cout << val << " ";

    return 0;
}
