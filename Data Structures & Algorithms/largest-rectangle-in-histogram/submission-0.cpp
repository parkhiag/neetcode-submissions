class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        // for each bar, we will calculate what is the area which we can get including that
        // particular bar. 
        int area=0;
        stack<int> st;

        for (int i=0; i<n; i++) {
            while (!st.empty() && heights[i]<heights[st.top()]) {
                // our current element is smaller. 
                // so it will be limiting. 
                // we pop till we find the other limiting element. 
                int h = heights[st.top()];
                st.pop();
                int width = st.empty() ? i : i-st.top()-1;
                area = max(area, h*width);
            }
            st.push(i);
        }
        while (!st.empty()) {
            int h = heights[st.top()];
            st.pop();
            int width = st.empty() ? n: n - st.top() - 1;
            area = max(area, h*width);
        }

        return area;
    }
};
