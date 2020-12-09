#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>

// strings
// O(len)

char c;
int code;

void nextChar() {
    code = scanf("%c", &c);
    if (code == EOF) {
        c = '<';
    }
}

bool text() {
    return 'A' <= c && c <= 'Z' ||
        'a' <= c && c <= 'z' ||
        '0' <= c && c <= '9';
}

bool punctuation() {
    return c == '.' ||
        c == ',' ||
        c == '?' ||
        c == '!' ||
        c == '-' ||
        c == ':' ||
        c == 39; // 39 == ' char
}

bool willNewLine() {
    if (c == '\n') {
        nextChar();
        if (c == '\n') {
            return true;
        }
    }
    return false;
}

std::string getWord() {
    std::string word = "";
    while (text()) {
        word += c;
        nextChar();
    }
    return word;
}

void printNewParagraph(int nWhitespaces) {
    for (int i = 0; i < nWhitespaces; i++) {
        printf(" ");
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int maxLineLen, nWhitespaces;
    scanf("%d %d", &maxLineLen, &nWhitespaces);
    int curLineLen = nWhitespaces;
    bool newParagraph = false;
    bool whitespaceBefore = false;
    printNewParagraph(nWhitespaces);
    while (true) {
        if (code == EOF) {
            break;
        }
        bool nextWillNewParagraph = false;
        if (newParagraph) {
            newParagraph = false;
            printf("\n");
            printNewParagraph(nWhitespaces);
            curLineLen = nWhitespaces;
        }
        if (text()) {
            std::string word = getWord();
            bool wasNewLine = false;
            while (!text() && code != EOF) {
                if (c == '\n' && wasNewLine) {
                    nextWillNewParagraph = true; 
                    break;
                } else if (c == '\n') {
                    wasNewLine = true;
                } else if (punctuation()) {
                    word.insert(word.end(), c);
                    wasNewLine = false;
                }
                nextChar();
            }
            int wordLen = (int)word.length();

            std::string whitespace = "";
            int whitespaceLen = 0;
            if (whitespaceBefore) {
                whitespace = " ";
                whitespaceLen = 1;
            }

            if (curLineLen + wordLen + whitespaceLen <= maxLineLen) {
                printf("%s", (whitespace + word).c_str());
                curLineLen += wordLen + whitespaceLen;
            } else {
                printf("\n%s", word.c_str());
                curLineLen = wordLen;
            }
            whitespaceBefore = true;
            
            if (nextWillNewParagraph) {
                whitespaceBefore = false;
                nextWillNewParagraph = false;
                newParagraph = true;
            }
        } else {
            nextChar();
        }
    }
    return 0;
}