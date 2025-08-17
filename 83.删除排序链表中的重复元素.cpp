/*
 * @lc app=leetcode.cn id=83 lang=cpp
 *
 * [83] 删除排序链表中的重复元素
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
        // 注意是已排序的
        // 没有探讨边界情况

        ListNode *dummy = new ListNode(-1, head);
        ListNode *cur = head;
        while (cur != nullptr && cur->next != nullptr)
        {
            // 一个指针来做
            if (cur->val == cur->next->val)
            {
                // 跳过下个值
                cur->next = cur->next->next; // 由于 cur->next不为空
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
