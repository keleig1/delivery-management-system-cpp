#ifndef DELIVERY_SYSTEM_STATUS_EVENT_H
#define DELIVERY_SYSTEM_STATUS_EVENT_H

#include "Enums.h"

#include <string>

// Kept as an aggregate so it can use aggregate initialization.
struct StatusEvent {
    DeliveryStatus status;
    std::string timestamp;
    std::string note;
};

#endif