# Circular-Buffer-Implementation
Ring Buffer Implementation in C
This repository contains a simple implementation of a Ring Buffer (circular buffer) in C, which is commonly used for buffering data in embedded systems and real-time applications.

Files Included
main.c
This file contains the test or demo program that demonstrates how to initialize, write to, and read from the ring buffer. You can modify this file to test various functionalities.

ring_buffer.h
The header file defining the ring_buffer_t structure, the related function prototypes, and enum status codes used in the implementation.

ring_buffer.c
This file contains the implementation of the ring buffer functionalities such as:
Initialization of the ring buffer
Writing to the buffer
Reading from the buffer
Checking if the buffer is empty


Features
Dynamic Buffer Allocation: The buffer size is dynamically allocated based on the user-provided capacity during initialization.
Wrap-around Pointers: Both the read and write pointers wrap around when they reach the end of the buffer, following the ring buffer pattern.
Status Codes: Enumerated status codes to check buffer states such as "buffer full" or "buffer empty".


Function Descriptions
1. ring_buffer_t* ring_buffer_init(max_data_type cap)
Initializes a ring buffer with a given capacity and returns a pointer to the created buffer. Returns NULL if the memory allocation fails.

2. bool ring_buffer_write(ring_buffer_t* ring_buf, uint8_t data)
Writes a single byte of data into the buffer. Returns true if the operation is successful, and false if the buffer is full.

3. uint8_t ring_buffer_read(ring_buffer_t* ring_buf)
Reads a single byte of data from the buffer. If the buffer is empty, the function returns '\0'.

4. bool ring_buffer_is_empty(ring_buffer_t* ring_buf)
Returns true if the buffer is empty and false otherwise.


