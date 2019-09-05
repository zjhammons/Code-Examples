#ifndef _CARDLIST_H
#define _CARDLIST_H_

typedef struct node_s {
     char rank[10];
     char suit[10];
     struct node_s *next;
} node_t;

typedef node_t* card_list;

card_list create();
void print_list(card_list the_list);
card_list add_start(card_list* the_list, char* suit, char* rank);
int check_input_suit(char *string);
int check_input_rank(char *string);
int check_input_rank_num(char *string);
card_list add_end( card_list* the_list, char* suit, char* rank);
card_list find_card( card_list* the_list, char* suit, char* rank);
card_list delete_card( card_list* the_list,  char* suit, char* rank);
#endif
