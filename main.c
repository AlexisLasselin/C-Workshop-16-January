#include <stdio.h>
#include <stdlib.h>
#include "frontend.h"
#include "backend.h"

int main() {
    
    T_DataBase DB;
    DB.NumberOfProduct = 0;
    
    T_Product x1 = CreateProduct(1, "pasta", 50, 2.20);
    T_Product x2 = CreateProduct(2, "rice", 45, 2.50);


    AddProduct(&DB, x1);
    AddProduct(&DB, x2);

    DisplayProduct(Search(&DB, "rice"));
    DeleteProduct(&DB, "rice");
    DisplayProduct(Search(&DB, "rice"));


    return EXIT_SUCCESS;
}