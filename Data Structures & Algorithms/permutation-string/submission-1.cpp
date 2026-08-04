class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1=s1.size();
        int n2=s2.size();
        if (n2<n1) return false;
        vector<int> f1(26);
        vector<int> f2(26);

        for (auto ch : s1) {
            f1[ch-'a']++;
        }

        int i=0;

        for (int j=0; j<n1; j++) {
            f2[s2[j]-'a']++;
        }

        if (f1==f2) return true;

        for (int k=n1; k<n2; k++) {
            f2[s2[k]-'a']++;
            f2[s2[i]-'a']--;
            i++;
            if (f1==f2) return true;
        }

        return false;
    }
};
