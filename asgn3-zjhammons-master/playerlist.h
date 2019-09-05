#ifndef _PLAYERLIST_H
#define _PLAYERLIST_H_

typedef struct node_s {
     int number;
     int position;
     int goals;
     struct node_s *next;
} node_t;

typedef node_t* player_list;

player_list create();

player_list add_start(player_list* the_list, int number, int position, int goals);
player_list add_end( player_list* the_list, int number, int position, int goals);
player_list find_player( player_list* the_list, int number, int position, int goals);
player_list delete_player( player_list* the_list, int number, int position, int goals);
void print_list(player_list the_list);
#endif

