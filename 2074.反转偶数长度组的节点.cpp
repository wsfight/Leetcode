/*
 * @lc app=leetcode.cn id=2074 lang=cpp
 *
 * [2074] 反转偶数长度组的节点
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
    ListNode *reverseEvenLengthGroups(ListNode *head)
    {
        int cnt = 0;
        ListNode *p = head;
        while (p)
        {
            ++cnt;
            p = p->next;
        }
        int i = 1;
        ListNode *dummy = new ListNode(-1, head);
        ListNode *p0 = dummy;
        while (cnt > 0)
        {
            i = min(cnt, i);
            cnt -= i;
            if (i % 2 == 0)
            {
                // 需要翻转的
                ListNode *curr = p0->next;
                ListNode *prev = nullptr;
                for (int j = 0; j < i; ++j)
                {
                    ListNode *nxt = curr->next;
                    curr->next = prev;
                    prev = curr;
                    curr = nxt;
                }
                ListNode *nxt = p0->next;
                p0->next->next = curr;
                p0->next = prev;
                p0 = nxt;
            }
            else
            {
                for (int k = 0; k < i; ++k)
                {
                    p0 = p0->next;
                }
            }
            ++i;
        }
        return dummy->next;
    }
};
// @lc code=end
