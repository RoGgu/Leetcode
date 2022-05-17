class Solution {
public:
    int removeElement(vector<int>& nums, int val) 
    {
        // 현재 인덱스에 값이 제거 해야할 값이 아닌경우에 현재 담아야할 인덱스에 넣는다.
        // 이러면 제거해야할 값이 나오면 다음값이 덮어씌움

        int idx = 0; // 인덱스에 하나씩 넣을때마다 증가

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != val) // 제거해야할 꺼 아니면 덮어씌운다.
            { 
                nums[idx] = nums[i];
                idx++; // 하나 채웠으니 인덱스 증가
            }
        }

        return idx;
    }
};