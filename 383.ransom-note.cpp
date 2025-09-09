/*
 * @lc app=leetcode id=383 lang=cpp
 *
 * [383] Ransom Note
 */

// @lc code=start

#include<string>
#include<algorithm>

class Solution {
public:
    bool canConstruct(std::string ransomNote, std::string magazine) {

        std::string a = ransomNote;
        std::string b = magazine;
        int b_idx = 0;
        int a_idx = 0;
        std::sort(a.begin(), a.end());
        std::sort(b.begin(), b.end());


        while(a_idx < a.size()){

            while(b[b_idx] < a[a_idx] && b_idx < b.size()){
                b_idx++;
            }

            if(a[a_idx] != b[b_idx] || b_idx > b.size()) return false;

            a_idx++;       
            b_idx++;
            
        }

        return true;
    }
};
// @lc code=end

