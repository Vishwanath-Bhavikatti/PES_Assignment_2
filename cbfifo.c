#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<stddef.h>

#define MAX_SIZE 256   // statically defining capacity of an array globally


// declaring queue with max size
uint8_t queue[MAX_SIZE];
// array for storing dequeued elements
char deq[1024];
void *ptr = &deq;
//declaring front, rear and length globally
uint8_t front = 0;
uint8_t rear = 0;
size_t length = 0;

/*
*********************************************************************************************************************
​ *
​ ​*​ ​@author​ :​Vishwanath Bhavikatti
​ ​*​ ​@date​ :Februrary 6, 2023 
 * @file name : cbfifo.c
 * @file_description: The fuction implements circular queue operation using arrays. Enqueue operation enqueues data 
 *                    to a statically defined queue as per the given number of bytes. Dequeue function dequeues element
 *                    from the queue and stores the dequeued elements into a seperate array.
 *         
 * ---------------------------Functions Included in this file---------------------------------------------------------
 * size_t cbfifo_enqueue(void *buf, size_t nbyte) : Enqueues nbytes into a queue returns enqueued length. 
 * size_t cbfifo_dequeue(void *buf, size_t nbyte) : Dequeues nbytes from the queue and returns the dequeued element.
 * size_t cbfifo_length() : returns length of the queue at any point of operation.
 * size_t cbfifo_capacity() : returns the maximum capacity of the queue.

*************************************************************************************************************************
*/


/*
 * Enqueues data onto the FIFO, up to the limit of the available FIFO
 * capacity.
 *
 * Parameters:
 *   buf      Pointer to the data
 *   nbyte    Max number of bytes to enqueue
 * 
 * Returns:
 *   The number of bytes actually enqueued, which could be 0. In case
 * of an error, returns (size_t) -1.
 */
size_t cbfifo_enqueue(void *buf, size_t nbyte)
{
    // Declared a variable for counting enqueued length
    uint16_t enqued_elements = 0;
    
    // condition to check if the array is full
    if((length >= MAX_SIZE))
    {
        length = MAX_SIZE;
        return -1;
    }
    
    // loop runs till nbytes to enqueue each ele
    for(int i = 0; (size_t)i < nbyte; i++)
    { 
        //using rear variable to enqueue elements
        queue[rear]=*(uint8_t*)buf;
        enqued_elements++;

        //Incrementing rear value in a circular fashion using modulo operation (Implemented using bitwise &)
        rear = (rear + 1) & (MAX_SIZE - 1);
        buf++;
        length++;
    }
    //returning enqueued elements length
    return enqued_elements;

}

/*
 * Attempts to remove ("dequeue") up to nbyte bytes of data from the
 * FIFO. Removed data will be copied into the buffer pointed to by buf.
 *
 * Parameters:
 *   buf      Destination for the dequeued data
 *   nbyte    Bytes of data requested
 * 
 * Returns:
 *   The number of bytes actually copied, which will be between 0 and
 * nbyte. 
 * 
 * To further explain the behavior: If the FIFO's current length is 24
 * bytes, and the caller requests 30 bytes, cbfifo_dequeue should
 * return the 24 bytes it has, and the new FIFO length will be 0. If
 * the FIFO is empty (current length is 0 bytes), a request to dequeue
 * any number of bytes will result in a return of 0 from
 * cbfifo_dequeue.
 */
size_t cbfifo_dequeue(void *ptr, size_t nbyte)
{
    // Declared a variable for counting dequeued length
    uint16_t dequeue_elements = 0;

    //condition for checking if asked nbytes for dequeue is greater than length 
    if(nbyte > length)
    {
        nbyte = length;
    }

    //running a loop till nbytes and storing the dequeued elements in an array using ptr
    for(size_t i = 0; i < nbyte; i++)
    {
        //using front variable to dequeue elements
        *(char*)ptr = queue[front];
        dequeue_elements++;
        ptr++;
        //Incrementing rear value in a circular fashion using modulo operation (Implemented using bitwise &)
        front = (front + 1) & (MAX_SIZE - 1);
        length--;
    }
    //returning dequeued length
    return dequeue_elements;

}

/*
 * Returns the number of bytes currently on the FIFO. 
 *
 * Parameters:
 *   none
 * 
 * Returns:
 *   Number of bytes currently available to be dequeued from the FIFO
 */

size_t cbfifo_length()
{
    return length;
}

/*
 * Returns the FIFO's capacity
 *
 * Parameters:
 *   none
 * 
 * Returns:
 *   The capacity, in bytes, for the FIFO
 */

size_t cbfifo_capacity()
{
    return MAX_SIZE;
}


//******************************************************** Function ENDS here ****************************************************************