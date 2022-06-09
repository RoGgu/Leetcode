
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) 
    {
        int l = 0;
        int r = numbers.size()-1;

        while (l < r)
        {
            if (target == numbers[l] + numbers[r])
                break;
            else if (target > numbers[l] + numbers[r])
                l++;
            else
                r--;
        }

        return vector<int>{l + 1, r + 1};
    }
};
