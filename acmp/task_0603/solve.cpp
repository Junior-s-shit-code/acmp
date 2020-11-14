#include <stdio.h>
#include <string>

bool isSame(const std::string& sample, const std::string& str, const int i) {
    bool isPrevSpace = false;
    bool ans = true;
    int extraId = 0;
    for (int j = 0; j < (int)sample.size(); j++) {
        int newId = i + j + extraId;
        if (newId >= (int)str.size()) {
            ans = false;
            break;
        }
        char c = str[newId];
        if ((c == ' ' || c == '\t' || c == '\n') && isPrevSpace) {
            extraId++;
            j--;
            continue;
        } else if (c == ' ' || c == '\t' || c == '\n') {
            c = ' ';
            isPrevSpace = true;
        } else {
            c = std::tolower(c);
            isPrevSpace = false;
        }
        
        if (c != sample[j]) {
            ans = false;
            break;
        }
    }
    return ans;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    char c;
    std::string sample = "";
    bool isPrevSpace = true;
    while (true) {
        scanf("%c", &c);
        if (c == '\n') {
            break;
        } else if ((c == '\t' || c == ' ') && !isPrevSpace) {
            sample += ' ';
            isPrevSpace = true;
        } else if (c == '\t' || c == ' ') {
            continue;
        } else {
            sample += std::tolower(c);
            isPrevSpace = false;
        }
    }
    int sSize = (int)sample.length();
    if (sample[sSize - 1] == ' ') {
        sample.erase(sample.begin() + sSize - 1);
    }
    std::string str = "";
    while (true) {
        int code = scanf("%c", &c);
        if (code == EOF) {
            break;
        }
        str += c;
    }
    int strSize = (int)str.length();
    for (int i = 0; i < strSize; i++) {
        if (isSame(sample, str, i)) {
            printf("@%c", str[i]);
        } else {
            printf("%c", str[i]);
        }
    }
    return 0;
}