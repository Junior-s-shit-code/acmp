#include <stdio.h>
#include <vector>
#include <algorithm>

struct Task {

    int begin;

    int end;

    int cost;

    static Task read() {
        int begin, time, cost;
        scanf("%d %d %d", &begin, &time, &cost);
        return Task{ begin, begin + time, cost };
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    scanf("%d", &n);
    std::vector<Task> tasks(n);
    for (int i = 0; i < n; i++) {
        tasks[i] = Task::read();
    }
    std::vector<int> times;
    for (Task &task : tasks) {
        times.push_back(task.begin);
        times.push_back(task.end);
    }
    std::sort(times.begin(), times.end());
    times.erase(std::unique(times.begin(), times.end()), times.end());
    int nT = (int)times.size();
    for (Task &p : tasks) {
        p.begin = int(std::lower_bound(times.begin(), times.end(), p.begin) - times.begin());
        p.end = int(std::lower_bound(times.begin(), times.end(), p.end) - times.begin());
    }
    std::vector<std::vector<int>> startingAt(nT);
    for (int i = 0; i < n; i++) {
        startingAt[tasks[i].begin].push_back(i);
    }
    std::vector<long long> maxSum(nT, 0);
    std::vector<int> tasksUsed(nT, -1);
    for (int t = 0; t < nT; t++) {
        if (t > 0) {
            if (maxSum[t] < maxSum[t - 1]) {
                maxSum[t] = maxSum[t - 1];
                tasksUsed[t] = -1;
            }
        }
        for (int tid : startingAt[t]) {
            Task &task = tasks[tid];
            if (maxSum[task.end] < maxSum[task.begin] + task.cost) {
                maxSum[task.end] = maxSum[task.begin] + task.cost;
                tasksUsed[task.end] = tid;
            }
        }
    }
    printf("%lld\n", maxSum.back());
    std::vector<int> ans;
    int t = nT - 1;
    while (t > 0) {
        if (tasksUsed[t] == -1) {
            t--;
        } else {
            int tid = tasksUsed[t];
            ans.push_back(tasksUsed[t]);
            t = tasks[tid].begin;
        }
    }
    int ansSize = (int)ans.size();
    printf("%d\n", ansSize);
    for (int i = ansSize - 1; i >= 0; i--) {
        printf("%d ", ans[i] + 1);
    }
    return 0;
}