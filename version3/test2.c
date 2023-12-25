#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for the queue node
typedef struct Node
{
    char data[100]; // Assuming a fixed size for the string, adjust as needed
    struct Node *next;
} Node;

// Define a structure for the queue
typedef struct Queue
{
    Node *front;
    Node *rear;
} Queue;

// Function to initialize a queue
void initializeQueue(Queue *queue)
{
    queue->front = queue->rear = NULL;
}

// Function to check if a queue is empty
int isQueueEmpty(Queue *queue)
{
    return queue->front == NULL;
}

// Function to enqueue a new element to the queue
void enqueue(Queue *queue, const char *data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("Memory allocation error\n");
        exit(EXIT_FAILURE);
    }

    strncpy(newNode->data, data, sizeof(newNode->data) - 1);
    newNode->data[sizeof(newNode->data) - 1] = '\0'; // Ensure null-terminated

    newNode->next = NULL;

    if (isQueueEmpty(queue))
    {
        queue->front = queue->rear = newNode;
    }
    else
    {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

// Function to dequeue an element from the queue
char *dequeue(Queue *queue)
{
    if (isQueueEmpty(queue))
    {
        printf("Queue is empty\n");
        exit(EXIT_FAILURE);
    }

    char *data = strdup(queue->front->data);
    if (data == NULL)
    {
        printf("Memory allocation error\n");
        exit(EXIT_FAILURE);
    }

    Node *temp = queue->front;

    if (queue->front == queue->rear)
    {
        queue->front = queue->rear = NULL;
    }
    else
    {
        queue->front = queue->front->next;
    }

    free(temp);
    return data;
}

// Function to display the contents of a queue
void displayQueue(Queue *queue)
{
    Node *current = queue->front;
    while (current != NULL)
    {
        printf("%s ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main()
{
    // Define the size of the array
    int arraySize = 5;

    // Create an array of pointers to queues
    Queue *array[arraySize];

    // Initialize each queue in the array
    for (int i = 0; i < arraySize; i++)
    {
        array[i] = (Queue *)malloc(sizeof(Queue));
        initializeQueue(array[i]);
    }

    // Enqueue some elements to the queues for demonstration
    const char *strings[] = {"apple", "banana", "cherry", "date", "elderberry"};

    for (int i = 0; i < arraySize; i++)
    {
        enqueue(array[i], strings[i]);
        enqueue(array[i], strings[i + 1]);
    }

    // Display the contents of each queue
    for (int i = 0; i < arraySize; i++)
    {
        printf("Queue %d: ", i + 1);
        displayQueue(array[i]);
    }

    // Dequeue elements from each queue for demonstration
    for (int i = 0; i < arraySize; i++)
    {
        char *dequeuedString = dequeue(array[i]);
        printf("Dequeue from Queue %d: %s\n", i + 1, dequeuedString);
        free(dequeuedString);
    }

    return 0;
}
