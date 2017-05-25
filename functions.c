#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"
#include "main.c"

void allocateMbStruct(Member* Mb)
{
  int i = 0;
  Mb->firstName = (char*) malloc (20 * sizeof(char));
  Mb->lastName = (char*) malloc (20 * sizeof(char));
  Mb->mailingAdress = (char*) malloc (40 * sizeof(char));
  Mb->eMailAdress = (char*) malloc (40 * sizeof(char));
  Mb->borrowedBooks = (char**) malloc (3 * sizeof(char*));
  for(i = 0; i < 3; i++)
    Mb->borrowedBooks[i] = (char*) malloc (char);
  Mb->dateOfBorrow = (Date*) malloc (3 * sizeof(Date));
  //Ne pas oublier de free les structures à la fin !
}

void allocateBookStruct(Book* Bk)
{
  Bk->title = (char*) malloc (30 * sizeof(char));
  Bk->author = (char*) malloc (20 * sizeof(char));
  Bk->bookCode = (char*) malloc (8 * sizeof(char));
}

void AddMember(Member** Mb, int i)
{
  /*int i, cpt = 0, answer = 0*/;
  printf("\nFirst Name: ");
  fgets(Mb[i]->firstName, 19, stdin);
  fflush(stdin);
  printf("\nLast Name: ");
  fgets(Mb[i]->lastName, 19, stdin);
  fflush(stdin);
  printf("\nAdresse (ex: 12 chemin des pres): ");
  fgets(Mb[i]->mailingAdress, 39, stdin);
  fflush(stdin);
  printf("\nE-mail adress : ");
  fgets(Mb[i]->eMailAdress, 39, stdin);
  fflush(stdin);
  /*for(i = 0; i < 3; i++)
  {
    if(Mb->borrowedBooks[i] == NULL)
      cpt++;
  }
  printf("Warning: You have borrowed %d books\n", 3-cpt);
  if(!cpt)
  {
      printf("You can't borrow a new book, please restitute at least one book :\n");
      for(i = 0; i < 3; i++)
      {
        printf("%s", Mb->borrowedBooks[i]);
        printf("\n");
      }
  }
  else if(cpt < 3 && cpt != 0)
  {
    printf("List of your books: \n");
    for(i = 0; i < cpt; i++)
    {
      printf("%s", Mb->borrowedBooks[i]);
      printf("\n");
    }
    printf("\nDo you want to add a book reference ? Yes = 1, No = 0");
    scanf("%d", &answer);
    if(answer)
    {
      printf("\nEnter code(s) (ex: NOV-010): ");
      for(i = cpt; i < 3; i++)
      {
        gets(Mb->borrowedBooks[i], 7, stdin);
        fflush(stdin);
      }
    }
  }
  else if(cpt == 3)
  {
  printf("Enter codes (ex: NOV-010): ");
    for(i = 0; i < 3; i++)
    {
      gets(Mb->borrowedBooks[i], 7, stdin);
      fflush(stdin);
    }
  }*/
}

void diplay_current_date(Date* Cdate)
{
  printf("Today Date : ");
  printf("%d / %d / %d", Cdate->month, Cdate->day, Cdate->Year);
}

void change_current_Date(Date* Cdate)
{
  printf("New Date:\n");
  scanf("%d %d %d", Cdate->month, Cdate->day, Cdate->Year);
}

void menu_librarian()
{
  printf("Librarian read menu:\n\n");
  printf("\t1. ")

}
