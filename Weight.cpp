///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab12a_fatCat - EE 205 - Spr 2022
///
/// @file Weight.cpp
/// @version 1.0
///
/// @author Kobe Uyeda <kobek@hawaii.edu>
/// @date   14_Apr_2022
///////////////////////////////////////////////////////////////////////////////

#include "Weight.h"
#include <stdexcept>
#include <iostream>
#include <iomanip>
#include <cassert>


#define FORMAT_LINE(className, member) std::cout << std::setw(10) << (className) << std::setw(20) << (member) << std::setw(52)

// Defining the constants for the class
const float Weight::UNKNOWN_WEIGHT   = -1;
const float Weight::KILOS_IN_A_POUND = 0.453592;
const float Weight::SLUGS_IN_A_POUND = 0.031081;

const std::string Weight::POUND_LABEL = "Pound";
const std::string Weight::KILO_LABEL  = "Kilo";
const std::string Weight::SLUG_LABEL  = "Slug";


// Everything underneath is a constructor for the weight class
Weight::Weight() noexcept {
    blsKnown     = false;
    bHasMax      = false;
    unitOfWeight = POUND;
    assert(validate()==true);
}
Weight::Weight(float newWeight) {

    bHasMax      = false;
    unitOfWeight = POUND;
    setWeight(newWeight);
    assert(validate()==true);
}
Weight::Weight(UnitOfWeight newUnitOfWeight) noexcept{
    blsKnown     = false;
    bHasMax      = false;
    unitOfWeight = newUnitOfWeight;
    assert(validate()==true);
}
Weight::Weight(float newWeight, UnitOfWeight newUnitOfWeight) {
    bHasMax      = false;
    unitOfWeight = newUnitOfWeight;
    setWeight(newWeight);
    assert(validate()==true);
}
Weight::Weight(float newWeight, float newMaxWeight) {

    setMaxWeight(newMaxWeight);
    unitOfWeight = POUND;
    setWeight(newWeight);
    assert(validate()==true);
}
Weight::Weight(UnitOfWeight newUnitOfWeight, float newMaxWeight){
    blsKnown     = false;
    unitOfWeight = newUnitOfWeight;
    setMaxWeight(newMaxWeight);
    assert(validate()==true);
}
Weight::Weight(float newWeight, UnitOfWeight newUnitOfWeight, float newMaxWeight){
    unitOfWeight = newUnitOfWeight;
    setMaxWeight(newMaxWeight);
    setWeight(newWeight);

    assert(validate()==true);
}

float Weight::fromKilogramToPound(float kilogram) noexcept {
    return kilogram / KILOS_IN_A_POUND;
}
float Weight::fromPoundToKilogram(float pound) noexcept {
    return pound * KILOS_IN_A_POUND;
}
float Weight::fromSlugToPound(float slug) noexcept {
    return slug / SLUGS_IN_A_POUND;
}
float Weight::fromPoundToSlug(float pound) noexcept {
    return pound * SLUGS_IN_A_POUND;
}
float Weight::convertWeight(float fromWeight, UnitOfWeight fromUnit, UnitOfWeight toUnit) noexcept {
    float convertedUnitToPound;
    switch(fromUnit){
        case POUND :  convertedUnitToPound = fromWeight;
            break;
        case KILO  :  convertedUnitToPound = fromKilogramToPound(fromWeight);
            break;
        case SLUG  :  convertedUnitToPound = fromSlugToPound(fromWeight);
            break;
    }
    float convertedUnitWeight;
    switch(toUnit){
        case POUND : convertedUnitWeight = convertedUnitToPound;
            break;
        case KILO  : convertedUnitWeight = fromPoundToKilogram(convertedUnitToPound);
            break;
        case SLUG  : convertedUnitWeight = fromPoundToSlug(convertedUnitToPound);
            break;
    }
    return convertedUnitWeight;
}


// Everything is the getters for the weight class
bool Weight::isWeightKnown() const noexcept{
    return blsKnown;
}
bool Weight::hasMaxWeight() const noexcept{
    return bHasMax;
}
float Weight::getWeight() const noexcept{
    // Makes it return a unKnown weight which is -1
    if (!isWeightKnown()){
        return UNKNOWN_WEIGHT;
    }
    // Use the switch statement to change the weight to the unit it is supposed to be
    return convertWeight(weight, POUND, unitOfWeight);
}
float Weight::getWeight(UnitOfWeight weightUnits) const noexcept{
    // Makes it return a unKnown weight which is -1
    if (!isWeightKnown()){
        return UNKNOWN_WEIGHT;
    }
    // Use the switch statement to change the weight to the unit it is supposed to be
    return convertWeight(weight, POUND, weightUnits);
}
float Weight::getMaxWeight() const noexcept{
    // When the object is initialized without a max weight it will return a 0
    // Makes it return a unKnown weight which is -1
    if (!hasMaxWeight()){
        return UNKNOWN_WEIGHT;
    }
    // Use the switch statement to change the weight to the unit it is supposed to be
    return convertWeight(maxWeight, POUND, unitOfWeight);
}
Weight::UnitOfWeight Weight::getWeightUnit() const noexcept{
    return unitOfWeight;
}

// Setters of the program
void Weight::setWeight(float newWeight) {
    if(!isWeightValid(newWeight)){
        throw std::out_of_range("Weight Validator: The weight must be greater than 0 or less than the maxWeight");
    }
    weight = convertWeight(newWeight, unitOfWeight, POUND);
    blsKnown = true;
    assert(validate()==true);
}
void Weight::setWeight(float newWeight, UnitOfWeight weightUnits) {
    if(!isWeightValid(newWeight)){
        throw std::out_of_range("Weight Validator: The weight must be greater than 0 or less than the maxWeight");
    }
    unitOfWeight = weightUnits;
    weight = convertWeight(newWeight, unitOfWeight, POUND);
    blsKnown = true;
    assert(validate()==true);
}
void Weight::setMaxWeight(float newMaxWeight) {
    if(!isMaxWeightValid(newMaxWeight)){
        throw std::out_of_range("Max Weight Validator: The weight must be greater than 0");
    }
    if(bHasMax){
        throw std::logic_error("Max Weight Validator: The max weight must have not been set before");
    }
    maxWeight = convertWeight(newMaxWeight, unitOfWeight, POUND);
    bHasMax = true;
    assert(validate()==true);
}

bool Weight::isWeightValid(float checkWeight) const noexcept {
    if(checkWeight <= 0){
        return false;
    }
    if(bHasMax){
        if(checkWeight >= maxWeight){
            return false;
        }
    }
    return true;
}

bool Weight::isMaxWeightValid(float checkMaxWeight) const noexcept {
    if(checkMaxWeight <= 0){
        return false;
    }
    return true;
}
bool Weight::validate() const noexcept {
    if ((!isWeightValid(weight) && blsKnown) || (!isMaxWeightValid(maxWeight) && bHasMax)){
        return false;
    }
    if(!bHasMax && maxWeight != 0){
        return false;
    }
    if(!blsKnown && weight != 0){
        return false;
    }
    return true;
}

void Weight::dump() const noexcept {
    assert( validate() );

    std::cout << std::setw(80) << std::setfill('=') << "" << std::endl;
    std::cout << std::setfill(' ');
    std::cout << std::left;
    std::cout << std::boolalpha;

    FORMAT_LINE("Weight", "this") << this << std::endl;
    FORMAT_LINE("Weight", "isKnown") << isWeightKnown() << std::endl;
    FORMAT_LINE("Weight", "weight") << getWeight() << std::endl;
    FORMAT_LINE("Weight", "unitOfWeight") << getWeightUnit() << std::endl;
    FORMAT_LINE("Weight", "hasMax") << hasMaxWeight() << std::endl;
    FORMAT_LINE("Weight", "maxWeight") << getMaxWeight() << std::endl;

    assert( validate() );
}

bool Weight::operator==(const Weight &rhs_Weight) const {
    float lhs_weight = isWeightKnown() ? getWeight(POUND) : 0;
    float rhs_weight = rhs_Weight.isWeightKnown() ? rhs_Weight.getWeight(POUND) : 0;

    return lhs_weight == rhs_weight;
}
bool Weight::operator<(const Weight &rhs_Weight) const {
    float lhs_weight = isWeightKnown() ? getWeight(POUND) : 0;
    float rhs_weight = rhs_Weight.isWeightKnown() ? rhs_Weight.getWeight(POUND) : 0;

    return lhs_weight < rhs_weight;
}

Weight &Weight::operator+=(float rhs_addToWeight) {
    if(!isWeightKnown()){
        throw std::out_of_range("Adding Error: You may not add to a weight that is undefined");
    }
    float lhs_weight = isWeightKnown() ? getWeight() : 0;
    setWeight(lhs_weight+rhs_addToWeight);
    return *this;
}


