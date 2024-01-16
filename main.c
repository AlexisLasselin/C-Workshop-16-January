#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 
#include "frontend.h"
#include "backend.h"

int main() 
{
    createCSVNew("database.csv");

    T_DataBase DB;
    DB.NumberOfProduct = 0;

    while (true) 
    {
        clearScreen();
        printf("\n\t\t **** Welcome to our ****");
        printf("\n\n\t\t\tMAIN MENU");
        printf("\n\t\t=====================");
        printf("\n\t\t[1] Add a new product");
        printf("\n\t\t[2] Remove a product");
        printf("\n\t\t[3] Search a product");
        printf("\n\t\t[4] Edit/Update a product");
        printf("\n\t\t[5] Save list of products to database");
        printf("\n\t\t[6] Display list of products");
        printf("\n\t\t[0] Exit the program");
        printf("\n\t\t=================\n\t\t");

        int choice;
            printf("\n\t\tSelect an option: ");
            scanf("%d", &choice);
            getchar();

        if (choice == 1)
        {
            clearScreen();

            printf("\n\n\n\t\t\tAdd a new product");
            printf("\n\t\t=====================");

            printf("\n\t\tEnter the product ID: ");
            int id;
            scanf("%d", &id);
            getchar();

            printf("\n\t\tEnter the product name: ");
            char name[50];
            scanf("%s", name);
            getchar();

            printf("\n\t\tEnter the product quantity: ");
            int quantity;
            scanf("%d", &quantity);
            getchar();

            printf("\n\t\tEnter the product price: ");
            double price;
            scanf("%lf", &price);
            getchar();

            T_Product product = CreateProduct(id, name, quantity, price);
            AddProduct(&DB, product);

            printf("\n\t\tProduct added successfully!\n");
            printf("\n\t\tDo you want to save it to the database? (y/n): ");
            char save;
            scanf("%c", &save);
            getchar();
            if (save == 'y')
            {
                saveCSV("database.csv", DB);
            }
            else
            {
                printf("\n\t\tProduct not saved!\n");
            }
        }
        else if (choice == 2)
        {
            clearScreen();

            printf("\n\n\n\t\t\tRemove a product");
            printf("\n\t\t=====================");

            printf("\n\t\tEnter the product name: ");
            char name[50];
            scanf("%s", name);
            getchar();

            T_Product product = Search(&DB, name);
            if(product.index != -1)
            {
                DeleteProduct(&DB, product.name);
            }
            else
            {
                printf("\n\t\tProduct not found!\n");
            }
        }
        else if (choice == 3)
        {
            clearScreen();

            printf("\n\n\n\t\t\tSearch a product");
            printf("\n\t\t=====================");

            printf("\n\t\tEnter the product name: ");
            char name[50];
            scanf("%s", name);
            getchar();

            T_Product product = Search(&DB, name);
            if(product.index != -1)
            {
                DisplayProduct(product);
            }
            else
            {
                printf("\n\t\tProduct not found!\n");
            }

            printf("\n\t\tpress any key to continue...");
            getchar();
        }
        else if (choice == 4)
        {
            clearScreen();

            printf("\n\n\n\t\t\tEdit/Update a product");
            printf("\n\t\t=====================");

            printf("\n\t\tEnter the product name: ");
            char name[50];
            scanf("%s", name);
            getchar();

            T_Product product = Search(&DB, name);
            if(product.index != -1)
            {
                printf("\n\t\tEnter the new product ID: ");
                int id;
                scanf("%d", &id);
                getchar();

                printf("\n\t\tEnter the new product name: ");
                char name[50];
                scanf("%s", name);
                getchar();

                printf("\n\t\tEnter the new product quantity: ");
                int quantity;
                scanf("%d", &quantity);
                getchar();

                printf("\n\t\tEnter the new product price: ");
                double price;
                scanf("%lf", &price);

                EditProduct(&DB, product.name, id, name, quantity, price);

            }
        } else if (choice == 5)
        {
            clearScreen();

            printf("\n\n\n\t\tSave list of products to database");
            printf("\n\t\t=====================");

            saveCSV("database.csv", DB);

            printf("\n\t\tProducts saved successfully!\n");

            printf("\n\t\tpress any key to continue...");
            getchar();

        } else if (choice == 6)
        {
            clearScreen();

            printf("\n\n\n\tDisplay list of products");
            printf("\n\t\t=====================");

            for (int i = 0; i < DB.NumberOfProduct; i++)
            {   
                DisplayProduct(DB.db[i]);
            }

            printf("\n\t\tNumber of products: %d", DB.NumberOfProduct);
            printf("\n\t\t=====================");

            printf("\n\t\tpress any key to continue...");
            getchar();
        } else if (choice == 0)
        {
            clearScreen();
            printf("\n\n\n\t\t\tThank you for using the program!");
            printf("\n\t\t=====================");

            printf("\n\t\tpress any key to continue...");
            getchar();
            break;

        }
        
    }
return 0;
}