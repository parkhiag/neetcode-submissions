class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        // we use indegree to write the order. 
        // the element having indegree 0 is the one which is not dependent on anyone
        // and thus will come first. 

        // build graph, calculate indegree, kahns algo, check cycle. 
        vector<bool> present(26,false);
        vector<unordered_set<int>> adj(26);

        for (auto &word : words) {
            for (char ch: word) {
                present[ch-'a'] = true;
            }
        }
        
        for (int i=0; i<words.size()-1; i++) {
            string a = words[i];
            string b = words[i+1];
            
            int len = min(a.size(), b.size());
            bool diff=false;
            for (int j=0; j<len; j++) {
                if (a[j]!=b[j]) {
                    // there is an edge from a[j] to b[j].
                    adj[a[j]- 'a' ].insert(b[j]- 'a');
                    diff=true;
                    break;
                }
            }
            if (!diff && a.size()>b.size()) return "";
        }
        vector<int> indegree(26,0);

        for (int u=0; u<26; u++) {
            for (int v : adj[u]) {
                indegree[v]++;
            }
        }
        queue<int> q;
        for (int i=0; i<26; i++) {
            if (indegree[i]==0 && present[i]) {
                q.push(i);
            }
        }
        string ans = "";
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            ans+=char(u+'a');
            for (int v : adj[u]) {
                indegree[v]--;
                if (indegree[v]==0) {
                    q.push(v);
                }
            }
        }
        int count = 0;
        for (int i=0; i<26; i++) {
            if (present[i]) {
                count++;
            }
        }
        if (ans.size()!=count) {
            return "";
        }
        return ans;
    }
};
