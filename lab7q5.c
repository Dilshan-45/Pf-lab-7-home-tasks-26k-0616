#include <stdio.h>

int main()
{
    char phone[30];
    char cleaned[30];

    int i = 0;
    int j = 0;
    int count = 0;

    printf("Enter phone number: ");
    scanf(" %29[^\n]", phone);

    while (phone[i] != '\0')
    {
        if (phone[i] >= '0' && phone[i] <= '9')
        {
            cleaned[j] = phone[i];
            j++;
            count++;
        }

        i++;
    }

    cleaned[j] = '\0';

    printf("\nOriginal Input: %s\n", phone);
    printf("Cleaned Number: %s\n", cleaned);
    printf("Number of Digits: %d\n", count);

    if (count == 11)
    {
        printf("Valid local number\n");
    }
    else
    {
        printf("Invalid length - please re-enter\n");
    }

    return 0;
}
