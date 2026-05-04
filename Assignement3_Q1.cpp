#include <iostream>
#include <string>
using namespace std;

bool aresame(string a, string b) {
    return a == b;
}

int main() {
    const int MAX_WORDS = 100;
    const int MAX_SENTENCES = 2;

    string usentence[MAX_SENTENCES][MAX_WORDS];
    string sentence;
    int wordCount[MAX_SENTENCES] = { 0, 0 };

    cout << "Enter two sentences:" << endl;

    // Read 2 sentences
    for (int s = 0; s < MAX_SENTENCES; ++s) {
        getline(cin, sentence);
        if (sentence.empty()) break;

        string word = "";
        int w = 0;

        for (int i = 0; i <= sentence.length(); ++i) {
            char c = sentence[i];

            if (c == ' ' || c == '\0') {
                if (!word.empty()) {
                    usentence[s][w++] = word;
                    word = "";
                }
            }
            else {
                word += c;
            }
        }
        wordCount[s] = w; // store number of words for this sentence
    }

    // Compare common words
    string commonWords[MAX_WORDS];
    int commonCount = 0;

    for (int i = 0; i < wordCount[0]; ++i) {
        bool alreadyFound = false;

        for (int k = 0; k < commonCount; ++k) {
            if (usentence[0][i] == commonWords[k]) {
                alreadyFound = true;
                break;
            }
        }
        if (alreadyFound) continue;

        for (int j = 0; j < wordCount[1]; ++j) {
            if (aresame(usentence[0][i], usentence[1][j])) {
                commonWords[commonCount++] = usentence[0][i];
                break;
            }
        }
    }

    // Compare consecutive word pairs
    string pairs1[MAX_WORDS], pairs2[MAX_WORDS], commonPairs[MAX_WORDS];
    int pairCount1 = 0, pairCount2 = 0, commonPairCount = 0;

    for (int i = 0; i < wordCount[0] - 1; ++i)
        pairs1[pairCount1++] = usentence[0][i] + " " + usentence[0][i + 1];

    for (int i = 0; i < wordCount[1] - 1; ++i)
        pairs2[pairCount2++] = usentence[1][i] + " " + usentence[1][i + 1];

    for (int i = 0; i < pairCount1; ++i) {
        bool alreadyFound = false;
        for (int k = 0; k < commonPairCount; ++k) {
            if (pairs1[i] == commonPairs[k]) {
                alreadyFound = true;
                break;
            }
        }
        if (alreadyFound) continue;

        for (int j = 0; j < pairCount2; ++j) {
            if (aresame(pairs1[i], pairs2[j])) {
                commonPairs[commonPairCount++] = pairs1[i];
                break;
            }
        }
    }

    // Display results
    cout << "\nNumber of common words: " << commonCount << endl;
    if (commonCount > 0) {
        cout << "Common words: ";
        for (int i = 0; i < commonCount; ++i)
            cout << commonWords[i] << " ";
        cout << endl;
    }

    cout << "\nNumber of common consecutive word pairs: " << commonPairCount << endl;
    if (commonPairCount > 0) {
        cout << "Common pairs: ";
        for (int i = 0; i < commonPairCount; ++i)
            cout << "[" << commonPairs[i] << "] ";
        cout << endl;
    }

    return 0;
}