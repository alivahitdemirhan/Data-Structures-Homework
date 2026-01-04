#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node *next;
    struct node *prev;
} Node;

Node *head = NULL;

/* Node oluşturma */
Node* createNode(int value) {
    Node *n = (Node*) malloc(sizeof(Node));
    n->value = value;
    n->next = NULL;
    n->prev = NULL;
    return n;
}

/* Sona ekleme */
void insertNode() {
    int val;
    printf("Yeni veri giriniz: ");
    scanf("%d", &val);

    Node *newNode = createNode(val);

    if (head == NULL) {
        head = newNode;
    } else {
        Node *tmp = head;
        while (tmp->next != NULL)
            tmp = tmp->next;

        tmp->next = newNode;
        newNode->prev = tmp;
    }
}

/* Listeyi yazdır */
void printList() {
    Node *tmp = head;
    int i = 1;

    while (tmp != NULL) {
        printf("%d. %d\n", i++, tmp->value);
        tmp = tmp->next;
    }
}

/* Veri silme */
void removeNode() {
    if (head == NULL) {
        printf("Liste bos!\n");
        return;
    }

    int key;
    printf("Silinecek veriyi giriniz: ");
    scanf("%d", &key);

    Node *tmp = head;

    /* Baştaki eleman silinecekse */
    if (head->value == key) {
        head = head->next;
        if (head != NULL)
            head->prev = NULL;

        free(tmp);
        return;
    }

    /* Orta veya sondaysa */
    while (tmp != NULL && tmp->value != key)
        tmp = tmp->next;

    if (tmp == NULL)
        return;

    tmp->prev->next = tmp->next;
    if (tmp->next != NULL)
        tmp->next->prev = tmp->prev;

    free(tmp);
}

/* Iterative liste silme */
void destroyList() {
    Node *tmp;

    while (head != NULL) {
        tmp = head;
        head = head->next;
        free(tmp);
    }
    printf("Liste silindi\n");
}

/* Recursive liste silme */
int destroyListRecursive(Node *current) {
    if (current == NULL)
        return 0;

    int count = destroyListRecursive(current->next);
    free(current);
    return count + 1;
}

int main() {
    int choice;

    do {
        printf("1 - Listeye ekle\n");
        printf("2 - Listeyi yazdir\n");
        printf("3 - Listeden sil\n");
        printf("4 - Listeyi recursive sil\n");
        printf("0 - Cikis\n");
        printf("Seciminiz: ");
        scanf("%d", &choice);
        printf("\n");

        switch (choice) {
            case 1: insertNode(); break;
            case 2: printList(); break;
            case 3: removeNode(); break;
            case 4: {
                int deleted = destroyListRecursive(head);
                head = NULL;
                printf("Liste silindi. %d node silindi.\n", deleted);
            } break;
            case 0:
                printf("Program sonlandirildi.\n");
                break;
            default:
                printf("Hatali secim!\n");
        }

    } while (choice != 0);

    return 0;
}
