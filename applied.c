#include <stdio.h>  
#include <stdlib.h> 
#include <conio.h> 
#include <unistd.h>
#include <windows.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define N 100
void Menu();
char getinput();
bool MenuOption (char c);
void Main_Array();
void Strings();
void Recursion();
void Struct();
void Files();
void Applications();
void Games();

bool option; 
char c;


int main () {

  // welcome_screen();

  while (option == false) {
    Menu();
    printf("Enter which option do you want: ");
    scanf(" %c",&c);
    option = MenuOption (c);
  }

  return 0;
}

void welcome_screen() {

}

/////*********************************************************/////
/////*          Colors, Main Menu, options                   */////
/////*********************************************************/////

void Black () {
  printf ("\033[1;30m");
}
void Green () {
  printf ("\033[1;32m");
}
void Red() {
  printf ("\033[1;31m");
}
void Yellow () {
  printf ("\033[1;33m");
}
void Blue () {
  printf ("\033[1;34m");
}
void purple () {
  printf("\033[1;35m");
}
void Cyan () {
  printf ("\033[1;36m");
}
void white () {
  printf("\033[0;37m");
}
void offwhite() {
  printf("\033[0;18m");
}

void Menu() {
  system("cls");
  offwhite();
  printf("\n\t\t\tWelcome To Our Final Project in Applied Programming Course\n\n\n");
  Yellow();
  printf("\t==     1 2D Arrays\n\n");
  printf("\t==     2 Strings\n\n");
  Cyan();
  printf("\t==     3 Recursion\n\n");
  purple();
  printf("\t==     4 Struct\n\n");
  printf("\t==     5 Files\n\n");
  Green();
  printf("\t==     6 Applications\n\n");
  printf("\t==     7 Games\n\n");
  Red();
  printf("\t==     e Exit the program\n\n");
  white();
  printf("\n");
}

bool MenuOption (char c) {
  switch (c){
  case '1':
    Main_Array();
    return 1;
  // case '2':
  //   Strings();
  //   return 1;
  // case '3':
  //   Recursion();
  //   return 1;
  // case '4':
  //   Struct();
  //   return 1;
  // case '5':
  //   Files();
  //   return 1;
  // case '6':
  //   Applications();
  //   return 1;
  // case '7':
  //   Games();
  //   return 1;
  case 'e':
  case 'E':
    exit (0);
  default:
    Red();
    printf ("Invalid Input!\n");
    Sleep(1000);
    return 0;
  }
}

/////*********************************************************/////
/////*                2D Arrays and Matrcies                 */////
/////*********************************************************/////
void Main_Array();
void ArrayMenu ();          // Display array menu
bool ArrayOption (char c);  // preform based on option choosen
void Diagonals ();          // Diagonals funcion                                                     // 1st option
void sumDiagonals ();       // get sum of 2 diagonals
void Sum2D ();              // Sum of 2 Matrcies                                                     // 2nd option
void addtion ();            // prifoming addition of 2 matrcies and printing them with the sum
void Multiply ();           // multiply 2 Matrcies                                                   // 3rd option
void Mult();
void MatrixInput();
void twoMatrixInput ();
void print_matrix(int r, int c, int mat[][N]);

int mat1[N][N], mat2[N][N], r1, c1,r2,c2;

void Main_Array() {
  option = false;
  while (option == false){
    white();
    ArrayMenu();
    printf("Enter which option do you want: ");
    scanf(" %c",&c);
    option = ArrayOption (c);
  }
  
}
void ArrayMenu () {
  system("cls");
  printf("\n\n\n");
  printf("\t==      1 Sum of main and inverse digonals\n\n");
  printf("\t==      2 Sum of two Matrcies\n\n");
  printf("\t==      3 Mutiply two Matrcies\n\n");
  printf("\t==      e Exit the program\n\n");
}
bool ArrayOption (char c) {
  switch (c){
  case '1':
    Diagonals();
    return 1;
  case '2':
    Sum2D();
    return 1;
  case '3':
    Multiply();
    return 1;
  case 'e':
  case 'E':
    exit(0);
  default:
    Red();
    printf ("Invalid Input!\n");
    Sleep(1000);
    white();
    return 0;
  }
} 

//////*               Sum of Diagonals "First option"         */////
void Diagonals () {
  system("cls");
  printf ("\n\n\tGet the sum of Main and Inverse Diagonal Program\n\n\n");
  MatrixInput();
  system("cls");
  printf ("\n\n\tGet the sum of Main and Inverse Diagonal Program\n\n\n");
  sumDiagonals();
}
void sumDiagonals () {

  int Dsum = 0, IDsum = 0;
  for (int i = 0; i < r1; i++)
    Dsum += mat1[i][i];

  for (int i = 0; i < r1; i++){
    int j = r1 - 1 - i;
      IDsum += mat1[i][j];
  }

  printf ("\nThe Matrix is: \n\n");
  Cyan();
  print_matrix(r1,c1,mat1);
  printf("\n\n");
  Green();
  printf ("Sum of main diagonal = %d\n", Dsum);
  printf ("Sum of inverse diagonal = %d\n", IDsum);
}

/////*      Sum of 2 Matrcies "Second option"                */////
void Sum2D () {
  system("cls");
  printf ("\n\n\t\tGet the sum of two Matrcies Program\n\n");
  twoMatrixInput();
  system("cls");
  printf ("\n\n\t\tGet the sum of two Matrcies Program\n\n");
  addtion();
}
void addtion () {
    if (r1 != r2 || c1 != c2){ // check if they are equals in rows and coulumns
    Red();
    printf("\n\n\tSorry can't preform this opertion\nWrong Dimensions!\nThe two matrcies must be in equal dimensions\n");
    return;
  }
  // preform SUM
  int sum[N][N];
  for (int i = 0; i < r1; i++)
    for (int j = 0; j < c1; j++)
      sum[i][j] = mat1[i][j] + mat2[i][j];
  printf ("\n\tThe sum of matrix\n\n");
  Cyan();
  print_matrix(r1,c1,mat1);
  white();
  printf("\n\tAnd Matrix\n\n");
  Cyan();
  print_matrix(r2,c2,mat2);
  // print the sum matrix
  Green();
  printf("\n\tIs equal:\n\n");
  print_matrix(r1,c1,sum);
}

/////*      Multiply two Matrcies "Third option"                */////
void Multiply () {
  system("cls");
  printf ("\n\n\t\tGet the Multiplication of two Matrcies Program\n\n");
  twoMatrixInput();
  system("cls");
  printf ("\n\n\t\tGet the Multiplication of two Matrcies Program\n\n");
  Mult ();
}
void Mult () {
   if (c1 != r2) {
    Red();
    printf("Sorry can't preform this opertion\nWrong Dimensions!");
    return;
  }
  int mult[N][N];
  for (int i = 0; i < r1; i++)
    for (int j = 0; j < c2; j++)
      for (int k = 0; k < c1; k++)
        mult[i][j] += mat1[i][k] * mat2[k][j];
  
  printf ("\n\tThe multiplication of Matrix\n\n");
  Cyan();
  print_matrix(r1,c1,mat1);
  white();
  printf("\n\tAnd Matrix\n\n");
  Cyan();
  print_matrix(r2,c2,mat2);
  // print the sum matrix
  Green();
  printf("\n\tIs equal:\n\n");
  print_matrix(r1,c2,mult);
  
}

/////*           input & output                  */////
void twoMatrixInput () {
  white();
  printf("Please enter rows and coulmns of first matrix:\n");
  printf("\nRows: ");  scanf("%d",&r1);
  printf("coulmns: ");  scanf("%d",&c1);
  printf ("Enter the first matrix %d X %d\n", r1, c1);
  for (int i = 0; i < r1; i++)
    for (int j = 0; j < c1; j++)
      scanf("%d",&mat1[i][j]);
  printf("Please enter rows and coulmns of second matrix:\n");
  printf("\nRows: ");  scanf("%d",&r2);
  printf("coulmns: ");  scanf("%d",&c2);
  printf ("Enter the second matrix %d X %d\n", r2, c2);
  for (int i = 0; i < r2; i++)
    for (int j = 0; j < c2; j++)
      scanf("%d",&mat2[i][j]);
}
void MatrixInput() {
  white();
  printf("Please enter rows and coulmns of the matrix:\n");
  Red();
  printf("note: rows & coulmns must be equal.\n");
  white();
  printf("\nRows: ");  scanf("%d",&r1);
  printf("coulmns: ");  scanf("%d",&c1);
  
  if (r1 != c1) { // Must be squaare Matrix
  Red();
  printf("Sorry can't preform this opertion\nWrong Dimensions!\n");
  return;
}
  printf ("Enter the matrix %d X %d\n", r1, c1);
  for (int i = 0; i < r1; i++)
    for (int j = 0; j < c1; j++)
      scanf("%d",&mat1[i][j]);
}
void print_matrix(int r, int c, int mat[][N]) {
  for (int i = 0; i < r; i++){
    printf ("\t");
    for (int j = 0; j < c; j++)
      printf("%d ",mat[i][j]);
    printf ("\n");
  }
}

/////*********************************************************/////
/////*                      Strings                          */////
/////*********************************************************/////



