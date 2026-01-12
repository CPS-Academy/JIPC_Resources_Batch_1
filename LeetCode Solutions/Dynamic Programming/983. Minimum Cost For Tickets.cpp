class Solution {
private:
    const int INVALID = -1;
    vector<int> minCost;

    int findNextDay(int dayIndex, int afterDays, vector<int>& days) {
        int nextDay = days.size();
        int i = 1;
        while(i <= afterDays && dayIndex + i < days.size()) {
            if(days[dayIndex] + afterDays <= days[dayIndex + i]) {
                nextDay = dayIndex + i;
                break;
            }
            i++;
        }
        return nextDay;
    }

    int findMinCost(int dayIndex, vector<int>& days, vector<int>& costs) {
        if(dayIndex == days.size()) {
            return 0;
        }

        int& minCostValue = minCost[dayIndex];
        if(minCostValue != INVALID) {
            return minCostValue;
        }

        int dailyPass = costs[0] + findMinCost(dayIndex + 1, days, costs);

        int afterSevenDays = findNextDay(dayIndex, 7, days);
        int weeklyPass = costs[1] + findMinCost(afterSevenDays, days, costs);

        int afterThirtyDays = findNextDay(dayIndex, 30, days);
        int monthlyPass = costs[2] + findMinCost(afterThirtyDays, days, costs);

        return minCostValue = min({dailyPass, weeklyPass, monthlyPass});
    }
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        minCost.assign(days.size(), INVALID);
        return findMinCost(0, days, costs);
    }
};
