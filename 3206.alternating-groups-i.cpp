/*
 * @lc app=leetcode id=3206 lang=cpp
 *
 * [3206] Alternating Groups I
 */

// @lc code=start
#include<vector>

class Solution {
public:
    int numberOfAlternatingGroups(std::vector<int>& colors) {
        
        int counter = 0;
        int prev, next;

        for(int index = 0; index < colors.size(); index++){

            prev = ((index - 1 ) < 0) ? colors.size() - 1 : index - 1;
            next = (index + 1 ) % colors.size();

            if( colors[prev] == colors[next] &&
                colors[index] != colors[prev]){
                    counter++;
                }
        }

        return counter;
    }
};
// @lc code=end

