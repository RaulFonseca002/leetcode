/*
 * @lc app=leetcode id=1163 lang=cpp
 *
 * [1163] Last Substring in Lexicographical Order
 */

// @lc code=start

#include<string>

class Solution {
public:

    std::string lastSubstring(std::string s) {

        int root = 0;
        const int lenght = s.length();

        for(int index = 0; index < lenght; index++){
            
            if(s.compare(root, lenght, s, index, lenght) < 0){
                root = index;
            }
        }

        return s.substr(root);
    }
};
// @lc code=end

