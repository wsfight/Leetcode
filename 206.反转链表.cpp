/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
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
    ListNode *reverseList(ListNode *head)
    {
        // 翻转链表的两种做法
        // 头插法
        ListNode *dummy = new ListNode(-1, nullptr);
        // 首先吧头结点取下来
        ListNode *p = head;
        while (p != nullptr)
        {
            p = p->next;
            head->next = dummy->next;
            dummy->next = head;
            head = p;
        }
        return dummy->next;
    }
};
// @lc code=end
