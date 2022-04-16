///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab12a_fatCat - EE 205 - Spr 2022
///
/// @file Weight.h
/// @version 1.0
///
/// @author Kobe Uyeda <kobek@hawaii.edu>
/// @date   14_Apr_2022
///////////////////////////////////////////////////////////////////////////////
#pragma once
#include <string>
#include <ostream>

class Weight{
public:
    // defining a enum for the class will be referenced outside of the object a bunch
    enum UnitOfWeight {POUND, KILO, SLUG};
    // Constant member valuables
    static const float        UNKNOWN_WEIGHT;
    static const float        KILOS_IN_A_POUND;
    static const float        SLUGS_IN_A_POUND;

    static const std::string  POUND_LABEL;
    static const std::string  KILO_LABEL;
    static const std::string  SLUG_LABEL;

private:
    // Member value
    // Changes per a initialization of an object
    bool  blsKnown;
    bool  bHasMax;
    enum  UnitOfWeight unitOfWeight;
    float weight;
    float maxWeight;

public:
    // Defining the constructor of the class
    Weight() noexcept;
    Weight(float newWeight);
    Weight(UnitOfWeight newUnitOfWeight) noexcept;
    Weight(float newWeight, UnitOfWeight newUnitOfWeight);
    Weight(float newWeight, float newMaxWeight);
    Weight(UnitOfWeight newUnitOfWeight, float newMaxWeight);
    Weight(float newWeight, UnitOfWeight newUnitOfWeight, float newMaxWeight);

private:
    static float fromKilogramToPound(float kilogram) noexcept;
    static float fromPoundToKilogram(float pound) noexcept;
    static float fromSlugToPound(float slug) noexcept;
    static float fromPoundToSlug(float pound) noexcept;
    static float convertWeight(float fromWeight, UnitOfWeight fromUnit, UnitOfWeight toUnit) noexcept;
    void setMaxWeight(float newMaxWeight);

public:
    void dump() const noexcept;
    bool operator==(const Weight &rhs_Weight) const;
    bool operator<(const Weight &rhs_Weight) const;
    Weight & operator+=(float rhs_addToWeight);

    //Getters
    float getWeight() const noexcept;
    float getWeight(UnitOfWeight weightUnits) const noexcept;
    float getMaxWeight() const noexcept;
    UnitOfWeight getWeightUnit() const noexcept;
    bool isWeightKnown() const noexcept;
    bool hasMaxWeight() const noexcept;

    //Setters
    void setWeight(float newWeight);
    void setWeight(float newWeight, UnitOfWeight weightUnits);

    //Validator
    bool isWeightValid(float checkWeight) const noexcept;
    bool isMaxWeightValid(float checkMaxWeight) const noexcept;
    bool validate() const noexcept;


};
inline std::ostream& operator<<( std::ostream& lhs_stream
        ,const Weight::UnitOfWeight rhs_UnitOfWeight ) {
    switch( rhs_UnitOfWeight ) {
        case Weight::POUND: return lhs_stream << Weight::POUND_LABEL ;
        case Weight::KILO: return lhs_stream << Weight::KILO_LABEL ;
        case Weight::SLUG: return lhs_stream << Weight::SLUG_LABEL ;
        default:
            throw std::out_of_range( "The unit can’t be mapped to a string" );
    }
}
