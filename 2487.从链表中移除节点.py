#
# @lc app=leetcode.cn id=2487 lang=python3
#
# [2487] 从链表中移除节点
#

# @lc code=start
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNodes(self, head: Optional[ListNode]) -> Optional[ListNode]:
        """
        5 2 13 3 8
        5 13 8
        2 13 3 8
        13 保存
        3 8
        从右往左递归，node 始终代表“右侧子链表的最大值所在的节点”；
        若这个最大值大于当前值，删当前节点，否则保留并接回
        """
        # 递归基
        if head.next == None:
            return head
        node = self.removeNodes(head.next)
        if node.val > head.val:
            # 如果右侧子链表的最大值比当前值大,说明当前节点应该被删除
            return node
        head.next = node
        return head
        
# @lc code=end

