#
# @lc app=leetcode.cn id=92 lang=python3
#
# [92] 反转链表 II
#

# @lc code=start
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseBetween(self, head: Optional[ListNode], left: int, right: int) -> Optional[ListNode]:
        dummy = ListNode(-1,head)
        p0 = dummy
        for _ in range(left - 1):
            p0 = p0.next    # p0位于要翻转的前一个结点
        cur = p0.next
        prev = None
        # 开始翻转right - left + 1个结点
        for _ in range(right - left + 1):
            nxt = cur.next
            cur.next = prev
            prev = cur
            cur = nxt
        # cur->5 prev->4
        # p0->1  p0.next->2
        p0.next.next = cur
        p0.next = prev
        return dummy.next   
# @lc code=end

