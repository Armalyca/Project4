#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Date {
int day;
int month;
int year
};

struct BorrowBook {
 char BookCode[7];
struct Date date;
};

struct Member {
 char FirstName[50];
 char LastName[50];
 char address[50];
 char email[50];
 char profession[20];
 struct BorrowBook one;
 struct BorrowBook two;
 struct BorrowBook three;
};

struct Book {
 char title[25];
 char author[20];
 char BookCode[7];
 int NbCopies;
 int AvaiCopies;
};
#include "functions.h"


int main(int argc, char** argv)
{
  int ans, choice = 0;
 while (choice == 0)
 {
  system("cls");
  printf("\t1. Access a read only access service menu\n\t2. Access an interactive menu\n\t3. Exit the program\n");
  scanf("%d", &ans);

  switch(ans)
  {
    case 1:
      read_menu_librarian() //fct which display the read only menu
      break;
    case 2:
      interact_menu_librarian(); //fct which display the interactive menu
      break;
   case 3:
      choice = 1;
      quit(); //exit the program
      break;
    default:
      printf("Warning: Enter 1 or 2");
      break;
  }
 }
 return 0;
}
