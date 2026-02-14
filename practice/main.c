#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int readFile(char *path);

int main(void)
{

    char *input = NULL;
    int choice = 0;
    char path[1024] = {0};
    bool isRunning = true;

    printf("**** C FILE MANAGER ****\n");

    while (isRunning)
    {

        printf("Choose an option:\n");
        printf("1. Read a file\n");
        printf("2. Write a file\n");
        printf("3. Close program\n");
        scanf("%d", &choice);
        getchar();

        switch (choice)
        {
        case 1:
            readFile(path);
            break;
        }
    }

    printf("Thank you for using C FILE MANAGER\n");

    return 0;
}

int readFile(char *path)
{

    FILE *fp;
    char data[1024] = {0};
    char closeFile;

    printf("Enter the path to the file you would like to read: ");
    fgets(path, 1024, stdin);
    path[strcspn(path, "\n")] = '\0';
    fp = fopen(path, "r");

    if (fp == NULL)
    {
        printf("Failed to open file\n");
        return 1;
    }

    printf("File opened succesfully\n\n");

    while (fgets(data, 1024, fp) != NULL)
    {
        printf("%s\n", data);
    }
    fclose(fp);
    return 0;
}