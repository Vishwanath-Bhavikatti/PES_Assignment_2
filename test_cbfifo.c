#include<stdio.h>
#include<string.h>
#include<stddef.h>
#include "test_cbfifo.h"
#include "cbfifo.h"

// defining a structure for test case which contains test parameters
struct CBFIFO_Test
{
    void *enqueue_ele;
    void *dequeue_ele;
    size_t nbytes;
    
    char act_dequeue_ele;

    size_t exp_len;
    //int exp_cap;
    int is_enqueue;
    int is_all_deq;
    
}CBFIFO;

/*
*********************************************************************************************************************
​ *
​ ​*​ ​@author​ :​Vishwanath Bhavikatti
​ ​*​ ​@date​ :Februrary 6, 2023 
 * @file name : test_cbfifo.c
 * @file_description: structure is defined for writing test cases to check the successful working of CBFIFO.C function.
 *                    All corner cases are being tested as per my bandwidth.
 * return : returns 1 in case of all test cases being passed
 * 
*************************************************************************************************************************
*/
int test_cbfifo()
{
    //const int capacity = cbfifo_capacity();
    char deq[1024];
    //CBFIFO.dequeue_ele = &deq;
    //size_t act_enq_ret = 0;
    size_t act_deq_ret = 0;

    // Random data from internet is pushed to the string for enqueue and dequeue purpose

    char *buf = "In the early medieval era Christianity Islam Judaism and Zoroastrianism \n"
    "became established on India's southern and western coasts.[42] Muslim armies from Central \n"
    "Asia intermittently overran India's northern plains,[43] eventually founding the Delhi Sultanate, \n"
    "and drawing northern India into the cosmopolitan networks of medieval Islam.[44] In the 15th century, \n"
    "the Vijayanagara Empire created a long-lasting composite Hindu culture in south India.[45] \n"
    "In the Punjab, Sikhism emerged, rejecting institutionalised religion.[46] The Mughal Empire, in 1526, \n"
    "ushered in two centuries of relative peace,[47] leaving a legacy of luminous architecture. \n";
    
    int test_passed = 0;
    int total_tests = 0;


    struct CBFIFO_Test cbfifo_test_list[] = {

        // Each structure represents a test case
        // Below test cases for List with capacity 5

        // dequeue before any enqueue operation
        {.dequeue_ele = (void*)deq, .nbytes = 1, .exp_len = 0, .is_enqueue = 0},
        //Enqueue 10 elements into the queue
        {.enqueue_ele = buf, .nbytes = 10 , .exp_len = 10, .is_enqueue = 1},
        // Dequeue all 10 elements
        {.dequeue_ele = (void*)deq, .nbytes = 10, .exp_len = 0, .is_enqueue = 0, .is_all_deq = 1},

        //Enqueue till the full capacity 
        {.enqueue_ele = buf, .nbytes = 256 , .exp_len = 256, .is_enqueue = 1},
        //Dequeue all elements
        {.dequeue_ele = (void*)deq, .nbytes = 256, .exp_len = 0, .is_enqueue = 0, .is_all_deq = 1},


        //Enque elements in different lengths
        {.enqueue_ele = buf, .nbytes = 10 , .exp_len = 10, .is_enqueue = 1},
        {.enqueue_ele = buf+10, .nbytes = 30 , .exp_len = 40, .is_enqueue = 1},
        {.enqueue_ele = buf+40, .nbytes = 40 , .exp_len = 80, .is_enqueue = 1},
        {.enqueue_ele = buf+80, .nbytes = 25 , .exp_len = 105, .is_enqueue = 1},
       // Dequeue elements in different lengths
        {.dequeue_ele = (void*)deq, .nbytes = 20, .exp_len = 85, .is_enqueue = 0},
        {.dequeue_ele = (void*)deq+20, .nbytes = 10, .exp_len = 75, .is_enqueue = 0},
        {.dequeue_ele = (void*)deq+30, .nbytes = 40, .exp_len = 35, .is_enqueue = 0},
        {.dequeue_ele = (void*)deq+70, .nbytes = 20, .exp_len = 15, .is_enqueue = 0},
        {.dequeue_ele = (void*)deq+90, .nbytes = 15, .exp_len = 0, .is_enqueue = 0, .is_all_deq = 1 },

        // enqueue all 256 elements
        {.enqueue_ele = buf, .nbytes = 256 , .exp_len = 256, .is_enqueue = 1},
        // enqueue exceeding MAX_SIZE of queue
        {.enqueue_ele = buf, .nbytes = 1 , .exp_len = 256, .is_enqueue = 1},

        {.dequeue_ele = (void*)deq, .nbytes = 256, .exp_len = 0, .is_enqueue = 0, .is_all_deq = 1 },

    };
   


// Running a loop for all test cases to do push or pop based on input operation and to check the returned lenght & capacity 
// matches with expected results.
    for (int i = 0; i < (int)(sizeof(cbfifo_test_list) / sizeof(struct CBFIFO_Test)); i++) {
        // case when enqueue is done
        if(cbfifo_test_list[i].is_enqueue)
        {
            cbfifo_enqueue(cbfifo_test_list[i].enqueue_ele,cbfifo_test_list[i].nbytes);
           
            if ((cbfifo_length() == cbfifo_test_list[i].exp_len))
            {
                test_passed++;
            }
        }
        //case when dequeue is done
        else {
            
            act_deq_ret = cbfifo_dequeue(cbfifo_test_list[i].dequeue_ele,cbfifo_test_list[i].nbytes);
            if(cbfifo_test_list[i].is_all_deq)
            {
               if (cbfifo_length() == cbfifo_test_list[i].exp_len && (strncmp(deq,buf,act_deq_ret) == 0 ))
                {
                    test_passed++;   
                } 
            }

            if ((cbfifo_test_list[i].is_all_deq == 0) && cbfifo_length() == cbfifo_test_list[i].exp_len )
            {
                test_passed++;
            }
        }
        total_tests++;
    }
// Checking for Failed test cases
    if (total_tests == 0 || total_tests != test_passed) {
        printf("Tests failed in CBFIFO: %d passed out of %d", test_passed, total_tests);
    }
    // Printing successful test cases
    else {
        printf("all CBFIFO test cases passed %d/%d\n", test_passed, total_tests);
    }
    return (total_tests == test_passed);
}