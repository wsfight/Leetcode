/*
 * @lc app=leetcode.cn id=725 lang=cpp
 *
 * [725] 分隔链表
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
    vector<ListNode *> splitListToParts(ListNode *head, int k)
    {
        /**
         * 分隔链表
         * 1.计算链表长度
         * 2.划分每个区间的最小长度
         * 3.计算每个区间的长度
         * 4.永远是当前区间的最后一个元素
         */
        // 1.计算链表长度
        int cnt = 0;
        ListNode *temp = head;
        while (temp != nullptr)
        {
            ++cnt;
            temp = temp->next;
        }
        // 2.计算区间个数
        int part = cnt / k;
        int remain = cnt % k;
        // 3.开始计算
        vector<ListNode *> ans;
        ans.reserve(k);
        temp = head;
        for (int i = 0; i < k; ++i)
        {
            ans.push_back(temp);
            // 计算区间大小
            int partSize = part + (remain > 0 ? 1 : 0);
            remain--;
            for (int j = 1; j < partSize; j++)
            {
                // 走partSize-1 步到区间末尾
                temp = temp->next;
            }
            // 分隔链表
            if (temp != nullptr)
            { // 为什么是temp不为空啊
                ListNode *nextTemp = temp->next;
                temp->next = nullptr;
                temp = nextTemp;
            }
        }
        return ans;
    }
};
// @lc code=end
