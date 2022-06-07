class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
    {
        int lp = m - 1;
        int rp = n - 1;
        int k = m + n - 1;

        while (lp >=0 && rp >=0)
        {
            if (nums1[lp] > nums2[rp])
                nums1[k--] = nums1[lp--];
            else
                nums1[k--] = nums2[rp--];
        }

        while (lp >= 0)
            nums1[k--] = nums1[lp--];
        while (rp >= 0)
            nums1[k--] = nums2[rp--];
    }
};