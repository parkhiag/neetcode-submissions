class Solution {
public:
    unordered_map<int,string> mpp{
        {2, "abc"},
        {3, "def"},
        {4, "ghi"},
        {5, "jkl"},
        {6, "mno"},
        {7, "pqrs"},
        {8, "tuv"},
        {9, "wxyz"}
    };
    void solve(int i, string digits, string curr, vector<string>& ans) {
        if (curr.size()==digits.size()) {
            ans.push_back(curr);
            return;
        }
        int number = digits[i]-'0';

        for (auto ch : mpp[number]) {
            solve(i+1, digits, curr+ch, ans);
        }
    }
    vector<string> letterCombinations(string digits) {
        if (digits.size()==0) return {};
        string curr;
        vector<string> ans;
        solve(0, digits, curr, ans);
        return ans;
    }
};
