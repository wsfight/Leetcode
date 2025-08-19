#
# @lc app=leetcode.cn id=2807 lang=python3
#
# [2807] 在链表中插入最大公约数
#

# @lc code=start
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def insertGreatestCommonDivisors(self, head: Optional[ListNode]) -> Optional[ListNode]:
        cur = head
        while cur.next:
            p = ListNode(gcd(cur.val,cur.next.val),cur.next)
            cur.next = p
            cur = cur.next.next
        return head
# @lc code=end

