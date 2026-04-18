class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        // 1. 排序 meetings (依 start 由小到大)

        sort(meetings.begin(), meetings.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0]; // 依 start 由小到大排序
        });

        
        // 2. 宣告兩個 priority_queue
        //    available: 空房的 min heap (依編號)
        //    busy: 忙房的 min heap (依 (結束時間, 編號))
        priority_queue<int, vector<int>, greater<int>> available;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> busy;
        
        // 3. 初始化:所有 n 間房都在 available 裡
        for (int i = 0; i < n; ++i) {
            available.push(i);
        }
        
        // 4. 宣告 count 陣列
        vector<int> count(n, 0);
        
        // 5. 對每個 meeting [start, end]:
        //    (a) 先把 busy 裡所有 end_time <= start 的房間搬回 available
        //    (b) 如果 available 非空:從 available 拿最小編號,放進 busy (結束時間 = end)
        //    (c) 如果 available 空:從 busy 拿最早結束的房間,
        //        實際開始時間 = 那間房的結束時間
        //        實際結束時間 = 實際開始時間 + (end - start)
        //        更新後重新 push 進 busy
        //    (d) count[被指派的房間]++
        for (const auto& meeting : meetings) {
            int start = meeting[0];
            int end = meeting[1];
            
            // (a)
            while (!busy.empty() && busy.top().first <= start) {
                available.push(busy.top().second);
                busy.pop();
            }
            
            // (b)
            if (!available.empty()) {
                int room = available.top();
                available.pop();
                busy.push({end, room});
                count[room]++;
            }
            // (c)
            else {
                auto earliest = busy.top();
                busy.pop();
                int actual_start = earliest.first;
                int room = earliest.second;
                int actual_end = actual_start + (end - start);
                busy.push({actual_end, room});
                count[room]++;
            }
        }


        
        // 6. 找 count 中最大值對應的最小編號房間
        int max_count = 0;
        int result_room = 0;
        for (int i = 0; i < n; ++i) {
            if (count[i] > max_count) {
                max_count = count[i];
                result_room = i;
            }
        }

        
        return result_room;
    }
};