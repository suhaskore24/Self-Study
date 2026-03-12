#include <stdio.h>
#include <stdint.h>

typedef struct
{
    uint8_t *buf;
    int head;
    int tail;
    int size;
}ring_buffer_t;

int rb_init(ring_buffer_t *rb,uint8_t *buffer,int size)
{
    rb->buf = buffer;
    rb->size = size;
    rb->head = rb->tail = 0;
    return 0;
}

int rb_push(ring_buffer_t *rb,uint8_t data)
{
    int next = (rb->head+1)%rb->size;

    if(next == rb->tail)
        return -1;

    rb->buf[rb->head] = data;
    rb->head = next;
    return 0;
}

int rb_pop(ring_buffer_t *rb,uint8_t *data)
{
    if(rb->head == rb->tail)
        return -1;

    *data = rb->buf[rb->tail];
    rb->tail = (rb->tail+1)%rb->size;

    return 0;
}
