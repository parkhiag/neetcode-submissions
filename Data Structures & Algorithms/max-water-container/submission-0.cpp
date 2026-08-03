class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int left=0;
        int right=n-1;
        int ans = 0;
        while (left<right) {
            ans = max(ans, (min(heights[left], heights[right]))*(right-left));
            if (heights[right]>heights[left]) {
                left++;
            }
            else {
                right--;
            }
        }
        return ans;
    }
};
