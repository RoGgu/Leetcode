
class Solution {
public:
    void rotate(vector<int>& nums, int k) 
    {
        int size = nums.size();
        if (k % size == 0) // 사이즈 만큼 돌면 제자리라서 제자리 도는거 다 없앤다.
            return;
        k = k % size;

        reverse(nums.begin(), nums.end()); // 반대로 다 돌린다.
        reverse(nums.begin(), nums.begin() + k); // k번 이동한거 까지 뒤집고
        reverse(nums.begin() + k, nums.end()); // 그다음 k+1번 까지 뒤집는다.
    }
};