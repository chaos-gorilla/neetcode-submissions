/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */

class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        if (lists == null || lists.length == 0) {
            return null;
        }

        PriorityQueue<ListNode> minHeap = new PriorityQueue<>((a, b) -> Integer.compare(a.val, b.val));
        ListNode resultNode = new ListNode();
        ListNode ptr = resultNode;
        
        // Insert all the first nodes to the pq.
        for (ListNode linkedList : lists) {
            if (linkedList != null) {
                minHeap.add(linkedList);
            }
        }

        // Now we keep popping from the linkedlist, and the list which was read from now.
        // we move the pointer to the next of it, and put that in the pq.
        while (!minHeap.isEmpty()) {
            ListNode topElement = minHeap.poll();
            ptr.next = topElement;
            ptr = ptr.next;
            if (topElement.next != null) {
                minHeap.add(topElement.next);
            }
        }

        return resultNode.next;
    }
}
