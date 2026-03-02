struct ListNode* removeElements(struct ListNode* head, int val) {
    
    // Remove nodes from beginning if they contain val
    while(head != NULL && head->val == val) {
        head = head->next;
    }

    struct ListNode* curr = head;

    while(curr != NULL && curr->next != NULL) {
        if(curr->next->val == val) {
            curr->next = curr->next->next;
        } else {
            curr = curr->next;
        }
    }

    return head;
}