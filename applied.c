#include <stdio.h>  
#include <stdlib.h> 
#include <conio.h> 
#include <windows.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

#define N 100
void Menu();
void welcome_screen();
void MainMenu();
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

  MainMenu();

  return 0;
}

void MainMenu() {
  option = false;
  while (option == false) {
    Menu();
    printf("Enter which option do you want: ");
    scanf(" %c",&c);
    option = MenuOption (c);
  }
}

void welcome_screen() {
  system("color F0");
  char helloStr[] = "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\tNames: Hussein Shalaby and Anton Ashraf\n\t\t\t\tRegistration numbers: 20106681, 20105183\n\t\t\t\tCourse Name: Applied Programming\n\t\t\t\tCourse Code: CC212";
  for (int i = 0; i < strlen(helloStr); i++) {
    if (helloStr[i] == '\n' || helloStr[i] == '\t') {
      printf("%c", helloStr[i]);
    }
    else {
      printf("%c", helloStr[i]);
      Sleep(50);
    }
  }
  getch();
  system("color 07");
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
  printf("\t==     6 Applications\n\n"); // morse // clock // other
  printf("\t==     7 Games\n\n"); // ninja // connect4 // tic-tac-toe algo
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
  case '6':
    Applications();
  //   return 1;
   case '7':
     Games();
     return 1;
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
  Blue();
  printf("\t==      1 Sum of main and inverse digonals\n\n");
  printf("\t==      2 Sum of two Matrcies\n\n");
  printf("\t==      3 Mutiply two Matrcies\n\n");
  Yellow();
  printf("\t==      4 Back to Main Menu\n\n");
  Red();
  printf("\t==      e Exit the program\n\n");
  white();
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
  case '4':
    MainMenu();
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


// ahmed 
//  hmeda
//  dahme

// pass
// beep
// fdsfs
// ...-.-.-.--
// clock 
// hh:mm:ss


/////*********************************************************/////
/////*                     Applications                      */////
/////*********************************************************/////
void Applications();
void ApplicationMenu ();
bool ApplicationOption (char c);
void Leap_year();
int IsLeapYear(int n);
int GetNextLeapYear(int n);
void DigitalClock ();
void DiffTime();
struct TIME {
   int hours;
   int minutes;
   int seconds;
};
void differenceBetweenTimePeriod(struct TIME start, struct TIME stop, struct TIME *diff);



void Applications() {
  option = false;
  while (option == false){
    white();
    ApplicationMenu();
    printf("Enter which option do you want: ");
    scanf(" %c",&c);
    option = ApplicationOption (c);
  }
  
}
void ApplicationMenu () {
  system("cls");
  printf("\n\n\n");
  Green();
  printf("\t==      1 Check Leap Year\n\n");
  printf("\t==      2 Set a Digital Clock\n\n");
  printf("\t==      3 Diffrence between two times\n\n");
  printf("\t==      4 Decimal and binary conversions\n\n");
  Yellow();
  printf("\t==      5 Back to Main Menu\n\n");
  Red();
  printf("\t==      e Exit the program\n\n");
  white();
}
bool ApplicationOption (char c) {
  switch (c){
  case '1':
    Leap_year();
    return 1;
  case '2':
    DigitalClock();
    return 1;
  case '3':
    DiffTime();
    return 1;
  case '4':

  case '5':
    MainMenu();
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

void Leap_year () {
  //  Leap Year:
  //  If a year is divisible by 4, 100 and 400 then it is a leap year.
  //  If a year is divisible by 4 but not divisible by 100 then it is a leap year

  //  Not a Leap Year:
  //  If a year is not divisible by 4 then it is not a leap year
  //  If a year is divisible by 4 and 100 but not divisible by 400 then it is not a leap year
  system("cls");
  printf ("\n\n\t\t\tCheck weather it is Leap year or not Program\n\n");
  
  int y;
  printf("Enter the year: ");
  scanf("%d",&y);
  if (IsLeapYear(y)){
    Green();
    printf ("Yeaaah %d is Leap year!",y);
    return;
  }
  int x = GetNextLeapYear(y);
  Red();
  printf("nope %d not Leap year\n\n",y);
  Green();
  printf("But %d is the next Leap year",x);
}
int IsLeapYear(int n){
  return (((n%4==0)&&(n%100!=0))||(n%400==0));
}
int GetNextLeapYear(int n){
    int CurrentYear = n;
    while(!IsLeapYear(CurrentYear))
        CurrentYear++;
    return CurrentYear;
}


void DigitalClock () {
  //  time_t t;   // not a primitive datatype
  //   time(&t);

  //   printf("\nThis program has been writeen at (date and time): %s", ctime(&t));

  int h=0,m=0,s=0;
	system ("cls");
	printf("Please enter a time format in HH:MM:SS");
	scanf("%d%d%d",&h,&m,&s);
	start:
  for(h;h<24;h++){
		for(m;m<60;m++){
			for(s;s<60;s++){
				system("cls");
        Red();
        printf ("press e to exit or M to go back to Main Menu\n");
				Green();
        if(h<12){
          printf("\n\n\t\t\t%d:%d:%d",h,m,s);
					printf(" AM");
        }
				else{
          printf("\n\n\t\t\t%d:%d:%d",h-12,m,s);
					printf(" PM");
        }
				printf("\n\n\t\t\tSunday 18 Nov 2018");
				Sleep(1000);
        if (kbhit()) {
            c = getch();
            if (c == 'e' || c == 'E')
              exit(0);
            else if (c == 'm' || c == 'M')
              Applications();
        }
			}
			s=0;
		}
		m=0;
	}
	h=0;
	goto start;
getch();
}
void DiffTime() {
  struct TIME startTime, stopTime, diff;
  system("cls");
  printf ("\n\n\t\t\tGet the Time difference between time period Program\n\n");
  Green();
  printf("Enter the start time. \n\n");
  white();
  printf("Enter hours, minutes and seconds: ");
  scanf("%d %d %d", &startTime.hours, &startTime.minutes, &startTime.seconds);

  Red();
  printf("\n\nEnter the stop time. \n\n");
  white();
  printf("Enter hours, minutes and seconds: ");
  scanf("%d %d %d", &stopTime.hours, &stopTime.minutes, &stopTime.seconds);

  // Difference between start and stop time
  differenceBetweenTimePeriod(startTime, stopTime, &diff);
  Cyan();
  printf("\nTime Difference: %d:%d:%d - ", stopTime.hours, stopTime.minutes, stopTime.seconds);
  printf("%d:%d:%d = ", startTime.hours, startTime.minutes, startTime.seconds);
  Green();
  printf("%d:%d:%d\n\n", diff.hours, diff.minutes, diff.seconds);
  Yellow();
  printf("Do you want to continue to other program: (y/n) ");
  scanf (" %c",&c);
  if (c == 'y' || c == 'Y')
    Applications();
  else 
    exit(0);
}

// Computes difference between time periods
void differenceBetweenTimePeriod(struct TIME start, struct TIME stop, struct TIME *diff) {
    if(start.seconds > stop.seconds){
        stop.seconds += 60;
        --stop.minutes;
    }

    if(start.minutes > stop.minutes){
        stop.minutes += 60;
        --stop.hours;
    }
   diff->seconds = stop.seconds - start.seconds;
   diff->minutes = stop.minutes - start.minutes;
   diff->hours = stop.hours - start.hours;
}

void decBinMenu() {
  Green();
  printf("\t==      1 Convert from decimal to binary\n\n");
  printf("\t==      2 Convert from binary to decimal\n\n");
  Yellow();
  printf("\t==      3 Back to Main Menu\n\n");
  Red();
  printf("\t==      e Exit the program\n\n");
  white();
}

void decToBin(int n) {
  char str1[1005];
  int i = 0;
  while (n) {
    if (n%2==0) {
      str1[i] = '0';
    }
    else {
      str1[i] = '1';
    }
    n/=2;
    i++;
  }
  str1[i] = '\0';
  printf("%s\n", str1);
}

void binToDec(int n) {
  int dec = 0;
  int i = 0;
  while (n) {
      dec += n%10 * pow(2, i);
      n/=10;
      i++;
  }
  printf("%d", dec);
}

void Games() {
  int result ;
  result=system("SDLMain.exe");
  printf("%d",result);
  system("cls");
}
