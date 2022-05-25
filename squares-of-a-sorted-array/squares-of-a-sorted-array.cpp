class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums)
    {
        vector<int> res(nums.size());
        int l = 0;
        int r = nums.size() - 1;
        int index = nums.size()-1; // 뒤에서부터 큰 수로 채운다

        while (l <= r) // 양 쪽 끝에서부터 돌면서 큰 수 index에 넣는다
        {
            if (abs(nums[l]) <= abs(nums[r]))
            {
                res[index] = nums[r] * nums[r];
                index--;
                r--;
            }
            else
            {
                res[index] = nums[l] * nums[l];
                index--;
                l++;
            }
        }
        
        return res;
    }
};