#define OK 1
#define ERROR 0

typedef int ElementType;
typedef int Status;

typedef struct Node_
{
	ElementType data;
	struct Node_ *next;	
} Node, *QueuePtr;

typedef struct
{
	QueuePtr front, rear;
} Queue;

void QueueInit(Queue *q);

Status EnQueue(Queue *q, ElementType e);

Status DeQueue(Queue *q, ElementType *e);

Status QueueEmpty(Queue *q);


