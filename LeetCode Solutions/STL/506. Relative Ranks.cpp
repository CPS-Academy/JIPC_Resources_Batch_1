class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        unordered_map<int, int> scorePlayerMap;
        int maxScore = 0;
        for(int i = 0; i < score.size(); i++) {
            int currentScore = score[i];
            maxScore = max(maxScore, currentScore);
            scorePlayerMap[currentScore] = i;
        }

        vector<string> relativeRanks(score.size(), "");
        int currentRank = 1;
        while(maxScore >= 0) {
            if(!scorePlayerMap.count(maxScore)) {
                maxScore--;
                continue;
            }
            int player = scorePlayerMap[maxScore];
            if(currentRank == 1) {
                relativeRanks[player] = "Gold Medal";
            }
            else if(currentRank == 2) {
                relativeRanks[player] = "Silver Medal";
            }
            else if(currentRank == 3) {
                relativeRanks[player] = "Bronze Medal";
            }
            else {
                relativeRanks[player] = to_string(currentRank);
            }
            currentRank++;
            maxScore--;
        }
        return relativeRanks;
    }
};

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        unordered_map<int, int> scorePlayerMap;
        for(int i = 0; i < score.size(); i++) {
            int currentScore = score[i];
            scorePlayerMap[currentScore] = i;
        }
        sort(score.begin(), score.end(), greater<int>());

        vector<string> relativeRanks(score.size(), "");
        int currentRank = 1;
        for(auto& currentScore: score){
            int player = scorePlayerMap[currentScore];
            if(currentRank == 1) {
                relativeRanks[player] = "Gold Medal";
            }
            else if(currentRank == 2) {
                relativeRanks[player] = "Silver Medal";
            }
            else if(currentRank == 3) {
                relativeRanks[player] = "Bronze Medal";
            }
            else {
                relativeRanks[player] = to_string(currentRank);
            }
            currentRank++;
        }
        return relativeRanks;
    }
};

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        priority_queue<pair<int, int>> maxHeap;
        for(int i = 0; i < score.size(); i++) {
            maxHeap.push({score[i], i});
        }
        vector<string> relativeRanks(score.size(), "");
        int currentRank = 1;
        while(!maxHeap.empty()) {
            pair<int, int> scorePlayerPair = maxHeap.top(); maxHeap.pop();
            int score = scorePlayerPair.first;
            int player = scorePlayerPair.second;
            if(currentRank == 1) {
                relativeRanks[player] = "Gold Medal";
            }
            else if(currentRank == 2) {
                relativeRanks[player] = "Silver Medal";
            }
            else if(currentRank == 3) {
                relativeRanks[player] = "Bronze Medal";
            }
            else {
                relativeRanks[player] = to_string(currentRank);
            }
            currentRank++;
        }
        return relativeRanks;
    }
};
