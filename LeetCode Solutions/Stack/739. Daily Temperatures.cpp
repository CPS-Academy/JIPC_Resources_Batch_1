class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> warmerDaysAhead(temperatures.size(), 0);
        int hottestTemperature = 0;
        int days = temperatures.size();
        for(int i = days - 1; i >= 0; i--) {
            if(hottestTemperature <= temperatures[i]) {
                hottestTemperature = temperatures[i];
                continue;
            }
            int day = 1;
            while(temperatures[i + day] <= temperatures[i]) {
                day += warmerDaysAhead[day + i];
            }
            warmerDaysAhead[i] = day;
        }
        return warmerDaysAhead;
    }
};
