
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int student_id;
    int score;
    struct Node* next;
};

struct Node* mergeAndSort(struct Node* a, struct Node* b) {
    struct Node* merged = NULL;
    struct Node* tail = NULL;

    while (a != NULL && b != NULL) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

        if (a->student_id < b->student_id) {
            newNode->student_id = a->student_id;
            newNode->score = a->score;
            a = a->next;
        } else {
            newNode->student_id = b->student_id;
            newNode->score = b->score;
            b = b->next;
        }

        newNode->next = NULL;

        if (merged == NULL) {
            merged = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    if (a != NULL) {
        if (merged == NULL) {
            merged = a;
        } else {
            tail->next = a;
        }
    } else if (b != NULL) {
        if (merged == NULL) {
            merged = b;
        } else {
            tail->next = b;
        }
    }

    return merged;
}

void printList(struct Node* head) {
    struct Node* current = head;

    while (current != NULL) {
        printf("%d %d\n", current->student_id, current->score);
        current = current->next;
    }
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    struct Node* listA = NULL;
    struct Node* listB = NULL;

    for (int i = 0; i < N; i++) {
        int student_id, score;
        scanf("%d %d", &student_id, &score);

        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->student_id = student_id;
        newNode->score = score;
        newNode->next = NULL;

        if (listA == NULL) {
            listA = newNode;
        } else {
            struct Node* current = listA;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    for (int i = 0; i < M; i++) {
        int student_id, score;
        scanf("%d %d", &student_id, &score);

        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->student_id = student_id;
        newNode->score = score;
        newNode->next = NULL;

        if (listB == NULL) {
            listB = newNode;
        } else {
            struct Node* current = listB;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    struct Node* mergedList = mergeAndSort(listA, listB);
    printList(mergedList);

    // Free allocated memory
    while (mergedList != NULL) {
        struct Node* temp = mergedList;
        mergedList = mergedList->next;
        free(temp);
    }

    return 0;
}
