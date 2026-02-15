#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int readFile(char *path);
int writeFile(char *path);

int main(void)
{

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
        case 2:
            writeFile(path);
            break;
        case 3:
            isRunning = false;
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
        printf("\n");
        printf("Failed to open file\n\n");
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

int writeFile(char *path)
{
    FILE *wfp;
    char option = '\0';

    printf("Enter the path to the file you would like to write: ");
    fgets(path, 1024, stdin);
    path[strcspn(path, "\n")] = '\0';

    FILE *check = fopen(path, "r");

    if (check != NULL)
    {
        printf("File exists. Overwrite(y/n)?: ");
        scanf(" %c", &option);
        getchar();

        if (option != 'y')
        {
            printf("Cancelled\n");
            return 1;
        }
    }
    else
    {
        printf("File does not exist. Create new file at the given directory(y/n)?: ");
        scanf(" %c", &option);
        getchar();

        if (option != 'y')
        {
            printf("File not created\n");
            return 1;
        }
    }

    wfp = fopen(path, "w");

    if (wfp == NULL)
    {
        perror("Failed to open file");
        return 1;
    }

    printf("Begin writing (Enter a new line to stop writing):\n");

    char buffer[1024] = "\0";

    while (1)
    {
        fgets(buffer, 1024, stdin);

        if (buffer[0] == '\n')
        {
            break;
        }

        fputs(buffer, wfp);

        fclose(wfp);
        printf("File saved succesfully\n");
        return 0;
    }
}