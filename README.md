## Day15

翻转链表的两种做法

- 头插法

```python
def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
    dummy = ListNode(-1,None)
    cur = head
    while cur is not None:
        head.next = dummy.next
        dummy.next = head
        head = cur
        cur = cur.next
    return dummy.next
```

- 就地做法

```python
def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
    prev = None
    cur = head
    while cur is not None:
        nxt = cur.next
        cur.next = prev
        prev = cur
        cur = nxt
    return prev             # 注意返回的是prev 此时prev指的是最后一个结点
```
