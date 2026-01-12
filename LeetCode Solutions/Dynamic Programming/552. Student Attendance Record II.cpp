class Solution {
private:
    const static int INVALID = -1;
    const static int MOD = 1000000007;
    const static int MAX_DAYS = 100005;
    const static int MAX_ABSENT_LIMIT = 2;
    const static int MAX_LATE_STREAK = 3;
    int N;
    int ways[MAX_DAYS][MAX_ABSENT_LIMIT][MAX_LATE_STREAK];

    int findPossibleRecords(int day, int absentCount, int lateStreakCount) {
        if(absentCount >= 2 || lateStreakCount >= 3) {
            return 0;
        }
        if(day == N) {
            return 1;
        }

        int& currentWays = ways[day][absentCount][lateStreakCount];
        if(currentWays != INVALID) {
            return currentWays;
        }

        int absent = findPossibleRecords(day + 1, absentCount + 1, 0);
        int late = findPossibleRecords(day + 1, absentCount, lateStreakCount + 1);
        int present = findPossibleRecords(day + 1, absentCount, 0);

        return currentWays = ((absent + late) %MOD + present) %MOD;
    }

public:
    int checkRecord(int n) {
        memset(ways, INVALID, sizeof ways);
        N = n;
        return findPossibleRecords(0, 0, 0);
    }
};
