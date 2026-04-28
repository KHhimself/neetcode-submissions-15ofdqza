class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n);

        int rightMax = arr[n-1];
        for (int i=n-2;i>=0;i--) {
            ans[i] = rightMax;
            rightMax = max(arr[i],rightMax);
        }
        ans[n-1] = -1;
        return ans;
    }
};