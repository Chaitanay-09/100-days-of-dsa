struct ListNode *detectCycle(struct ListNode *head) {

    struct ListNode *slow = head;
    struct ListNode *fast = head;

    // Step 1: Detect cycle
    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast)
        {
            // Step 2: Find start of cycle
            slow = head;

            while(slow != fast)
            {
                slow = slow->next;
                fast = fast->next;
            }

            return slow;
        }
    }

    return NULL;
}