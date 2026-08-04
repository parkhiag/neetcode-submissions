class Solution {
public:
    string minWindow(string s, string t) {
        // we make a list of all the chars that we need. 
        // jaise jaise we find them, we will remove them.
        vector<int> need(128);
        int i=0;
        
        for (char ch : t) {
            need[ch]++;
        }
        int count=t.size();
        int minlen= INT_MAX;
        int start = 0;

        for (int j=0; j<s.size(); j++) {
            if (need[s[j]]>0) {
                count--;
            }
            need[s[j]]--;
            while (count==0) {
                if (minlen > j-i+1) {
                    minlen = j-i+1;
                    start = i;
                }
                // we are shrinking window, so we will need the element which we are reducing
                need[s[i]]++;
                if (need[s[i]]>0) {
                    // window became invalid.
                    count++;
                }
                i++;
            }
        }

        return minlen == INT_MAX ? "" : s.substr(start, minlen);
    }
};
