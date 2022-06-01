class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        int mid;
        while (l < r)
        {
            mid = (l + r) / 2;
            if (nums[mid] == target)
                return mid;

            if (target > nums[mid])
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }

        if (r < 0 || l < 0)
            return 0;

        if (target > nums[r])
            return r + 1;
        else
            return l;
    }
};