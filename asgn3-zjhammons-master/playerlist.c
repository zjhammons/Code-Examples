#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "memwatch.h"
#include "playerlist.h"

/* Purpose:Create a empty player list
*  Input: None
*  Output: Returns NULL
*/
player_list create()
{ 
  return NULL;
}

/* Purpose:Print the player list
*  Input:The list of player
*  Output:Ech player of list printed on their own line
*/
void print_list(player_list the_list)
{
  node_t*  current = the_list;
  while( current != NULL )
  {
    printf( "Player Number:%d\t\t Position:%d\t\t Goals Scored:%d\n", current->number, current->position, current->goals );
    current = current->next;
  }  
}

/* Purpose:Add a player to beggining of list
*  Input:Pointer to the list, new players: number, position, and goals
*  Output:pointer to the new playerlist with add player at the front
*/
player_list add_start( player_list* the_list, int number, int position, int goals )
{
  node_t* new_node = (node_t*) malloc(sizeof(node_t));
    if ( new_node == NULL )
    {
      perror("Something went wrong...");
      
    }
  new_node->number = number;
  new_node->position = position;
  new_node->goals = goals;
  new_node->next = *the_list;
  *the_list = new_node;
  
  return *the_list;
}

/* Purpose:Add player to the end of the list
*  Input:Pointer to the list, and new players data: number, position, goals
*  Output:Pointer to the new linked list with added player at the end
*/
player_list add_end( player_list* the_list, int number, int position, int goals )
{
  node_t* new_node = (node_t*) malloc(sizeof(node_t));
    if ( new_node == NULL )
    {
      perror("Something went wrong...");
    }
  node_t *last = *the_list;
    
  new_node->number = number;
  new_node->position = position;
  new_node->goals = goals;
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

/* Purpose:Find a player in the list using their data
*  Input:Pointer to the list, players info we want to find: number, position, goals
*  Output:The players inf printed to screen if it was found.or a message saying not found.
*/
player_list find_player( player_list* the_list, int number, int position, int goals )
{
  node_t* finder = *the_list;
  while( finder != NULL )
  {
    if( finder->number == number && finder->position == position && finder->goals == goals )
    {
      printf(" Player Number:%d\t\t Position:%d\t\t Goals Scored:%d\n", finder->number, finder->position, finder->goals );
      return *the_list;
    }
    finder = finder-> next;
  }
  printf( "Did not find player in list!\n" );
  return *the_list;
}

/* Purpose:delete a player from the list
*  Input:Pointer to the list and players data you want to delete: Number, position, and goals
*  Output:Silent on success. returns the new list with deleted player gone
*/
player_list delete_player( player_list* the_list, int number, int position, int goals )
{
  node_t* find = *the_list;
  node_t* temp;
  node_t* prev;
  while( find != NULL )
  {
    if( find->number == number && find->position == position && find->goals == goals )
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
