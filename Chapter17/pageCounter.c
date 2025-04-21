#include <stdio.h>
void printPage( const char* aHeading );
int main( void )  {
  printPage( "Title Page" );
  printPage( "Chapter 1 " );
  printPage( "          " );
  printPage( "          " );
  printPage( "Chapter 2 " );
  printPage( "          " );
  printPage( "Conclusion" );
}
void printPage( const char* aHeading )  {
  static int pageNo = 1;
  printf( "---------------------\n"
          "| %10s        |\n" , aHeading );
  printf( "|                   |\n"
          "|    Page Content   |\n"
          "|     Goes Here     |\n"
          "|                   |\n");
  printf( "|            Page %1d |\n"
          "---------------------\n" , pageNo );
  pageNo++;
}