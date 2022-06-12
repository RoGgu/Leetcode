class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) 
    {
        map<int, int> mp;
        int size = nums.size();
        int maxSum = 0, currSum = 0;
        int s = 0, e = 0; // 하위 인덱스 시작 s, 끝 e
        while (e < size)
        {
            if (!mp[nums[e]]) // 하위 인덱스에서 죽복된 수 없다면 추가
            {
                currSum += nums[e];
                mp[nums[e]]++; //Inserting value to map
            }
            else // 중복이 있다면 중복된거 다 뺄떄까지 s 시작위치 올린다.
            {
                while (s < e  && mp[nums[e]])
                {
                    mp[nums[s]]--;  
                    currSum -= nums[s];
                    s++;
                }
                mp[nums[e]]++;  // 중복 다 없앤다음에 하나 넣어준다.
                currSum += nums[e];
            }
            // 맥시멈 비교
            maxSum = currSum > maxSum ? currSum : maxSum;
            e++;
        }
        return maxSum;
    }
};
