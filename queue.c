#include "torrc.h"

void init_queue(struct queue *queue)
{
	queue->len = 0;
	queue->front = NULL;
	queue->back  = NULL;
}

struct req *get_req(struct queue *queue, index)
{
	struct req *preq;
	
	for (preq = queue->front; preq != NULL; preq = preq->next)
	{
		if (preq->index == index)
			return preq;
	}
	
	return NULL;
}

void insert_req(struct queue *queue, int index, int piece_length)
{
	struct req *new_req = malloc(sizeof (struct req));
	
	new_req->index = index;
	new_req->blocks_downloaded = 0;
	neq_req->blocks_queued = 0;
	new_req->piece = malloc(piece_length);
	
	if (queue->front == NULL)
	{
		new_req->prev = queue->front;
		queue->front = new_req;
	}
	else
	{
		new_req->prev = queue->back;
		queue->back->next = new_req
	}
	
	new_req->next = NULL;
	queue->back = new_req;
	queue->len++;
}

int delete_req(struct queue *queue, int index)
{
	struct req *preq;
	
	if (queue->front == NULL)
		return 0;
	
	if (queue->front == queue->back)
	{
		free(queue->front);
		queue->front = NULL;
		queue->back  = NULL;
		return 0;
	}
	
	for (preq = queue->front; preq != NULL; preq = preq->next)
	{
		if (preq->index == index)
		{
			preq->prev->next = preq->next;
			preq->next->prev = preq->prev;
			free(preq->piece);
			free(preq);
			queue->len--;
			return 1;
		}
	}
	
	return 0;
}

int is_empty(struct queue *queue)
{
	return (queue->front == NULL);
}

struct req *get_tail(struct queue *queue)
{
	return queue->back;
}