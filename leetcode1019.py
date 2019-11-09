# -*- coding:utf-8 -*-
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def nextLargerNodes(self, head):
        """
        :type head: ListNode
        :rtype: List[int]
        """
        res = []
        stack = []
       	curr_node = head
       	index = 0

        while curr_node != None:
        	res.append(0) #加入0，防止后续操作导致数组越界

        	if len(stack) == 0:
        		stack.append((index, curr_node.val))#栈为空直接压栈
        	else:
        		while len(stack) > 0 and stack[len(stack) - 1][1] < curr_node.val:#如果栈顶元素比当前节点的值小，弹出并设置对应的res值
        			temp = stack[len(stack) - 1]
        			res[temp[0]] = curr_node.val
        			stack.pop()
        		stack.append((index, curr_node.val))
        		
        	curr_node = curr_node.next#更新当前节点的位置和下标的值
        	index += 1



        return res 
        

def createLinkList(List):
	if len(List) == 0:
		return None

	t_head = ListNode(List[0])
	t_node = t_head

	i = 1
	while i < len(List):
		t_node.next = ListNode(List[i])
		t_node = t_node.next
		i += 1

	return t_head


temp = [1,7,5,1,9,2,5,1]
t_head = createLinkList(temp)
so = Solution()
print(so.nextLargerNodes(t_head))
