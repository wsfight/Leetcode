#
# @lc app=leetcode.cn id=24 lang=python3
#
# [24] 两两交换链表中的节点
#

# @lc code=start
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def swapPairs(self, head: Optional[ListNode]) -> Optional[ListNode]:
        """三指针
        Args:
            1->2->3->4
            head (Optional[ListNode]): 头结点
            dummy = 哑结点
            temp2 = 指向第三个结点
            temp1 = 指向第一个结点
            temp0 = 指向第一个结点的前一个结点(dummy结点)
        Returns:    
            返回交换后的头结点
        """
        if head is None or head.next is None:
            return head
        dummy = ListNode(-1,head)
        temp0 = dummy
        while temp0.next is not None and temp0.next.next is not None:
            temp1 = temp0.next
            temp3 = temp1.next.next
            temp0.next = temp1.next
            temp1.next.next = temp1
            temp1.next = temp3
            temp0 = temp1
        return dummy.next
# @lc code=end

