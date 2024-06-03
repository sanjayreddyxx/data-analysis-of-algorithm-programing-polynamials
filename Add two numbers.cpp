#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* dummyHead = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* current = dummyHead;
    int carry = 0;

    while (l1 || l2 || carry) {
        int sum = carry;
        if (l1) {
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2) {
            sum += l2->val;
            l2 = l2->next;
        }
        carry = sum / 10;
        
        current->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        current = current->next;
        current->val = sum % 10;
        current->next = NULL;
    }

    struct ListNode* result = dummyHead->next;
    free(dummyHead);
    return result;
}

void printList(struct ListNode* head) {
    while (head) {
        printf("%d -> ", head->val);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    // Example 1
    struct ListNode* l1 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* l2 = (struct ListNode*)malloc(sizeof(struct ListNode));
    l1->val = 2; l1->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    l1->next->val = 4; l1->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    l1->next->next->val = 3; l1->next->next->next = NULL;
    
    l2->val = 5; l2->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    l2->next->val = 6; l2->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    l2->next->next->val = 4; l2->next->next->next = NULL;

    printf("Input: ");
    printList(l1);
    printf("        ");
    printList(l2);

    struct ListNode* result1 = addTwoNumbers(l1, l2);
    printf("Output: ");
    printList(result1);

    // Free memory
    while (l1) {
        struct ListNode* temp = l1;
        l1 = l1->next;
        free(temp);
    }
    while (l2) {
        struct ListNode* temp = l2;
        l2 = l2->next;
        free(temp);
    }
    while (result1) {
        struct ListNode* temp = result1;
        result1 = result1->next;
        free(temp);
    }

    return 0;
}

