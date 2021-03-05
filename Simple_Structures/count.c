#ifndef count_c
#define count_c

typedef struct count
{   
    int stCount; //Stack count
    int qeCount; //Queue count
    int snCount; //Singly linked list count
    int doCount; //Doubly linked list count
    int crCount; //Circular linked list count

}count;

void initializeCounts(count *c)
{
    //Initialize the counters
    c->stCount = c->qeCount = c->snCount = c->doCount = c->crCount = 0;
}

#endif