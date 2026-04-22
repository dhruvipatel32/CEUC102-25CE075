#include <iostream>
#include <map>
#include <sstream>
using namespace std;

int main() {
    string sentence, word;
    map<string, int> freq;

    cout << "Enter a sentence:\n";
    getline(cin, sentence);

    stringstream ss(sentence);

    while (ss >> word) {
        freq[word]++;   // key concept
    }

    cout << "\nWord Frequencies:\n";
    for (auto it = freq.begin(); it != freq.end(); it++) {
        cout << it->first << " : " << it->second << endl;
    }

    return 0;
}
