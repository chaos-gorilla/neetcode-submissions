# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def getListLength(self, head: Optional[ListNode]) -> int:
        length = 0
        while head:
            length += 1
            head = head.next 
        return length

    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        length_of_ll = self.getListLength(head)
        from_start = length_of_ll - n
        prev = None
        current = head
        for i in range(from_start):
            prev = current
            current = current.next
        if prev:
            prev.next = current.next
        else:
            head = head.next
        return head

