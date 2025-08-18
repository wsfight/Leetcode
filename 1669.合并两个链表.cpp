/*
 * @lc app=leetcode.cn id=1669 lang=cpp
 *
 * [1669] 合并两个链表
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
    ListNode *mergeInBetween(ListNode *list1, int a, int b, ListNode *list2)
    {
        ListNode *prev1 = list1;
        ListNode *cur1 = list1;
        for (int i = 0; i < (a - 1); ++i)
        {
            prev1 = prev1->next;
        }
        for (int j = 0; j < (b + 1); ++j)
        {
            cur1 = cur1->next;
        }
        // 此时prev1 和 cur1 已经落位
        ListNode *tail2 = list2;
        while (tail2->next != nullptr)
        {
            tail2 = tail2->next;
        }
        prev1->next = list2;
        tail2->next = cur1;
        return list1;
    }
};
// @lc code=end
