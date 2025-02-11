#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashtable.h"
#include "ex2.h"

char **reconstruct_trip(Ticket **tickets, int length)
{
  HashTable *ht = create_hash_table(length);
  char **route = malloc(length * sizeof(char *));

  /* YOUR CODE HERE */

  // loop through tickets array
  for (int i = 0; i < length; i++)
  {
    // store each ticket such that source (the starting location) is the key
    // and the destination is the value
    hash_table_insert(ht, tickets[i]->source, tickets[i]->destination);
  }

  // find a destination of the first flight using a source(starting point) of NONE
  char *dest = hash_table_retrieve(ht, "NONE");

  // loop again
  for (int i = 0; i < length; i++)
  {
    // assign that destination to first index position in array
    route[i] = dest;
    // Find the next destination by updating the source(starting point) with last destination
    dest = hash_table_retrieve(ht, route[i]);
  }
  return route;
}

void print_route(char **route, int length)
{
  for (int i = 0; i < length; i++)
  {
    printf("%s\n", route[i]);
  }
}

#ifndef TESTING
int main(void)
{
  // Short test
  Ticket **tickets = malloc(3 * sizeof(Ticket *));

  Ticket *ticket_1 = malloc(sizeof(Ticket));
  ticket_1->source = "NONE";
  ticket_1->destination = "PDX";
  tickets[0] = ticket_1;

  Ticket *ticket_2 = malloc(sizeof(Ticket));
  ticket_2->source = "PDX";
  ticket_2->destination = "DCA";
  tickets[1] = ticket_2;

  Ticket *ticket_3 = malloc(sizeof(Ticket));
  ticket_3->source = "DCA";
  ticket_3->destination = "NONE";
  tickets[2] = ticket_3;

  print_route(reconstruct_trip(tickets, 3), 3); // PDX, DCA, NONE

  for (int i = 0; i < 3; i++)
  {
    free(tickets[i]);
  }

  free(tickets);

  return 0;
}
#endif
