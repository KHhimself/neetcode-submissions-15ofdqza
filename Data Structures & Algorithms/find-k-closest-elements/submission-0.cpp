class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        auto it = lower_bound(arr.begin(), arr.end(), x);
        int idx = it - arr.begin();
        int left = idx-1;
        int right = idx;
        while (right-left+-1<k) { // from left+1, right-1
            if (left>=0 && right>=arr.size()) {
                left--;
            }
            else if (left<0 && right<arr.size()) {
                right++;
            }
            else {
                 if (abs(arr[left]-x) < abs(arr[right]-x)) {
                    left--;
                }
                else if (abs(arr[left]-x)>abs(arr[right]-x)) {
                    right++;
                }
                else {
                    if (arr[left]<arr[right]) {
                        left--;
                    }
                    else {
                        right++;
                    }
                }
            }
           
        }
        
        vector<int> ans(arr.begin() + left + 1, arr.begin() + right);
        //ans = arr.substr(arr.begin()+left, arr.begin()+right+1);
        return ans;
    }
};