/*
 * @lc app=leetcode.cn id=2095 lang=cpp
 *
 * [2095] 删除链表的中间节点
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
    ListNode *deleteMiddle(ListNode *head)
    {
        int cnt = 0;
        ListNode *p = head;
        while (p)
        {
            ++cnt;
            p = p->next;
        }
        int k = cnt / 2;
        ListNode *dummy = new ListNode(-1, head);
        ListNode *p0 = dummy;
        for (int i = 0; i < k; ++i)
        {
            p0 = p0->next;
        }
        p0->next = p0->next->next;
        return dummy->next;
    }
};
// @lc code=end
