/*
 * @lc app=leetcode.cn id=2181 lang=cpp
 *
 * [2181] 合并零之间的节点
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
    ListNode *mergeNodes(ListNode *head)
    {
        /**
         * 合并0 原地修改
         */
        ListNode *cur = head->next;
        ListNode *prev = new ListNode(-1, head);
        while (cur != nullptr)
        {
            prev = prev->next;
            prev->val = 0;
            while (cur->val != 0)
            { // 最后指向的位置一定是cur->val = 0

                prev->val += cur->val;
                cur = cur->next;
            }
            // 考虑最后一个节点
            cur = cur->next;
        }
        prev->next = nullptr;

        return head;
    }
};
// @lc code=end
