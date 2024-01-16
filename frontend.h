#include <string.h>

typedef struct Product
{
    int id;
    char name[50];
    int quantity;
    double price;
    int index;
}T_Product;

T_Product CreateProduct(int xid, char xname[50], int xquantity, double xprice)
{
    T_Product arival;
    arival.id = xid;
    for(int i=0; i<50; i++)
    {
        arival.name[i] = xname[i];
    }
    arival.quantity = xquantity;
    arival.price = xprice;
    return arival;
}

void DisplayProduct(T_Product product)
{
    if(product.index != -1)
    {
        printf("=====Product=====\n");
        printf("ID: %d\n", product.id);
        printf("Name: %s\n", product.name);
        printf("Quantity: %d\n", product.quantity);
        printf("Price: %lf\n", product.price);
        printf("=================\n");
    } 

}

typedef struct DataBase
{
    T_Product db[1000];
    int NumberOfProduct;
}T_DataBase;

void AddProduct(T_DataBase* xdb, T_Product xproduct)
{
    xproduct.index = xdb->NumberOfProduct;
    xdb->db[xdb->NumberOfProduct] = xproduct;
    xdb->NumberOfProduct = xdb->NumberOfProduct+1;
}

T_Product Search(T_DataBase* xdb, char xname[50])
{
    T_Product back;
    back.index = -1;
    for(int i = 0 ; i < xdb->NumberOfProduct; i++)
    {
        if(!strcmp(xdb->db[i].name, xname))
        {
            return xdb->db[i];
        }
    }
    printf("ERROR: Product Not Found\n");
    return back;
}

void DeleteProduct(T_DataBase* xdb, char xname[50])
{
    T_Product x;
    x = Search(xdb, xname);
    if(x.index != -1)
    {
        for(int i = x.index; i < xdb->NumberOfProduct+1; i++)
        {
            xdb->db[i] = xdb->db[i+1];
        }
        xdb->NumberOfProduct = xdb->NumberOfProduct-1;
        printf("Product Deleted\n");
    }
}