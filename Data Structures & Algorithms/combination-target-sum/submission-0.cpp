class Solution {
public:
    void solve(int i, vector<int>& curr, vector<vector<int>>& ans, int target, vector<int>& nums) {
        if (target==0) {
            ans.push_back(curr);
            return;
        }
        if (target<0 || i==nums.size()) return;
        // take 
        curr.push_back(nums[i]);
        solve(i, curr, ans, target-nums[i], nums);
        curr.pop_back();
        solve(i+1, curr, ans, target, nums);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> curr;
        vector<vector<int>> ans;
        
        solve(0, curr, ans, target, nums);
        return ans;
    }
};
