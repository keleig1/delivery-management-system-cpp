#ifndef DELIVERY_SYSTEM_EXCEPTIONS_H
#define DELIVERY_SYSTEM_EXCEPTIONS_H

#include "Enums.h"

#include <stdexcept>
#include <string>

class DeliverySystemException : public std::runtime_error {
public:
    explicit DeliverySystemException(const std::string& message)
        : std::runtime_error(message) {}
};

class ValidationException : public DeliverySystemException {
public:
    explicit ValidationException(const std::string& message)
        : DeliverySystemException("Validation error: " + message) {}
};

class UserNotFoundException : public DeliverySystemException {
public:
    explicit UserNotFoundException(int userId)
        : DeliverySystemException(
              "User with ID " + std::to_string(userId) + " was not found."
          ) {}
};

class DeliveryNotFoundException : public DeliverySystemException {
public:
    explicit DeliveryNotFoundException(int deliveryId)
        : DeliverySystemException(
              "Delivery with ID " + std::to_string(deliveryId)
              + " was not found."
          ) {}
};

class DuplicateDocumentException : public DeliverySystemException {
public:
    explicit DuplicateDocumentException(const std::string& document)
        : DeliverySystemException(
              "A user with document " + document + " is already registered."
          ) {}
};

class InvalidStatusTransitionException : public DeliverySystemException {
public:
    InvalidStatusTransitionException(
        DeliveryStatus currentStatus,
        DeliveryStatus requestedStatus
    )
        : DeliverySystemException(
              "Invalid delivery status transition from "
              + toString(currentStatus) + " to "
              + toString(requestedStatus) + "."
          ) {}
};

class MotorBoyUnavailableException : public DeliverySystemException {
public:
    explicit MotorBoyUnavailableException(int motorBoyId)
        : DeliverySystemException(
              "MotorBoy with ID " + std::to_string(motorBoyId)
              + " is unavailable."
          ) {}
};

class PersistenceException : public DeliverySystemException {
public:
    explicit PersistenceException(const std::string& message)
        : DeliverySystemException("Persistence error: " + message) {}
};

#endif