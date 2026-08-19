class Solution {
public:
    bool ispalindrome (string s, int start, int end) {
        while (start<=end) {
            if (s[start]!=s[end]) {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
    void solve(int i, string s, vector<vector<string>>& ans, vector<string>& curr) {
        if (i==s.size()) {
            ans.push_back(curr);
            return;
        }
        for (int j=i; j<s.size(); j++) {
            if (ispalindrome(s, i, j)) {
                curr.push_back(s.substr(i,j-i+1));
                solve(j+1, s, ans, curr);
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> curr;
        solve(0, s, ans, curr);
        return ans;
    }
};
