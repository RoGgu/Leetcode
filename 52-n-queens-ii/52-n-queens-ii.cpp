class Solution {
public:

    bool IsCheck(int y, int x)
    {
        // 위로 y행렬 퀸 있는지 체크
        for (int cy = y; cy >= 0; cy--)
        {
            if (map[cy][x] == 1) 
                return false;
        }

        //  대각선 '\'  위 방향으로 퀸 있는지 체크
        for (int cy = y, cx = x; cy >= 0 && cx >= 0; cy--, cx--)
        {
            if (map[cy][cx] == 1)
                return false;
        }

        //  대각선 '/'  위 방향으로 퀸 있는지 체크
        for (int cy = y, cx = x; cy >= 0 && cx < N; cy--, cx++)
        {
            if (map[cy][cx] == 1)
                return false;
        }
        
        return true;
    }

    void DFS(int y,int L)
    {
        if (L == N) // 퀸 N개 만큼 있으면 조건 충족하는 경우
        {
            cnt++;
            return;
        }

        for (int nx = 0; nx < N; nx++)
        {
            if (IsCheck(y, nx) == true) // 공격 당하는 퀸 없으면 퀸 새로 세팅
            {
                map[y][nx] = 1;
                DFS(y + 1, L + 1);
                map[y][nx] = 0;
            }
        }
    }

    int totalNQueens(int n) 
    {
        N = n;
        map.resize(N, vector<int>(N));
        
        DFS(0, 0);
        return cnt;
    }

private:

    int N;
    int cnt = 0;
    vector<vector<int>> map;
};