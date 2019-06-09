#include <stdio.h>
#include <stdlib.h>
#include "hashtable.h"
#include "ex1.h"

Answer *get_indices_of_item_weights(int *weights, int length, int limit)
{
  HashTable *ht = create_hash_table(16);

  /* YOUR CODE HERE */

  // loop through weights array
  for (int i = 0; i < length; i++)
  {
    // Store each weight as keys and it's array index as values into hash table
    hash_table_insert(ht, weights[i], i);
  }

  // Now loop again
  for (int i = 0; i < length; i++)
  {
    // Find the difference (limit - weight) and assign it to a variable 'diff'
    int diff = limit - weights[i];

    // Find index (i.e. the value in hashtable ) of the difference in array)
    int diff_position = hash_table_retrieve(ht, diff);

    // Check if that index exist in array
    // If it does then we found our two items whose weights sum up to `Limit`
    if (diff_position != -1)
    {
      // Allocating a block of memory and a pointer is returned to the start of the block
      Answer *ans = malloc(sizeof(Answer));
      // Assigning the higher index value to index_1
      ans->index_1 = diff_position;
      // Assigning the smaller index value to index_2
      ans->index_2 = i;

      return ans;
    }
  }
  //  If such a pair doesn’t exist for the given inputs, your function should return NULL.
  return NULL;
}

void print_answer(Answer *answer)
{
  if (answer != NULL)
  {
    printf("%d %d\n", answer->index_1, answer->index_2);
  }
  else
  {
    printf("NULL\n");
  }
}

#ifndef TESTING
int main(void)
{
  // TEST 1
  int weights_1 = {9};
  Answer *answer_1 = get_indices_of_item_weights(&weights_1, 1, 9);
  print_answer(answer_1); // NULL

  // TEST 2
  int weights_2[] = {4, 4};
  Answer *answer_2 = get_indices_of_item_weights(weights_2, 2, 8);
  print_answer(answer_2); // {1, 0}

  // TEST 3
  int weights_3[] = {4, 6, 10, 15, 16};
  Answer *answer_3 = get_indices_of_item_weights(weights_3, 5, 21);
  print_answer(answer_3); // {3, 1}

  // TEST 4
  int weights_4[] = {12, 6, 7, 14, 19, 3, 0, 25, 40};
  Answer *answer_4 = get_indices_of_item_weights(weights_4, 9, 7);
  print_answer(answer_4); // {6, 2}

  return 0;
}

#endif
