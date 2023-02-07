/*
*********************************************************************************************************************
************************************** Including necessary Header files *********************************************
*/

#include<stdio.h>
#include<string.h>
#include<stddef.h>
#include "test_lllifo.h"
#include "lllifo.h"


// defining a structure for test case which contains test parameters
struct LLLIFO_Test
{
    lllifo_t *list;
    void *push_ele;
    void *pop_ele;
    char *act_pop_ele;

    int exp_len;
    int exp_cap;
    int is_push;
    int is_destroy;
}LLLIFO;

/*
*********************************************************************************************************************
​ *
​ ​*​ ​@author​ :​Vishwanath Bhavikatti
​ ​*​ ​@date​ :Februrary 5, 2023 
 * @file name : test_lllifo.c
 * @file_description: structure is defined for writing test cases to check the successful working of LLLIFO.C function.
 *                    All corner cases are being tested as per my bandwidth.
 * return : returns 1 in case of all test cases being passed
 * 
*************************************************************************************************************************
*/
int test_lllifo()
{
    char var_char[] = "LLLIFO";
    int capacity[] = {5,20,1,0};
    int test_passed = 0;
    int total_tests = 0;
    lllifo_t *list1 = lllifo_create(capacity[0]);
    lllifo_t *list2 = lllifo_create(capacity[1]);
    lllifo_t *list3 = lllifo_create(capacity[2]);
    lllifo_t *list4 = lllifo_create(capacity[3]);
     
    
    // array of test cases
    struct LLLIFO_Test lllifo_test_list[] = {

        // Each structure represents a test case
        // Below test cases for List with capacities 5, 20, 1, 0

        //Pushing the elements till the capacity of 5 for list1

        {.list = list1, .push_ele = &var_char, .exp_len = 1, .exp_cap = 5, .is_push = 1, .is_destroy = 0},
        {.list = list1, .push_ele = &var_char, .exp_len = 2, .exp_cap = 5, .is_push = 1, .is_destroy = 0},
        {.list = list1, .push_ele = &var_char, .exp_len = 3, .exp_cap = 5, .is_push = 1, .is_destroy = 0},
        {.list = list1, .push_ele = &var_char, .exp_len = 4, .exp_cap = 5, .is_push = 1, .is_destroy = 0},
        {.list = list1, .push_ele = &var_char, .exp_len = 5, .exp_cap = 5, .is_push = 1, .is_destroy = 0},
        
        //Pushing the elements beyond the capacity of List 1
        {.list = list1, .push_ele = &var_char, .exp_len = 6, .exp_cap = 6, .is_push = 1, .is_destroy = 0},
        {.list = list1, .push_ele = &var_char, .exp_len = 7, .exp_cap = 7, .is_push = 1, .is_destroy = 0},
        {.list = list1, .push_ele = &var_char, .exp_len = 8, .exp_cap = 8, .is_push = 1, .is_destroy = 0},
        {.list = list1, .push_ele = &var_char, .exp_len = 9, .exp_cap = 9, .is_push = 1, .is_destroy = 0},
        {.list = list1, .push_ele = &var_char, .exp_len = 10, .exp_cap = 10, .is_push = 1, .is_destroy = 0},

        //Pop all the elements from List 1
        {.list = list1, .pop_ele = &var_char, .exp_len = 9, .exp_cap = 10, .is_push = 0, .is_destroy = 0},
        {.list = list1, .pop_ele = &var_char, .exp_len = 8, .exp_cap = 10, .is_push = 0, .is_destroy = 0},
        {.list = list1, .pop_ele = &var_char, .exp_len = 7, .exp_cap = 10, .is_push = 0, .is_destroy = 0},
        {.list = list1, .pop_ele = &var_char, .exp_len = 6, .exp_cap = 10, .is_push = 0, .is_destroy = 0},
        {.list = list1, .pop_ele = &var_char, .exp_len = 5, .exp_cap = 10, .is_push = 0, .is_destroy = 0},
        {.list = list1, .pop_ele = &var_char, .exp_len = 4, .exp_cap = 10, .is_push = 0, .is_destroy = 0},
        {.list = list1, .pop_ele = &var_char, .exp_len = 3, .exp_cap = 10, .is_push = 0, .is_destroy = 0},
        {.list = list1, .pop_ele = &var_char, .exp_len = 2, .exp_cap = 10, .is_push = 0, .is_destroy = 0},
        {.list = list1, .pop_ele = &var_char, .exp_len = 1, .exp_cap = 10, .is_push = 0, .is_destroy = 0},
        {.list = list1, .pop_ele = &var_char, .exp_len = 0, .exp_cap = 10, .is_push = 0, .is_destroy = 0},

        //Push and pop operation in random manner on List1
        {.list = list1, .push_ele = &var_char, .exp_len = 1, .exp_cap = 10, .is_push = 1, .is_destroy = 0},
        {.list = list1, .push_ele = &var_char, .exp_len = 2, .exp_cap = 10, .is_push = 1, .is_destroy = 0},
        {.list = list1, .push_ele = &var_char, .exp_len = 3, .exp_cap = 10, .is_push = 1, .is_destroy = 0},
        {.list = list1, .pop_ele = &var_char, .exp_len = 2, .exp_cap = 10, .is_push = 0, .is_destroy = 0},
        {.list = list1, .pop_ele = &var_char, .exp_len = 1, .exp_cap = 10, .is_push = 0, .is_destroy = 0},
        {.list = list1, .pop_ele = &var_char, .exp_len = 0, .exp_cap = 10, .is_push = 0, .is_destroy = 0},

       // pop ele after the length has reached zero.
        {.list = list1, .pop_ele = NULL, .exp_len = 0, .exp_cap = 10, .is_push = 0, .is_destroy = 0},

       // destroy List1
        {.list = list1, .exp_len = -1, .exp_cap = -1, .is_destroy = 1},

       //Pushing the elements till the capacity of 20 for list2

        {.list = list2, .push_ele = &var_char, .exp_len = 1, .exp_cap = 20, .is_push = 1, .is_destroy = 0},
        {.list = list2, .push_ele = &var_char, .exp_len = 2, .exp_cap = 20, .is_push = 1, .is_destroy = 0},
        {.list = list2, .push_ele = &var_char, .exp_len = 3, .exp_cap = 20, .is_push = 1, .is_destroy = 0},
        {.list = list2, .push_ele = &var_char, .exp_len = 4, .exp_cap = 20, .is_push = 1, .is_destroy = 0},
        {.list = list2, .push_ele = &var_char, .exp_len = 5, .exp_cap = 20, .is_push = 1, .is_destroy = 0},
        {.list = list2, .push_ele = &var_char, .exp_len = 6, .exp_cap = 20, .is_push = 1, .is_destroy = 0},
        {.list = list2, .push_ele = &var_char, .exp_len = 7, .exp_cap = 20, .is_push = 1, .is_destroy = 0},
        {.list = list2, .push_ele = &var_char, .exp_len = 8, .exp_cap = 20, .is_push = 1, .is_destroy = 0},
        {.list = list2, .push_ele = &var_char, .exp_len = 9, .exp_cap = 20, .is_push = 1, .is_destroy = 0},
        {.list = list2, .push_ele = &var_char, .exp_len = 10, .exp_cap = 20, .is_push = 1, .is_destroy = 0},
        {.list = list2, .push_ele = &var_char, .exp_len = 11, .exp_cap = 20, .is_push = 1, .is_destroy = 0},
        {.list = list2, .push_ele = &var_char, .exp_len = 12, .exp_cap = 20, .is_push = 1, .is_destroy = 0},
        {.list = list2, .push_ele = &var_char, .exp_len = 13, .exp_cap = 20, .is_push = 1, .is_destroy = 0},
        {.list = list2, .push_ele = &var_char, .exp_len = 14, .exp_cap = 20, .is_push = 1, .is_destroy = 0},
        {.list = list2, .push_ele = &var_char, .exp_len = 15, .exp_cap = 20, .is_push = 1, .is_destroy = 0},
        {.list = list2, .push_ele = &var_char, .exp_len = 16, .exp_cap = 20, .is_push = 1, .is_destroy = 0},
        {.list = list2, .push_ele = &var_char, .exp_len = 17, .exp_cap = 20, .is_push = 1, .is_destroy = 0},
        {.list = list2, .push_ele = &var_char, .exp_len = 18, .exp_cap = 20, .is_push = 1, .is_destroy = 0},
        {.list = list2, .push_ele = &var_char, .exp_len = 19, .exp_cap = 20, .is_push = 1, .is_destroy = 0},
        {.list = list2, .push_ele = &var_char, .exp_len = 20, .exp_cap = 20, .is_push = 1, .is_destroy = 0},

        // Pushing elemnets beyond capacity of List 2 
        {.list = list2, .push_ele = &var_char, .exp_len = 21, .exp_cap = 21, .is_push = 1, .is_destroy = 0},
        {.list = list2, .push_ele = &var_char, .exp_len = 22, .exp_cap = 22, .is_push = 1, .is_destroy = 0},

        //Pop all the elements from List 2
        {.list = list2, .pop_ele = &var_char, .exp_len = 21, .exp_cap = 22, .is_push = 0, .is_destroy = 0},
        {.list = list2, .pop_ele = &var_char, .exp_len = 20, .exp_cap = 22, .is_push = 0, .is_destroy = 0},
        {.list = list2, .pop_ele = &var_char, .exp_len = 19, .exp_cap = 22, .is_push = 0, .is_destroy = 0},
        {.list = list2, .pop_ele = &var_char, .exp_len = 18, .exp_cap = 22, .is_push = 0, .is_destroy = 0},
        {.list = list2, .pop_ele = &var_char, .exp_len = 17, .exp_cap = 22, .is_push = 0, .is_destroy = 0},
        {.list = list2, .pop_ele = &var_char, .exp_len = 16, .exp_cap = 22, .is_push = 0, .is_destroy = 0},
        {.list = list2, .pop_ele = &var_char, .exp_len = 15, .exp_cap = 22, .is_push = 0, .is_destroy = 0},
        {.list = list2, .pop_ele = &var_char, .exp_len = 14, .exp_cap = 22, .is_push = 0, .is_destroy = 0},
        {.list = list2, .pop_ele = &var_char, .exp_len = 13, .exp_cap = 22, .is_push = 0, .is_destroy = 0},
        {.list = list2, .pop_ele = &var_char, .exp_len = 12, .exp_cap = 22, .is_push = 0, .is_destroy = 0},
        {.list = list2, .pop_ele = &var_char, .exp_len = 11, .exp_cap = 22, .is_push = 0, .is_destroy = 0},
        {.list = list2, .pop_ele = &var_char, .exp_len = 10, .exp_cap = 22, .is_push = 0, .is_destroy = 0},
        {.list = list2, .pop_ele = &var_char, .exp_len = 9, .exp_cap = 22, .is_push = 0, .is_destroy = 0},
        {.list = list2, .pop_ele = &var_char, .exp_len = 8, .exp_cap = 22, .is_push = 0, .is_destroy = 0},
        {.list = list2, .pop_ele = &var_char, .exp_len = 7, .exp_cap = 22, .is_push = 0, .is_destroy = 0},
        {.list = list2, .pop_ele = &var_char, .exp_len = 6, .exp_cap = 22, .is_push = 0, .is_destroy = 0},
        {.list = list2, .pop_ele = &var_char, .exp_len = 5, .exp_cap = 22, .is_push = 0, .is_destroy = 0},
        {.list = list2, .pop_ele = &var_char, .exp_len = 4, .exp_cap = 22, .is_push = 0, .is_destroy = 0},
        {.list = list2, .pop_ele = &var_char, .exp_len = 3, .exp_cap = 22, .is_push = 0, .is_destroy = 0},
        {.list = list2, .pop_ele = &var_char, .exp_len = 2, .exp_cap = 22, .is_push = 0, .is_destroy = 0},
        {.list = list2, .pop_ele = &var_char, .exp_len = 1, .exp_cap = 22, .is_push = 0, .is_destroy = 0},
        {.list = list2, .pop_ele = &var_char, .exp_len = 0, .exp_cap = 22, .is_push = 0, .is_destroy = 0},

        //Push and pop operation in random manner on List2
        {.list = list2, .push_ele = &var_char, .exp_len = 1, .exp_cap = 22, .is_push = 1, .is_destroy = 0},
        {.list = list2, .push_ele = &var_char, .exp_len = 2, .exp_cap = 22, .is_push = 1, .is_destroy = 0},
        {.list = list2, .push_ele = &var_char, .exp_len = 3, .exp_cap = 22, .is_push = 1, .is_destroy = 0},
        {.list = list2, .pop_ele = &var_char, .exp_len = 2, .exp_cap = 22, .is_push = 0, .is_destroy = 0},
        {.list = list2, .pop_ele = &var_char, .exp_len = 1, .exp_cap = 22, .is_push = 0, .is_destroy = 0},
        {.list = list2, .pop_ele = &var_char, .exp_len = 0, .exp_cap = 22, .is_push = 0, .is_destroy = 0},

        // pop ele after the length has reached zero.
        {.list = list2, .pop_ele = NULL, .exp_len = 0, .exp_cap = 22, .is_push = 0, .is_destroy = 0},

        // destroy List2
        {.list = list2, .exp_len = -1, .exp_cap = -1, .is_destroy = 1},

        //Pushing the elements till the capacity of 1 for list3 and even beyond capacity

        {.list = list3, .push_ele = &var_char, .exp_len = 1, .exp_cap = 1, .is_push = 1, .is_destroy = 0},
        {.list = list3, .push_ele = &var_char, .exp_len = 2, .exp_cap = 2, .is_push = 1, .is_destroy = 0},
        {.list = list3, .push_ele = &var_char, .exp_len = 3, .exp_cap = 3, .is_push = 1, .is_destroy = 0},
        {.list = list3, .push_ele = &var_char, .exp_len = 4, .exp_cap = 4, .is_push = 1, .is_destroy = 0},
        {.list = list3, .push_ele = &var_char, .exp_len = 5, .exp_cap = 5, .is_push = 1, .is_destroy = 0},

        //Pop all the elements from List 3
        {.list = list3, .pop_ele = &var_char, .exp_len = 4, .exp_cap = 5, .is_push = 0, .is_destroy = 0},
        {.list = list3, .pop_ele = &var_char, .exp_len = 3, .exp_cap = 5, .is_push = 0, .is_destroy = 0},
        {.list = list3, .pop_ele = &var_char, .exp_len = 2, .exp_cap = 5, .is_push = 0, .is_destroy = 0},
        {.list = list3, .pop_ele = &var_char, .exp_len = 1, .exp_cap = 5, .is_push = 0, .is_destroy = 0},
        {.list = list3, .pop_ele = &var_char, .exp_len = 0, .exp_cap = 5, .is_push = 0, .is_destroy = 0},

        // pop ele after the length has reached zero.
        {.list = list3, .pop_ele = NULL, .exp_len = 0, .exp_cap = 5, .is_push = 0, .is_destroy = 0},


        // destroy List3
        {.list = list3, .exp_len = -1, .exp_cap = -1, .is_destroy = 1},

        //Pushing elements into a list 4 with zero capacity

        {.list = list4, .push_ele = &var_char, .exp_len = 1, .exp_cap = 1, .is_push = 1, .is_destroy = 0},
        {.list = list4, .push_ele = &var_char, .exp_len = 2, .exp_cap = 2, .is_push = 1, .is_destroy = 0},
        {.list = list4, .push_ele = &var_char, .exp_len = 3, .exp_cap = 3, .is_push = 1, .is_destroy = 0},

        //Pop all the elements from List 4
        {.list = list4, .pop_ele = &var_char, .exp_len = 2, .exp_cap = 3, .is_push = 0, .is_destroy = 0},
        {.list = list4, .pop_ele = &var_char, .exp_len = 1, .exp_cap = 3, .is_push = 0, .is_destroy = 0},
        {.list = list4, .pop_ele = &var_char, .exp_len = 0, .exp_cap = 3, .is_push = 0, .is_destroy = 0},\

        // pop ele after the length has reached zero.
        {.list = list4, .pop_ele = NULL, .exp_len = 0, .exp_cap = 3, .is_push = 0, .is_destroy = 0},

       
       // destroy List4
       {.list = list4, .exp_len = -1, .exp_cap = -1, .is_destroy = 1},


       
    };

// Running a loop for all test cases to do push or pop based on input operation and to check the returned lenght & capacity 
// matches with expected results.
    for (int i = 0; i < (int)(sizeof(lllifo_test_list)/ sizeof(struct LLLIFO_Test)); i++) {
        // Initial check for destroy case
        if(lllifo_test_list[i].is_destroy)
        {
            lllifo_destroy(lllifo_test_list[i].list);
           
            if ((lllifo_length(lllifo_test_list[i].list) == lllifo_test_list[i].exp_len) && (lllifo_capacity(lllifo_test_list[i].list) 
            == lllifo_test_list[i].exp_cap))
            {
                
                test_passed++;
            }
        }
        // Push case
        else if (lllifo_test_list[i].is_push) {
            
            lllifo_push(lllifo_test_list[i].list, lllifo_test_list[i].push_ele);
            
            if ((lllifo_length(lllifo_test_list[i].list) == lllifo_test_list[i].exp_len) && (lllifo_capacity(lllifo_test_list[i].list) 
            == lllifo_test_list[i].exp_cap))
            {
                test_passed++;
            }
        }
        //pop case
        else {
            
            LLLIFO.act_pop_ele = (char *)lllifo_pop(lllifo_test_list[i].list);
            // printf("Poped element: %s\n",LLLIFO.act_pop_ele);
            if ((lllifo_length(lllifo_test_list[i].list) == lllifo_test_list[i].exp_len) && (lllifo_capacity(lllifo_test_list[i].list) 
            == lllifo_test_list[i].exp_cap) && (LLLIFO.act_pop_ele == (char*)lllifo_test_list[i].pop_ele))
            {
                test_passed++;
            }
        }
        
        total_tests++;
    }
    // Checking for Failed test cases
    if (total_tests == 0 || total_tests != test_passed) {
        printf("Tests failed in LLLIFO: %d passed out of %d", test_passed, total_tests);
    }
    // Printing successful test cases
    else {
        printf("all LLLIFO test cases passed %d/%d\n", test_passed, total_tests);
    }
    return (total_tests == test_passed);
}