/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
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
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        ListNode *dummy = new ListNode(-1, head);
        ListNode *prev = dummy;

        for (int i = 0; i < left - 1; ++i)
        {
            prev = prev->next; // prev 位于要翻转链表的上一个位置
        }
        ListNode *cur = prev->next;
        ListNode *p = nullptr;
        int k = right - left + 1; // 翻转这么多个结点
        while (k-- > 0)
        {
            ListNode *nxt = cur->next;
            cur->next = p;
            p = cur;   // p->4
            cur = nxt; // cur->5
        }
        prev->next->next = cur;
        prev->next = p;
        return dummy->next;
    }
};
// @lc code=end
