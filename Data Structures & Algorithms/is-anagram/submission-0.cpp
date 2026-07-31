class Solution {
public:
    bool isAnagram(string s, string t) {
        int n1=s.size();
        int n2=t.size();

        if (n1!=n2) return false;

        unordered_map<char,int> freq;
        // we can store the freq of each element in s. 
        // and then we can decrease the freq for each element in t.
        // if at the end, freq of all elements is 0, return true.

        for (int i=0; i<n1; i++) {
            freq[s[i]]++;
        }

        for (int i=0; i<n2; i++) {
            freq[t[i]]--;
        }

        for (auto x : freq) {
            if (x.second!=0) return false;
        }
        return true;
    }
};
