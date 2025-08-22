#
# @lc app=leetcode.cn id=25 lang=python3
#
# [25] K 个一组翻转链表
#

# @lc code=start
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseKGroup(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        # 1.先取出结点个数
        cnt = 0
        p = head
        while p is not None:
           cnt += 1
           p = p.next
        
        dummy = ListNode(-1,head)
        p0 = dummy
        while cnt >= k:
            # 2.结点>=k个时翻转
            cnt -= k
            cur = p0.next
            prev = None
            for _ in range(k):
                nxt = cur.next
                cur.next = prev
                prev = cur
                cur = nxt   
            """
            1->2->3->4->5  k = 3
            cur->4  prev = 3 p0 = dummy dummy.next = 1
            3->2->1->4->5
            nxt->1 nxt.next->4  dummy.next->3 p0->1
            """
            nxt = p0.next
            p0.next.next = cur
            p0.next = prev
            p0 = nxt
        return dummy.next
                
        
# @lc code=end

