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

// Defining the constants for the class
const float Weight::UNKNOWN_WEIGHT   = -1;
const float Weight::KILOS_IN_A_POUND = 0.453592;
const float Weight::SLUGS_IN_A_POUND = 0.031081;


// Everything underneath is a constructor for the weight class
Weight::Weight() noexcept {
    blsKnown     = false;
    bHasMax      = false;
    unitOfWeight = POUND;
}
Weight::Weight(float newWeight) {
    blsKnown     = false;
    bHasMax      = false;
    unitOfWeight = POUND;
    weight       = newWeight;
}
Weight::Weight(UnitOfWeight newUnitOfWeight) noexcept{
    blsKnown     = false;
    bHasMax      = false;
    unitOfWeight = newUnitOfWeight;
}
Weight::Weight(float newWeight, UnitOfWeight newUnitOfWeight) {
    blsKnown     = false;
    bHasMax      = false;
    unitOfWeight = newUnitOfWeight;
    weight       = newWeight;
}
Weight::Weight(float newWeight, float newMaxWeight) {
    blsKnown     = false;
    bHasMax      = false;
    unitOfWeight = POUND;
    weight       = newWeight;
    maxWeight    = newMaxWeight;
}
Weight::Weight(UnitOfWeight newUnitOfWeight, float newMaxWeight){
    blsKnown     = false;
    bHasMax      = false;
    unitOfWeight = newUnitOfWeight;
    maxWeight    = newMaxWeight;
}
Weight::Weight(float newWeight, UnitOfWeight newUnitOfWeight, float newMaxWeight){
    blsKnown     = false;
    bHasMax      = false;
    unitOfWeight = newUnitOfWeight;
    weight       = newWeight;
    maxWeight    = newMaxWeight;
}

// Everything is the getters for the weight class
float Weight::getWeight() const noexcept{
    return weight;
}
float Weight::getWeight(UnitOfWeight weightUnits) const noexcept{

}
float Weight::getMaxWeight() const noexcept{
    return maxWeight;
}
Weight::UnitOfWeight Weight::getWeightUnit() const noexcept{
    return unitOfWeight;
}
bool Weight::isWeightKnown() const noexcept{
    return blsKnown;
}
bool Weight::hasMaxWeight() const noexcept{
    return bHasMax;
}

