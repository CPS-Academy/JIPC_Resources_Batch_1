class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_set<int> jewelsSet;
        for(auto& jewel: jewels) {
            jewelsSet.insert(jewel);
        }

        int jewelCountInStones = 0;
        for(auto& stone: stones) {
            if(jewelsSet.count(stone)) {
                jewelCountInStones++;
            }
        }
        return jewelCountInStones;
    }
};

class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int jewelCountInStones = 0;
        for(auto& stone: stones) {
            for(auto& jewel: jewels) {
                if(stone == jewel) {
                    jewelCountInStones++;
                    break;
                }
            }
        }
        return jewelCountInStones;
    }
};

class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_set<char> jewelSet;
        for(auto& ch: jewels) {
            jewelSet.insert(ch);
        }

        int jewelCountInStones = 0;
        for(auto& ch: stones) {
            if(jewelSet.count(ch)) {
                jewelCountInStones++;
            }
        }
        
        return jewelCountInStones;
    }
};
