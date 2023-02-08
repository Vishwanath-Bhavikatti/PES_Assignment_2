#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
/*
*********************************************************************************************************************
​ *
​ ​*​ ​@author​ :​Vishwanath Bhavikatti
​ ​*​ ​@date​ :Februrary 5, 2023 
 * @file name : lllifo.c
 * @file_description: The fuction implements stack operation using linked lists. Push operation pushes data to a predefined list with 
 *                    given capacity. Pop function pops element from the list and the capacity will not change even after pop operation.
 *                    While pushing the data if the capacity of a list is insufficient then function silently adds a node.
 * ---------------------------Functions Included in this file---------------------------------------------------------
 * lllifo_t *lllifo_create(int capacity) : Function to create a list
 * int lllifo_push(lllifo_t *lifo, void *element) : To push an element into the list
 * void *llfifo_pop(lllifo_t *lifo) : To pop elements from the list
 * int lllifo_length(lllifo_t *lifo) : Length of the list at any point of operation
 * int lllifo_capacity(lllifo_t *lifo) : Capacity of the list at any point of operation
 * void lllifo_destroy(lllifo_t *lifo) : Destroy the list 

*************************************************************************************************************************
*/


typedef struct lllifo_s lllifo_t;

// structure which defines a node parameters
typedef struct node
{
    void *data;
    struct node *next;
} node;

// structure that defines a list parameters
struct lllifo_s
{
    node *head; // head pointer -  to get the starting address of the node
    node *write; // write pointer  - used to push and pop the elements
    int capacity; //capacity of the list
    int length; //length of the list at any instance
};

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

lllifo_t *lllifo_create(int capacity)
{
    //check if capacity is less than zero 
    if (capacity < 0)   
    {
        return NULL;
    }
    //check if capacity is zero 
    if (capacity == 0)
    {
        //create a list with zero nodes
        lllifo_t *list = (lllifo_t *)malloc(sizeof(lllifo_t)); 
        if(list == NULL)
        {
            return NULL;  // checking if malloc has memory to allocate
        }
       
        list->head = NULL;
        list->capacity = capacity;
        list->length = 0;
        return list;
    }
    // creating temporary nodes
    node *temp;
    node *newnode;
    // creating a list using malloc operation
    lllifo_t *list = (lllifo_t *)malloc(sizeof(lllifo_t));
    if(list == NULL)
    {
        return NULL;  // checking if malloc has memory to allocate
    }
    list->head = NULL;
    list->capacity = capacity;
    list->length = 0;
   
    // creating head node with malloc function
    list->head = (node *)malloc(sizeof(node));
    if(list->head == NULL)
    {
        return NULL;  // checking if malloc has memory to allocate
    }
    (list->head)->data = 0;
    (list->head)->next = NULL;
    //assigning head to temp pointer
    temp = list->head;
    //At the beginning head and write pointer are pointing to the same node
    list->write = list->head;

    // creating nodes till the given capacity
    for (int i = 0; i < capacity - 1; i++)
    {
        newnode = (node*)malloc(sizeof(node));
        if(newnode == NULL)
        {
            return NULL;  // checking if malloc has memory to allocate
        }
        newnode->data = 0;
        newnode->next = NULL;

        temp->next = newnode;
        temp = temp->next;
    }
    //returning the list with nodes created
    return list;
}

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
int lllifo_push(lllifo_t *list, void *element)
{
    //checking for an element 
    if (element == NULL)
    {
        return -1;
    }
    //checking if list is NULL
    if(list == NULL)
    {
        return -1;
    }
    //if a capacity is zero then connect a node when push operation is called.
    if(list->capacity == 0)
    {
        list->capacity += 1;
        list->head = (node *)malloc(sizeof(node));
        if(list->head == NULL)
        {
            return -1;  // checking if malloc has memory to allocate
        }
        //Logic to connect the head node to write pointer
        (list->head)->data = element;
        (list->head)->next = NULL;
        list->write = list->head;
    }
    list->length++;

    // if the length is greater than capacity then silently increasing the capacity and pushing the ele into the list
    if (list->length > list->capacity )
    {
        list->capacity += 1;
        node *temp = (node *)malloc(sizeof(node));
        if(temp == NULL)
        {
            return -1;  // checking if malloc has memory to allocate
        }
        temp->data = element;
        temp->next = NULL;
        
        //logic to connect the temp node to the write node 
        node *ptr = list->head;
        while(ptr->next != list->write)
        {
            ptr = ptr->next;
        }
        ptr->next = temp;
        list->write = temp->next;

    }
    //logic for push operation using write pointer
    else
    {
        (list->write)->data = element;
        list->write = list->write->next;
    }

    // returning the list length after push operation
    return list->length;
}

/*
 * Removes ("pops") an element from the LIFO, and returns it
 *
 * Parameters:
 *   lifo  The lifo in question
 * 
 * Returns:
 *   The poped element, or NULL if the LIFO was empty
 */

void *lllifo_pop(lllifo_t *list)
{
    //defining a void pointer for storing a popped ele
    void *ptr;
    //returning NULL in case of NULL list or zero length
    if (list == NULL )
    {
        return NULL;
    }
    if (list->length == 0)
    {
        return NULL;
    }
    //decrementing length at the beginning
   
    if (list->length > 0)
    {
        //Logic for pop operation
        list->length--;
        node *temp = list->head;
        while(temp->next != list->write)
        {
            temp=temp->next;
        }
        list->write = temp;
        ptr = list->write->data;

    }
    
    //returning a pointer to a popped ele
    return ptr;
}

/*
 * Returns the number of elements currently on the LIFO.
 *
 * Parameters:
 *   lifo  The lifo in question
 * 
 * Returns:
 *   The number of elements currently on the LIFO
 */

int lllifo_length(lllifo_t *lifo)
{
    //return -1 in case of NULL list
    if (lifo == NULL)
    {
        return -1;
    }
    //in happy cases return length
    else
    {
        return lifo->length;
    }
}

/*
 * Returns the LIFO's current capacity
 *
 * Parameters:
 *   lifo  The lifo in question
 * 
 * Returns:
 *   The current capacity, in number of elements, for the LIFO
 */

int lllifo_capacity(lllifo_t *lifo)
{
    //return -1 in case of NULL list
    if (lifo == NULL)
    {
        return -1;
    }
    //in happy cases return length
    else
    {
        return lifo->capacity;
    }
}
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
void lllifo_destroy(lllifo_t *lifo)
{
    node *temp;
    node *ptr;
    temp = lifo->head;
    ptr = lifo->head;
    //travesring list using ptr pointer and freeing temp pointer in each case
    while (ptr != NULL)
    {
        ptr = ptr->next;
        free(temp);
        temp = ptr;
    }
    // assigning capacity as well as length to -1 so if a list is NULL I am returning -1 in capacity as well as length function
    lifo->capacity = -1;
    lifo->length = -1;
    // freeing the pointers and list
    free(lifo);
    lifo = NULL;
}


// ******************************************* End ******************************************************************


