class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix)
    {
        vector<vector<int>> res(matrix[0].size());

        for (int x = 0; x < matrix[0].size(); x++)
        {
            for (int y = 0; y < matrix.size(); y++)
            {
                res[x].push_back(matrix[y][x]);
            }
        }

        return res;
    }
};