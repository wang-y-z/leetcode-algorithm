/*
 * @lc app=leetcode.cn id=819 lang=cpp
 *
 * [819] 最常见的单词
 */

// @lc code=start
class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_map<string, int> cnt;
        unordered_set<string> ban;
        for (auto& w : banned) {
            ban.insert(w);
        }

        for(auto &c:paragraph){
            c = isalpha(c)?c:' ';
        }
        int maxcnt = 0 ;
        string ans;
        string buf;
        stringstream is(paragraph);
        while( is>> buf){
            for(auto &c:buf){
                c = tolower(c);
            }
            if(ban.count(buf)!=0) continue;
            cnt[buf]++;
            if(cnt[buf]>maxcnt){
                maxcnt = cnt[buf];
                ans = buf;
            }
        }
        return ans;
    }
};
// @lc code=end

