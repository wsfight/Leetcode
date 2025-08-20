/*
 * @lc app=leetcode.cn id=147 lang=cpp
 *
 * [147] 对链表进行插入排序
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
    ListNode *insertionSortList(ListNode *head)
    {
        /***
         * 插入排序是从后往前找
         * 这个是单项链表
         * 如果我们逆转过来呢?
         * 一样的啊
         */
        if (head->next == nullptr)
        {
            return head;
        }
        ListNode *dummy = new ListNode(-1, head);
        ListNode *lastSorted = head; // 最后一个排序好的
        ListNode *cur = head->next;
        while (cur)
        {
            if (lastSorted->val <= cur->val)
            {
                lastSorted = lastSorted->next;
            }
            else
            {
                ListNode *prev = dummy; // 保存遍历节点的前一个值
                while (prev->next->val <= cur->val)
                {
                    prev = prev->next;
                }
                lastSorted->next = cur->next;
                cur->next = prev->next;
                prev->next = cur;
            }
            cur = lastSorted->next;
        }
        return dummy->next;
    }
};
// @lc code=end
