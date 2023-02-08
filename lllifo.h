/*
 * lllifo.h - a dynamically-growing LIFO(STACK)
 * 
 * Author: Howdy Pierce/Lalit Pandit, lalit.pandit@colorado.edu
 * 
 * DO NOT EDIT THIS FILE: You should check this file into your repo
 * exactly as it was delivered to you.
 */

#ifndef _LLLIFO_H_
#define _LLLIFO_H_

/* 
 * The lllifo's main data structure.
 *
 * Defined here as an incomplete type, in order to hide the
 * implementation from the user. You will need to define this struct
 * in your .c file.
 */
typedef struct lllifo_s lllifo_t;


/*
 * Creates and initializes the LIFO
 *
 * Parameters:
 *   capacity  the initial size of the lifo, in number of elements.
 *             Valid values are in the range of 0 to the limits of memory
 * 
 * Returns: A pointer to a newly-created lllifo_t instance, or NULL in
 *   case of an error.
 */
lllifo_t *lllifo_create(int capacity);


/*
 * Pushes an element onto the LIFO, growing the LIFO by adding
 * additional elements, if necessary
 *
 * Parameters:
 *   lifo    The lifo in question
 *   element The element to push, which cannot be NULL
 * 
 * Returns:
 *   The new length of the LIFO on success, -1 on failure. It is an error to attempt
 * to push the NULL pointer.
 */
int lllifo_push(lllifo_t *lifo, void *element);


/*
 * Removes ("pops") an element from the LIFO, and returns it
 *
 * Parameters:
 *   lifo  The lifo in question
 * 
 * Returns:
 *   The poped element, or NULL if the LIFO was empty
 */
void *lllifo_pop(lllifo_t *lifo);


/*
 * Returns the number of elements currently on the LIFO.
 *
 * Parameters:
 *   lifo  The lifo in question
 * 
 * Returns:
 *   The number of elements currently on the LIFO
 */
int lllifo_length(lllifo_t *lifo);


/*
 * Returns the LIFO's current capacity
 *
 * Parameters:
 *   lifo  The lifo in question
 * 
 * Returns:
 *   The current capacity, in number of elements, for the LIFO
 */
int lllifo_capacity(lllifo_t *lifo);


/*
 * Teardown function: Frees all dynamically allocated
 * memory. After calling this function, the lifo should not be used
 * again!
 *
 * Parameters:
 *   lifo  The lifo in question
 * 
 * Returns: none
 */
void lllifo_destroy(lllifo_t *lifo);

#endif // _LLLIFO_H_
