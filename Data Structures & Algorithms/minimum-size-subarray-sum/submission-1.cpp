class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0;
        int minLen = INT_MAX;
        int cur = 0;
        bool flag = false;
        for (int i=0;i<nums.size();i++) {
            cur += nums[i];
            while (cur>=target) {
                flag = true;
                minLen = min(minLen,i-left+1);
                cur -= nums[left];
                left++;
                //minLen = min(minLen,i-left+1);
            }
        }
        if (!flag) return 0;
        return minLen;
    }
};