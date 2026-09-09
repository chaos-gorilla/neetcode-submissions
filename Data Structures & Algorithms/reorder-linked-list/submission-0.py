# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        nodes = []
        
        ptr = head
        while ptr:
            nodes.append(ptr)
            ptr = ptr.next

        left = 0
        right = len(nodes) - 1

        updated_list = ListNode()
        pointer_to_updated_list = updated_list
        
        while left <= right:
            node_left = nodes[left]
            node_right = nodes[right]
            node_left.next = None
            node_right.next = None
            if left == right:
                updated_list.next = node_left
                break
            else:
                updated_list.next = node_left
                updated_list.next.next = node_right
                updated_list = node_right
            left += 1
            right -= 1
        
        head = pointer_to_updated_list.next


        
        