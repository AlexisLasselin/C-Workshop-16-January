typedef struct Product
{
    int id;
    char name[50];
    int quantity;
    double price;
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