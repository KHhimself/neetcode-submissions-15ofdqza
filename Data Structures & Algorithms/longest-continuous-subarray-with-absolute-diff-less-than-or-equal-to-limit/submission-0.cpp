class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int l = 0;
        int ans = 0;
        //{value, index}
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minHp;
        priority_queue<pair<int,int>, vector<pair<int,int>>, less<pair<int,int>>> maxHp;
        
        for (int i=0;i<nums.size();i++) {
            minHp.push({nums[i], i});
            maxHp.push({nums[i], i});
           
            while (maxHp.top().first-minHp.top().first > limit) {
                l++;
                while (maxHp.top().second<l) {
                    maxHp.pop();
                }
                while (minHp.top().second<l) {
                    minHp.pop();
                }
            }
            ans = max (ans, i-l+1);
        }
        return ans;
    }
};