class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) 
    {
        int l = 0;
        int r = numbers.size()-1;

        while (l < r)
        {
            if (target == numbers[l] + numbers[r]) // 합친 수가 정답이면 현재 인덱스들 리턴
                break;
            else if (target > numbers[l] + numbers[r]) // 합친수가 작으면 l 작은쪽 인덱스 올려줌
                l++;
            else // 합친수가 크면 r 큰 쪽 인덱스 낮춰줌
                r--;
        }

        return vector<int>{l + 1, r + 1};
    }
};