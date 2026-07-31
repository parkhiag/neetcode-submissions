class Solution {
public:
    bool isAnagram(string s, string t) {
        // to do it using constant space
        // we will define an array of size 26. 
        // now for each element of s, we increase count
        // and for each in t, we decrease count. 

        if (s.size()!=t.size()) return false;

        vector<int> freq(26);

        for (int i=0; i<s.size(); i++) {
            freq[s[i]-'a']++;
            freq[t[i]-'a']--;
        }

        for (auto x : freq) {
            if (x!=0) return false;
        }

        return true;
    }
};
