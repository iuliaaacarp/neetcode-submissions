class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int left = (nums1.size() + nums2.size() + 1) / 2;
        int right = (nums1.size() + nums2.size() + 2) / 2;
        return (getKth(nums1, nums1.size(), nums2, nums2.size(), left, 0, 0) / 1.0 + getKth(nums1, nums1.size(), nums2, nums2.size(), right, 0, 0)) / 2.0;
    }

    int getKth(vector<int>& A, int m, vector<int>& B, int n, int k, int aStart, int bStart){
        if (m > n){
            return getKth(B, n, A, m, k, bStart, aStart);
        }
        if (m == 0){
            return B[bStart + k - 1];
        }
        if (k == 1){
            return min(A[aStart], B[bStart]);
        }

        int i = min(m, k / 2);
        int j = min(n, k / 2);

        if (A[aStart + i - 1] > B[bStart + j - 1]){
            return getKth(A, m, B, n - j, k - j, aStart, bStart + j);
        }
        else {
            return getKth(A, m - i, B, n, k - i, aStart + i, bStart);
        }
    }
};
