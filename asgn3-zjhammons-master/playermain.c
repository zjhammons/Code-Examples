#include <stdlib.h>
#include <stdio.h>
#include "memwatch.h"
#include "playerlist.h"

#define INSERT_BEGINNING 'b'
#define INSERT_END       'e'
#define DELETE           'd'
#define FIND             'f'
#define PRINT            'p'
#define QUIT             'q'

const int BUFFER_LENGTH=2;
/* purpose: print a message and terminate the program
* input:   the message
* returns: never!! terminates progam
*/
static void die(char *msg)
{
  perror(msg);
  exit(-1);
}	
	
int main(int argc, char *argv[])
{
  char command[BUFFER_LENGTH];
  int number;
  int position;
  int goals;
  player_list list = create();
 	
  while (1) 
  {
   printf("Command:");
   if (scanf("%1s", command) < 1)
	die("scanf command: ");
	
   if (*command != QUIT  && *command != PRINT)
     {
      printf("Number: ");
      if (scanf("%d", &number) != 1)
	 die("scanf value: ");

      printf("\nPosition: ");
      if (scanf("%d", &position) != 1)
         die("scanf value: ");

      printf("\nGoals: ");
      if (scanf("%d", &goals) != 1)
         die("scanf value: ");
     }
     switch (*command)
     {     
       case DELETE: list = delete_player( &list, number, position, goals ); break;
       case FIND:list = find_player( &list, number, position, goals ); break;
       case INSERT_BEGINNING:list  = add_start( &list, number, position, goals ); break;
       case INSERT_END: list  = add_end( &list, number, position, goals ); break;
       case PRINT: print_list( list ); break;
       case QUIT:  exit(0);
       default: printf("Invalid command!\n"); break;
     }
   }
}
