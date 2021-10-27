<------ 1 ------!>

// Find intersection point of Y LinkedList
// https://leetcode.com/problems/intersection-of-two-linked-lists/

// time -> O(2*m)
// space -> O(1)

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
{    
    ListNode* cur1=headA;
    ListNode* cur2=headB;
    
    while(cur1 != cur2)
    {
        if(cur1)
            cur1=cur1->next;
        else
            cur1=headB;
        
        if(cur2)
            cur2=cur2->next;
        else
            cur2=headA;
    }
        
    return cur1;        
}



<------ 2 ------!>

// Detect a cycle in Linked List
// https://leetcode.com/problems/linked-list-cycle/

// time -> O(n)
// space -> O(1)

bool hasCycle(ListNode *head) {
    ListNode *fp=head;
    ListNode *lp=head;
    
    while(fp && fp->next)
    {                        
        lp=lp->next;
        fp=fp->next->next;                
        if(fp == lp)
            return true;
    }
    
    return false;
}



<------ 3 ------!>

// Reverse a LinkedList in groups of size k
// https://leetcode.com/problems/reverse-nodes-in-k-group/

// time -> O(n)
// space -> O(1)

ListNode* reverseKGroup(ListNode* head, int k)
{
    if(head==NULL || k==1)
        return head;
    
    ListNode* s = new ListNode(0);
    s->next = head;
    
    ListNode *curr=s, *next=s, *pre=s;
    int cnt=0;
    
    while(curr->next) {
        curr=curr->next;
        cnt++;
    }        
    while(cnt>=k)
    {
        curr=pre->next;
        next=curr->next;
        
        for(int i=1;i<k;i++)
        {
            curr->next = next->next;
            next->next = pre->next;
            pre->next = next;
            next = curr->next;
        }
        pre = curr;
        cnt-=k;
    }
    return s->next;
}



<------ 4 ------!>

// Check if a LinkedList is palindrome or not
// https://leetcode.com/problems/palindrome-linked-list/

// time -> O(n)
// space -> O(1)

bool isPalindrome(ListNode* head)
{        
	if(!head || !head->next)
		return true;

    ListNode* fast=head;
    ListNode* slow=head;
    
    while(fast->next && fast->next->next)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    
    slow->next = reverseList(slow->next);
    slow=slow->next;
    
    while(slow)
    {
        if(head->val != slow->val)
            return false;
        head=head->next;
        slow=slow->next;
    }
    return true;   
}
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



<------ 5 ------!>

// Find the starting point of the Loop of LinkedList
// https://leetcode.com/problems/linked-list-cycle-ii/

// time -> O(n)
// space -> O(1)

ListNode *detectCycle(ListNode *head)
{
    if(head==NULL || head->next==NULL)
        return NULL;
    
    ListNode *fast=head, *slow=head;
    
    while(fast->next && fast->next->next)
    {
        slow=slow->next;
        fast=fast->next->next;
        
        if(slow==fast)
        {
            fast=head;
            while(fast!=slow)
            {
                slow=slow->next;
                fast=fast->next;
            }
            return fast;
        }
    }
    return NULL;
}



<------ 6 ------!>

// Flattening of a LinkedList
// https://practice.geeksforgeeks.org/problems/flattening-a-linked-list/1

// time -> O(sum(n))
// space -> O(1)

Node* merge(Node *l1, Node *l2)
{
    Node* res = new Node(0);
    Node* temp= res;
    
    while(l1 && l2)
    {
        if(l1->data < l2->data)
        {
            temp->bottom = l1;
            temp = temp->bottom;
            l1 = l1->bottom;
        }
        else
        {
            temp->bottom = l2;
            temp = temp->bottom;
            l2 = l2->bottom;
        }
    }
    if(l1)
        temp->bottom = l1;
    else
        temp->bottom = l2;
    
    return res->bottom;
}

Node *flatten(Node *root)
{
    if(!root || !root->next)
        return root;
        
    root->next = flatten(root->next);
    
    root = merge(root, root->next);
    
    return root;
}



<------ 7 ------!>

// Rotate a LinkedList
// https://leetcode.com/problems/rotate-list/

// time -> O(n)
// space -> O(1)

ListNode* rotateRight(ListNode* head, int k)
{
    if(!head || !head->next || k==0)
        return head;
    
    ListNode *curr=head;
    int cnt=1;
    while(curr->next)
    {
        curr=curr->next;
        cnt++;
    }        
    curr->next = head;
    k = k%cnt;
    k = cnt - k;
    
    curr=head;                        
    for(int i=1;i<k;i++)
        curr=curr->next;
    
    head = curr->next;
    curr->next = NULL;
    
    return head;        
}