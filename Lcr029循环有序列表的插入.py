def insert(self,head,insertVal):
    t = new Node(insertVal)
    t.next = t
    if head is None:
        return t
    ans = head
    minNums = ans.val
    maxNums = ans.val
    while ans.next is not head:
        # 找出了最大最小值
        ans = ans.next
        minNums = min(minNums,ans.val)
        maxNums = max(maxNums,ans.val)
  
  
    # 查找跳跃分段点
 while not(ans.val == maxNums and ans.next.val == minNums):
            # 此时ans处于最大值处
            ans = ans.next
        # 开始进行分类讨论
        # 1.insertVal >= maxNums or insertVal <= minNums
        if insertVal >= maxNums or insertVal <= minNums:
            t.next = ans.next
            ans.next = t
        else:
            # 从头开始遍历
            ans = ans.next
            # 从最小值开始遍历
            while not(ans.val <= insertVal and insertVal <= ans.next.val):
                ans = ans.next
            t.next = ans.next
            ans.next = t
    return head