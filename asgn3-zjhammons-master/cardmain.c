#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include "memwatch.h"
#include "cardlist.h"


#define INSERT_BEGINNING 'b'
#define INSERT_END       'e'
#define DELETE           'd'
#define FIND             'f'
#define PRINT            'p'
#define QUIT             'q'
	
const int BUFFER_LENGTH = 2;
	
	
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
  char suit[10];
  char rank[10];
 
  card_list list = create(); 
        
  while (1) 
  {          
   printf("Command:");
   if (scanf("%1s", command) < 1)
        die("scanf command: ");
        
   if (*command != QUIT  && *command != PRINT)
     { 
      printf("\nRank: ");
      if (scanf("%s", rank) != 1)
        { die("scanf value: ");}
      //number
      else if(  isdigit(rank[0]) != 0 )
      {
         if( check_input_rank_num(rank) != 1 )
         {
           printf("Bad Number\n");
           //break;
         }
      }
     //word
      else
      {
        if( check_input_rank(rank) != 1 )
          {
           printf("Bad word\n"); 
           //break;
          } 
      }

      printf("\nSuit: ");
      if (scanf("%s", suit) != 1)
        { die("scanf value: ");}
      else
      {
        if( check_input_suit(suit) != 1)
        { 
          printf("BAD");
          //break;
        }
      }
      }printf("\n");



     switch (*command)
     {
       case DELETE: list = delete_card( &list, suit, rank); break;
       case FIND:list = find_card( &list, suit,rank); break;
       case INSERT_BEGINNING:list  = add_start( &list, suit, rank  ); break;
       case INSERT_END: list  = add_end( &list, suit, rank ); break;
       case PRINT: print_list( list ); break;
       case QUIT:  exit(0);
       default: printf("Invalid command!\n"); break;
     }
   }
}
