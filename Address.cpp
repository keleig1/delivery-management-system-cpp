#include "Address.h"
#include "Exceptions.h"
#include <sstream>
Address::Address() = default;
Address::Address(
    const string& street,
    const string& number,
    const string& neighborhood,
    const string& city,
    const string& state,
    const string& postalCode,
    const string& complement
)
    : street(street),
      number(number),
      neighborhood(neighborhood),
      city(city),
      state(state),
      postalCode(postalCode),
      complement(complement){
    if(!isValid()){
        throw ValidationException(
            "street, number, neighborhood, city, state and postal code"
        );
    }
    }
const string& Address::getStreet()const{
    return street;
}
const string& Address::getNumber()const{
    return number;
}
const string& Address::getNeighborhood()const{
    return neighborhood;
}
const string&Address:: getComplement()const{
    return complement;
}
const string& Address::getCity()const{
    return city;
}
const string& Address::getPostalCode()const{
    return postalCode;
}
const string& Address::getState()const{
    return state;
}
bool Address::isValid() const{
    return !street.empty()
        && !number.empty()
        && !neighborhood.empty()
        && !city.empty()
        && !state.empty()
        && !postalCode.empty();
}

std::string Address::toString()const{
    std::ostringstream output;
    output << street << ", " << number;
    if(!complement.empty()){
        output << " - " << complement;
    }
    output << ", " << neighborhood
           << "- " << city << " - " << state
           << ", " << postalCode;
    return output.str();
}