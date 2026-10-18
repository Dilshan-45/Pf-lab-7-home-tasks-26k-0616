#include <stdio.h>

int main()
{
    int stock[] = {25, 12, 8, 40, 5, 18, 3, 22};
    int size = sizeof(stock) / sizeof(stock[0]);

    int item, sold;
    int total = 0;
    int leastStock = 0;

    printf("Initial Cafeteria Stock:\n");

    for (int i = 0; i < size; i++)
    {
        printf("Item %d: %d units\n", i + 1, stock[i]);

        if (stock[i] < 10)
        {
            printf("Item %d is LOW on stock - reorder required\n",
                   i + 1);
        }
    }

    while (1)
    {
        printf("\nEnter item number (1-8, or 0 to finish): ");
        scanf("%d", &item);

        if (item == 0)
            break;

        if (item < 1 || item > size)
        {
            printf("Invalid item number!\n");
            continue;
        }

        printf("Enter quantity sold: ");
        scanf("%d", &sold);

        if (sold < 0)
        {
            printf("Error: Quantity sold cannot be negative.\n");
        }
        else if (sold > stock[item - 1])
        {
            printf("Error: Sale exceeds available stock. "
                   "Stock unchanged.\n");
        }
        else
        {
            stock[item - 1] = stock[item - 1] - sold;
            printf("Stock updated successfully.\n");
        }
    }

    printf("\nFinal Stock Levels:\n");

    total = 0;
    leastStock = 0;

    for (int i = 0; i < size; i++)
    {
        printf("Item %d: %d units\n", i + 1, stock[i]);

        total = total + stock[i];

        if (stock[i] < stock[leastStock])
        {
            leastStock = i;
        }
    }

    printf("\nTotal Units Remaining: %d\n", total);
    printf("Item with Least Stock: Item %d\n", leastStock + 1);
    printf("Least Stock Quantity: %d units\n", stock[leastStock]);

    return 0;
}
