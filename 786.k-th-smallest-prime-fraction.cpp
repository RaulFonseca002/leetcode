/*
 * @lc app=leetcode id=786 lang=cpp
 *
 * [786] K-th Smallest Prime Fraction
 */

// @lc code=start

#include <vector>
#include <map>
#include <stack>
#include <queue>

class Solution {
public:
    std::vector<int> kthSmallestPrimeFraction(std::vector<int>& arr, int k) {
        
        using fraction = std::pair<double, std::pair<int, int>>;
        std::priority_queue<fraction, std::vector<fraction>, std::greater<fraction>> queue;
        std::pair<int,int> resp;

        for (int j = 1; j < arr.size(); ++j) {
            queue.push({static_cast<double>(arr[0]) / arr[j], {0, j}});
        }

        for (int c = 0; c < k ; c++) {

            resp = queue.top().second;
            queue.pop();

            int num_idx = resp.first;
            int den_idx = resp.second;

            if (num_idx + 1 < den_idx) {
                double val = static_cast<double>(arr[num_idx + 1]) / arr[den_idx];
                queue.push({val, {num_idx + 1, den_idx}});
            }
        }

        return {arr[resp.first], arr[resp.second]};
    }

};
// @lc code=end

