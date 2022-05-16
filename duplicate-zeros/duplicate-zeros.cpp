class Solution {
public:
    void duplicateZeros(vector<int>& arr) 
    {
        int zeroNum = count(begin(arr), end(arr), 0); // 현재 배열 0 개수
        int lenght = arr.size(); // 배열 사이즈

        // 뒤에서부터 0 개수만큼 해당 인덱스 값 뒤로 밀어준다.
        // 만약 현재 인덱스 값이 0 면 제로개수(뒤로 미는 값) 하나 줄이고
        // 0 뒤로 민다음 그 다음 수도 0으로 바꿔준다.

        for (int i = arr.size() - 1; i >= 0; i--) 
        {
            if (arr[i] == 0)
                zeroNum--;

            if (i + zeroNum < lenght)
            {
                arr[i + zeroNum] = arr[i]; // 0 개수만큼 뒤로 밀어줌
                if (arr[i] == 0 && i + zeroNum + 1 < lenght) // 만약 0이고 배열 범위 안에있으면 그 다음수도 0로 바꿈
                    arr[i + zeroNum + 1] = 0;
            }
        }
    }
};