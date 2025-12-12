#include <stdio.h>
#include <string.h>

#define MAX_ITEMS 100

struct Item
{
    char name[50];
    float price;
    int quantity;
};

void addItem(struct Item items[], int *count)
{
    if (*count >= MAX_ITEMS)
    {
        printf("Storage full! Cannot add more items.\n");
        return;
    }

    printf("Enter item name: ");
    scanf("%s", items[*count].name);

    printf("Enter price: ");
    scanf("%f", &items[*count].price);

    printf("Enter quantity: ");
    scanf("%d", &items[*count].quantity);

    (*count)++;

    printf("Item added successfully!\n");
}

void showItems(struct Item items[], int count)
{
    if (count == 0)
    {
        printf("No items added yet.\n");
        return;
    }

    printf("\n===== ITEMS LIST =====\n");
    for (int i = 0; i < count; i++)
    {
        printf("%d. %s | Price: %.2f | Qty: %d | Cost: %.2f\n",
               i + 1, items[i].name, items[i].price,
               items[i].quantity, items[i].price * items[i].quantity);
    }
}

void searchItem(struct Item items[], int count)
{
    char searchName[50];
    printf("Enter item name to search: ");
    scanf("%s", searchName);

    int found = 0;
    for (int i = 0; i < count; i++)
    {
        if (strcmp(searchName, items[i].name) == 0)
        {
            printf("Found: %s | Price: %.2f | Qty: %d\n",
                   items[i].name, items[i].price, items[i].quantity);
            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("Item not found.\n");
    }
}

void deleteItem(struct Item items[], int *count)
{
    int index;

    if (*count == 0)
    {
        printf("No items to delete.\n");
        return;
    }

    printf("Enter item number to delete: ");
    scanf("%d", &index);
    index--;

    if (index >= 0 && index < *count)
    {
        for (int i = index; i < *count - 1; i++)
        {
            items[i] = items[i + 1];
        }
        (*count)--;
        printf("Item deleted successfully!\n");
    }
    else
    {
        printf("Invalid index.\n");
    }
}

void showTotalCost(struct Item items[], int count)
{
    float total = 0;

    for (int i = 0; i < count; i++)
    {
        total += items[i].price * items[i].quantity;
    }

    printf("\nTOTAL MONEY SPENT: %.2f\n", total);
}

int main()
{
    struct Item items[MAX_ITEMS];
    int count = 0;
    int choice;

    printf("\n===== HOUSE ACCESSORIES TRACKER =====\n");

    while (1)
    {
        printf("\n1. Add New Item");
        printf("\n2. Show All Items");
        printf("\n3. Search Item");
        printf("\n4. Delete Item");
        printf("\n5. Show Total Cost");
        printf("\n6. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addItem(items, &count);
            break;
        case 2:
            showItems(items, count);
            break;
        case 3:
            searchItem(items, count);
            break;
        case 4:
            deleteItem(items, &count);
            break;
        case 5:
            showTotalCost(items, count);
            break;
        case 6:
            printf("Exiting...\n");
            return 0;
        default:
            printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}



