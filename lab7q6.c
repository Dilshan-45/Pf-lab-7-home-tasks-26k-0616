#include <stdio.h>

int main()
{
    int queue[15];
    int count = 0;
    int token;
    char choice;

    
    while (count < 15)
    {
        printf("Enter token number (-1 to finish): ");
        scanf("%d", &token);

        if (token == -1)
            break;

        queue[count] = token;
        count++;
    }

    // Display the registered queue
    printf("\nCurrent Queue:\n");

    for (int i = 0; i < count; i++)
    {
        printf("Position %d -> Token %d\n", i + 1, queue[i]);
    }

    while (count > 0)
    {
        printf("\nEnter C to call patient, E for emergency, Q to quit: ");
        scanf(" %c", &choice);

        if (choice == 'C' || choice == 'c')
        {
            printf("Calling Token %d\n", queue[0]);

            for (int i = 0; i < count - 1; i++)
            {
                queue[i] = queue[i + 1];
            }

            count--;
        }
        else if (choice == 'E' || choice == 'e')
        {
            if (count == 15)
            {
                printf("Queue is full! Cannot add emergency token.\n");
                continue;
            }

            printf("Enter emergency token: ");
            scanf("%d", &token);

            for (int i = count; i > 0; i--)
            {
                queue[i] = queue[i - 1];
            }

            queue[0] = token;
            count++;
        }
        else if (choice == 'Q' || choice == 'q')
        {
            printf("Queue management stopped.\n");
            break;
        }
        else
        {
            printf("Invalid choice!\n");
            continue;
        }

        // Display the updated queue
        printf("\nUpdated Queue:\n");

        if (count == 0)
        {
            printf("No patients waiting.\n");
        }

        for (int i = 0; i < count; i++)
        {
            printf("Position %d -> Token %d\n", i + 1, queue[i]);
        }
    }

    if (count == 0)
    {
        printf("\nAll patients have been called. Queue is empty.\n");
    }

    return 0;
}
