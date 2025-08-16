/*
 * @lc app=leetcode.cn id=817 lang=cpp
 *
 * [817] 链表组件
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    int numComponents(ListNode *head, vector<int> &nums)
    {
        /**
         * 题目意思:就是找联通分量的个数
         */

        // 思路是用两个指针遍历
        int ans = 0;
        ListNode *cur = head;
        while (cur != nullptr)
        {
            int temp = cur->val;
            if (find(nums.begin(), nums.end(), temp) != nums.end())
            {
                // 找到了
                ++ans;
                while (cur != nullptr && find(nums.begin(), nums.end(), cur->val) != nums.end())
                {
                    // 一直存在
                    cur = cur->next;
                }
            }
            else
            {
                cur = cur->next;
            }
        }
        return ans;
    }
};
// @lc code=end
