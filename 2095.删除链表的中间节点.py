#
# @lc app=leetcode.cn id=2095 lang=python3
#
# [2095] 删除链表的中间节点
#

# @lc code=start
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteMiddle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        cnt = 0
        p = head
        while p:
            cnt += 1
            p = p.next
        k = cnt // 2
        dummy = ListNode(-1,head)
        p0 = dummy
        for _ in range(k):
            p0 = p0.next
        p0.next = p0.next.next
        return dummy.next
            
            
# @lc code=end

