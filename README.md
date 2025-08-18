## Day15
翻转链表的两种做法
- 头插法
```python
dummy = ListNode(-1,None)
cur = head
while cur is not None:
    head.next = dummy.next
    dummy.next = head
    head = cur
    cur = cur.next
return dummy.next
```
