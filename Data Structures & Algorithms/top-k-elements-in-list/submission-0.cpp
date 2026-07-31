class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();

        unordered_map<int,int> freq(n);

        for (int num : nums) {
            freq[num]++;
        }

        priority_queue<pair<int,int>> pq;

        for (auto x : freq) {
            pq.push({x.second, x.first});
        }

        vector<int> ans;

        for (int i=0; i<n; i++) {
            while (k!=0) {
                ans.push_back(pq.top().second);
                k--;
                pq.pop();
            }
        }
        return ans;
    }
};
