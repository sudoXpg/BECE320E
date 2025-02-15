#include <stdio.h>
#include <string.h>

#define MAX 100

int reg[MAX];
char name[MAX][50];
float cgpa[MAX];

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swap_float(float *a, float *b) {
    float temp = *a;
    *a = *b;
    *b = temp;
}

void swap_str(char a[], char b[]) {
    char temp[50];
    strcpy(temp, a);
    strcpy(a, b);
    strcpy(b, temp);
}

void sort_by_name(int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (strcmp(name[j], name[j + 1]) > 0) {
                swap(&reg[j], &reg[j + 1]);
                swap_float(&cgpa[j], &cgpa[j + 1]);
                swap_str(name[j], name[j + 1]);
            }
        }
    }
    printf("\nRegd No\tName\tCGPA\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%s\t%.2f\n", reg[i], name[i], cgpa[i]);
    }
}

void sort_by_cgpa(int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (cgpa[j] < cgpa[j + 1]) {
                swap(&reg[j], &reg[j + 1]);
                swap_float(&cgpa[j], &cgpa[j + 1]);
                swap_str(name[j], name[j + 1]);
            }
        }
    }
    printf("\nRegd No\tName\tCGPA\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%s\t%.2f\n", reg[i], name[i], cgpa[i]);
    }
}

void find_max(int n) {
    int max_index = 0;
    for (int i = 1; i < n; i++) {
        if (cgpa[i] > cgpa[max_index]) {
            max_index = i;
        }
    }
    printf("\nLargest CGPA:\n%d\t%s\t%.2f\n", reg[max_index], name[max_index], cgpa[max_index]);
}

void find_min(int n) {
    int min_index = 0;
    for (int i = 1; i < n; i++) {
        if (cgpa[i] < cgpa[min_index]) {
            min_index = i;
        }
    }
    printf("\nSmallest CGPA:\n%d\t%s\t%.2f\n", reg[min_index], name[min_index], cgpa[min_index]);
}

void search(int n, int search_reg) {
    for (int i = 0; i < n; i++) {
        if (reg[i] == search_reg) {
            printf("\nCGPA of student with Registration Number %d is %.2f\n", reg[i], cgpa[i]);
            return;
        }
    }
    printf("\nNot found\n");
}

int main() {
    int n, choice, search_reg;
    printf("Enter number of students: ");
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        printf("Enter registration number: ");
        scanf("%d", &reg[i]);
        printf("Enter name: ");
        scanf("%s", name[i]);
        printf("Enter CGPA: ");
        scanf("%f", &cgpa[i]);
    }
    
    while (1) {
        printf("\n1. Sort by Name\n2. Sort by CGPA\n3. Highest CGPA\n4. Lowest CGPA\n5. Search by Reg No\n6. Exit\nEnter choice: ");
        scanf("%d", &choice);
        if (choice == 6) break;
        if (choice == 1) sort_by_name(n);
        else if (choice == 2) sort_by_cgpa(n);
        else if (choice == 3) find_max(n);
        else if (choice == 4) find_min(n);
        else if (choice == 5) {
            printf("Enter registration number to search: ");
            scanf("%d", &search_reg);
            search(n, search_reg);
        }
    }
    return 0;
}