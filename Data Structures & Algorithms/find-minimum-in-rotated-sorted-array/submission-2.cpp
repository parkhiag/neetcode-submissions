class Solution {
public:
    int findMin(vector<int> &nums) {
        int n=nums.size();
        // we find out which part is sorted and search in that portion

        int low=0;
        int high=n-1;
        int ans=INT_MAX;
        while (low<=high) {
            int mid = (high+low)/2;
            // left sorted
            if (nums[low]<=nums[mid]) {
                ans=min(ans,nums[low]);
                low=mid+1;
            }
            else {
                ans=min(ans,nums[mid]);
                high=mid-1;
            }
        }
        return ans;
    }
};
