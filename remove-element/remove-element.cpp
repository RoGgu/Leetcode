class Solution {
public:
    int removeElement(vector<int>& nums, int val) 
    {
        int cnt = 0;

        for (int i = 0; i < nums.size()- cnt; i++)
        {

            if (nums[i] == -1)
            {
                nums[i] = nums[i + cnt];
                nums[i + cnt] = -1;
            }

            while (nums[i] == val)
            {
                cnt++;
                if (i + cnt >= nums.size())
                    break;
                int tmp = nums[i + cnt];
                nums[i + cnt] = -1;
                nums[i] = tmp;
            }
        }

        return  nums.size() - cnt;
    }
};