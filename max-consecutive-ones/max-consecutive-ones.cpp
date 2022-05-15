class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxCnt = 0;
        int cnt = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 1)
                cnt++;
            else
            {
                if (cnt > maxCnt)
                    maxCnt = cnt;

                cnt = 0;

                if (nums.size() - i <= maxCnt)
                    break;
            }
        }

        if (cnt > maxCnt)
            maxCnt = cnt;

        return maxCnt;
    }
};