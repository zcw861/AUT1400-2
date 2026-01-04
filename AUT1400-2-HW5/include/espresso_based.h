#pragma once


#include "sub_ingredients.h"

#include "ingredient.h"
#include <iostream>
#include <vector>
#include <string>

class EspressoBased
{
    public:
    virtual std::string get_name() = 0;
    virtual double price() = 0;

    virtual void brew();
    std::vector<Ingredient*>& get_ingredients();

    virtual ~EspressoBased();

    protected:
    EspressoBased();
    EspressoBased(const EspressoBased& esp);
    void operator=(const EspressoBased& esp);

    std::vector<Ingredient*> _ingredients;
    std::string m_name;

};