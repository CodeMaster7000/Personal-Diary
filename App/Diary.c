#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRY_SIZE 1000 

void addEntry()
{
    char entry[MAX_ENTRY_SIZE];
    printf(
        "Please enter your diary entry (max 1000 characters):\n");
    getchar();
    fgets(entry, sizeof(entry), stdin);

    time_t t = time(NULL);
    struct tm* tm_info = localtime(&t);
    char timestamp[20];
    strftime(timestamp, sizeof(timestamp),
             "%Y-%m-%d %H:%M:%S", tm_info);

    FILE* file = fopen("Diary.txt", "a");
    if (file != NULL) {
        fprintf(file, "[%s]\n%s\n\n", timestamp, entry);
        fclose(file);
        printf("Entry added successfully.\n");
    }
    else {
        printf("Error: Could not open diary file.\n");
    }
}

void viewEntries()
{
    char line[MAX_ENTRY_SIZE];
    FILE* file = fopen("Diary.txt", "r");
    if (file != NULL) {
        while (fgets(line, sizeof(line), file) != NULL) {
            printf("%s", line);
        }
        fclose(file);
    }
    else {
        printf("Error: Could not open diary file.\n");
    }
}
int main()
{
    int choice;
    do {
        printf("\nPersonal Diary App\n");
        printf("1. Add diary entry\n");
        printf("2. View diary entries\n");
        printf("3. Exit\n");
        printf("Enter option: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            addEntry();
            break;
        case 2:
            viewEntries();
            break;
        case 3:
            printf("Exiting diary application...");
            break;
        default:
            printf("Invalid input. Please enter a valid option.");
        }
    } while (choice != 3);
    return 0;
}
