#pragma once


#include "ingredient.h"
#include <vector>
#include <string>
#include <iostream>

#include "espresso_based.h"

class Cappuccino:public EspressoBased
{
public:
    Cappuccino();
    Cappuccino(const Cappuccino& cap);
    ~Cappuccino() override;
    void operator=(const Cappuccino& cap);

    void brew() override;
    virtual std::string get_name();
    virtual double price();

    void add_side_item(Ingredient* side);
    std::vector<Ingredient*>& get_side_items();

private:
    std::vector<Ingredient*> side_items;

};
