# Course: Principle of Embedded Software - ECEN 5813 (Spring 2023)
# Assignment 2
## Author : Vishwanath Bhavikatti (vishwanathbhavikatti1310@gmail.com)
## Date : 2/7/2023

### This assignment gives some challenges to implement stack using linked list and circular buffer using arrays using C program and datastructures.

### Program Languages/Environment:
This entire assignment is written in C. ( gcc Compiler 9.3 is recommended for compilation )

### IDE Used: Visual Studio Code

## Program execution:
### In Visual studio Code : 
--> Created a C project in VS Code 

--> Source functions were written in src file

--> To compile: I used make command in VS Code terminal which takes care of compiling all the src files

--> To run: use .exe file to run (./main.exe in my case)

### In Ubuntu terminal :
--> Create a folder to save all the .c .h files

--> cd sourcefolder
  
--> To compile: gcc -o main main.c lllifo.c lllifo.h cbfifo.c cbfifo.h test_lllifo.c test_lllifo.h test_cbfifo.c test_cbfifo.h -Wall -Werror
  
--> To run: ./main
  
## Overview

### Stack Implementation Using Linked List 
### Problem staatement
  The lllifo implementation will be capable of growing dynamically through an efficient use of malloc().
  The caller will suggest an initial capacity when the LIFO is created, but if the caller subsequently attempts to push more elements onto the LIFO than the current     capacity would support, lllifo will silently increase its capacity up to the limits of available memory. For simplicity, the capacity of an lllifo instance will not   shrink until the LIFO is destroyed.
  
  ###The FIFO should implement the following API:
   lllifo_t *lllifo_create(int capacity);  // Creates a list with nodes of given capacity and returns list
   
   int lllifo_push(lllifo_t *lifo, void *element); // Pushes an element to the list and returns the length of the list 
   
   void *llfifo_pop(lllifo_t *lifo); // pops an element from the list and returns the popped element.
   
   int lllifo_length(lllifo_t *lifo); // returns length of a list at any point of operation
   
   int lllifo_capacity(lllifo_t *lifo); // returns capacity of list at any point of operation
   
   void lllifo_destroy(lllifo_t *lifo); // Destroys/frees the list and allocated memory
   
### Circular Queue Implementation using Arrays
### Problem statement
  The cbfifo implementation will be statically allocated, with a size of 256 bytes. (You should make this constant a #define in your code.) The FIFO should implement   the following API:
  
  size_t cbfifo_enqueue(void *buf, size_t nbyte); // Enqueues nbytes to the queue and returns the enqueued length
  
  size_t cbfifo_dequeue(void *buf, size_t nbyte); // Dequeues nbytes of element from the queue and returns dequeued length
  
  size_t cbfifo_length(); // returns length of filled elements in a queue
  
  size_t cbfifo_capacity(); // returns capacity of queue
 






