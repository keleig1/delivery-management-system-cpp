#include "MotorBoy.h"
#include "Exceptions.h"
#include <algorithm>
#include <iostream>
MotorBoy::MotorBoy( 
    const string& name,
    const string& phone,
    const string& email,
    const string& cpf,
    const string& motorcyclePlate,
    const Address& currentLocation,
    std::size_t maxActiveDeliveries
)
 : User(name, phone, email),
  cpf(cpf),
  motorcyclePlate(motorcyclePlate),
  available(true),
  currentLocation(currentLocation),
  completedDeliveries(0),
  maxActiveDeliveries(maxActiveDeliveries){
if(cpf.empty()){
    throw ValidationException("CPF field cannot be empty.");
}
if(motorcyclePlate.empty()){
    throw ValidationException("MotorBoy location is invalid.")
}
if(maxActiveDeliveries == 0){
    throw ValidationException(
        "maximum active deliveries must be greater than zero."
    );
}
  }