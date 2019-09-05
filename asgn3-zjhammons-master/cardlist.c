#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "memwatch.h"
#include "cardlist.h"


int check_input_suit(char *string)
{
  int c = 0;
  while (string[c] != '\0') 
  {
    if (string[c] >= 'a' && string[c] <= 'z') 
      {
         string[c] = string[c] - 32;
      }
      c++;
  } 
  if( strcmp(string,"SPADES") != 0 && strcmp(string,"HEARTS") != 0 && strcmp(string,"CLUBS") != 0 && strcmp(string,"DIAMONDS") != 0)
  {
     // printf("WRONG SUIT ENTERED!\n");
      return -1;
  }
  else return 1;
}

int check_input_rank(char *string)
{
  int c = 0;
  while (string[c] != '\0')
  {
    if (string[c] >= 'a' && string[c] <= 'z')
      {
         string[c] = string[c] - 32;
      }
      c++;
  }
  if( strcmp(string,"ACE") != 0 && strcmp(string,"KING") != 0 && strcmp(string,"QUEEN") != 0 && strcmp(string,"JACK") != 0)
  {
      //printf("WRONG RANK ENTERED!\n");
      return -1;
  }
  else return 1;
}


int check_input_rank_num(char *string)
{ 
  int s0 = string[0] - '0';
  int s1 = string[1] - '0';
  if( strlen(string) > 2 )
  {
  // printf("BAD NUMBER. ENTER 1- 10");
   return -1;
  }
  else if( strlen(string) == 2 && s0 != 1 && s1 != 0 )
  {
    //printf("NOT 10");
    return -1;
  }
  else if(s0 > 9 || s0 < 2 )
  {
    //printf("NOT 2-9");
    return -1;
  }
 return 1;
}


/* Purpose:Create a empty card list
*  Input: None
*  Output: Returns NULL
*/
card_list create()
{
  return NULL;
}

/* Purpose:Print the cards in the list
*  Input:The list of cards
*  Output:Each card's suit and rank are printed on their own line
*/
void print_list(card_list the_list)
{ 
  node_t*  current = the_list;
  while( current != NULL )
  {  
      printf("%s of %s\n", current->rank, current->suit );    
      //value = current->rank;
      current = current->next;
  
  }
}
/* Purpose:Add a card to beggining of list
*  Input:Pointer to the list, new card info: suit and rank
*  Output:pointer to the new cardlist with added card at the front
*/
card_list add_start( card_list* the_list, char *suit, char *rank )
{
//  printf("IN START");
  node_t* new_node = (node_t*) malloc(sizeof(node_t));
    if ( new_node == NULL )
    {
      perror("Something went wrong...");

    }
 // new_node->suit = *suit;
  strcpy(new_node->rank, rank);
  strcpy(new_node->suit, suit);
  new_node->next = *the_list;
  *the_list = new_node;
//  print_list(*the_list);
  return *the_list;
}

/* Purpose:Add card to the end of the list
*  Input:Pointer to the list, and new cards data: suit and rank
*  Output:Pointer to the new linked list with added card at the end
*/
card_list add_end( card_list* the_list, char* suit, char* rank )
{
  node_t* new_node = (node_t*) malloc(sizeof(node_t));
    if ( new_node == NULL )
    {
      perror("Something went wrong...");
    }
  node_t *last = *the_list;
  strcpy(new_node->rank, rank);
  strcpy(new_node->suit, suit);
  new_node->next = NULL;

  if( last == NULL )
  {
    *the_list = new_node;
    return *the_list;
  }
  while( last->next != NULL )
  {
    last = last->next;
  }
  last->next = new_node;
  return *the_list;
}



/* Purpose: Find a card in the list based on rank and suit 
*   Input:Pointer to the list, cards info we want to find: suit, rank
*  Output:The cards info printed to screen if it was found.or a message saying not found.
*/
card_list find_card( card_list* the_list, char* suit,char* rank )
{ 
  node_t* finder = *the_list;
  while( finder != NULL )
  { 
    if( strcmp(finder->suit,suit) == 0 && strcmp(finder->rank, rank) == 0 )
    { 
      printf("%s of %s\n", finder->rank, finder->suit );
      return *the_list;
    }
    finder = finder->next;
  }
  printf( "Did not find player in list!\n" );
  return *the_list;
}

/* Purpose: Delete a card give a suit and rank
*  Input:Pointer to the list and cards data you want to delete:suit and rank
*  Output:Silent on success. returns the new list with deleted card gone
*/
card_list delete_card( card_list* the_list, char* suit,char* rank )
{
  node_t* find = *the_list;
  node_t* temp;
  node_t* prev;
  while( find != NULL )
  {
    if( strcmp(find->suit,suit) == 0 && strcmp(find->rank, rank) == 0 )
    {
      //Node is the first node in list
      if( find == *the_list )
      {
        if( find == NULL )
        {
          return NULL;
        }
        temp = *the_list;
        *the_list = temp->next;
        free(temp);
        return *the_list;
      }
      //node is last node
      else if( find->next == NULL )
      {
       if( find == NULL )
       {
         return NULL;
       }
        prev = *the_list;
        while( prev->next->next != NULL )
          prev = prev->next;
        free(prev->next);
        prev->next = NULL;
        return *the_list;
      }
      //somewhere not in the begining or last node
      else
      {
        prev = *the_list;
        while( prev->next != NULL && prev->next != find )
          prev = prev->next;
        prev->next = prev->next->next;
        free(find);
        return *the_list;
      }
     }
   find = find->next;
  }
  return NULL;
}
