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

- 翻转链表(就地做法)有 2 个特性
- 1.prev 永远指向翻转后的第一个结点(翻转前的最后一个结点)
- 2.cur 永远指向翻转前的最后一个结点的下个(如果为空则为空)

eg(Lc92): 1 2 3 4 5 要翻转 2 3 4-> 4 3 2 最后链表为 1 4 3 2 5
则 prev 翻转结束后指向 4,cur 指向 5

## Day16

递归链表其实就是从尾部遍历链表
[warning]不懂必须重新学习

```python3
if head.next is None:
    return head
node = reverseNode(head.next)
if node.val > head.val:
    return node
head.next = node
return head
```
