#
# @lc app=leetcode.cn id=817 lang=python3
#
# [817] 链表组件
#

# @lc code=start
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def numComponents(self, head: Optional[ListNode], nums: List[int]) -> int:
        """同理而已,改进用集合"""
        s = set(nums)
        ans = 0
        while head != None:
            temp = head.val
            if temp in s:
                ans += 1
                while head != None and head.val in s:
                    head = head.next
            else:
                head = head.next
        return ans
# @lc code=end

