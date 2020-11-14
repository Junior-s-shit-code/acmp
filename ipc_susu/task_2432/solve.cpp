#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>

struct Query {

    int right;

    int id;
};

struct Node {

    int left;

    int right;

    int sum;

    int minSuf;

    Node operator+(const Node &second) {
        return Node{
            left,
            second.right,
            sum + second.sum,
            std::min(minSuf + second.sum, second.minSuf)
        };
    }
};

class SegmentTree {

private:

    int size;

    std::vector<Node> tree;

    void build(int pos, int left, int right, const std::vector<int> &balance) {
        if (left == right) {
            tree[pos] = Node{ left, right, balance[left], std::min(balance[left], 0) };
            return;
        }
        int mid = (left + right) >> 1;
        build((pos << 1) + 1, left, mid, balance);
        build((pos << 1) + 2, mid + 1, right, balance);
        tree[pos] = tree[(pos << 1) + 1] + tree[(pos << 1) + 2];
    }

    Node get(int pos, int left, int right) {
        if (tree[pos].left == left && tree[pos].right == right) {
            return tree[pos];
        }
        int mid = (tree[pos].left + tree[pos].right) >> 1;
        if (right <= mid) {
            return get((pos << 1) + 1, left, right);
        } else if (left > mid) {
            return get((pos << 1) + 2, left, right);
        } else {
            return get((pos << 1) + 1, left, mid) + get((pos << 1) + 2, mid + 1, right);
        }
    }

    void update(int pos, int id, const int value, std::vector<int> &balance) {
        if (tree[pos].left == tree[pos].right) {
            balance[id] += value;
            tree[pos] = Node{ id, id, balance[id], std::min(balance[id], 0) };
            return;
        }
        int mid = (tree[pos].left + tree[pos].right) >> 1;
        if (id <= mid) {
            update((pos << 1) + 1, id, value, balance);
        } else {
            update((pos << 1) + 2, id, value, balance);
        }
        tree[pos] = tree[(pos << 1) + 1] + tree[(pos << 1) + 2];
    }

public:

    SegmentTree(const std::vector<int> &balance) {
        size = (int)balance.size();
        tree.resize(4 * size);
        build(0, 0, size - 1, balance);
    }

    Node get(int left, int right) {
        return get(0, left, right);
    }

    void update(int id, int value, std::vector<int> &balance) {
        update(0, id, value, balance);
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    scanf("%d", &n);
    char buf[1 + 500000];
    scanf("%s", &buf);
    std::string s(buf);
    std::vector<int> balance(n);
    for (int i = 0; i < n; i++) {
        balance[i] = s[i] == '(' ? 1 : -1;
    }
    SegmentTree tree(balance);
    int nQueries;
    scanf("%d", &nQueries);
    std::vector<std::vector<Query>> queries(n);
    for (int iQ = 0; iQ < nQueries; iQ++) {
        int left, right;
        scanf("%d %d", &left, &right);
        left--;
        right--;
        queries[left].push_back(Query{ right, iQ });
    }
    std::vector<int> answers(nQueries);
    std::vector<int> stack;
    for (int i = n - 1; i >= 0; i--) {
        if (balance[i] == -1) {
            stack.push_back(i);
            tree.update(i, 1, balance);
        } else if (!stack.empty()) {
            tree.update(stack.back(), -1, balance);
            stack.pop_back();
        }
        for (Query &query : queries[i]) {
            int left = i;
            int right = query.right;
            answers[query.id] = std::upper_bound(stack.rbegin(), stack.rend(), right)
                - stack.rbegin()
                - tree.get(left, right).minSuf;
        }
    }
    for (int ans : answers) {
        printf("%d\n", ans);
    }
    return 0;
}