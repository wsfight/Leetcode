/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
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
#include <stack>
class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        /**
         * 使用栈的特性
         */
        if (!head or !head->next)
        {
            return head;
        }
        ListNode *dummy = new ListNode(-1, head);
        ListNode *p = dummy;
        ListNode *cur = p->next;
        // 用栈来保存每两个结点
        stack<ListNode *> s;
        while (cur && cur->next)
        {

            s.push(cur);
            s.push(cur->next);
            cur = cur->next->next;
            p->next = s.top();
            s.pop();
            p->next->next = s.top();
            s.pop();
            p = p->next->next;
            p->next = cur;
        }
        return dummy->next;
    }
};
// @lc code=end
