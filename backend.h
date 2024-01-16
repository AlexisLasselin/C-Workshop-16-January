// back end file
// simple file mangement system 
// create a command line program that can create, delete, and list files
// must support both text and binary files
// minimal main function
// don't open files 
// think about the frontend needs and how to implement them

#include <stdlib.h>
#include <stdio.h>

int createCSVNew(const char* fileName)
{
    FILE* myFile = fopen(fileName, "a+");
    if(myFile == NULL)
    {
        fputs("Cannot open file\n", stderr);
        return EXIT_FAILURE;
    }

    fclose(myFile);

    return EXIT_SUCCESS;
}

int removeCSVNew(const char* fileName)
{
    remove(fileName);
    if (remove(fileName) != 0)
        printf("Deleted successfully the csv file.\n");
    else
        printf("Unable to delete the file\n");

    return 0;
}

int saveCSV (const char* fileName, T_DataBase DB)
{
    FILE* myFile = fopen(fileName, "w");
    if(myFile == NULL)
    {
        fputs("Cannot open file\n", stderr);
        return EXIT_FAILURE;
    }

    for(int i = 0; i < DB.NumberOfProduct; i++)
    {
        fprintf(myFile, "%d,%s,%d,%lf\n", DB.db[i].id, DB.db[i].name, DB.db[i].quantity, DB.db[i].price);
    }

    fclose(myFile);

    return EXIT_SUCCESS;
}

/* This is the instructions*/

//int main(void)
//{

    //createCSVNew("fileName.txt");  -> creating a .txt file
    //createCSVNew("fileName.csv");  -> creating a .csv file
    //removeCSVNew("fileName.txt");  -> removing a .txt file
    //removeCSVNew("fileName.csv");  -> removing a .csv file

    // We just need to change the 'fileName' in these calls to change the actual filename that will be created.

    //return EXIT_SUCCESS;
//}
