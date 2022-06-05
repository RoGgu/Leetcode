class Solution {
public:
    void DFS(int y,int L)
    {
        if (L == N)
        {
            cnt++;
            return;
        }

        for (int nx = 0; nx < N; nx++)
        {
            if (map[y][nx] == 0)
            {
                bool isExist = false;
                for (int c = 0; c < N; c++)
                {
                    if (map[y][c] == 1)
                        isExist = true;
                    if (map[c][nx] == 1)
                        isExist = true;

                    if(y + c <N && nx+c < N && map[y+c][nx+c] == 1)
                        isExist = true;
                    if(y + c <N && nx-c >=0 && map[y+c][nx-c] == 1)
                        isExist = true;

                    if(y - c >=0 && nx-c >=0 && map[y-c][nx-c] == 1)
                        isExist = true;
                    if(y - c >=0 && nx+c <N && map[y-c][nx+c] == 1)
                        isExist = true;

                    if (isExist == true)
                        break;
                }

                if (isExist == false)
                {
                    map[y][nx] = 1;
                    DFS(y + 1, L + 1);
                    map[y][nx] = 0;
                }
            }
        }

    }

    int totalNQueens(int n) 
    {
        N = n;
        map.resize(N, vector<int>(N));
        ch.resize(N, vector<int>(N));

        DFS(0, 0);

        return cnt;
    }
    int N;
    int cnt = 0;
    vector<vector<int>> map;
    vector<vector<int>> ch;
};