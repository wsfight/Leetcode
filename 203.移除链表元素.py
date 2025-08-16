#
# @lc app=leetcode.cn id=203 lang=python3
#
# [203] 移除链表元素
#

# @lc code=start
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeElements(self, head: Optional[ListNode], val: int) -> Optional[ListNode]:
        dummy =  ListNode(-1,head)
        cur = head
        prev = dummy
        while cur is not None:
            if cur.val == val:
                prev.next = cur.next
                cur = prev.next
            else:
                prev = cur
                cur = cur.next
        return dummy.next
# @lc code=end

