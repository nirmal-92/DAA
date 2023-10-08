#include <iostream>
#include <string>

using namespace std;

// Rabin-Karp Algorithm
void searchRabinKarp(const string& text, const string& pattern) {
    int n = text.length();
    int m = pattern.length();

    // Calculate the hash of the pattern
    int patternHash = 0;
    int textHash = 0;
    const int prime = 101; // You can use any prime number

    // Calculate the initial hash values
    for (int i = 0; i < m; i++) {
        patternHash = (patternHash + pattern[i]) % prime;
        textHash = (textHash + text[i]) % prime;
    }

    for (int i = 0; i <= n - m; i++) {
        if (patternHash == textHash) {
            bool match = true;
            for (int j = 0; j < m; j++) {
                if (text[i + j] != pattern[j]) {
                    match = false;
                    break;
                }
            }
            if (match) {
                cout << "Pattern found at index " << i << endl;
            }
        }

        // Calculate the hash value for the next window of text
        if (i < n - m) {
            textHash = (textHash - text[i] + text[i + m]) % prime;
            if (textHash < 0) {
                textHash += prime;
            }
        }
    }
}

int main() {
    string text, pattern;

    cout << "Enter the text: ";
    getline(cin, text);

    cout << "Enter the pattern to search for: ";
    getline(cin, pattern);

    searchRabinKarp(text, pattern);

    return 0;
}

