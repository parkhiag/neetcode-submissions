class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int maxspeed = *max_element(piles.begin(), piles.end());
        // so min speed can be 1 and max can be maximum of all elements. 
        // our ans will lie in this range, so we perform a binary search

        int low = 1;
        int high = maxspeed;

        while (low<=high) {
            int mid = (low+high)/2;
            long long hours = 0;
            for (int pile: piles) {
                hours+=(pile+mid-1)/mid;
            }
            if (hours<=h) {
                high=mid-1;
            }
            else {
                low=mid+1;
            }
        }
        return low;
    }
};
