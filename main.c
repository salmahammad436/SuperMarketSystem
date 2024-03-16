//NOTE:User admin = {"salma", "14034"};

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>


#define DEFAULT_COLOR 11
#define HIGHLIGHT_COLOR 3



void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void setTextColor(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}





typedef  struct  User User;
typedef struct product product;
typedef struct category category;
typedef struct SuperMarket SuperMarket;



struct User{

char userName[50];
char userPass[50];
};



struct product
{
  char productName[25];
  float  productPrice;
  int quantity;
};


  struct category
  {
  char CatName[20];
  product products[20];
  int ProductCounter;
  };


  struct SuperMarket
  {
  category categories[25];
  int CatCounter;
  };


//Establitining
 void EstablishSuperMarket(SuperMarket *carrfour)
  {
       carrfour->CatCounter = 3;
       for (int i = 0; i < carrfour->CatCounter; i++)
    {
       carrfour->categories[i].ProductCounter=3;
    }
       strcpy(carrfour->categories[1].CatName, "grocery");
       strcpy(carrfour->categories[2].CatName, "Milk&cheese");



      //'GROCERY CATEGORY'
      strcpy(carrfour->categories[1].products[0].productName,"Apple");
      carrfour->categories[1].products[0].productPrice=50;
      carrfour->categories[1].products[0].quantity=20;

      strcpy(carrfour->categories[1].products[1].productName,"Orange");
      carrfour->categories[1].products[1].productPrice=20;
      carrfour->categories[1].products[1].quantity=15;

      strcpy(carrfour->categories[1].products[2].productName,"Tomato");
      carrfour->categories[1].products[2].productPrice=10;
      carrfour->categories[1].products[2].quantity=30;


      //'MILK&CHEESE CATEGORY'
      strcpy(carrfour->categories[2].products[0].productName,"Goda cheese");
      carrfour->categories[2].products[0].productPrice=400;
      carrfour->categories[2].products[0].quantity=10;

      strcpy(carrfour->categories[2].products[1].productName,"Zapado");
      carrfour->categories[2].products[1].productPrice=20;
      carrfour->categories[2].products[1].quantity=30;

      strcpy(carrfour->categories[2].products[2].productName,"cottage");
      carrfour->categories[2].products[2].productPrice=60;
      carrfour->categories[2].products[2].quantity=15;

    }




//displayyy

void DisplaySuperMarket(SuperMarket *carrfour)
{

        printf("\n***********************************************WELCOME TO CARRFOUR*****************************************************\n");
    for (int i = 1;i< carrfour->CatCounter; i++)
    {

        setTextColor(DEFAULT_COLOR);
        printf("\n--------------------------------------------------(  %s Category  )--------------------------------------------\n", carrfour->categories[i].CatName);
        for (int k = 0; k < carrfour->categories[i].ProductCounter; k++)
        {

            setTextColor(HIGHLIGHT_COLOR);
            printf("\n Product Name :( %s )\t product Price : %.2f LE\tquantity :%d\n", carrfour->categories[i].products[k].productName, carrfour->categories[i].products[k].productPrice,
                    carrfour->categories[i].products[k].quantity);

        }
    }
}



//addCategory

void Addcategory(SuperMarket* carrfour) {

    char c;
    do {
        char categoryname[25];

        setTextColor(14);
        printf("\n\nIf you want to add a new category, please enter a category name: ");

        setTextColor(DEFAULT_COLOR);
        scanf("%s", categoryname);

        int getcategoryindex = -1;

        for (int i = 0; i < carrfour->CatCounter; i++) {
            if (strcmp(carrfour->categories[i].CatName, categoryname) == 0) {
                getcategoryindex = i;
                setTextColor(12);
                printf("\nYou have added an existing category.\n");
                break;
            }
        }

        if (getcategoryindex == -1) {
            strcpy(carrfour->categories[carrfour->CatCounter].CatName, categoryname);
            carrfour->categories[carrfour->CatCounter].ProductCounter = 0;
            setTextColor(10);
            printf("\nYou have added a new category successfully!\n");
            carrfour->CatCounter++;
        }

        setTextColor(14);
        printf("Do you want to add another category (Y/N)? ");
        setTextColor(DEFAULT_COLOR);
        c = getch();
    } while (c == 'y' || c == 'Y');
}








//creatProducttt

void CreateProduct(SuperMarket* carrfour) {
    char c;

    do {
        char catname[20];
        char productname[20];
        float proprice;
        int quantity;
        int getcatindex = -1;
        int productExist = 0;

        getchar();
        setTextColor(14);
        printf("\n Which category to want to add to? ");

        setTextColor(11);
        fgets(catname, sizeof(catname), stdin);
        catname[strcspn(catname, "\n")] = '\0';






        for (int i = 0; i < carrfour->CatCounter; i++) {
            if (strcmp(carrfour->categories[i].CatName, catname) == 0) {
                getcatindex = i;
                break;
            }
        }

        if (getcatindex != -1) {
            setTextColor(14);
            printf("\nPlease add a product name: ");
            setTextColor(11);
            fgets(productname, sizeof(productname), stdin);
            productname[strcspn(productname, "\n")] = '\0';


            for (int j = 0; j < carrfour->categories[getcatindex].ProductCounter; j++) {
                if (strcmp(carrfour->categories[getcatindex].products[j].productName, productname) == 0) {
                    productExist = 1;
                    break;
                }
            }
          if (!productExist) {
                setTextColor(14);
                printf("\nAdd the price of this product: ");
                setTextColor(11);


                while (scanf("%f", &proprice) != 1 || proprice <= 0) {
                    setTextColor(12);
                    printf("Please enter a valid  price: ");
                    setTextColor(11);
                    getchar();
                }

                setTextColor(14);
                printf("\nPlease enter the quantity you want: ");
                setTextColor(11);


                while (scanf("%d", &quantity) != 1 || quantity <= 0) {
                    setTextColor(12);
                    printf(" Please enter a valid value: ");
                    setTextColor(11);
                    getchar();
                }







                if (carrfour->categories[getcatindex].ProductCounter < 25) {
                    strcpy(carrfour->categories[getcatindex].products[carrfour->categories[getcatindex].ProductCounter].productName, productname);
                    carrfour->categories[getcatindex].products[carrfour->categories[getcatindex].ProductCounter].productPrice = proprice;
                    carrfour->categories[getcatindex].products[carrfour->categories[getcatindex].ProductCounter].quantity = quantity;
                    carrfour->categories[getcatindex].ProductCounter++;
                    setTextColor(10);
                    printf("\nProduct added successfully!\n");
                } else {
                    setTextColor(12);
                    printf("\nCant add more products to this category.\n");
                }
            } else {
                setTextColor(12);
                printf("\nProduct already exists!\n");
            }
        } else {
            setTextColor(12);
            printf("\nSorry, there is no category with this name!\n");
        }

        setTextColor(14);
        printf("Do you want to add another product (Y/N)? ");
        setTextColor(DEFAULT_COLOR);
        scanf(" %c", &c);
    } while (c == 'y' || c == 'Y');
}






//Removecategory

void RemoveCategory(SuperMarket* carrfour) {
    char c;
    do {
        char Catname[20];
        int getcatindex = -1;

        if (carrfour->CatCounter > 0) {
            setTextColor(14);
            printf("\nAdd a category name to remove: ");
            setTextColor(11);
            scanf("%s", Catname);

            for (int i = 0; i < carrfour->CatCounter; i++) {
                if (strcmp(carrfour->categories[i].CatName, Catname) == 0) {
                    getcatindex = i;
                    break;
                }
            }

            if (getcatindex != -1) {
                for (int i = getcatindex; i < carrfour->CatCounter - 1; i++) {
                    carrfour->categories[i] = carrfour->categories[i + 1];
                }
                carrfour->CatCounter--;
                setTextColor(10);
                printf("\n The Category removed successfully! \n");
            } else {
                setTextColor(12);
                printf("\nSoorry,This Category not found\n");
            }
        } else {
            setTextColor(12);
            printf("\nSorry, carrfour is empty!\n");
            break;
        }

        setTextColor(14);
        printf("Do you want to remove another category (Y/N)? ");
        c = getch();
    } while (c == 'y' || c == 'Y');
}




//removeproduct

void RemoveProduct(SuperMarket* carrfour) {
    char catname[25];
    char productname[20];
    int catIndex = -1;
    char c;

    do {
        if (carrfour->CatCounter == 0) {
            setTextColor(12);
            printf("Sorry, there are no categories available!\n");
            return;
        }

        setTextColor(14);
        printf("\nWhich category do you want to remove a product from? ");
        setTextColor(DEFAULT_COLOR);
        scanf("%s", catname);

        for (int i = 0; i < carrfour->CatCounter; i++) {
            if (strcmp(carrfour->categories[i].CatName, catname) == 0) {
                catIndex = i;
                break;
            }
        }

        if (catIndex == -1) {
            setTextColor(12);
            printf("Sorry, there is no category with this name!\n");
            return;
        }

        do {
            setTextColor(14);
            printf("Enter the product name to remove: ");
            setTextColor(DEFAULT_COLOR);
            scanf("%s", productname);

            int productIndex = -1;
            for (int i = 0; i < carrfour->categories[catIndex].ProductCounter; i++) {
                if (strcmp(carrfour->categories[catIndex].products[i].productName, productname) == 0) {
                    productIndex = i;
                    break;
                }
            }

            if (productIndex == -1) {
                setTextColor(12);
                printf("Sorry, this product Not found!\n");
            } else {
                // Removingg
                for (int i = productIndex; i < carrfour->categories[catIndex].ProductCounter - 1; i++) {
                    carrfour->categories[catIndex].products[i] = carrfour->categories[catIndex].products[i + 1];
                }
                carrfour->categories[catIndex].ProductCounter--;

                setTextColor(10);
                printf("The product was removed successfully!\n");
            }

            setTextColor(14);
            printf("Do you want to remove another product in this category (Y/N)? ");
            c = getch();
        } while (c == 'y' || c == 'Y');

        setTextColor(14);
        printf("Do you want to remove a product from another category (Y/N)? ");
        c = getch();
    } while (c == 'y' || c == 'Y');
}






//MoveProduct

void MoveProduct(SuperMarket* carrfour) {

    char movee;

    do {

    char proname[25];
    char sourceCatName[25];
    char distCatName[25];
    int sourceCatIndex = -1;
    int proIndex = -1;
    int destCatIndex = -1;
    int destProIndex = -1;
        if (carrfour->CatCounter > 1) {
            setTextColor(14);
            printf("Please enter the source category name: ");
            setTextColor(DEFAULT_COLOR);
            fgets(sourceCatName, sizeof(sourceCatName), stdin);
            sourceCatName[strcspn(sourceCatName, "\n")] = '\0';

            for (int i = 0; i < carrfour->CatCounter; i++) {
                if (strcmp(carrfour->categories[i].CatName, sourceCatName) == 0) {
                    sourceCatIndex = i;
                    break;
                }
            }

            if (sourceCatIndex == -1) {
                setTextColor(12);
                printf("Error: this category is not found\n");
                return;
            }

            if (carrfour->categories[sourceCatIndex].ProductCounter == 0) {
                setTextColor(12);
                printf("Error: There are no products in this category\n");
                return;
            }
            setTextColor(14);
            printf("Please enter the product name you want to move: ");
            setTextColor(DEFAULT_COLOR);
            fgets(proname, sizeof(proname), stdin);
            proname[strcspn(proname, "\n")] = '\0';

    for (int i = 0; i < carrfour->categories[sourceCatIndex].ProductCounter; i++) {
       if (strcmp(carrfour->categories[sourceCatIndex].products[i].productName, proname) == 0)
        {
         proIndex = i;
         break;
        }
}


            if (proIndex == -1) {
                setTextColor(12);
                printf("Error: Product not found\n");
                return;
            }

            setTextColor(14);
            printf("Please enter the destination category name: ");

            setTextColor(DEFAULT_COLOR);
            fgets(distCatName, sizeof(distCatName), stdin);
            distCatName[strcspn(distCatName, "\n")] = '\0';


            for (int i = 0; i < carrfour->CatCounter; i++) {
                if (strcmp(carrfour->categories[i].CatName, distCatName) == 0) {
                    destCatIndex = i;
                    break;
                }
            }

            if (destCatIndex == -1) {
                setTextColor(12);
                printf("Error: Destination category not found\n");
                return;
            }

           for (int i = 0; i <= carrfour->categories[destCatIndex].ProductCounter; i++) {
        if (strcmp(carrfour->categories[destCatIndex].products[i].productName, proname) == 0) {
            destProIndex = i;
            break;
        }
    }

    if (destProIndex != -1) {
        setTextColor(12);
        printf("Error: The product already exists in this category\n");
        return;
    }

    carrfour->categories[destCatIndex].products[carrfour->categories[destCatIndex].ProductCounter] = carrfour->categories[sourceCatIndex].products[proIndex];
    carrfour->categories[destCatIndex].ProductCounter++;

            for (int i = proIndex; i < carrfour->categories[sourceCatIndex].ProductCounter - 1; i++) {
                carrfour->categories[sourceCatIndex].products[i] = carrfour->categories[sourceCatIndex].products[i + 1];
            }

            carrfour->categories[sourceCatIndex].ProductCounter--;

            setTextColor(10);
            printf("You moved the product successfully!\n");

            setTextColor(14);
            printf("Do you want to move another product (Y/N)? ");
            setTextColor(DEFAULT_COLOR);
            scanf(" %c", &movee);

        } else {
            setTextColor(12);
            printf("Error: There are not enough categories to move products.\n");
            return;
        }

    } while (movee == 'Y' || movee == 'y');
}








//sellproduct

void sellproduct(SuperMarket* carrfour) {
    char movee;
    char catName[25];
    char proName[25];
    int quantity;
    float TotPrice = 0.00;
    int catIndex = -1;
    int proIndex = -1;

    do {
        setTextColor(14);
        printf("\nPlease Enter the category you want to sell from: ");
        setTextColor(11);
        fgets(catName, sizeof(catName), stdin);
        catName[strcspn(catName, "\n")] = '\0';

        for (int i = 0; i < carrfour->CatCounter; i++)
         {
            if (strcmp(carrfour->categories[i].CatName, catName) == 0)
                {
                catIndex = i;
                break;
                }
         }

        if (catIndex != -1) {
            setTextColor(14);
            printf("\nPlease Enter a product to sell: ");
            setTextColor(11);
            fgets(proName, sizeof(proName), stdin);
            proName[strcspn(proName, "\n")] = '\0';

            for (int i = 0; i < carrfour->categories[catIndex].ProductCounter; i++) {
                if (strcmp(carrfour->categories[catIndex].products[i].productName, proName) == 0) {
                    proIndex = i;
                    break;
                }
            }

            if (proIndex != -1) {
                setTextColor(14);
                printf("\nPlease Enter the quantity you want: ");
                do {
                    setTextColor(11);
                    if (scanf("%d", &quantity) == 1 && quantity > 0 && quantity <= carrfour->categories[catIndex].products[proIndex].quantity) {
                        break;
                    } else {
                        setTextColor(12);
                        printf("\nEnter a valid value between 1 and %d: ", carrfour->categories[catIndex].products[proIndex].quantity);
                    }
                } while (getchar() != '\n');

                carrfour->categories[catIndex].products[proIndex].quantity -= quantity;
                setTextColor(10);
                printf("\nThe sale has been completed successfully!");
                setTextColor(DEFAULT_COLOR);
                printf("\n\n you sold %d of %s and the Total price is %.2f", quantity, proName, quantity * carrfour->categories[catIndex].products[proIndex].productPrice);
                TotPrice += quantity * carrfour->categories[catIndex].products[proIndex].productPrice;
            } else {
                setTextColor(12);
                printf("\nError: Product not found");
            }
        } else {
            setTextColor(12);
            printf("\nError: Category not found");
        }
        setTextColor(14);
        printf("\nDo you want to make another sale (Y/N)? ");
        setTextColor(11);
        scanf(" %c", &movee);
        getchar();
    } while (movee == 'Y' || movee == 'y');
    setTextColor(10);
    printf("\n\nTotal price from sales: %.2f\n", TotPrice);
}





//displaymenuu


void DisplayMenu(char Menu[][20], int menusize, int col, int row, int current_item)
{
    system("cls");

    for (int i = 0; i < menusize; i++)
    {
        gotoxy(col, row + i);
        if (current_item == i)
        {
            setTextColor(14);
        }
        else
        {
            setTextColor(11);
        }
        printf("%s", Menu[i]);
        setTextColor(1);
    }
}



int loginUser(User*  admin) {
    char getUserName[50];
    char getPassword[50];
    setTextColor(15);
    printf("\nEnter  your username: ");
    setTextColor(8);
    scanf("%s", getUserName);
    setTextColor(15);
    printf("Enter  your password: ");
    setTextColor(8);
    scanf("%s", getPassword);

     if (strcmp(admin->userName,getUserName) == 0 && strcmp(admin->userPass,getPassword) == 0) {
        return 1;
    } else {
        return 0;
    }
}







int main()
{



    User admin = {"salma", "14034"};
    SuperMarket carrfour;
    int col = 50, row = 1;
    int current_item =0;
    gotoxy(col,row);
    setTextColor(11);
    printf("***");
    setTextColor(14);
    printf("Welcome to Carrfour");
    setTextColor(11);
    printf("***");
    setTextColor(11);
    printf("\n\nPlease login to Access the menu....\n");

if (loginUser(&admin)){

    char Menu[8][30] = {
        ">> View SuperMarket\n",
        ">> Add Category\n",
        ">> Create Product\n",
        ">> Remove Category\n",
        ">> Remove Product\n",
        ">> Move Product\n",
        ">> Sell Product\n",
        ">> Exit\n"
    };

    char c;
    EstablishSuperMarket(&carrfour);

    do
    {

        system("cls");
        for (int i = 0; i < 8; i++)
        {
            gotoxy(col, row + i);
            if (current_item == i)
            {
                setTextColor(14);
            }
            else
            {
                setTextColor(11);
            }
            printf("%s", Menu[i]);
            setTextColor(1);
        }

        c = getch();
        system("cls");
        switch (c)
        {
        case 72:
            if (current_item > 0)
                current_item--;
            else
                current_item = 7;
            break;
        case 80:
            if (current_item < 7)
                current_item++;
            else
                current_item = 0;
            break;
        case 13:

            switch (current_item)
            {
            case 0:
                printf(">> All\n");
                DisplaySuperMarket(&carrfour);
                break;
            case 1:
                printf(">> Add category\n");
                Addcategory(&carrfour);
                break;
            case 2:

                printf(">> Add product\n");
                CreateProduct(&carrfour);
                break;
            case 3:

                printf(" Remove Category\n");
                RemoveCategory(&carrfour);
                break;
            case 4:

                printf(">> Remove product\n");
                RemoveProduct(&carrfour);
                break;
            case 5:


                printf(">> Move Product\n");
                MoveProduct(&carrfour);
                break;
            case 6:


                printf(">> Invoice Product\n");
                sellproduct(&carrfour);
                break;
            case 7:
                printf("Exit\n");
                c = 27;
                break;
            }
            getch();
            break;
        }
    } while (c != 27);
    }else {
        setTextColor(12);
        printf("failed,please try again\n");
    }

    return 0;
    }
