#
# @lc app=leetcode.cn id=147 lang=python3
#
# [147] 对链表进行插入排序
#

# @lc code=start
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def insertionSortList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        """
            对于我个人来说还挺难的
        """
        if head is None:
            return head
        dummy = ListNode(-1,head)
        lastSortedNode = head
        cur = head.next
        while cur:
            if lastSortedNode.val <= cur.val:
                lastSortedNode = lastSortedNode.next
            else:
                # lastSortedNode > cur.val
                prev = dummy
                while prev.next.val <= cur.val:
                    # 思路不清楚
                    prev = prev.next
                lastSortedNode.next = cur.next
                cur.next = prev.next
                prev.next = cur
                
            cur = lastSortedNode.next
        return dummy.next
                    
        
# @lc code=end

