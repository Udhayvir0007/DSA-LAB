#include <stdio.h>
struct Employee {
    int salary;
    char name[20];
    int increment;
};
int main(void) {
    struct Employee employees[3];
    FILE* fptr;
        printf("\n");
    fptr = fopen("employees.txt", "wb");
    if (fptr == NULL) return 1;
    for (int i = 0; i < 3; i++) {
        printf("enter salary: ");
        scanf("%d", &employees[i].salary);
        printf("enter name: ");
        scanf("%19s", employees[i].name);
        if (employees[i].salary >= 50000) {
            employees[i].increment = 5;
        }
        else if (employees[i].salary > 20000 && employees[i].salary < 50000) {
            employees[i].increment = 10;
        }
        else {
            employees[i].increment = 15;
        }
        employees[i].salary += (employees[i].salary * employees[i].increment) / 100;
        fwrite(&employees[i], sizeof(struct Employee), 1, fptr);
    }
    fclose(fptr);
    






fptr = fopen("employees.txt", "rb"); 
    if (fptr == NULL) return 1;
    for (int i = 0; i < 3; i++) {
        if (fread(&employees[i], sizeof(struct Employee), 1, fptr) == 1) {
            printf("Employee %d -> Name: %s, Salary: %d, Increment: %d%%\n", 
                   i + 1, employees[i].name, employees[i].salary, employees[i].increment);
        }
    }
    fclose(fptr);
    return 0;
}
