#ifndef QUEUE_H
#define QUEUE_H
#include "status.h"


typedef void* QUEUE;

struct Queue *createQueue();
struct QNode* newNode(int k);
void enQueue(struct Queue *q, int k);
struct QNode *deQueue(struct Queue *q);
struct QNode *front(struct Queue *q);
struct QNode *next(struct Queue *q);

#endif