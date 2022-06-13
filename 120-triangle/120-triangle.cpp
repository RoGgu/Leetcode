
class Solution {
public:
    int minimumTotal(vector<vector<int> >& triangle)
    {
        // 바텀에서부터 작은거 선택해서 올라오는 방식으로 풀이
        vector<int> v = triangle[triangle.size()-1];  // 현재 배열 작은거 인덱스별로 저장
        for (int i = triangle.size() - 2; i >= 0; --i) 
        {
            for (int j = 0; j <= i; ++j)
            {
                v[j] = triangle[i][j] + min(v[j], v[j + 1]);
            }
        }
        return v[0];
    }
};