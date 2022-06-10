class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        vector<int> ch(256, -1);
        int startIdx = -1; // 카운트 시작한 인덱스 값
        int maxLenght = 0;

        for (int i = 0; i < s.size(); i++)
        {
            if (ch[s[i]] > startIdx) // ch가 이미 세팅 즉 앞에서 이미 있다면 그 단어 인덱스를 스타트 위치로 세팅
                startIdx = ch[s[i]];
            ch[s[i]] = i; // 발견된 문자에 인덱스를 세팅한다

            maxLenght = max(maxLenght, i - startIdx); // 맥스값 비교해서 세팅
        }
        return maxLenght;
    }
};