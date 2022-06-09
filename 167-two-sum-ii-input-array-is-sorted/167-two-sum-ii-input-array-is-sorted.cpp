
class Solution {
public:
    int Target;


    int findNum(vector<int>& numbers, int l, int r, int idx)
    {
        int findNum = Target - numbers[idx];

        if (numbers[idx] == findNum)
        {
            if (idx + 1 < numbers.size() && numbers[idx + 1] == findNum)
                return idx + 1;
            else if(idx - 1 >=0 - 1 && numbers[idx - 1] == findNum)
                return idx - 1;
        }

        while (l <= r)
        {
            int mid = (l + r) / 2;

            if (numbers[mid] == findNum)
            {
                return mid;
            }
            else if (findNum > numbers[mid])
            {
                l = mid + 1;
            }
            else
                r = mid - 1;
        }

        return -1;
    }

    vector<int> twoSum(vector<int>& numbers, int target) 
    {
        Target = target;
        vector<int> res;

        int l = 0;
        int r = numbers.size() - 1;
        int mid;

        while (l < r)
        {
            mid = (l + r) / 2;
            if (target > numbers[mid])
                l = mid + 1;
            else
                r = mid - 1;
        }

        l = mid - 1;
        r = mid;


        while (l >= 0 && r < numbers.size())
        {
            int lIndex = findNum(numbers, 0, numbers.size() - 1, l);
            if (lIndex != -1)
            {
                res.push_back(l + 1);
                res.push_back(lIndex + 1);
                break;
            }

            int rIndex = findNum(numbers, 0, numbers.size() - 1, r);
            if (rIndex != -1)
            {
                res.push_back(r + 1);
                res.push_back(rIndex + 1);
                break;
            }

            l--;
            r++;
        }

        if (res.size() != 2)
        {
            while (l > 0)
            {
                int lIndex = findNum(numbers, 0, numbers.size() - 1, l);
                if (lIndex != -1)
                {
                    res.push_back(l + 1);
                    res.push_back(lIndex + 1);
                    break;
                }
                l--;
            }

            while (r < numbers.size())
            {
                int rIndex = findNum(numbers, 0, numbers.size() - 1, r);
                if (rIndex != -1)
                {
                    res.push_back(r + 1);
                    res.push_back(rIndex + 1);
                    break;
                }
                r++;
            }
        }


        sort(res.begin(), res.end());
        return res;
    }
};