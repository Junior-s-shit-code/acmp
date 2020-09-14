#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>

struct PreparedData {

    int id;

    double frequency;

    static PreparedData read(const int id) {
        char c;
        double frequency;
        scanf(" %c %lf", &c, &frequency);
        return { id, frequency };
    }
};

struct RawData {

    char c;

    double frequency;
};

struct AnsData {

    int id;

    char c;
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, m;
    scanf("%d %d", &n, &m);
    std::vector <PreparedData> prepared(n);
    for (int i = 0; i < n; i++) {
        prepared[i] = PreparedData::read(i);
    }
    std::sort(prepared.begin(), prepared.end(), [](const PreparedData &left, const PreparedData &right) {
        return left.frequency > right.frequency;
    });
    char buf[1 + (int)100000];
    scanf("%s", &buf);
    std::string str(buf);
    const int SIZE_ALPHABET = 26;
    std::vector <int> count(SIZE_ALPHABET, 0);
    for (int i = 0; i < (int)str.length(); i++) {
        count[str[i] - 'a']++;
    }
    std::vector <RawData> raw(SIZE_ALPHABET);
    for (int i = 0; i < SIZE_ALPHABET; i++) {
        raw[i] = RawData{ (char) ('a' + i), 1.0 * count[i] / (int)str.length() };
    }
    std::sort(raw.begin(), raw.end(), [](const RawData &left, const RawData &right) {
        return left.frequency > right.frequency;
    });
    std::vector <AnsData> ans(n);
    for (int i = 0; i < n; i++) {
        ans[i] = AnsData{ prepared[i].id, raw[i].c };
    }
    std::sort(ans.begin(), ans.end(), [](const AnsData &left, const AnsData &right) {
        return left.id < right.id;
    });
    for (int i = 0; i < n; i++) {
        printf("%c\n", ans[i].c);
    }
    return 0;
}