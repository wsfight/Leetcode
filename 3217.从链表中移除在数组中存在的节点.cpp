/*
 * @lc app=leetcode.cn id=3217 lang=cpp
 *
 * [3217] 从链表中移除在数组中存在的节点
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
    ListNode *modifiedList(vector<int> &nums, ListNode *head)
    {
        unordered_set<int> s;
        for (auto x : nums)
        {
            s.emplace(x);
        }
        ListNode *dummy = new ListNode(-1, head);
        ListNode *prev = dummy;
        ListNode *cur = head;
        while (cur != nullptr)
        {
            if (s.count(cur->val))
            {
                // 存在
                prev->next = cur->next;
                cur = prev->next;
            }
            else
            {
                // 不存在
                prev = cur;
                cur = cur->next;
            }
        }
        return dummy->next;
    }
};
// @lc code=end
