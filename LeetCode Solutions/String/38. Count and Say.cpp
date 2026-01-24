class Solution {
public:
    string countAndSay(int n) {
        string answer = "1";
        while(--n) {
            string updatedAnswer = "";
            int adjacentDigitCount = 1;
            for(int i = 0; i + 1 < answer.size(); i++) {
                if(answer[i] == answer[i + 1]) {
                    adjacentDigitCount++;
                }
                else {
                    updatedAnswer += to_string(adjacentDigitCount) + answer[i];
                    adjacentDigitCount = 1;
                }
            }
            updatedAnswer += to_string(adjacentDigitCount) + answer[ answer.size() - 1 ];
            answer = updatedAnswer;
        }

        return answer;
    }
};
