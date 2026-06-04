struct ListNode* insertionSortList(struct ListNode* head) {
    // Dummy node as the head of sorted list
    struct ListNode dummy;
    dummy.val = 0;
    dummy.next = NULL;

    struct ListNode* curr = head;

    while (curr != NULL) {
        struct ListNode* next = curr->next; // Save next node

        // Find the correct position in sorted list
        struct ListNode* prev = &dummy;
        while (prev->next != NULL && prev->next->val < curr->val) {
            prev = prev->next;
        }

        // Insert curr between prev and prev->next
        curr->next = prev->next;
        prev->next = curr;

        curr = next; // Move to next unsorted node
    }

    return dummy.next;
}