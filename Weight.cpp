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
    weight = UNKNOWN_WEIGHT;
    maxWeight = UNKNOWN_WEIGHT;
    assert(validate()==true);
    #ifdef DEBUG
        std::cout << "Weight Object Test: Weight object has just been created" << std::endl;
        dump();
    #endif
}
Weight::Weight(float newWeight) {

    blsKnown     = false;
    bHasMax      = false;
    unitOfWeight = POUND;
    weight = UNKNOWN_WEIGHT;
    maxWeight = UNKNOWN_WEIGHT;
    setWeight(newWeight);
    assert(validate()==true);
    #ifdef DEBUG
        std::cout << "Weight Object Test: Weight object has just been created" << std::endl;
        dump();
    #endif
}
Weight::Weight(UnitOfWeight newUnitOfWeight) noexcept{
    blsKnown     = false;
    bHasMax      = false;
    unitOfWeight = newUnitOfWeight;
    weight = UNKNOWN_WEIGHT;
    maxWeight = UNKNOWN_WEIGHT;
    assert(validate()==true);
    #ifdef DEBUG
        std::cout << "Weight Object Test: Weight object has just been created" << std::endl;
        dump();
    #endif
}
Weight::Weight(float newWeight, UnitOfWeight newUnitOfWeight) {
    blsKnown     = false;
    bHasMax      = false;
    unitOfWeight = newUnitOfWeight;
    weight = UNKNOWN_WEIGHT;
    maxWeight = UNKNOWN_WEIGHT;
    setWeight(newWeight);
    assert(validate()==true);
    #ifdef DEBUG
        std::cout << "Weight Object Test: Weight object has just been created" << std::endl;
        dump();
    #endif
}
Weight::Weight(float newWeight, float newMaxWeight) {
    blsKnown     = false;
    bHasMax      = false;
    unitOfWeight = POUND;
    weight = UNKNOWN_WEIGHT;
    maxWeight = UNKNOWN_WEIGHT;
    setMaxWeight(newMaxWeight);
    setWeight(newWeight);
    assert(validate()==true);
    #ifdef DEBUG
        std::cout << "Weight Object Test: Weight object has just been created" << std::endl;
        dump();
    #endif
}
Weight::Weight(UnitOfWeight newUnitOfWeight, float newMaxWeight){
    blsKnown     = false;
    bHasMax      = false;
    unitOfWeight = newUnitOfWeight;
    weight = UNKNOWN_WEIGHT;
    maxWeight = UNKNOWN_WEIGHT;
    setMaxWeight(newMaxWeight);
    assert(validate()==true);
    #ifdef DEBUG
        std::cout << "Weight Object Test: Weight object has just been created" << std::endl;
        dump();
    #endif
}
Weight::Weight(float newWeight, UnitOfWeight newUnitOfWeight, float newMaxWeight){
    blsKnown     = false;
    bHasMax      = false;
    unitOfWeight = newUnitOfWeight;
    weight = UNKNOWN_WEIGHT;
    maxWeight = UNKNOWN_WEIGHT;
    setMaxWeight(newMaxWeight);
    setWeight(newWeight);

    assert(validate()==true);
    #ifdef DEBUG
        std::cout << "Weight Object Test: Weight object has just been created" << std::endl;
        dump();
    #endif
}
// Converter: This converts all the values given into the correct unit
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

// Determines what conversion is necessary to convert a certain unit to the desired unit
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
    assert( validate() );
    return blsKnown;
}
bool Weight::hasMaxWeight() const noexcept{
    assert( validate() );
    return bHasMax;
}
float Weight::getWeight() const noexcept{
    assert( validate() );
    // Makes it return a unKnown weight which is -1
    if (!isWeightKnown()){
        return UNKNOWN_WEIGHT;
    }
    assert( validate() );
    // Use the switch statement to change the weight to the unit it is supposed to be
    return convertWeight(weight, POUND, unitOfWeight);
}
float Weight::getWeight(UnitOfWeight weightUnits) const noexcept{
    assert( validate() );
    // Makes it return a unKnown weight which is -1
    if (!isWeightKnown()){
        return UNKNOWN_WEIGHT;
    }
    assert( validate() );
    // Use the switch statement to change the weight to the unit it is supposed to be
    return convertWeight(weight, POUND, weightUnits);
}
float Weight::getMaxWeight() const noexcept{
    assert( validate() );
    // Makes it return a unKnown weight which is -1
    if (!hasMaxWeight()){
        return UNKNOWN_WEIGHT;
    }
    // Use the switch statement to change the weight to the unit it is supposed to be
    assert( validate() );
    return convertWeight(maxWeight, POUND, unitOfWeight);
}
Weight::UnitOfWeight Weight::getWeightUnit() const noexcept{
    assert( validate() );
    return unitOfWeight;
}

// Setters of the program
void Weight::setWeight(float newWeight) {
    if(!isWeightValid(newWeight)){
        throw std::out_of_range("Weight Validator: The weight must be greater than 0 or less than the maxWeight");
    }
    weight = convertWeight(newWeight, unitOfWeight, POUND);
    blsKnown = true;
    assert(validate());
}
void Weight::setWeight(float newWeight, UnitOfWeight weightUnits) {
    if(!isWeightValid(newWeight)){
        throw std::out_of_range("Weight Validator: The weight must be greater than 0 or less than the maxWeight");
    }
    unitOfWeight = weightUnits;
    weight = convertWeight(newWeight, unitOfWeight, POUND);
    blsKnown = true;
    assert(validate());
}
void Weight::setMaxWeight(float newMaxWeight) {
    if(!isMaxWeightValid(newMaxWeight)){
        throw std::out_of_range("Max Weight Validator: The weight must be greater than 0");
    }
    // If the max weight has been set and you are trying to reset MaxWeight somehow it should throw an error
    // This should never happen. This is worst case scenario.
    if(bHasMax){
        throw std::logic_error("Max Weight Validator: The max weight must have not been set before");
    }
    Weight::maxWeight = convertWeight(newMaxWeight, unitOfWeight, POUND);
    bHasMax = true;
    assert(validate());
}

// Underneath are validator methods used to validate the setting of the weight and max weight
bool Weight::isWeightValid(float checkWeight) const noexcept {
    if(checkWeight <= 0){
        #ifdef DEBUG
        std::cout << "Test 1" << std::endl;
        #endif
        return false;
    }
    if(bHasMax){
        if(checkWeight >= maxWeight){
            #ifdef DEBUG
            std::cout << "Test 2" << std::endl;
            #endif
            return false;
        }
    }
    return true;
}

bool Weight::isMaxWeightValid(float checkMaxWeight) noexcept {
    if(checkMaxWeight <= 0){
        return false;
    }
    return true;
}
// Uses the other validaters defined up above.
// Also validates that if there is a value defined for weight and max weight then the
// Values for blsKnown is set true, and values for bHasMax is true
bool Weight::validate() const noexcept {
    if ((!isWeightValid(weight) && blsKnown) || (!isMaxWeightValid(maxWeight) && bHasMax)){
        #ifdef DEBUG
        std::cout << "Test 1" << std::endl;
        #endif
        return false;
    }
    if(!bHasMax && maxWeight != UNKNOWN_WEIGHT){
        #ifdef DEBUG
        std::cout << "Test 2" << std::endl;
        #endif
        return false;
    }
    if(!blsKnown && weight != UNKNOWN_WEIGHT){
        #ifdef DEBUG
        std::cout << "Test 3" << std::endl;
        #endif
        return false;
    }
    return true;
}

// Is basically a print method of the object
/* Example of what the print should look like
 * ====================================================
 * Weight    this            0x8b933912
 * Weight    isKnown         false
 * Weight    weight          -1
 * Weight    unitOfWeight    POUND
 * Weight    hasMax          false
 * Weight    maxWeight       -1
 * */
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

// Compare operators to see if the weight value is equal or less than the object given
bool Weight::operator==(const Weight &rhs_Weight) const {
    float lhs_weight = isWeightKnown() ? getWeight(POUND) : 0;
    float rhs_weight = rhs_Weight.isWeightKnown() ? rhs_Weight.getWeight(POUND) : 0;
    assert( validate() );
    return lhs_weight == rhs_weight;
}
bool Weight::operator<(const Weight &rhs_Weight) const {
    float lhs_weight = isWeightKnown() ? getWeight(POUND) : 0;
    float rhs_weight = rhs_Weight.isWeightKnown() ? rhs_Weight.getWeight(POUND) : 0;
    assert( validate() );
    return lhs_weight < rhs_weight;
}

// This operation adds a certain value to the object and returns the object
Weight &Weight::operator+=(float rhs_addToWeight) {
    if(!isWeightKnown()){
        throw std::out_of_range("Adding Error: You may not add to a weight that is undefined");
    }
    float lhs_weight = isWeightKnown() ? getWeight() : 0;
    if(!isWeightValid(lhs_weight+rhs_addToWeight)){
        throw std::invalid_argument("Adding Error: the value is either to high or to small than 0 or the max weight");
    }
    setWeight(lhs_weight+rhs_addToWeight);
    assert( validate() );
    return *this;
}


