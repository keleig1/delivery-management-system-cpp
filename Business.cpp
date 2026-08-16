#include "Business.h"
#include "Exceptions.h"
#include <ostream>

Business::Business(
    const string& contactName,
    const string& phone,
    const string& email,
    const string& cnpj,
    const string& companyName,
    const Address& businessAddress
)
    : User(contactName, phone, email),
      cnpj(cnpj),
      companyName(companyName),
      businessAddress(businessAddress){
        if(cnpj.empty()){
            throw ValidationException("CNPJ cannot be empty.");
        }
        if(companyName.empty()){
            throw ValidationException("business address is invalid.");
        }
        if(!businessAddress.isValid()){
            throw ValidationException("business address is invalid");
        }
      }
const std::string& Business::getCnpj()const{
    return cnpj;
}
const string& Business::getCompanyName()const{
    return companyName;
}
const Address& Business::getBusinessAddress()const{
    return businessAddress;
}
void Business::setBusinessAddress(const Address& address){
    if(!address.isValid()){
        throw ValidationException("Business address is invalid.");
    }
    businessAddress = address;
}
int Business::getRequesterId()const{
    return getId();
}
const std::string& Business::getRequesterName()const{
    return companyName;
}
const Address& Business::getDefaultPickupAddress()const{
    return businessAddress;
}
UserType Business::getType()const{
    return UserType::Business;
}
void Business::display(std::ostream& output)const{
    output << "[Business]";
    printCommonData(output);
    output << " | CNPJ: " << cnpj
           << " | company: " << companyName
           << " | Address: "  << businessAddress.toString();
}