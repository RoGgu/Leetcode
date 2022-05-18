class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
        int cnt = 0;
        int prevNum = nums[0];

        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] == prevNum) // 중복되면 제거해야한다.
                cnt++; // 제거해야할 수 카운트 증가
            else
            {
                prevNum = nums[i]; // 다음 체크를 위해 수 저장
                nums[i - cnt] = nums[i]; // 중복되지 않는 수이면 현재 빠져야하는 수 만큼 전가서 덮어씌운다.
            }
        }

        return nums.size() - cnt; // 전체 수 - 제거한 수
    }
};