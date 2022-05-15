class Solution {
public:
    int findNumbers(vector<int>& nums) 
    {
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            int tmp = nums[i];
            bool isEven = true;
            while (tmp > 0)
            {
                tmp = tmp / 10;
                isEven = !isEven;
            }
            if (isEven == true)
                cnt++;
        }

        return cnt;
    }
};