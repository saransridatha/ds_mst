#include <iostream>
#include <string>

using namespace std;

int main() {
    string arr[] = {"hello world", "example string", "pattern matching", "search and replace"};
    int arrSize = 4;

    string patterns[] = {"hello", "pattern", "search"};
    int patSize = 3;

    string foundPatterns = "";

    for (int i = 0; i < arrSize; ++i) {
        for (int j = 0; j < patSize; ++j) {
            if (arr[i].find(patterns[j]) != string::npos) {
                foundPatterns += patterns[j] + " ";
                arr[i].replace(arr[i].find(patterns[j]), patterns[j].length(), "REPLACED");
            }
        }
    }

    for (int i = 0; i < arrSize; ++i) {
        cout << arr[i] << endl;
    }

    cout << "Found Patterns: " << foundPatterns << endl;

    return 0;
}
