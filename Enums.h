#ifndef DELIVERY_SYSTEM_ENUMS_H
#define DELIVERY_SYSTEM_ENUMS_H
#include <stdexcept>
#include <string>
#include "DeliveryQueueItem.h"
enum class UserType{
    Client,
    Business,
    MotorBoy
};
enum class DeliveryStatus{
    Pending, 
    Assigned,
    InProgress, 
    Delivered,
    Cancelled
};
enum class DeliveryPriority {
    Low,
    Normal,
    High,
    Urgent
};
inline std::string toString(UserType type){
    switch(type){
        case UserType::Client:
            return "CLIENT";
        case UserType::Business:
            return "BUSINESS";
        case UserType::MotorBoy:
            return "MOTORBOY"; 
    }
    throw std::invalid_argument("Unknown user type.");
}

inline std::string toString(DeliveryStatus status){
    switch(status){
        case DeliveryStatus::Pending:
            return "PENDING";
        case DeliveryStatus::Assigned:
            return "ASSIGNED";
        case DeliveryStatus::InProgress:
            return "IN_PROGRESS";
        case DeliveryStatus::Cancelled: 
            return "CANCELLED";
    }
    throw std::invalid_argument("unknown delivery status.");
}
inline std::string toString(DeliveryPriority priority){
    switch (priority){
        case DeliveryPriority::Low:
            return "LOW";
        case DeliveryPriority::Normal:
            return "NORMAL";
        case DeliveryPriority::High:
            return "HIGH";
        case DeliveryPriority::Urgent:
            return "URGENT";
        default:
            throw std::invalid_argument("Unknown delivery priority.");
    }
}
inline DeliveryStatus deliveryStatusFromString(const std::string& value){
    if(value == "PENDING"){
        return DeliveryStatus::Pending;
    }
    if(value == "ASSIGNED"){
        return DeliveryStatus::Assigned;
    }
    if(value == "IN_PROGRESS"){
        return DeliveryStatus::InProgress;
    }
    if(value == "DELIVERED"){
        return DeliveryStatus::Delivered;
    }
    if(value == "CANCELLED"){
        return DeliveryStatus::Cancelled;
    }
    throw std::invalid_argument("invalid delivery status" + value);
}
inline DeliveryPriority deliveryPriorityFromString(
    const std::string& value
){
    if(value == "LOW"){
        return DeliveryPriority::Low;
    }
    if(value == "NORMAL"){
        return DeliveryPriority::Normal;
    }
    if(value == "HIGH"){
        return DeliveryPriority::High;
    }
    if(value == "URGENT"){
        return DeliveryPriority::Urgent;
    }
    throw std::invalid_argument("Invalid delivery priority: " + value);
}
#endif