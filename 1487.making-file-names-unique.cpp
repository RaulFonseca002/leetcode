/*
 * @lc app=leetcode id=1487 lang=cpp
 *
 * [1487] Making File Names Unique
 */

// @lc code=start

#include <stdlib.h>
#include <map>
#include <string>
#include <vector>
#include <set>
#include <regex>

class Solution
{

    public:
        std::vector<std::string> getFolderNames(std::vector<std::string> &names)
        {

            std::set<std::string> fileNameSet;
            std::map<std::string, int> clashMap;
            std::vector<std::string> resp;
            int clash = 0;
            std::string name;

            for (std::string fileName : names)
            {
                name = fileName;
                while (fileNameSet.count(fileName)){

                    clash++;
                    if(clashMap.count(name)) clash = ++clashMap[name];

                    fileName = name + '(' + std::to_string(clash).c_str() + ')';
                }

                resp.push_back(fileName);
                fileNameSet.insert(fileName);
                clashMap.insert({name, clash});
                clash = 0;
            }

            return resp;
        }
};
// @lc code=end
