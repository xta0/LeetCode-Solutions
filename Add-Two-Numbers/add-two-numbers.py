# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        head = last = None
        has_carry = False;
        while(l1 or l2):
            v1 = l1.val if l1 else 0
            v2 = l2.val if l2 else 0
            value = v1+v2
            if has_carry:
                value += 1
            if value >= 10:
                has_carry = True
                value -= 10
            else:
                has_carry = False;
            if head is None:
                head = ListNode(value)
                last = head
            else:
                last.next = ListNode(value)
                last = last.next
            
            l1 = l1.next if l1 else None
            l2 = l2.next if l2 else None
            
        if has_carry:
            last.next = ListNode(1)
            
        return head
        