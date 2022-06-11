class Solution {
public:
    int minOperations(vector<int>& nums, int x) 
    {
        int l = 0;
        int r = nums.size() - 1;
        int tmp = 0;
        int cnt = 0;
        int res = 2147000000;

        while (l < nums.size())
        {
            tmp += nums[l];
            if (tmp == x)
            {
                cnt = l +1;
                res = min(res, cnt);
                break;
            }
            else if (tmp > x)
            {
                break;
            }
            ++l;
        }

        tmp = 0;
        while (r >= 0)
        {
            tmp += nums[r];
            if (tmp == x)
            {
                cnt = nums.size() - r;
                res = min(res, cnt);
                break;
            }
            else if (tmp > x)
            {
                break;
            }
            --r;
        }

        l = 0;
        cnt = 2147000000;
        while (r < nums.size())
        {
            tmp -= nums[r];
            ++r;

            while (tmp < x && l < r)
            {
                tmp += nums[l];
                ++l;
            }

            if (tmp == x && l < r)
            {
                cnt = l + nums.size() - r;
                res = min(res, cnt);
            }
        }

        if (res == 2147000000 && cnt == 2147000000)
            return - 1;
        
        res = min(res, cnt);
        return res;
    }
};
