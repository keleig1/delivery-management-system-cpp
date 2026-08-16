#ifndef DELIVERY_SYSTEM_DELIVERY_QUEUE_ITEM_H
#define DELIVERY_SYSTEM_DELIVERY_QUEUE_ITEM_H
#include "Enums.h"
#include <cstdint>
inline int priorityRank(DeliveryPriority priority){
    switch (priority)
    {
    case DeliveryPriority::Low:
        return 1;
    case DeliveryPriority::Normal:
        return 2;
    case DeliveryPriority::High:
        return 3;
    case DeliveryPriority::Urgent:
        return 4;
    }
    return 0; 
}

struct  DeliveryQueueItem{
    int deliveryId;
    DeliveryPriority priority;
    std::uint64_t requestOrder;

    bool operator<(const DeliveryQueueItem other) const{
        const int thisPriority = priorityRank(priority);
        const int otherPriority = priorityRank(other.priority);
        if(thisPriority != otherPriority){
            return thisPriority < otherPriority;
        }
        // std::priority_queue places the "largest" item first. For equal
        // priorities, a smaller requestOrder represents an earlier request.
        return requestOrder > other.requestOrder;
    }
};
#endif
