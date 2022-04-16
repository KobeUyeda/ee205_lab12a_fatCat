#include <iostream>
#include <cassert>
#include "Weight.h"

int main() {
    // Trying all the initializers successfully
    Weight *noData = new Weight();
    Weight *onlyWeight = new Weight(4);
    Weight *onlyWeightType = new Weight(Weight::SLUG);
    Weight *weightAndWeightType = new Weight(50, Weight::POUND);
    Weight *weightAndMaxWeight = new Weight(50, 60);
    Weight *unitAndMaxWeight = new Weight(Weight::KILO, 60);
    Weight *myWeight = new Weight( 3.14, Weight::KILO, 20 );

    // trying all the initializers that would not be successful since max is less than the value
    try{
        Weight *issueOne = new Weight(50, 25);
        assert(false);
    } catch (std::exception const& error) {

    }
    try{
        Weight *issueTwo = new Weight( 3.14, Weight::KILO, 1 );
        assert(false);
    } catch (std::exception const& error) {

    }

    assert(weightAndWeightType->operator==(*weightAndMaxWeight));
    assert(myWeight->operator==(*weightAndMaxWeight) == false);
    assert(onlyWeight->operator<(*myWeight));
    assert(myWeight->operator<(*onlyWeight)==false);

    assert(myWeight->operator+=(5).getWeight() == (float)8.14);

    weightAndMaxWeight->dump();
    weightAndMaxWeight->setWeight(20, Weight::KILO);
    assert(weightAndMaxWeight->getWeightUnit() == Weight::KILO);
    assert(weightAndMaxWeight->getWeight() == (float) 20);
    weightAndMaxWeight->dump();


    noData->dump();
    onlyWeight->dump();
    onlyWeightType->dump();
    weightAndWeightType->dump();
    weightAndMaxWeight->dump();
    unitAndMaxWeight->dump();
    myWeight->dump();



    return 0;
}
