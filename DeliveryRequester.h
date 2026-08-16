#ifndef DELIVERY_SYSTEM_DELIVERY_REQUESTER_H
#define DELIVERY_SYSTEM_DELIVERY_REQUESTER_H
#include "Address.h"
#include <string>

class DeliveryRequester{
    public:
        virtual ~DeliveryRequester() = default;
        virtual int getRequesterId() const = 0;
        virtual const std::string& getRequesterName() const = 0;
        virtual const Address& getDefaultPickupAddress() const = 0;
};
#endif