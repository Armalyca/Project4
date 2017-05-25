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

void read_menu_librarian()
{
  int ans;
  system("cls");
  printf("Librarian read menu:\n\n");
  printf("\t1. View the list of members\n\t2. Display the list of books (by code, title or author)\n\t3. Search for information about specific book\n\t4. List of books to return\n\t5. Exit\n");
  scanf("%d", &ans);

  switch(ans)
  {
    case 1:
      members_ordered_alpha(); //fct which display list of the members ordered alphabetically
      break;
    case 2:
      read_menu_librarian2(); //renvoie à un deuxième menu pour demander à l'utilisateur quel critère il choisit pour trier les livres
      break;
    case 3:
      read_menu_librarian3(); //renvoie également à un second menu pour chercher UN livre suivant plusieurs critères dispo
      break;
    case 4:
      books_to_return(); //fct which display all the books that must be returned
      break;
    case 5:
      quit(); //fct to exit the menu
      break;
    default:
      printf("Warning: Enter a number between 1 and 5");
      break;
  }
}

void read_menu_librarian2()
{
  int ans;
  system("cls");
  printf("Filter by:\n\t1. Code\n\t2. Title\n\t3. Author\n\t4. Previous menu\n");
  scanf("%d", &ans);

  switch(ans)
  {
    case 1:
      disp_books_ByCode(); //fct that display list of books by their code
      break;
    case 2:
      disp_books_ByTitle(); //fct that display list of books by their title
      break;
    case 3:
      disp_books_ByAuthor(); //fct that display list of books by their author
      break;
    case 4:
      read_menu_librarian(); //going back to first menu
      break;
    default:
      printf("Warning: Enter a value between 1 and 4");
      break;
  }
}

void read_menu_librarian3()
{
  int ans;
  system("cls");
  printf("Filter by:\n\t1. Code\n\t2. Title\n\t3. Author\n\t4. Previous menu\n");
  scanf("%d", &ans);

  switch(ans)
  {
    case 1:
      search_book_ByCode(); // fct to search for a specific book using its code
      break;
    case 2:
      search_book_ByTitle() // fct to search for a specific book using its title
      break;
    case 3:
      search_book_ByAuthor() // fct to search for a specific book using its author
      break;
    case 4:
      read_menu_librarian(); //going back to first menu
      break;
    default:
      printf("Warning: Enter a value between 1 and 4");
      break;
  }
}

void interact_menu_librarian()
{
  int ans;
  system("cls");
  printf("Librarian interactive menu:\n\n");
  printf("\t1. Display current date\n\t2. Change current date\n\t3. Add member\n\t4. Delete member\n\t5. Delete book\n\t6. New book loan\n\t7. Quit\n");
  scanf("%d", &ans);

  switch(ans)
  {
    case 1:
      diplay_current_date(Cdate); //fct that display the current date (déja faite)
      break;
    case 2:
      change_current_Date(Cdate); // fct to change the current date(déja faite)
      break;
    case 3:
      AddMember(Mb, i); // fct to add a new member (à refaire/faire correspondre avec le reste)
      break;
    case 4:
      delete_member(); // fct to delete a member
      break;
    case 5:
      delete_book(); //fct to delete a book
      break;
    case 6:
      new_loan(); //fct to to add a new loan to a member (Warning: the user has to be a member else, has to register)
      break;
    case 7:
      quit();
      break;
    default:
      printf("Warning: Enter a value between 1 and 7");
      break;
  }
}

void quit()
{
  int ans = 0;
  printf("Are you sure you want to exit this program ? Yes -> 1, No -> 0");
  scanf("%d", &ans);
  if(ans)
    exit(0);
}
