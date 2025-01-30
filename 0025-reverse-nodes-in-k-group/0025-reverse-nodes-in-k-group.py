# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseKGroup(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:

        
        res = []
        temp = head

        while temp != None:
            res.append(temp.val)
            temp = temp.next
        
        #reset temp pointer to head
        temp = head
        
        #length of array
        ind = len(res)

        #Find largest window in res array for swapping (in terms of k)
        while ind != 0:
            if ind % k == 0:
                break
            ind -= 1
        
        #Puts elements insie of temp
        array2 = res[:ind]
        dummyArray = []

        #Loops over each value
        for i in range(0, len(res), k):
            #Process chunks
            t = array2[i:k + i]
            #Reverses
            t = t[::-1]
            #Add to ans (Extends list, does not append)
            dummyArray.extend(t)

        #Loops and adds values to res(array)
        for i in range(len(array2)):
            res[i] = dummyArray[i]

        #Reset temp
        temp = head

        #Counter for array
        counter = 0
        #Loop and recreate linkedlist
        while (temp != None):
            temp.val = res[counter]
            counter += 1
            temp = temp.next

        return head

            


        
        

        
        





        