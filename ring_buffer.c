#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "ring_buffer.h"

// Function to initialize the ring buffer
ring_buffer_t *ring_buffer_init(max_data_type cap)
{
    // Allocate memory for the ring buffer structure
    ring_buffer_t *ring_buf = (ring_buffer_t *)malloc(sizeof(ring_buffer_t));

    // Allocate memory for the buffer array
    uint8_t *arr = (uint8_t *)malloc(cap);

    // Check if the memory allocation was successful
    if (arr == NULL)
        return NULL;

    // Initialize ring buffer properties
    ring_buf->array_ptr = arr;   // Pointer to the allocated array
    ring_buf->capacity = cap;    // Maximum capacity of the ring buffer
    ring_buf->length = 0;        // Current length of the buffer (can be used if needed)
    ring_buf->read_ptr = 0;      // Read pointer (starts at 0)
    ring_buf->write_ptr = 0;     // Write pointer (starts at 0)
    return ring_buf;             // Return the initialized buffer
}

// Function to write data to the ring buffer
bool ring_buffer_write(ring_buffer_t *ring_buf, uint8_t data)
{
    bool ret_val = 1; // Variable to store return value

    // Check if the buffer is full (write pointer is one step ahead of the read pointer)
    if (ring_buf->read_ptr == (ring_buf->write_ptr + 1) % (ring_buf->capacity))
        ret_val = 0; // Buffer is full, cannot write data

    // Store the data at the write pointer location
    ring_buf->array_ptr[ring_buf->write_ptr] = data;

    // Move the write pointer forward (wrap around using modulus if it reaches the end)
    ring_buf->write_ptr = (ring_buf->write_ptr + 1) % (ring_buf->capacity);

    return ret_val; // Return 1 if data is written, 0 if the buffer was full
}

// Function to read data from the ring buffer
uint8_t ring_buffer_read(ring_buffer_t *ring_buf)
{
    // Check if the buffer is empty (read pointer equals the write pointer)
    if (ring_buf->read_ptr == ring_buf->write_ptr)
        return '\0'; // Buffer is empty, return null character

    // Temporarily store the data from the read pointer location
    uint8_t temp = (ring_buf->array_ptr[ring_buf->read_ptr]);

    // Move the read pointer forward (wrap around using modulus if it reaches the end)
    ring_buf->read_ptr = (ring_buf->read_ptr + 1) % (ring_buf->capacity);

    return temp; // Return the read data
}

// Function to check if the ring buffer is empty
bool ring_buffer_is_empty(ring_buffer_t *ring_buf)
{
    // If the read and write pointers are the same, the buffer is empty
    if (ring_buf->read_ptr == ring_buf->write_ptr)
        return 1; // Return true (buffer is empty)
    else
        return false; // Return false (buffer is not empty)
}
