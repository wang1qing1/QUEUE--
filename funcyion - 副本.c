#include"QUEUE.h"

void QInit(Queue* queue)
{
	queue->head = NULL;
	queue->tail = NULL;
}

void QueuePrintf(Queue* queue)
{
	assert(queue);
	Queue* cur = queue;
	while (cur->head)
	{
		printf("%d ", cur->head->data);
		cur->head = cur->head->next;
	}
}

void QueuePush(Queue*queue, int x)
{
	assert(queue);
	QueueData* newnode = (QueueData*)malloc(sizeof(QueueData));
	newnode->data = x;
	newnode->next = NULL;
	if (queue->head == NULL)
	{
		queue->head = newnode;
		queue->tail = queue->head;
	}
	else
	{
		queue->tail->next = newnode;
		queue->tail = newnode;
	}
}

void QueueDestoy(Queue* queue)
{
	assert(queue);
	QueueData* cur = queue->head;
	while (cur)
	{
		QueueData* next = cur->next;
		free(cur);
		cur = next;
	}
	queue->head = queue->tail = NULL;
}