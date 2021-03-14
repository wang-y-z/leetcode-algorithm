/*
 * @lc app=leetcode.cn id=875 lang=cpp
 *
 * [875] 爱吃香蕉的珂珂
 */

// @lc code=start
class Solution {
public:
    int getMax(const vector<int>& piles ){
        int res = 0;
        for(auto i : piles){
            res = max(res, i);
        }
        return res;
    }
    bool cando( int speed, vector<int>& piles , int h ){
        int time = 0;
        for( int n : piles ){
            time += (n / speed) + ((n % speed > 0) ? 1 : 0);
        }
        return time <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        //01暴力，从最小到最大的可能性遍历
        //想到可以遍历，那么就可以用二分来减小搜索空间
        int l = 1 , r = getMax(piles) + 1 ; //二分细节啊
        while( l < r ){
            int mid = l + ( r - l ) / 2;
            if( cando(mid,piles,h) ){
                r = mid;
            }else{
                l = mid + 1;
            }
        }
        return l;
    }
};
// @lc code=end

