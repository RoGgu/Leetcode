class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        int l;
        int r;
        vector<int> res;
        unordered_map<int, int> map;
        
        for (int i = 0; i < nums.size(); i++)
        {
            if (map.find(target - nums[i]) != map.end())
            {
                l = map[target - nums[i]];
                r = i;
                break;
            }
            else
                map[nums[i]] = i;
        }


        return vector<int>{l, r};
    }
};