#include <stdlib.h>
#include <stdbool.h>
#include "IsraeliQueue.h"

typedef Node queuePosition;

struct IsraeliQueue_t {
    FriendshipFunction* funcs;
    ComparisonFunction compare;
    int friendshipThreshold;
    int rivalryThreshold;
    queuePosition start;                                                                                  
};

IsraeliQueue IsraeliQueueCreate(FriendshipFunction* funcs, ComparisonFunction compare, int friendshipThreshold, 
int rivalryThreshold) {
    // we need to return a pointer to a new object of type IsraeliQueue_t
    // and so we must dynamically allocate. If we wont be able to use our new object because it is
    // scoped to this function only
    IsraeliQueue q = malloc(sizeof(*q));
    if (q == NULL) {
        return NULL; // FAILURE
    }
    q->friendshipThreshold = friendshipThreshold;
    q->rivalryThreshold = rivalryThreshold;
    q->compare = compare;
    q->start = NULL;
    // the field funcs in IsraeliQueue_t is an array but we need to have it dynamically allocated
    // in our new object because it has a function that changes the array's size later on

    // maybe put the following in a helper function:
    FriendshipFunction* friendshipFuncs = malloc(funcs);
    if (friendshipFuncs == NULL) {
        return NULL; // FAILURE
    }
    // copy over values:
    int i = 0;
    while (true)
    {
        if (funcs[i] == NULL) {
            friendshipFuncs[i] = funcs[i];
            break;
        }
        friendshipFuncs[i] = funcs[i];
        i++;
    }
    q->funcs = friendshipFuncs;
}

