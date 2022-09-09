#include <stdio.h>
#include <string>
#include <vector>

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    const int INF = (int) 1e9;
    const int MAX_LEN = 100;
    std::vector<int> a;
    int wordLength = 0;
    int maxWordLen = 0;
    while (true) {
        char c;
        int code = scanf("%c", &c);
        if (code == EOF || c == '\n') {
            a.push_back(wordLength);
            maxWordLen = std::max(maxWordLen, wordLength);
            break;
        } else if (c == ' ') {
            a.push_back(wordLength);
            maxWordLen = std::max(maxWordLen, wordLength);
            wordLength = 0;
        } else {
            wordLength++;
        }
    } 
    int bestProd = INF;
    int bestLen = INF;
    int bestH = INF;
    for (int len = maxWordLen; len <= MAX_LEN; len++) {
        int curH = 0;
        int curWordsLength = 0;
        for (int iWord = 0; iWord < (int)a.size(); iWord++) {
            curWordsLength = a[iWord];
            while (iWord + 1 < (int)a.size() &&
                curWordsLength + 1 + a[iWord + 1] <= len
            ) {
                curWordsLength += 1 + a[iWord + 1];
                iWord++;
            }
            curH++;
        }
        int curProd = len * curH;
        if (curProd <= bestProd) {
            bestProd = curProd;
            bestLen = len;
            bestH = curH;
        }
    }
    printf("%d %d", bestLen, bestH);
    return 0;
}