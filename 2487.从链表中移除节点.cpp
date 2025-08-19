/*
 * @lc app=leetcode.cn id=2487 lang=cpp
 *
 * [2487] 从链表中移除节点
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
    ListNode *reverseNodes(ListNode *head)
    {
        ListNode *prev = nullptr;
        while (head != nullptr)
        {
            ListNode *nxt = head->next;
            head->next = prev;
            prev = head;
            head = nxt;
        }
        return prev;
    }
    ListNode *removeNodes(ListNode *head)
    {
        /**
         * 5 2 13 3 8 移除右侧有更大结点
         * 5 -> 13 和 8
         * 2 -> 13 3 和 8
         * 13 保存
         * 3 -> 8
         * 8  保存
         * 最后一个结点一定被保存
         * 13 和 8
         * 如果我们反转链表
         * 8 -> 3 -> 13 -> 2 -> 5
         * 我们如何来计算呢?
         * 只需要保存 比左边大的值即可?
         */
        // 反转了链表
        // 然后双指针进行比较吗?
        head = reverseNodes(head);
        ListNode *cur = head;
        while (cur->next)
        {
            if (cur->val > cur->next->val)
            {
                cur->next = cur->next->next; // 链接上了
            }
            else
            {
                cur = cur->next;
            }
        }
        return reverseNodes(head);
    }
};
// @lc code=end
