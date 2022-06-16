class Solution {
public:
    int PalindRomeLen(string s, int left, int right)
    {
        while (left >= 0 && right < s.size() && s[left] == s[right])
        {
            left -= 1;
            right += 1;
        }
        return right - left - 1; // right,left는 포함되지 않는 문자다. 그전까지가 회문 문자열 
    }

    string longestPalindrome(string s) 
    {
        if (s.empty() || s.length() < 1) 
            return "";

        int start = 0;
        int end = 0;
        for (int i = 0; i < s.size(); i++)
        {
            int len1 = PalindRomeLen(s, i, i); // 홀 수 탐색
            int len2 = PalindRomeLen(s, i, i + 1); // 짝 수 탐색 
            int len = max(len1, len2); 
            if (len > end - start + 1)  // 처음 세팅된 회전문 길이보다 크지 않으면 세팅 안함
            {
                start = i - (len - 1) / 2;
                end = i + len / 2;
            }
        }
        return s.substr(start, end - start +1); // 시작 지점, 시작지점 부터 얻어올 길이
    }
};