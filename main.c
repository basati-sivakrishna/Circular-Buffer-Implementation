/*
if the buffer is full then iam overwritting the data to the next pointer which makes 
available data as 1 character and all data which is not read cant be read
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "ring_buffer.h"
#include "ring_buffer.c"

ring_buffer_t *ring;


void buffer_status_print(ring_buffer_t *ring_buff, ring_buff_status_e status)
{
    printf("capacity: %ld\n", ring_buff->capacity);
    printf("write_ptr: %ld\n", ring_buff->write_ptr);
    printf("read_ptr: %ld\n", ring_buff->read_ptr);
    printf("status: ");
    switch (status)
    {
    case ring_buff_status_e_create_error:
        printf("creation error\n");
        break;
    case ring_buff_status_e_buff_empty:
        printf("buffer empty\n");
        break;
    case ring_buff_status_e_buff_full:
        printf("Buffer full\n");
        break;
    case ring_buff_status_e_write_success:
        printf("write success\n");
        break;
    default:
        printf("Invalid status\n");
        break;
    }
}

int main()
{
    ring = ring_buffer_init(10);
    if (!ring)
        buffer_status_print(ring, ring_buff_status_e_create_error);

    int status = ring_buffer_write(ring, 'a');
    if (!status)
        buffer_status_print(ring, ring_buff_status_e_buff_full);

    status = ring_buffer_write(ring, 'b');
    if (!status)
        buffer_status_print(ring, ring_buff_status_e_buff_full);

    status = ring_buffer_write(ring, 'c');
    if (!status)
        buffer_status_print(ring, ring_buff_status_e_buff_full);

    status = ring_buffer_write(ring, 'd');
    if (!status)
        buffer_status_print(ring, ring_buff_status_e_buff_full);

    status = ring_buffer_write(ring, 'e');
    if (!status)
        buffer_status_print(ring, ring_buff_status_e_buff_full);

    status = ring_buffer_write(ring, 'f');
    if (!status)
        buffer_status_print(ring, ring_buff_status_e_buff_full);

    uint8_t data = ring_buffer_read(ring);
    if (!data)
        buffer_status_print(ring, ring_buff_status_e_buff_empty);

    data = ring_buffer_read(ring);
    if (!data)
        buffer_status_print(ring, ring_buff_status_e_buff_empty);

    data = ring_buffer_read(ring);
    if (!data)
        buffer_status_print(ring, ring_buff_status_e_buff_empty);

    data = ring_buffer_read(ring);
    if (!data)
        buffer_status_print(ring, ring_buff_status_e_buff_empty);

    data = ring_buffer_read(ring);
    if (!data)
        buffer_status_print(ring, ring_buff_status_e_buff_empty);

    printf("test is done\n");

    return 0;
}