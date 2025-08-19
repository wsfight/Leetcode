/*
 * @lc app=leetcode.cn id=2807 lang=cpp
 *
 * [2807] 在链表中插入最大公约数
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
    int gcb(int a, int b)
    {
        if (a % b == 0)
        {
            return b;
        }
        return gcb(b, a % b);
    }
    ListNode *insertGreatestCommonDivisors(ListNode *head)
    {
        if (!head->next)
        {
            return head;
        }
        ListNode *prev = head;
        ListNode *cur = head->next;
        while (cur != nullptr)
        {
            ListNode *p = new ListNode(gcb(prev->val, cur->val), cur);
            prev->next = p;
            prev = cur;
            cur = cur->next;
        }
        return head;
    }
};
// @lc code=end
