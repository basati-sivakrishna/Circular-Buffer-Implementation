#ifndef RING_BUFFER_H_
#define RING_BUFFER_H_

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

/******* Macros *********** */

// A macro for demonstration purposes (replace with meaningful macros if needed)
#define macro_test 10

/******* Typedefs ********* */

// Typedef for defining a large unsigned integer data type used for buffer pointers and capacity
typedef long long unsigned int max_data_type;

/******* Structs ********** */

// Structure definition for the ring buffer
typedef struct ring_buffer
{
    uint8_t *array_ptr;          // Pointer to the buffer's internal array
    max_data_type read_ptr;      // Index of the read pointer
    max_data_type write_ptr;     // Index of the write pointer
    max_data_type capacity;      // Capacity of the ring buffer (maximum number of elements)
    max_data_type length;        // Current number of elements in the buffer (optional usage)
} ring_buffer_t;

/******* Enums ************ */

// Enum to represent various status codes for the ring buffer operations
typedef enum ring_buff_status
{
    ring_buff_status_e_create_error,  // Error during buffer creation
    ring_buff_status_e_write_success, // Successful write operation
    ring_buff_status_e_buff_full,     // Buffer is full, write not possible
    ring_buff_status_e_buff_empty     // Buffer is empty, read not possible
} ring_buff_status_e;

/******* Function Declarations *******/

// Function to initialize a ring buffer with a specified capacity
ring_buffer_t *ring_buffer_init(max_data_type cap);

// Function to write data to the ring buffer; returns true on success, false if the buffer is full
bool ring_buffer_write(ring_buffer_t *ring_buf, uint8_t data);

// Function to read data from the ring buffer; returns the read byte, or '\0' if the buffer is empty
uint8_t ring_buffer_read(ring_buffer_t *ring_buf);

// Function to check if the ring buffer is empty; returns true if empty, false otherwise
bool ring_buffer_is_empty(ring_buffer_t *ring_buf);

#endif // RING_BUFFER_H_
