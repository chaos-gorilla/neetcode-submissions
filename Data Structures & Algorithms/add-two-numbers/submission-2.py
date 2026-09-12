# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):, no_type_check_decorator
#         self.val = val
#         self.next = next

class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        answer = ListNode()        
        current_pos = answer

        # here, we need to process both the lists.
        carry = 0
        while l1 and l2:
            node_sum = l1.val + l2.val + carry
            carry = 1 if node_sum >= 10 else 0
            if node_sum >= 10:
                node_sum = node_sum % 10
            current_pos.next = ListNode(node_sum)
            current_pos = current_pos.next
            l1 = l1.next
            l2 = l2.next

        while l1:
            node_sum = l1.val + carry
            carry = 1 if node_sum >= 10 else 0
            if node_sum >= 10:
                node_sum = node_sum % 10
            current_pos.next = ListNode(node_sum)
            current_pos = current_pos.next
            l1 = l1.next

        while l2:
            node_sum = l2.val + (carry if carry == 1 else 0)
            carry = node_sum // 10
            if node_sum >= 10:
                node_sum = node_sum % 10
            current_pos.next = ListNode(node_sum)
            current_pos = current_pos.next
            l2 = l2.next

        if carry:
            current_pos.next = ListNode(1)
            
        return answer.next