<------ 1 ------!>

// Reverse a LinkedList 
// https://leetcode.com/problems/reverse-linked-list/

// time -> O(n)
// space -> O(1)

ListNode* reverseList(ListNode* head) {    
    
    ListNode* newHead = NULL;     
    
    while(head)
    {
        ListNode* next = head->next;
        head->next = newHead;
        newHead = head;
        head = next;
    }
    return newHead;
}



<------ 2 ------!>

// Find middle of LinkedList
// https://leetcode.com/problems/middle-of-the-linked-list/

// time -> O(n/2)
// space -> O(1)

ListNode* middleNode(ListNode* head)
{
    ListNode *fast=head;
    ListNode *slow=head;
    
    while(fast && fast->next)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}



<------ 3 ------!>

// Merge two sorted Linked List
// https://leetcode.com/problems/merge-two-sorted-lists/

// time -> O(n+m)
// space -> O(1)

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
{
    if(!l1)    
        return l2;
    if(!l2)
        return l1;
    
    if(l1->val > l2->val)
        swap(l1,l2);
    
    ListNode* res=l1;
    while(l1 && l2)
    {
        ListNode* temp;
        while(l1 && l1->val <= l2->val)
        {
            temp=l1;
            l1=l1->next;
        }
        temp->next = l2;
        swap(l1, l2);
    }
    return res;            
}



<------ 4 ------!>

// Remove N-th node from back of LinkedList
// https://leetcode.com/problems/remove-nth-node-from-end-of-list/

// time -> O(n)
// space -> O(1)

ListNode* removeNthFromEnd(ListNode* head, int n)
{
    ListNode *fast=head, *slow=head;
    
    while(n--)
    {
        fast=fast->next;
    }    
    if(fast==NULL)         //This is conditon when need to delete 1st node
        return head->next;
    
    while(fast->next != NULL)
    {
        fast=fast->next;
        slow=slow->next;
    }
    slow->next = slow->next->next;
    
    return head;
}



<------ 5 ------!>

// Delete a given Node when a node is given
// https://leetcode.com/problems/delete-node-in-a-linked-list/

// time -> O(1)
// space -> O(1)

void deleteNode(ListNode* node)
{
    ListNode *toDelete = node->next;
    node->val = node->next->val;
    node->next = node->next->next;
    delete toDelete;
    toDelete = NULL;
}



<------ 6 ------!>

// Add two numbers as LinkedList
// https://leetcode.com/problems/add-two-numbers/

// time -> O(max(n,m))
// space -> O(n)

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
    ListNode s(0);
    ListNode *start = &s;
    
    int carry=0;
    while(l1!=NULL || l2!=NULL || carry)
    {
        int sum= (l1?l1->val:0) + (l2?l2->val:0) + carry;
        carry=sum/10;
        start->next = new ListNode(sum%10);
        start = start->next;
        
        l1=l1?l1->next:l1;
        l2=l2?l2->next:l2;
    }  
    
    return s.next;
}