class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        vector<int> result(n);


        // make a copy
        for(int i = 0; i < n; i++){
            result[i] = digits[i]; // time O(n)
        }


        bool lessThan9Found = false;
        for(int i = n - 1; i >= 0; i--){ // time O(n)
            if(digits[i] == 9){
                result[i] = 0;
            }
            else{
                result[i] = digits[i] + 1;
                lessThan9Found = true;
                break;
            }
        }
        if(!lessThan9Found){
            // insert 1 at the beginning
            result.insert(result.begin(), 1); // time O(n)
        }


        // time O(n)
        // space O(1)
        return result;
    }
};
