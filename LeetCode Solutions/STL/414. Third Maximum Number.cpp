class Solution {
private:
    const static int K_TH_MAX_NUMBER = 3;
public:
    int thirdMax(vector<int>& nums) {
        vector<int> maxValues;
        for(auto& num: nums) {
            
            stack<int> backupValues;
            while(!maxValues.empty() && maxValues.back() < num) {
                backupValues.push(maxValues.back());
                maxValues.pop_back();
            }

            if(maxValues.empty() || (maxValues.size() < K_TH_MAX_NUMBER && maxValues.back() > num)) {
                maxValues.push_back(num);
            }

            while(!backupValues.empty() && maxValues.size() < K_TH_MAX_NUMBER) {
                maxValues.push_back(backupValues.top());
                backupValues.pop();
            }
        }

        return maxValues.size() == K_TH_MAX_NUMBER ? maxValues.back() : maxValues[0];
    }
};


