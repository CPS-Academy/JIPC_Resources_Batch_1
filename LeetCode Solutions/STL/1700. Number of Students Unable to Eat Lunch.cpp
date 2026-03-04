class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int circularPreferers = 0;
        for(auto& student: students) {
            if(student == 0) circularPreferers++;
        }
        int squarePreferers = students.size() - circularPreferers;

        stack<int> sandwichStack(sandwiches.rbegin(), sandwiches.rend());

        while(!sandwichStack.empty()) {
            if(sandwichStack.top() == 0 && circularPreferers == 0) {
                return squarePreferers;
            }
            if(sandwichStack.top() == 1 && squarePreferers == 0) {
                return circularPreferers;
            }
            if(sandwichStack.top() == 0 && circularPreferers > 0) {
                circularPreferers--;
            }
            else if(sandwichStack.top() == 1 && squarePreferers > 0) {
                squarePreferers--;
            }
            sandwichStack.pop();
        }

        return 0;
    }
};
