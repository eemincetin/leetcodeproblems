struct ListNode* generateNode() {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    if (newNode == NULL)
        return NULL;

    newNode->next = NULL;
    newNode->val = 0;

    return newNode;
}

void appendNode(struct ListNode** head, const int ival) {
    struct ListNode* newNode = generateNode();
    if (NULL == newNode) {
        printf("Memory Error");
        return;
    }

    struct ListNode* tail = *head;

    newNode->val = ival;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    }
    else {
        tail = *head;
        while (tail->next != NULL) {
            tail = tail->next;
        }
        tail->next = newNode;
    }
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int ival1 = 0;
    int ival2 = 0;
    int sum = 0;
    int carry = 0;

    struct ListNode* temp1 = l1;
    struct ListNode* temp2 = l2;

    struct ListNode* retList = NULL;

    while (temp1 != NULL || temp2 != NULL) {
        ival1 = (temp1 != NULL) ? temp1->val : 0;
        ival2 = (temp2 != NULL) ? temp2->val : 0;
        sum = carry + ival1 + ival2;
        carry = sum / 10;
        appendNode(&retList, sum % 10);
        if (temp1 != NULL)
            temp1 = temp1->next;
        if (temp2 != NULL)
            temp2 = temp2->next;
    }
    
    if (carry > 0)
        appendNode(&retList, carry);
    
    return retList;
}