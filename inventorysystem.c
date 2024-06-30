/*
    Developed by: James Ald Teves
    BS Computer Science

    Instructor: Prof. Assist. Melody Angelique Rivera
	Computing Problem 9 Final Project
    Description: Inventory Systemc:\Users\james\OneDrive\Desktop\Programming Files\Programs\doublylist.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

typedef struct item
{
    int num;
    char name[30];
    float price;
    int stock;
} item;

typedef struct supplier
{
    int num;
    char name[30];
    char address[60];
    char contact[15];
} supplier;

typedef struct sale
{
    int num;
    char dateOfSale[20];
    int itemNum;
    int quantity;
    float subtotal;

} sale;

typedef struct purchase
{
    int num;
    char dateOfPurchase[20];
    int supplierNum;
    int itemNum;
    float unitCost;
    int qtyPurchased;
    int subtotal;
} purchase;
// HELPER FUNCTION
int isValidItemNumber(int num)
{
    item i;
    FILE *fp;
    fp = fopen("ITEM.dat", "rb");
    while (fread(&i, sizeof(item), 1, fp))
    {
        if (i.num == num)
        {
            fclose(fp);
            return -1;
        }
    }
    fclose(fp);

    return 1;
}

int isValidSupplierNumber(int num)
{
    supplier i;
    FILE *fp;
    fp = fopen("SUPPLIER.dat", "rb");
    while (fread(&i, sizeof(supplier), 1, fp))
    {
        if (i.num == num)
        {
            fclose(fp);
            return -1;
        }
    }
    fclose(fp);

    return 1;
}

int isValidSaleTransactionNumber(int num)
{
    sale sl;
    FILE *fp;
    fp = fopen("SALE.dat", "rb");
    while (fread(&sl, sizeof(sale), 1, fp))
    {
        if (sl.num == num)
        {
            fclose(fp);
            return -1;
        }
    }
    fclose(fp);

    return 1;
}

int isValidPurchaseTransactionNumber(int num)
{
    purchase p;
    FILE *fp;
    fp = fopen("PURCHASE.dat", "rb");
    while (fread(&p, sizeof(purchase), 1, fp))
    {
        if (p.num == num)
        {
            fclose(fp);
            return -1;
        }
    }
    fclose(fp);

    return 1;
}

void purchaseTransactionBanner()
{
    system("clear");
    printf("------------------------------------------------------------\n");
    printf("                     ITEMS MAINTENANCE                      \n");
    printf("------------------------------------------------------------\n\n");
}

void itemsBanner()
{
    system("clear");
    printf("------------------------------------------------------------\n");
    printf("                     ITEMS MAINTENANCE                      \n");
    printf("------------------------------------------------------------\n\n");
}

void supplierBanner()
{
    system("clear");
    printf("------------------------------------------------------------\n");
    printf("                    SUPPLIER MAINTENANCE                    \n");
    printf("------------------------------------------------------------\n\n");
}

void salesTransactionBanner()
{
    system("clear");
    printf("------------------------------------------------------------\n");
    printf("                    SALES TRANSACTION                       \n");
    printf("------------------------------------------------------------\n\n");
}
// ITEM MAINTENANCE SECTION START

// ADD ITEM
void addItem()
{
    item i;
    FILE *fp;
    int tempNum;

    fp = fopen("ITEM.dat", "ab");

    itemsBanner();
    printf("Add item\n");
    printf("Enter item number: ");
    scanf("%d", &tempNum);

    if (isValidItemNumber(tempNum) != 1)
    {
        printf("\nInvalid item number. Number already taken!\n");
    }
    else
    {
        i.num = tempNum;
        fflush(stdin);
        printf("Enter item name: ");
        scanf(" %[^\n]s", i.name);

        printf("Enter item price: ");
        scanf("%f", &i.price);

        printf("Enter item stock: ");
        scanf("%d", &i.stock);

        fwrite(&i, sizeof(item), 1, fp);
        printf("Item added successfully!\n");
    }

    fclose(fp);
}

// EDIT ITEM

void editItem()
{
    item i;
    FILE *fp, *tempfp;
    int itemNum, itemExist = 0;
    fp = fopen("ITEM.dat", "r");
    tempfp = fopen("tempITEM.dat", "wb");

    itemsBanner();
    printf("Edit item\n");

    printf("Enter item number to edit: ");
    scanf("%d", &itemNum);

    while (fread(&i, sizeof(item), 1, fp))
    {
        if (i.num == itemNum)
        {
            itemExist = 1;
            fflush(stdin);
            printf("Enter item name: ");
            scanf(" %[^\n]s", i.name);

            printf("Enter item price: ");
            scanf("%f", &i.price);

            printf("Enter item stock: ");
            scanf("%d", &i.stock);

            fwrite(&i, sizeof(item), 1, fp);
        }
        fwrite(&i, sizeof(item), 1, tempfp);
    }
    fclose(fp);
    fclose(tempfp);

    if (itemExist)
    {
        tempfp = fopen("tempITEM.dat", "rb");
        fp = fopen("ITEM.dat", "wb");

        while ((fread(&i, sizeof(item), 1, tempfp)))
        {
            fwrite(&i, sizeof(item), 1, fp);
        }
        fclose(fp);
        fclose(tempfp);
        printf("Item edited successfully!\n");
    }
    else
        printf("\nRecord not found!\n");
}

// DELETE ITEM
void deleteItem()
{
    item i;
    FILE *fp, *tempfp;
    int itemNum, itemExist = 0;
    fp = fopen("ITEM.dat", "r");
    tempfp = fopen("tempITEM.dat", "wb");

    itemsBanner();
    printf("Delete item\n");

    printf("Enter item number to delete: ");
    scanf("%d", &itemNum);

    while (fread(&i, sizeof(item), 1, fp))
    {
        if (i.num == itemNum)
            itemExist = 1;
        else
            fwrite(&i, sizeof(item), 1, tempfp);
    }
    fclose(fp);
    fclose(tempfp);

    if (itemExist)
    {
        tempfp = fopen("tempITEM.dat", "rb");
        fp = fopen("ITEM.dat", "wb");
        while (fread(&i, sizeof(item), 1, tempfp))
        {
            fwrite(&i, sizeof(item), 1, fp);
        }
        fclose(fp);
        fclose(tempfp);
        printf("Item deleted successfully!\n");
    }
    printf("\nRecord not found!\n");
}

// VIEW ALL ITEMS
void viewAllItems()
{

    item i;
    FILE *fp;

    itemsBanner();
    printf("View all items\n");

    fp = fopen("ITEM.dat", "rb");

    printf("\n%-10s%-30s%-10s%13s", "Number", "Name", "Price", "Stock");
    printf("\n------------------------------------------------------------------");

    while (fread(&i, sizeof(item), 1, fp))
    {
        printf("\n%-10d%-30s%-.2f%15d", i.num, i.name, i.price, i.stock);
    }
    fclose(fp);
    printf("\n\n");
}

// SEARCH AND DISPLAY ITEM
void searchItem()
{
    item i;
    FILE *fp;
    char itemName[30];
    int itemExist = 0;

    itemsBanner();
    printf("Search item name\n");

    fp = fopen("ITEM.dat", "rb");
    printf("Enter name of item to search: ");
    scanf("%s", itemName);
    while (fread(&i, sizeof(item), 1, fp))
    {
        if (strcmp(itemName, i.name) == 0)
        {
            itemExist = 1;
            printf("\n%-10s%-30s%-10s%20s", "Number", "Name", "Price", "Stock");
            printf("\n%-10d%-30s%-.2f%20d\n", i.num, i.name, i.price, i.stock);
        }
    }
    if (itemExist == 0)
        printf("\nItem not found!\n");
    fclose(fp);
}

void itemMaintenance()
{

    int ch;

    itemsBanner();
    do
    {
        if (ch == 6)
            break;
        printf("\n1.Add New Item");
        printf("\n2.Edit Existing Item");
        printf("\n3.Delete Existing Item");
        printf("\n4.Search and Display Specific Item");
        printf("\n5.View All Items");
        printf("\n6.Exit Item Maintenance");

        printf("\n\nEnter Your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            addItem();
            break;
        case 2:
            editItem();
            break;
        case 3:
            deleteItem();
            break;
        case 4:
            searchItem();
            break;
        case 5:
            viewAllItems();
            break;
        case 6:
            break;
        default:
            printf("\nYOU ENTERED AN INVALID NUMBER!\n");
        }

    } while (ch != 6);
}
// ITEM MAINTENANCE SECTION END

// SUPPLIER MAINTENANCE SECTION START
void addSupplier()
{
    supplier s;
    FILE *fp;
    int tempNum;

    fp = fopen("SUPPLIER.dat", "ab");

    supplierBanner();
    printf("Add Supplier\n");
    printf("Enter supplier number: ");
    scanf("%d", &tempNum);

    if (isValidSupplierNumber(tempNum) != 1)
    {
        printf("\nInvalid item number. Number already taken!\n");
    }
    else
    {
        s.num = tempNum;
        fflush(stdin);
        printf("Enter supplier name: ");
        scanf(" %[^\n]s", s.name);

        fflush(stdin);
        printf("Enter supplier address: ");
        scanf(" %[^\n]s", s.address);

        fflush(stdin);
        printf("Enter supplier contact: ");
        scanf(" %[^\n]s", s.contact);

        fwrite(&s, sizeof(supplier), 1, fp);
        printf("\n------Supplier added successfully!-----\n");
    }

    fclose(fp);
    getchar();
}

// EDIT SUPPLIER
void editSupplier()
{
    supplier s;
    FILE *fp, *tempfp;
    int supplierNum, supplierExist = 0;
    fp = fopen("SUPPLIER.dat", "r");
    tempfp = fopen("tempSUPPLIER.dat", "wb");

    supplierBanner();
    printf("Edit Supplier\n");

    printf("Enter Supplier number to edit: ");
    scanf("%d", &supplierNum);

    while (fread(&s, sizeof(supplier), 1, fp))
    {
        if (s.num == supplierNum)
        {
            supplierExist = 1;
            fflush(stdin);
            printf("Enter supplier name: ");
            scanf(" %[^\n]s", s.name);

            fflush(stdin);
            printf("Enter supplier address: ");
            scanf(" %[^\n]s", s.address);

            fflush(stdin);
            printf("Enter supplier contact: ");
            scanf(" %[^\n]s", s.contact);

            fwrite(&s, sizeof(supplier), 1, fp);
            printf("\n------Supplier edited successfully!-----\n");
        }
        fwrite(&s, sizeof(supplier), 1, tempfp);
    }
    fclose(fp);
    fclose(tempfp);

    if (supplierExist)
    {
        tempfp = fopen("tempSUPPLIER.dat", "rb");
        fp = fopen("SUPPLIER.dat", "wb");

        while ((fread(&s, sizeof(supplier), 1, tempfp)))
        {
            fwrite(&s, sizeof(supplier), 1, fp);
        }
        fclose(fp);
        fclose(tempfp);
        printf("Supplier edited successfully!\n");
    }
    else
        printf("\nRecord not found!\n");
}

// DELETE SUPPLIER
void deleteSupplier()
{
    supplier s;
    FILE *fp, *tempfp;
    int supplierNum, itemExist = 0;
    fp = fopen("SUPPLIER.dat", "r");
    tempfp = fopen("tempSUPPLIER.dat", "wb");

    supplierBanner();
    printf("Delete supplier\n");

    printf("Enter supplier number to delete: ");
    scanf("%d", &supplierNum);

    while (fread(&s, sizeof(supplier), 1, fp))
    {
        if (s.num == supplierNum)
        {
            puts("found!\n");
            itemExist = 1;
        }
        else
            fwrite(&s, sizeof(supplier), 1, tempfp);
    }
    fclose(fp);
    fclose(tempfp);

    if (itemExist)
    {
        tempfp = fopen("tempSUPPLIER.dat", "rb");
        fp = fopen("SUPPLIER.dat", "wb");

        while (fread(&s, sizeof(supplier), 1, tempfp))
        {
            fwrite(&s, sizeof(supplier), 1, fp);
        }
        fclose(fp);
        fclose(tempfp);
        printf("Supplier deleted successfully!\n");
    }
    else
        printf("\nRecord not found!\n");
}

// SEARCH SUPPLIER
void searchSupplier()
{
    supplier s;
    FILE *fp;
    char supplierName[30];
    int itemExist = 0;

    supplierBanner();
    printf("Search supplier name\n");

    fp = fopen("SUPPLIER.dat", "rb");
    printf("Enter name of item to search: ");
    scanf("%s", supplierName);
    while (fread(&s, sizeof(supplier), 1, fp))
    {
        if (strcmp(supplierName, s.name) == 0)
        {
            itemExist = 1;

            printf("\n%-10s%-30s%-20s%13s", "Number", "Name", "Address", "Contact");
            printf("\n-------------------------------------------------------------------------");
            printf("\n%-10d%-30s%-20s%15s", s.num, s.name, s.address, s.contact);
            puts("\n");
        }
    }
    if (itemExist == 0)
        printf("\nItem not found!\n");
    fclose(fp);
}

// VIEW SUPPLIER
void viewAllSuppliers()
{
    supplier s;
    FILE *fp;

    supplierBanner();
    printf("View all Supplier\n");

    fp = fopen("SUPPLIER.dat", "rb");

    printf("\n%-10s%-30s%-20s%13s", "Number", "Name", "Address", "Contact");
    printf("\n----------------------------------------------------------------------------");

    while (fread(&s, sizeof(supplier), 1, fp))
    {
        printf("\n%-10d%-30s%-20s%15s", s.num, s.name, s.address, s.contact);
    }
    fclose(fp);
    printf("\n\n");
}

void supplierMaintenance()
{

    int ch;
    supplierBanner();
    do
    {

        printf("\n1.Add New Supplier");
        printf("\n2.Edit Existing Supplier");
        printf("\n3.Delete Existing Supplier");
        printf("\n4.Search and Display Specific Item");
        printf("\n5.View All Suppliers");
        printf("\n6.Exit Supplier Maintenance");

        printf("\n\nEnter Your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            addSupplier();
            break;
        case 2:
            editSupplier();
            break;
        case 3:
            deleteSupplier();
            break;
        case 4:
            searchSupplier();
            break;
        case 5:
            viewAllSuppliers();
            break;
        case 6:
            break;
        default:
            printf("\nYOU ENTERD AN INVALID NUMBER!\n");
        }

    } while (ch != 6);
}
// SALE TRANSACTION

float searchItemNum(int num)
{
    item i;
    FILE *fp;

    fp = fopen("ITEM.dat", "rb");

    while (fread(&i, sizeof(item), 1, fp))
    {
        if (num == i.num)
        {

            return i.price;
        }
    }
    fclose(fp);
    return -1;
}

void addSales()
{
    sale sl;
    item i;

    FILE *fpSale, *fpItem;
    int tempNum, itemNum;
    float itemPrice;
    fpSale = fopen("SALE.dat", "ab");
    fpItem = fopen("ITEM.dat", "r+b");

    salesTransactionBanner();
    printf("Add Sale Transaction\n\n");

    printf("Enter item number to search: ");
    scanf("%d", &itemNum);

    itemPrice = searchItemNum(itemNum);
    if (itemPrice != -1)
    {
        printf("Enter sale transaction number: ");
        scanf("%d", &tempNum);

        if (isValidSaleTransactionNumber(tempNum) != 1)
        {
            printf("\nInvalid item number. Number already taken!\n");
        }
        else
        {
            sl.num = tempNum;
            fflush(stdin);
            printf("Enter date of sale(mm-dd-yyyy): ");
            scanf(" %[^\n]s", sl.dateOfSale);

            int qty;
            printf("Enter quantity: ");
            scanf("%d", &qty);

            sl.quantity = qty;
            sl.subtotal = itemPrice * (float)qty;
            sl.itemNum = itemNum;
            printf("\n%f\n", itemPrice * qty);
            printf("\n%f\n", sl.subtotal);

            fwrite(&sl, sizeof(sale), 1, fpSale);
            printf("\n%f\n", sl.subtotal);

            /////////////////
            FILE *tempfp;
            tempfp = fopen("tempITEM.dat", "wb");

            int itemExist = 0;

            while (fread(&i, sizeof(item), 1, fpItem))
            {

                if (i.num == itemNum)
                {
                    itemExist = 1;
                    i.stock = i.stock - qty;
                    printf("\n%d\n", i.stock);
                    fwrite(&i, sizeof(item), 1, fpItem);
                }
                fwrite(&i, sizeof(item), 1, tempfp);
            }
            fclose(tempfp);
            fclose(fpItem);
            if (itemExist)
            {
                tempfp = fopen("tempITEM.dat", "rb");
                fpItem = fopen("ITEM.dat", "wb");

                while ((fread(&i, sizeof(item), 1, tempfp)))
                {
                    fwrite(&i, sizeof(item), 1, fpItem);
                }
                fclose(fpItem);
                fclose(tempfp);
                printf("Item stock edited successfully!\n");
            }
            ////////////////////
            printf("Sale Transaction added successfully!\n");
            // fclose(fpItem);

            // fclose(tempfp);
        }
    }
    else
    {
        printf("\nITEM DOES NOT EXIST\n");

        fclose(fpItem);
    }
    fclose(fpSale);
}

void viewAllSales()
{
    sale sl;
    FILE *fp;

    salesTransactionBanner();
    printf("View all Sales Transaction\n");

    fp = fopen("SALE.dat", "rb");

    printf("\n%-10s%-20s%-20s%-10s%-10s", "Number", "Date of Sale", "Item Number", "Quantity", "Subtotal");
    printf("\n---------------------------------------------------------------------");

    while (fread(&sl, sizeof(sale), 1, fp))
    {
        printf("\n%-10d%-20s%-20d%-10d%-10.2f", sl.num, sl.dateOfSale, sl.itemNum, sl.quantity, sl.subtotal);
    }
    printf("\n---------------------------------------------------------------------");

    fclose(fp);
    printf("\n\n");
}

void salesTransaction()
{
    int ch;
    salesTransactionBanner();
    do
    {
        if (ch == 3)
            break;
        printf("\n1.Add New Sales");
        printf("\n2.View All Sales");
        printf("\n3.Exit Sales Transactions");

        printf("\n\nEnter Your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            addSales();
            break;
        case 2:
            viewAllSales();
            break;
        case 3:
            break;
        default:
            printf("\nYOU ENTERD AN INVALID NUMBER!\n");
        }

    } while (ch != 6);
}
// SALE TRANSACTION

// PURCHASE TRANSACTION

void addPurchase()
{
    purchase p;
    FILE *fp;
    int tempNum;

    fp = fopen("PURCHASE.dat", "r+b");

    purchaseTransactionBanner();
    printf("Add Purchase Transaction\n");
    printf("Enter Purchase Transaction number: ");
    scanf("%d", &tempNum);

    if (isValidPurchaseTransactionNumber(tempNum) != 1)
    {
        printf("\nInvalid item number. Number already taken!\n");
    }
    else
    {
        p.num = tempNum;
        fflush(stdin);
        printf("Enter date of sale(mm-dd-yyyy): ");
        scanf(" %[^\n]s", p.dateOfPurchase);

        printf("Enter item number :");
        scanf("%d", &p.itemNum);

        printf("Enter Supplier Number: ");
        scanf("%d", &p.supplierNum);

        fwrite(&p, sizeof(sale), 1, fp);
        printf("Sale Transaction added successfully!\n");
    }
    fclose(fp);
}
void viewAllPurchase()
{
    purchase p;
    FILE *fp;

    printf("View all items\n");
    fp = fopen("PURCHASE.dat", "rb");
    printf("\n%-10s%-30s%-10s%-16s", "Number", "Date of Purchase", "Item Number", "Supplier Number");
    printf("\n------------------------------------------------------------------");
    while (fread(&p, sizeof(item), 1, fp))
    {
        printf("\n%-10d%-30s%-10d%-16d", p.num, p.dateOfPurchase, p.itemNum, p.supplierNum);
    }

    fclose(fp);
    printf("\n\n");

}

void purchaseTransaction()
{
    int ch;
    salesTransactionBanner();
    do
    {

        printf("\n1.Add New Purchase");
        printf("\n2.View All Purchases");
        printf("\n3.Exit Purchase Transactions");

        printf("\n\nEnter Your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            addPurchase();
            break;
        case 2:
            viewAllPurchase();
            break;
        case 3:
            break;
        default:
            printf("\nYOU ENTERD AN INVALID NUMBER!\n");
        }

    } while (ch != 3);
}
// PURCHASE TRANSACTION END
int main()
{
    int ch;

    do
    {
        system("clear");

        printf("\n\n-------------------   GROCERY STORE MANAGEMENT   -------------------\n");
        printf("\n1.Item Maintenance");
        printf("\n2.Supplier Maintenance");
        printf("\n3.Sales Transaction");
        printf("\n4.Purchase Transaction");
        printf("\n5.Exit\n");

        printf("\nEnter Your choice: ");
        scanf("%d", &ch);
        fflush(stdin);

        switch (ch)
        {
        case 1:
            itemMaintenance();
            break;
        case 2:
            supplierMaintenance();
            break;
        case 3:
            salesTransaction();
            break;
        case 4:
            purchaseTransaction();
            break;
        case 5:
            continue;
        default:
            printf("\nYOU ENTERD AN INVALID NUMBER!\n");
        }

    } while (ch != 5);

    puts("\nGoodbye!\n\n");
}
