class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size()>nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }
        int m = nums1.size();
        int n = nums2.size();

        int left =0;
        int right = m;

        int half = (n+m+1)/2;

        while (left<=right) {
            int i = (right+left)/2;
            int j = half - i;

            long long l1 = (i==0) ? LLONG_MIN : nums1[i-1];
            long long r1 = (i==m) ? LLONG_MAX : nums1[i];
            long long l2 = (j==0) ? LLONG_MIN : nums2[j-1];
            long long r2 = (j==n) ? LLONG_MAX : nums2[j];

            if (l1<=r2 && l2<=r1) {
                // odd len
                if ((m+n)%2==1) {
                    return max(l1,l2);
                }
                long long lmax = max(l1,l2);
                long long rmin = min(r1,r2);
                return ((lmax+rmin)/2.0);
            }
            else if (l1>r2) {
                right=i-1;
            }
            else {
                left=i+1;
            }
        }
        return 0.0;
    }
};
