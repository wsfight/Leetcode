/*
 * @lc app=leetcode.cn id=82 lang=cpp
 *
 * [82] 删除排序链表中的重复元素 II
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
    ListNode *deleteDuplicates(ListNode *head)
    {
        /**
         * 1.已排序的
         * 2.要求重复的都删除,不是留一个
         */
        ListNode *dummy = new ListNode(-1, head);
        ListNode *cur = dummy;
        while (cur->next && cur->next->next)
        {
            int val = cur->next->val;
            if (val == cur->next->next->val)
            {
                // 后面两个结点的值相同
                // 后面等于val的值全部删除
                while (cur->next && cur->next->val == val)
                {
                    cur->next = cur->next->next;
                }
            }
            else
            {
                cur = cur->next;
            }
        }
        return dummy->next;
    }
};
// @lc code=end
