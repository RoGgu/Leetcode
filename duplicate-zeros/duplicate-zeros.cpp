class Solution {
public:
    void duplicateZeros(vector<int>& arr) 
    {

        for (int i = arr.size() - 2; i >= 0; i--)
        {
            if (arr[i] == 0)
            {
                int num = arr[i + 1];
                for (int j = i + 2; j < arr.size(); j++)
                {
                    int tmp = arr[j];
                    arr[j] = num;
                    num = tmp;
                }
                arr[i + 1] = 0;
            }
        }
    }
};