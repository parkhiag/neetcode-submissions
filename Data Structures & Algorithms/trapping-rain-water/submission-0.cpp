class Solution {
public:
    int trap(vector<int>& height) {
        // at each index, the trapped water will be
        // boundary height - curr height. 
        // now boundary height will be the minimum of the maximum height at the left & right

        int n = height.size();
        int ans=0;
        int left=0;
        int right=n-1;
        int leftmax = 0;
        int rightmax = 0;

        while (left<=right) {
            if (height[left]<height[right]) {
                // left will be limiting.  
                // so we will be moving left ahead, but first we update leftmax. 
                if (height[left]>leftmax) {
                    leftmax=height[left];
                }
                else {
                    ans+=leftmax-height[left];
                }
                left++;
            }
            else {
                // right will be the limiting. 
                if (height[right]>rightmax) {
                    rightmax=height[right];
                }
                else {
                    ans+=rightmax-height[right];
                }
                right--;
            }
        }
        return ans;
    }
};
