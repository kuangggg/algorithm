#define MAX_SIZE 5
#define OK 1
#define FAIL 0

typedef int ElementType;
typedef int Status;

typedef struct {
	
	int front;	
	int rear;
	
	ElementType data[MAX_SIZE];

} Queue;


Status InitQueue(Queue *q);

Status QueueFull(Queue *q);
Status QueueEmpty(Queue *q);

Status EnQueue(Queue *q, ElementType e);
Status DeQueue(Queue *q, ElementType *e);






