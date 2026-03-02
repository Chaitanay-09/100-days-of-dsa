class Solution {
  public:
    void removeLoop(Node* head) {
        
        Node *slow = head, *fast = head;
        
        // Step 1: Detect loop
        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            
            if(slow == fast)
            {
                // Step 2: Move slow to head
                slow = head;
                
                // Special case: loop starts at head
                if(slow == fast)
                {
                    while(fast->next != slow)
                        fast = fast->next;
                }
                else
                {
                    while(slow->next != fast->next)
                    {
                        slow = slow->next;
                        fast = fast->next;
                    }
                }
                
                // Step 3: Break loop
                fast->next = NULL;
                return;
            }
        }
    }
};