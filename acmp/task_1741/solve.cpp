#include <stdio.h>
#include <vector>

bool canDrive(
    double time,
    const int fineId,
    const int nSegments,
    const std::vector<int> &maxSegmentSpeed,
    const std::vector<int> &speedLimits,
    const std::vector<int> &segmentLen
) {
    for (int i = 0; i < nSegments; i++) {
        int curSpeed = maxSegmentSpeed[i] + speedLimits[fineId];
        time -= 1.0 * segmentLen[i] / curSpeed;
    }
    return time >= 0;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int nSegments;
    scanf("%d", &nSegments);
    std::vector<int> maxSegmentSpeed(nSegments);
    for (int i = 0; i < nSegments; i++) {
        scanf("%d", &maxSegmentSpeed[i]);
    }
    std::vector<int> segmentLen(nSegments);
    for (int i = 0; i < nSegments; i++) {
        scanf("%d", &segmentLen[i]);
    }
    int nSpeedLimits;
    scanf("%d", &nSpeedLimits);
    std::vector<int> speedLimits(nSpeedLimits, 0);
    for (int i = 1; i < nSpeedLimits; i++) {
        scanf("%d", &speedLimits[i]);
    }
    std::vector<int> violationCost(nSpeedLimits + 1, 0);
    for (int i = 1; i <= nSpeedLimits; i++) {
        scanf("%d", &violationCost[i]);
    }
    int nQ;
    scanf("%d", &nQ);
    for (int q = 0; q < nQ; q++) {
        int start, end;
        scanf("%d %d", &start, &end);
        int time = end - start;
        int left = -1;
        int right = nSpeedLimits;
        while (left + 1 < right) {
            int mid = (left + right) >> 1;
            if (canDrive(time, mid, nSegments, maxSegmentSpeed, speedLimits, segmentLen)) { 
                right = mid;
            } else {
                left = mid;
            }
        }

        int maxCost = violationCost[right];
        printf("%d\n", maxCost);
    }
    return 0;
}