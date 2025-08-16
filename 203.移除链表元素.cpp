/*
 * @lc app=leetcode.cn id=203 lang=cpp
 *
 * [203] 移除链表元素
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
    ListNode *removeElements(ListNode *head, int val)
    {
        ListNode *dummy = new ListNode(-1, head);
        ListNode *cur = head;
        ListNode *prev = dummy;
        while (cur != nullptr)
        {
            if (cur->val == val)
            {
                prev->next = cur->next;
                cur = prev->next;
                continue;
            }
            prev = cur;
            cur = cur->next;
        }
        return dummy->next;
    }
};
// @lc code=end
