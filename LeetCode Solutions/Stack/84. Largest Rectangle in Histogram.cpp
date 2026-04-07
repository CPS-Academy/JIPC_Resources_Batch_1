class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> stk;
        stk.push(-1);
        int ans = 0;
        for(int i = 0; i < heights.size(); i++) {
            while(stk.top() != -1 && heights[ stk.top() ] >= heights[i]) {
                int currentMaxHeight = heights[ stk.top() ];
                stk.pop();
                ans = max(ans, (i - 1 - stk.top())*currentMaxHeight);
            }
            stk.push(i);
        }
        while(stk.top() != -1) {
            int currentMaxHeight = heights[ stk.top() ];
            stk.pop();
            ans = max(ans, ((int)heights.size() - 1 - stk.top())*currentMaxHeight);
        }
        return ans;
    }
};

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> histogramStack;
        histogramStack.push(-1);
        int maxArea = 0;
        for (int i = 0; i < heights.size(); i++) {
            while(histogramStack.top() != -1 && heights[ histogramStack.top() ] >= heights[i]) {
               int currentHeight = heights[ histogramStack.top() ];
               histogramStack.pop();
               int currentWeidth = i - histogramStack.top() - 1;
               maxArea = max(maxArea, currentHeight*currentWeidth);
            }
            histogramStack.push(i);
        }
        while(histogramStack.top() != -1) {
               int currentHeight = heights[ histogramStack.top() ];
               histogramStack.pop();
               int currentWeidth = heights.size() - histogramStack.top() - 1;
               maxArea = max(maxArea, currentHeight*currentWeidth);
        }

        return maxArea;
    }
};
