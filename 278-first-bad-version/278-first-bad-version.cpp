// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution 
{
public:
    int firstBadVersion(int n) 
    {
        long long start=1, end=n;
        while(start<end) // 이분 탐색으로 탐색
        {
            long long mid=(start+end)/2;
            if(isBadVersion(mid))
            {
                end=mid;
            }
            else
            {
                start=mid+1;
            }
        }
        return  start;
    }
};