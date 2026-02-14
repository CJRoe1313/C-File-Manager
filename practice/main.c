#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{

    char *input = NULL;
    int choice = 0;

    printf("**** C FILE MANAGER ****\n");

    do
    {

        printf("Choose an option:\n");
        printf("1. Read a file\n");
        printf("2. Write a file\n");
        printf("3. Close program\n");
        scanf("%d", &choice);

    } while (choice != 3);

    printf("Thank you for using C FILE MANAGER\n");

    return 0;
}