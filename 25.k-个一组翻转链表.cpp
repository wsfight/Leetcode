/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
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
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        int cnt = 0;
        ListNode *dummy = new ListNode(-1, head);
        ListNode *p = head;
        while (head)
        {
            ++cnt;
            head = head->next;
        }
        ListNode *p0 = dummy;

        while (cnt >= k)
        {
            cnt -= k;
            ListNode *prev = nullptr;
            ListNode *cur = p0->next;
            for (int i = 0; i < k; i++)
            {
                ListNode *nxt = cur->next;
                cur->next = prev;
                prev = cur;
                cur = nxt;
            }
            // prev->2 p0->next->1 cur->4
            ListNode *nxt = p0->next;
            p0->next->next = cur;
            p0->next = prev;
            p0 = nxt;
        }
        return dummy->next;
    }
};
// @lc code=end
