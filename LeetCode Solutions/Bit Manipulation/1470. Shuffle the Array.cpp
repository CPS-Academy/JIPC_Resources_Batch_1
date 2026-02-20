class Solution {
   
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        return shuffleInPlace(nums, n); // comment it for naive code
        // naive solution with extra space
        vector<int> result(2 * n);
        // time O(n)
        // space O(1)
        for(int i = 0; i < n; i++){
            result[2 * i] = nums[i]; // filling all x positions
            result[2 * i + 1] = nums[n + i]; // filling all y positions
        }
        return result;
    }


    int getPos(int i, int n){
        return (i < n) ? (2 * i) : (2 * (i - n) + 1);
    }
    vector<int> shuffleInPlace(vector<int>& nums, int n) {
        // time O(n)
        // space O(1)
        int newval, oldval;
        for(int i = 0; i < 2*n ; i++){
            if(nums[i] < 0) continue; // check if touched tracker is present


            int newpos = getPos(i, n); // somehow we will find this, based on i and n
            newval = nums[i];
            while(nums[newpos] > 0){
                oldval = nums[newpos];   // 4, the value that got replaced
                nums[newpos] = -newval; // -9, the value that replaces along with tracker - sign


                newpos = getPos(newpos, n); // based on existing newpos and n
                newval = oldval;
            }
        }
        for(int i = 0; i < 2*n; i++){
            nums[i] = -nums[i]; // remove the tracker
        }
        return nums;
    }


    // what happens when -10^9 <= nums[i] <= 10^9 ?
};
