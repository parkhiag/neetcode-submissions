class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        
        unordered_map<char,int> freq;
        for (auto it: tasks) {
            freq[it]++;
        }

        priority_queue<int> pq;
        // larger freq at top
        for (auto it : freq) {
            pq.push(it.second);
        }
        int currtime=0;
        queue<pair<int,int>> q;

        while (!pq.empty() || !q.empty()) {
            currtime++;
            if (!pq.empty()) {
                int f = pq.top();
                pq.pop();
                f--;
                if (f>0) {
                    q.push({f,currtime+n});
                }
            }
            if (!q.empty()&& q.front().second==currtime) {
                pq.push(q.front().first);
                q.pop();
            }
        }
        return currtime;
    }
};