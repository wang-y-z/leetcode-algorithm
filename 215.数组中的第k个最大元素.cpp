/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */

// @lc code=start
// class Solution {
// public:
//     int findKthLargest(vector<int>& nums, int k) {
//         sort(nums.begin(),nums.end());
//         return *(nums.end()-k);
//     }
// };

//02 max_element 赋值
// class Solution {
// public:
//     int findKthLargest(vector<int>& nums, int k) {
//         for(int i{0} ; i<k-1 ; i++)*max_element(nums.begin(),nums.end())=INT_MIN;
//         return *max_element(nums.begin(),nums.end());
//     }
// };

//03 太凶残了
// class Solution {
// public:
//     int findKthLargest(vector<int>& nums, int k) {
//         nth_element(nums.begin(),nums.end()-k,nums.end());
//         return nums[nums.size()-k];
//     }
// };

//04 大佬答案
// #include <time.h>
// class Solution {
// public:
//     int partition(vector<int>& nums, int lo, int hi) {
//         if (lo == hi) return lo;
//         int rand_idx = rand()%(hi-lo+1) + lo;
//         swap(nums[lo], nums[rand_idx]);
//         int pivot = nums[lo];
//         int i = lo, j = hi+1;
//         while (true) {
//             while (nums[++i] < pivot) 
//                 if (i == hi) break;
            
//             while (nums[--j] > pivot) 
//                 if (j == lo) break;
            
//             if (i==j || i==j+1) break;
            
//             swap(nums[i], nums[j]);
//         }
        
//         swap(nums[lo], nums[j]);
//         return j;
//     } 
    
//     int findKthLargest(vector<int>& nums, int k) {
//         srand(time(0));
//         int lo = 0, hi = nums.size()-1;
//         k = nums.size() - k;
//         while (lo <= hi) {
//             int p = partition(nums, lo, hi);
//             if (p > k) {
//                 hi = p - 1;
//             } else if (p < k) {
//                 lo = p + 1;
//             } else 
//                 return nums[p];
//         }
//         return -1;
//     }
// };

//05 优先队列
// class Solution {
// public:
//     int findKthLargest(vector<int>& nums, int k) {
//         priority_queue<int, vector<int>, std::greater<int>> pq;
//         for (int n : nums) {
//             pq.push(n);
//             if (pq.size() > k)
//                 pq.pop();
//         }
//         return pq.top();
//     }
// };

//06 最大堆
// class Solution {
// public:
//     static bool cmp(int &a,int &b)
//     {
//         return a>b;
//     }
//     int findKthLargest(vector<int>& nums, int k) {
//         int len=nums.size();
//         if( k>len )
//         {
//             return 0;
//         }
//         //建立最大堆，最前面是最大
//         make_heap( nums.begin(), nums.end() );
//         //堆排序
//         sort_heap( nums.begin(), nums.end() );
//         return nums[len-k];
//     }
// };

//07 最小堆
class Solution {
public:
    //最小堆 (top是最小的)，时间复杂度o(nlogk)
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> mini_heap;
        for(int i = 0; i < nums.size();i++){
            mini_heap.push(nums[i]);
            if(mini_heap.size()>k) mini_heap.pop();
        }
        return mini_heap.top();
    }
};
// @lc code=end

