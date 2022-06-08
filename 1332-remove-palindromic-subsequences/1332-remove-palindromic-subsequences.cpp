class Solution {
public:
    int removePalindromeSub(string s) 
    {
        int l = 0;
        int r = s.size() - 1;
        bool isPalindrome = true;
        while (l < r)
        {
            if (s[l++] != s[r--])
            {
                isPalindrome = false;
                break;
            }
        }

        return isPalindrome ? 1 : 2;

    }
};