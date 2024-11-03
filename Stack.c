#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};
typedef struct node node;

int max_size = 5;
void push(node **head, int *size);
void pop(node **head, int *size);
void peek(node *head);
void traverse(node *head);
int isEmpty(node *head);
int isFull(int size);

int main() {
    node *head = NULL;
    char pilih;
    int size = 0;

    printf("Masukkan batas maksimum stack: ");
    scanf("%d", &max_size);

    do {
        system("cls");
        printf("Ayo dipilih\n");
        printf("1. Push data ke stack\n");
        printf("2. Pop data dari stack\n");
        printf("3. Lihat data teratas (Peek)\n");
        printf("4. Tampilkan isi stack\n");
        printf("MASUKKAN PILIHAN (tekan q untuk keluar): ");
        fflush(stdin);
        scanf("%c", &pilih);

        if (pilih == '1') {
            push(&head, &size);
        }
        else if (pilih == '2') {
            pop(&head, &size);
        }
        else if (pilih == '3') {
            peek(head);
            getch();
        }
        else if (pilih == '4') {
            traverse(head);
            getch();
        }

    } while (pilih != 'q');

    return 0;
}

void push(node **head, int *size) {
    if (isFull(*size)) {
        printf("Stack penuh! Tidak bisa menambah data lagi.\n");
        getch();
        return;
    }

    int bil;
    node *newNode = (node *)malloc(sizeof(node));
    if (newNode == NULL) {
        printf("Alokasi memori gagal.\n");
        getch();
        return;
    }

    printf("Masukkan bilangan: ");
    scanf("%d", &bil);

    newNode->data = bil;
    newNode->next = *head;
    *head = newNode;
    (*size)++;

    printf("Data berhasil ditambahkan ke stack.\n");
    getch();
}

void pop(node **head, int *size) {
    if (isEmpty(*head)) {
        printf("Stack kosong. Tidak ada data yang di-pop.\n");
        getch();
        return;
    }

    node *temp = *head;
    *head = (*head)->next;
    printf("Data %d berhasil di-pop dari stack.\n", temp->data);
    free(temp);
    (*size)--;
    getch();
}

void peek(node *head) {
    if (isEmpty(head)) {
        printf("Stack kosong.\n");
    } else {
        printf("Data teratas di stack: %d\n", head->data);
    }
}

void traverse(node *head) {
    node *current = head;
    system("cls");
    printf("Isi stack (top -> bottom): ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int isEmpty(node *head) {
    return head == NULL;
}

int isFull(int size) {
    return size >= max_size;
}
