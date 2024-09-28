// To Run on local machine add the #include files

typedef struct Node {
    int data;
    struct Node *prev, *next;
} Node;


typedef struct {
    int size, cur;
    Node* front,* rear;
} MyCircularDeque;

typedef MyCircularDeque Deq;

Node* createNode(int val) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = val; node->prev = node->next = NULL;

    return node;
}

void firstNode(int val, Deq* deq) {
    Node* node = createNode(val);
    deq->front = deq->rear = node;
}

MyCircularDeque* myCircularDequeCreate(int k) {
    Deq* deq = (Deq*)malloc(sizeof(Deq));

    deq->size = k; deq->cur = 0;
    deq->front = deq->rear = NULL;

    return deq;
}

bool myCircularDequeInsertFront(MyCircularDeque* obj, int value) {
    if (obj->cur == obj->size) return false;
    if (obj->front == NULL) firstNode(value, obj);
    else {
        Node* node = createNode(value);

        obj->front->prev = node; node->next = obj->front;
        obj->front = node;
    }

    obj->cur++; return true;
}

bool myCircularDequeInsertLast(MyCircularDeque* obj, int value) {
    if (obj->cur == obj->size) return false;
    if (obj->front == NULL) firstNode(value, obj);
    else {
        Node* node = createNode(value);

        obj->rear->next = node; node->prev = obj->rear;
        obj->rear = node;
    }

    obj->cur++; return true;   
}

bool myCircularDequeDeleteFront(MyCircularDeque* obj) {
    if (obj->front == NULL) return false;
    Node* node = obj->front;

    if (obj->cur == 1) {
        obj->front = obj->rear = NULL;
    } else {
        obj->front = node->next;
        obj->front->prev = NULL;
    }

    free(node); obj->cur--; return true;
}

bool myCircularDequeDeleteLast(MyCircularDeque* obj) {
    if (obj->rear == NULL) return false;
    Node* node = obj->rear;

    if (obj->cur == 1) {
        obj->front = obj->rear = NULL;
    } else {
        obj->rear = node->prev;
        obj->rear->next = NULL;
    }

    free(node); obj->cur--; return true;
}

int myCircularDequeGetFront(MyCircularDeque* obj) {
    return (!obj->front) ? -1 : obj->front->data;
}

int myCircularDequeGetRear(MyCircularDeque* obj) {
    return (!obj->rear) ? -1: obj->rear->data;
}

bool myCircularDequeIsEmpty(MyCircularDeque* obj) {
    return (obj->front == NULL);
}

bool myCircularDequeIsFull(MyCircularDeque* obj) {
    return (obj->size == obj->cur);
}

void myCircularDequeFree(MyCircularDeque* obj) {
    Node* node = obj->front;

    while (node) {
        Node* temp = node;
        node = node->next; free(temp);
    }

    free(obj);
}
