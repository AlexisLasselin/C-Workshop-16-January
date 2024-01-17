#include <assert.h>
#include <stdio.h>
#include "frontend.h"

int main(void)
{
    //UNIT TEST 1: CREATE A NEW PRODUCT
    T_Product product = CreateProduct(1, "Test", 1, 1.0);
    assert(product.id == 1);
    assert(strcmp(product.name, "Test") == 0);
    assert(product.quantity == 1);
    assert(product.price == 1.0);
    assert(product.index == NULL);
    printf("UNIT TEST 1: CREATE A NEW PRODUCT: PASSED\n");

    printf("========================================\n");

    //UNIT TEST 2: DISPLAY A PRODUCT
    DisplayProduct(product);
    printf("UNIT TEST 2: DISPLAY A PRODUCT: PASSED\n");

    printf("========================================\n");

    //UNIT TEST 3: CREATE A NEW DATABASE
    T_DataBase db;
    db.NumberOfProduct = 0;
    assert(db.NumberOfProduct == 0);
    printf("UNIT TEST 3: CREATE A NEW DATABASE: PASSED\n");

    printf("========================================\n");

    //UNIT TEST 4: ADD A PRODUCT TO DATABASE
    AddProduct(&db, product);
    assert(db.NumberOfProduct == 1);
    assert(db.db[0].id == 1);
    assert(strcmp(db.db[0].name, "Test") == 0);
    assert(db.db[0].quantity == 1);
    assert(db.db[0].price == 1.0);
    assert(db.db[0].index == 0);
    printf("UNIT TEST 4: ADD A PRODUCT TO DATABASE: PASSED\n");

    printf("========================================\n");

    //UNIT TEST 5: SEARCH A PRODUCT IN DATABASE

    T_Product searchProduct = Search(&db, "Test");
    assert(searchProduct.id == 1);
    assert(strcmp(searchProduct.name, "Test") == 0);
    assert(searchProduct.quantity == 1);
    assert(searchProduct.price == 1.0);
    assert(searchProduct.index == 0);
    printf("UNIT TEST 5: SEARCH A PRODUCT IN DATABASE: PASSED\n");

    printf("========================================\n");

    //UNIT TEST 6: DELETE A PRODUCT IN DATABASE

    DeleteProduct(&db, "Test");
    assert(db.NumberOfProduct == 0);
    printf("UNIT TEST 6: DELETE A PRODUCT IN DATABASE: PASSED\n");

    printf("========================================\n");

    //UNIT TEST 7: UPDATE A PRODUCT IN DATABASE

    AddProduct(&db, product);
    EditProduct(&db, "Test", 2, "Test2", 3, 2.0);
    assert(db.db[0].id == 2);
    assert(strcmp(db.db[0].name, "Test2") == 0);
    assert(db.db[0].quantity == 3);
    assert(db.db[0].price == 2.0);
    assert(db.db[0].index == 0);
    printf("UNIT TEST 7: UPDATE A PRODUCT IN DATABASE: PASSED\n");
}


