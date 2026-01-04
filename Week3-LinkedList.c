#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student {
    int id;
    char name[40];
    int mid;
    int fin;
    struct student *next;
} Student;

Student *start = NULL;

Student* newStudent(int id, char name[], int mid, int fin) {
    Student *s = (Student*) malloc(sizeof(Student));
    s->id = id;
    strcpy(s->name, name);
    s->mid = mid;
    s->fin = fin;
    s->next = NULL;
    return s;
}

void insertStudent() {
    int id, mid, fin;
    char name[40];

    printf("Ogrenci no: ");    scanf("%d", &id);
    printf("Isim: ");          scanf("%s", name);
    printf("Vize: ");          scanf("%d", &mid);
    printf("Final: ");         scanf("%d", &fin);

    Student *s = newStudent(id, name, mid, fin);

    if (start == NULL || start->id >= id) {
        s->next = start;
        start = s;
    } else {
        Student *tmp = start;
        while (tmp->next && tmp->next->id < id)
            tmp = tmp->next;

        s->next = tmp->next;
        tmp->next = s;
    }
    printf("\n");
}

void printList() {
    Student *p = start;

    if (!p) {
        printf("Liste bos!\n");
        return;
    }

    while (p) {
        int avg = (int)(p->mid * 0.4 + p->fin * 0.6);
        printf("Isim: %s No: %d Vize: %d Final: %d Ortalama: %d\n",
               p->name, p->id, p->mid, p->fin, avg);
        p = p->next;
    }
    printf("\n");
}

void menu() {
    int secim;
    do {
        printf("1- Ogrenci ekle\n");
        printf("2- Listele\n");
        printf("0- Cikis\n");
        scanf("%d", &secim);

        if (secim == 1)
            insertStudent();
        else if (secim == 2)
            printList();
        else if (secim == 0)
            printf("Program kapandi\n");
        else
            printf("Hatali secim!\n");

    } while (secim != 0);
}

int main() {
    menu();
    return 0;
}
