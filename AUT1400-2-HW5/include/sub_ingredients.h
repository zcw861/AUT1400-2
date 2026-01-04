#pragma once


#include "ingredient.h"
#include <string>

#define DEFCLASS(ClassName,PriceValue)\
class ClassName : public Ingredient {\
public:\
    ClassName(int units):Ingredient(PriceValue,units) {\
        this->name = #ClassName;\
    }\
    std::string get_name() const override {return this->name;}\
};

DEFCLASS(Cinnamon, 5);
DEFCLASS(Chocolate, 5);
DEFCLASS(Sugar, 1);
DEFCLASS(Cookie, 10);
DEFCLASS(Espresso, 15);
DEFCLASS(Milk, 10);
DEFCLASS(MilkFoam, 5);
DEFCLASS(Water, 1);