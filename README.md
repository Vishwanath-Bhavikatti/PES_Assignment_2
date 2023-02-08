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
   
### Circular Queue Implementation using Arrays
### Problem statement
  The cbfifo implementation will be statically allocated, with a size of 256 bytes. 
  
## The Following Files are included:
  -->lllifo.c
  
  -->lllifo.h
  
  -->test_lllifo.c
  
  -->test_lllifo.h
  
  -->cbfifo.c
  
  -->cbfifo.h
  
  -->test_cbfifo.c
  
  -->test_cbfifo.h
  

##Test Functions

  ### test_lllifo.c() 
  
  The function involves different test cases within my bandwidth to check the proper working of lllifo.c function. 
  
  ### test_cbfifo.c()
  
  The function involves different test cases within my bandwidth to check the proper working of cbfifo.c function. 
  
  





