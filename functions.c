#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"
#include "main.c"


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
      AlphaOrder(); //fct which display list of the members ordered alphabetically
      break;
    case 2:
      read_menu_librarian2(); //renvoie à un deuxième menu pour demander à l'utilisateur quel critère il choisit pour trier les livres
      break;
    case 3:
      read_menu_librarian3(); //renvoie également à un second menu pour chercher UN livre suivant plusieurs critères dispo
      break;
    case 4:
      LateBooks(); //fct which display all the books that must be returned
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
      search_book_ByTitle(); // fct to search for a specific book using its title
      break;
    case 3:
      search_book_ByAuthor(); // fct to search for a specific book using its author
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
  int ans, pb = 0;
  system("cls");
  printf("Librarian interactive menu:\n\n");
  printf("\t1. Display current date\n\t2. Change current date\n\t3. Add member\n\t4. Delete member\n\t5. Add book\n\t6.Delete book\n\t7. New book loan\n\t8. Quit\n");
  scanf("%d", &ans);

  switch(ans)
  {
    case 1:
      diplay_current_date(Cdate); //fct that display the current date
      break;
    case 2:
      change_current_Date(Cdate); // fct to change the current date
      break;
    case 3:
      AddMember(); // fct to add a new member (à refaire/faire correspondre avec le reste)
      break;
    case 4:
      SuppressMember(); // fct to delete a member
      break;
    case 5:
      AddBook(); //fct to add a book
      break;
    case 6:
      pb = SuppressBook(); //fct to delete a book
      if (pb == 1)
      {
          printf("There was an error");
          return 0;
      }break;
    case 7:
      pb = NewLoan(); //fct to to add a new loan to a member (Warning: the user has to be a member else, has to register)
      if (pb == 1)
      {
          printf("There was an error");
          return 0;
      }
      break;
    case 8:
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

void AddMember() /*We add a member in the member's file, with all the information except the list of borrowed book*/
{
    struct Member PersA;

    FILE* fichier = NULL;
    fichier = fopen("members.txt", "a+");

    printf("\nFirst Name: ");
    fflush(stdin);
    fgets(PersA.FirstName, 50, stdin);
    printf("\nLast Name: ");
    fflush(stdin);
    fgets(PersA.LastName, 50, stdin);
    printf("\nAddress: ");
    fflush(stdin);
    fgets(PersA.address, 50, stdin);
    printf("\nEmail: ");
    fflush(stdin);
    fgets(PersA.email, 50, stdin);
    printf("\nProfession: ");
    fflush(stdin);
    fgets(PersA.profession, 50, stdin);

    /*now we will initialize the list of borrowed books*/
    strcpy(PersA.one.BookCode, "XXX-YYY");
    PersA.one.date.day = 00;
    PersA.one.date.month = 00;
    PersA.one.date.year = 0000;
    strcpy(PersA.two.BookCode, "XXX-YYY");
    PersA.two.date.day = 00;
    PersA.two.date.month = 00;
    PersA.two.date.year = 0000;
    strcpy(PersA.three.BookCode, "XXX-YYY");
    PersA.three.date.day = 00;
    PersA.three.date.month = 00;
    PersA.three.date.year = 0000;
    fflush(stdin);

    /*we write all the informations into the file*/
    fprintf(fichier, "Member:%s%s%s%s%s", PersA.FirstName, PersA.LastName, PersA.address, PersA.email, PersA.profession);
    fprintf(fichier, "\nBook1:\n%s\n%d/%d/%d\n",PersA.one.BookCode, PersA.one.date.day);
    fprintf(fichier, "\nBook2:\n%s\n%d/%d/%d\n",PersA.two.BookCode, PersA.two.date.month);
    fprintf(fichier, "\nBook3:\n%s\n%d/%d/%d\n\n",PersA.three.BookCode, PersA.three.date.year);
    getchar();
    fclose(fichier);

}

int SuppressMember (int argc, char *argv[])
{
    struct Member PersA;
    int pos1 = -1, pos2 = -1, pos = 0;
    char mot[50], line[50];

    FILE* fichier = NULL;
    fichier = fopen("members.txt", "r+");

    FILE* copie = NULL;
    copie = fopen("members2.txt", "a+");


    if (fichier != NULL)
    {
        printf("\nFirst name of the member you want to suppress: ");
        fflush(stdin);
        fgets(PersA.FirstName, 50, stdin);
        printf("\nHis last name: ");
        fflush(stdin);
        fgets(PersA.LastName, 50, stdin);

        while ( !feof(fichier))
        {
            fgets(mot, 50, fichier);
            if (strcmp(mot, PersA.FirstName) == 0)
                pos1 = pos;
            if (strcmp(mot, PersA.LastName) == 0)
                pos2 = pos;
            pos++;
        }

        if (pos1 > 0 && pos2 > 0 && (pos2 == pos1 + 1))
        {
            rewind(fichier);
            pos = 0;

            while ( !feof(fichier) )
            {
                fgets(line, 50, fichier);
                printf("%s", line);

                if ((pos < (pos1-1)) || (pos > (pos2+3)))
                    fputs(line, copie);
                pos++;
            }
            system("cls");
            fclose(copie);
            fclose(fichier);
            remove("members.txt");
            rename("members2.txt", "members.txt");
            return 0;
        }
    }
    return 1;

}

void AlphaOrder ()
{
    char array[10][2], tri[10][2], line[25];
    int pos = 0, comp = -1, i = 0, j = 0, m = 0;

    FILE* fichier = NULL;
    fichier = fopen("members.txt", "a+");

    if (fichier != NULL)
    {
       /*we search the First Name*/
       rewind(fichier);
       while ( !feof(fichier))
        {
            fgets(line, 25, fichier);
            while ((1 + 16*i) <= pos)
            {
                if (pos == 1 + 16*i)
                {
                    array[j][0] = line;
                    j++;
                }
                i++;
            }
            pos++;
        }

        /*we search the Last Name*/
        rewind(fichier);
        j = 0;
       while ( !feof(fichier))
        {
            fgets(line, 25, fichier);
            while ((1 + 16*i) <= pos)
            {
                if (pos == 1 + 16*i)
                {
                    array[j][1] = line;
                    j++;
                }
                i++;
            }
            pos++;
        }
        fclose(fichier);
    }
    for (i = 0; i < j; i++)
    {
        while (pos+i < j)
        {
            if (comp < 0)
            {
                tri[m][1] = array[i][1];
                pos++;
                comp = strcmp(array[i][1],array[i+pos][1]);
            }
            if (comp > 0)
            {
                tri[m][1] = array[i+pos][1];
                i++;
                comp = strcmp(array[i][1], array[i+pos-1][1]);
            }
            if (comp == 0)
            {
                comp = strcmp(array[i][0],array[i+pos][0]);
                if (comp <= 0)
                {
                    tri[m][0] = array[i][0];
                    tri[m][1] = array[i][1];
                }
                else if (comp > 0)
                {
                    tri[m][0] = array[i+pos][0];
                    tri[m][1] = array[i+pos][1];
                }
            }
        }
        m++;
    }

    /*we print the members in alphabetical order*/
    printf("The members are: ");
    for (i = 0; i < j; i++)
        printf("\n%s %s", tri[i][0], tri[i][1]);
}

void AddBook() /*We add a book in the book's file, with all the information*/
{
    struct Book myBook;

    FILE* fichier = NULL;
    fichier = fopen("books.txt", "a+");

    if (fichier != NULL)
    {
        printf("\nTitle: ");
        fflush(stdin);
        fgets(myBook.title, 25, stdin);
        printf("\nAuthor: ");
        fflush(stdin);
        fgets(myBook.author, 20, stdin);
        printf("\nBookCode (as XXX-YYY): ");
        fflush(stdin);
        fgets(myBook.BookCode, 7, stdin);
        printf("\nNumber of copies: ");
        scanf("%d", &(myBook.NbCopies));
        printf("\nNumber of Available copies: ");
        scanf("%d", &(myBook.AvaiCopies));

        fprintf(fichier, "%s%s%s", myBook.title, myBook.author, myBook.BookCode);
        fprintf(fichier, "\n%d\n%d\n", &(myBook.NbCopies), &(myBook.AvaiCopies));
        fclose(fichier);
    }
    else
    {
        printf("Impossible d'ouvrir le fichier members.txt");
    }
}

int SuppressBook ()
{
    struct Book myBook;
    int pos1 = -1, pos2 = -1, pos = 0;
    char mot[25], line[25];

    FILE* fichier = NULL;
    fichier = fopen("books.txt", "r+");

    FILE* copie = NULL;
    copie = fopen("books2.txt", "a+");


    if (fichier != NULL)
    {
        printf("\nTitle of the book you want to suppress: ");
        fflush(stdin);
        fgets(myBook.title, 25, stdin);
        printf("\nIts author: ");
        fflush(stdin);
        fgets(myBook.author, 25, stdin);

        while ( !feof(fichier))
        {
            fgets(mot, 25, fichier);
            if (strcmp(mot, myBook.title) == 0)
                pos1 = pos;
            if (strcmp(mot, myBook.author) == 0)
                pos2 = pos;
            pos++;
        }

        if (pos1 > 0 && pos2 > 0 && (pos2 == pos1 + 1))
        {
            rewind(fichier);
            pos = 0;

            while ( !feof(fichier) )
            {
                fgets(line, 25, fichier);
                printf("%s", line);

                if ((pos < (pos1-1)) || (pos > (pos2+3)))
                    fputs(line, copie);
                pos++;
            }
            system("cls");
            fclose(copie);
            fclose(fichier);
            remove("members.txt");
            rename("members2.txt", "members.txt");
            return 0;
        }
    }
    return 1;

}

