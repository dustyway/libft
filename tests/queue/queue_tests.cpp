#include <catch2/catch_all.hpp>

extern "C" {
#include "queue.h"
}

TEST_CASE( "CHECK the basic functionality of t_queue", "[queue]" ) {
    t_queue *q;
    int a = 1;
    int b = 2;
    int c = 3;
    int *ap = (int *)malloc(sizeof(int));
    int *bp = (int *)malloc(sizeof(int));
    int *cp = (int *)malloc(sizeof(int));
    int *ip;

    init_queue(&q,free);
    CHECK( queue_peek(q) == NULL);
    CHECK( queue_size(q) == 0);
    enqueue(q,&a);
    CHECK( queue_peek(q) == &a);
    CHECK( *((int *)queue_peek(q)) == 1);
    CHECK( queue_size(q) == 1);
    enqueue(q,&b);
    enqueue(q,&c);
    CHECK( queue_size(q) == 3);
    CHECK( queue_peek(q) == &a);
    ip = (int *) dequeue(q);
    CHECK( ip == &a);
    CHECK( queue_size(q) == 2);
    CHECK( queue_peek(q) == &b);
    CHECK( queue_is_empty(q) == 0);
    CHECK( *(int *)dequeue(q) == 2);
    CHECK( *(int *)dequeue(q) == 3);
    CHECK( queue_is_empty(q) == 1);
    enqueue(q,ap);
    enqueue(q,bp);
    enqueue(q,cp);
    clear_queue(&q);
    CHECK( q == NULL);
}

TEST_CASE( "CHECK dequeue_nth", "[queue]" ) {
    t_queue *q;
    int a = 1;
    int b = 2;
    int c = 3;
    int d = 4;
    int *ip;

    init_queue(&q, NULL);
    CHECK( queue_peek(q) == NULL);
    CHECK( queue_size(q) == 0);
    enqueue(q,&a);
     CHECK( queue_peek(q) == &a);
     CHECK( *((int *)queue_peek(q)) == 1);
     CHECK( queue_size(q) == 1);
     enqueue(q,&b);
     enqueue(q,&c);
     enqueue(q,&d);
     CHECK( queue_size(q) == 4);
    CHECK( queue_peek(q) == &a);
    ip = (int *) dequeue_nth(q,4);
    CHECK( ip == NULL);
    CHECK( queue_size(q) == 4);
    ip = (int *) dequeue_nth(q,3);
    CHECK( ip == &d);
     CHECK( queue_size(q) == 3);
      CHECK( queue_peek(q) == &a);
     CHECK( queue_peek_n(q, 1) == &b);
     CHECK( queue_peek_n(q, 2) == &c);
    CHECK( q->back->content == &c);
    enqueue(q,&d);
    CHECK( queue_size(q) == 4);
    CHECK( q->back->content == &d);
    ip = (int *) dequeue_nth(q,2);
    CHECK( ip == &c);
    CHECK( queue_size(q) == 3);

     CHECK( queue_is_empty(q) == 0);
    ip = (int *) dequeue_nth(q,0);
    CHECK( ip == &a);
    ip = (int *) dequeue_nth(q,1);
    CHECK( ip == &d);
    ip = (int *) dequeue_nth(q,0);
    CHECK( ip == &b);
    CHECK( queue_is_empty(q) == 1);
     clear_queue(&q);
     CHECK( q == NULL);
}

