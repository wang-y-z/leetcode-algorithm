/*
 * @lc app=leetcode.cn id=773 lang=cpp
 *
 * [773] 滑动谜题
 */

// @lc code=start
class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        string start = "";
        string target = "123450";
        for(int i = 0 ; i < 2 ; i++){
            for(int j = 0 ; j < 3 ; j++){
                start += (board[i][j]+'0');
            }
        }
        vector<vector<int>> neighbor = {
            {1,3},
            {0,2,4},{1,5},{0,4},{3,1,5},{4,2}
        };
        //BFS
        queue<string> q;
        unordered_set<string> visited;
        q.push(start);
        visited.insert(start);
        int step = 0;
        while( !q.empty() ){
            int sz = q.size();
            for(int i = 0 ; i < sz ; i++){
                string cur  = q.front();
                q.pop();
                if(target == cur) return step;
                int idx = 0;
                for( ; cur[idx] != '0' ;idx++  );
                for( int adj : neighbor[idx] ){
                    string new_board = cur;
                    swap(new_board[adj] , new_board[idx]);
                    if(!visited.count(new_board)){
                        q.push(new_board);
                        visited.insert(new_board);
                    }
                }
            }
            step++;
        }
        return -1;
    }
};
// @lc code=end

