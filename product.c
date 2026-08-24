#include <stdio.h>

#define MAX 100

struct Product {
    int id;
    char name[50];
    float price;
    int quantity;
};

int main() {
    struct Product products[MAX];
    int count = 0;
    int choice, i, id, found;
    float totalValue;

    while (1) {
        printf("\n===== PRODUCT MANAGEMENT SYSTEM =====\n");
        printf("1. Add Product\n");
        printf("2. Display Products\n");
        printf("3. Search Product\n");
        printf("4. Update Product\n");
        printf("5. Delete Product\n");
        printf("6. Total Inventory Value\n");
        printf("7. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                if (count >= MAX) {
                    printf("Product limit reached!\n");
                    break;
                }

                printf("Enter Product ID: ");
                scanf("%d", &products[count].id);

                printf("Enter Product Name: ");
                scanf(" %[^\n]", products[count].name);

                printf("Enter Product Price: ");
                scanf("%f", &products[count].price);

                printf("Enter Product Quantity: ");
                scanf("%d", &products[count].quantity);

                count++;

                printf("Product added successfully!\n");
                break;

            case 2:
                if (count == 0) {
                    printf("No products available!\n");
                } else {
                    printf("\nID\tName\t\tPrice\tQuantity\n");
                    printf("---------------------------------------------\n");

                    for (i = 0; i < count; i++) {
                        printf("%d\t%s\t\t%.2f\t%d\n",
                               products[i].id,
                               products[i].name,
                               products[i].price,
                               products[i].quantity);
                    }
                }
                break;

            case 3:
                printf("Enter Product ID to search: ");
                scanf("%d", &id);

                found = 0;

                for (i = 0; i < count; i++) {
                    if (products[i].id == id) {
                        printf("\nProduct Found!\n");
                        printf("ID: %d\n", products[i].id);
                        printf("Name: %s\n", products[i].name);
                        printf("Price: %.2f\n", products[i].price);
                        printf("Quantity: %d\n", products[i].quantity);
                        found = 1;
                        break;
                    }
                }

                if (!found) {
                    printf("Product not found!\n");
                }
                break;

            case 4:
                printf("Enter Product ID to update: ");
                scanf("%d", &id);

                found = 0;

                for (i = 0; i < count; i++) {
                    if (products[i].id == id) {

                        printf("Enter New Product Name: ");
                        scanf(" %[^\n]", products[i].name);

                        printf("Enter New Price: ");
                        scanf("%f", &products[i].price);

                        printf("Enter New Quantity: ");
                        scanf("%d", &products[i].quantity);

                        printf("Product updated successfully!\n");
                        found = 1;
                        break;
                    }
                }

                if (!found) {
                    printf("Product not found!\n");
                }
                break;

            case 5:
                printf("Enter Product ID to delete: ");
                scanf("%d", &id);

                found = 0;

                for (i = 0; i < count; i++) {
                    if (products[i].id == id) {

                        for (int j = i; j < count - 1; j++) {
                            products[j] = products[j + 1];
                        }

                        count--;

                        printf("Product deleted successfully!\n");
                        found = 1;
                        break;
                    }
                }

                if (!found) {
                    printf("Product not found!\n");
                }
                break;

            case 6:
                totalValue = 0;

                for (i = 0; i < count; i++) {
                    totalValue += products[i].price *
                                  products[i].quantity;
                }

                printf("Total Inventory Value = %.2f\n", totalValue);
                break;

            case 7:
                printf("Thank you! Exiting Product Management System...\n");
                return 0;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}