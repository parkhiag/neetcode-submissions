class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n-1;

        while (low<=high) {
            int mid = (high+low)/2;
            if (target==nums[mid]) return mid;
            // right sorted
            if (nums[mid]<=nums[high]) {
                // check if it exists in the right half.
                if (nums[mid]<target && target<=nums[high]) {
                    low=mid+1;
                }
                else {
                    high=mid-1;
                }
            }
            // left sorted
            else {
                // check if target exists in the left half. 
                if (nums[low]<=target && target<nums[mid]) {
                    high=mid-1;
                }
                else {
                    low=mid+1;
                }
            }
        }
        return -1;
    }
};

// 6 7 8 9 3 4 
