class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>> q;
        q.push({beginWord,1});

        unordered_set<string> st;
        st.insert(wordList.begin(), wordList.end());
        if (st.find(beginWord)!=st.end()) st.erase(beginWord);
        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            string word = it.first;
            int steps = it.second;
            if (word==endWord) return steps;
            for (int i=0; i<word.size(); i++) {
                char original = word[i];
                for (int k='a'; k<='z'; k++) {
                    word[i]=k;
                    if (st.find(word)!=st.end()) {
                        st.erase(word);
                        q.push({word, steps+1});
                    }
                }
                word[i]=original;
            }
        }
        return 0;
    }
};