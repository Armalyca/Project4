#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct BorrowBook {
 char BookCode[7];
 char date[10];
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
#include<functions.h>


int main(int argc, char** argv)
{

  return 0;
}
