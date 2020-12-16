#include <stdio.h>
#include <algorithm>
#include <string>
#include <unordered_map>

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int nSamples;
    scanf("%d", &nSamples);
    std::vector<std::string> samples(nSamples);
    for (int i = 0; i < nSamples; i++) {
        char buf[1 + 50];
        scanf("%s", &buf);
        samples[i] = std::string(buf);
    }

    int nWords;
    scanf("%d", &nWords);
    std::vector<std::string> words(nWords);
    for (int i = 0; i < nWords; i++) {
        char buf[1 + 50];
        scanf("%s", &buf);
        words[i] = std::string(buf);
    }

    std::unordered_map<std::string, int> mp;
    for (std::string &word : words) {
        mp[word] = 0;
    }
    
    for (const std::string &sample : samples) {
        for (int len = 1; len <= (int)sample.length(); len++) {
            std::string pref = sample.substr(0, len);
            std::string suff = sample.substr((int)sample.length() - len);
            if (pref == suff) {
                auto it = mp.find(pref);
                if (it != mp.end()) {
                    it->second++;
                }
            }
        }
    }
    for (const std::string &word : words) {
        printf("%d\n", mp[word]);
    }
    return 0;
}
