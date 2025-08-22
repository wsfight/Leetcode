#
# @lc app=leetcode.cn id=2074 lang=python3
#
# [2074] 反转偶数长度组的节点
#

# @lc code=start
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseEvenLengthGroups(self, head: Optional[ListNode]) -> Optional[ListNode]:
        cnt = 0
        p = head
        while p:
            cnt += 1
            p = p.next
        dummy = ListNode(-1,head)
        p0 = dummy
        i = 1
        while cnt > 0:
            i = min(i,cnt)
            cnt -= i
            if i % 2 == 0:
                # 此时需要翻转
                prev = None
                cur = p0.next  # 指向要翻转的第一个结点
                for _ in range(i):
                    nxt = cur.next
                    cur.next = prev
                    prev = cur
                    cur = nxt
                nxt = p0.next
                p0.next.next = cur
                p0.next = prev
                p0 = nxt
            else:
                for _ in range(i):
                    p0 = p0.next
            i += 1
        return dummy.next
                
               
            
# @lc code=end

