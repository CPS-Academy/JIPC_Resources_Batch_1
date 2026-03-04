class Solution {
private:
    static constexpr int MINUTES_IN_DAY = 24 * 60;
    static constexpr int MINUTES_IN_HOUR = 60;

    int convertTimeToMinutes(string time) {
        int hours = stoi(time.substr(0, 2));
        int minutes = stoi(time.substr(3));
        return hours*MINUTES_IN_HOUR + minutes;
    }
    bool isValidTime(int currentTimeInMinutes, unordered_set<int>& allowedDigits) {

        int hours = currentTimeInMinutes / 60;
        int minutes = currentTimeInMinutes % 60;

        // 20:55
        int h1 = hours/10; // 2
        int h2 = hours%10; // 0
        int m1 = minutes/10; // 5
        int m2 = minutes%10; // 5

        return allowedDigits.count(h1) 
        && allowedDigits.count(h2) 
        && allowedDigits.count(m1) 
        && allowedDigits.count(m2);
    }

    string formatTime(int currentTimeInMinutes) {
        int hours = currentTimeInMinutes / 60;
        int minutes = currentTimeInMinutes % 60;

        // 01:05 -> 1:5
        string hoursInString = (hours < 10) ? "0" + to_string(hours) : to_string(hours);
        string minutesInString = (minutes < 10) ? "0" + to_string(minutes) : to_string(minutes);

        return hoursInString + ":" + minutesInString;
    }
public:
    string nextClosestTime(string time) {
        int currentTimeInMinutes = convertTimeToMinutes(time);
        unordered_set<int> allowedDigits;
        for(char ch: time) {
            if(ch != ':') {
                allowedDigits.insert(ch - '0');
            }
        }
        while(true) {
            currentTimeInMinutes = currentTimeInMinutes + 1;
            if(MINUTES_IN_DAY < currentTimeInMinutes) {
                currentTimeInMinutes = 0;
            }

            if(isValidTime(currentTimeInMinutes, allowedDigits)) {
                return formatTime(currentTimeInMinutes);
            }
        }
    }
};
