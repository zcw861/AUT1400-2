#pragma once


#include <string>

class Ingredient
{
public:
    double get_price_unit() const {return price_unit;}
    size_t get_units() const {return units;}
    virtual std::string get_name() const = 0;
    virtual ~Ingredient() = default;

    double price() const {return (double) price_unit * units;}


protected:
    Ingredient(double price_unit, int units) : price_unit(price_unit), units(units){}

    double price_unit;
    size_t units;
    std::string name;
};