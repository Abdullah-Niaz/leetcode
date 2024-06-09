#include <iostream>
#include <string>

using namespace std;

bool isAcronym(string words[], int size, const string& s) {
    string acronym = "";
    for (int i = 0; i < size; i++) {
        acronym += words[i][0];
    }
    return acronym == s;
}

int main() {
    string words[] = {"alice", "bob", "charlie"}; 
    int size = sizeof(words) / sizeof(words[0]);
    string s = "abc";
    bool result = isAcronym(words, size, s);
    cout << (result ? "true" : "false") << endl;
    return 0;
}
