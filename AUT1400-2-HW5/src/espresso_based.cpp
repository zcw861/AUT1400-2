
#include "espresso_based.h"

EspressoBased::EspressoBased()= default;

EspressoBased::EspressoBased(const EspressoBased &esp) {
    for (const auto* ingredient : esp._ingredients) {
        std::string name = ingredient->get_name();
        int units = ingredient->get_units();
        if (name == "Cinnamon") {
            _ingredients.push_back(new Cinnamon(units));
        } else if (name == "Chocolate") {
            _ingredients.push_back(new Chocolate(units));
        } else if (name == "Sugar") {
            _ingredients.push_back(new Sugar(units));
        } else if (name == "Cookie") {
            _ingredients.push_back(new Cookie(units));
        } else if (name == "Espresso") {
            _ingredients.push_back(new Espresso(units));
        } else if (name == "Milk") {
            _ingredients.push_back(new Milk(units));
        } else if (name == "MilkFoam") {
            _ingredients.push_back(new MilkFoam(units));
        } else if (name == "Water") {
            _ingredients.push_back(new Water(units));
        }
    }
}

void EspressoBased::operator=(const EspressoBased &esp) {
    m_name = esp.m_name;

    for(const auto& i : _ingredients) {
        delete i;
    }
    _ingredients.clear();

    for (const auto& ingredient : esp._ingredients) {
        std::string name = ingredient->get_name();
        int units = ingredient->get_units();
        if (name == "Cinnamon") {
            _ingredients.push_back(new Cinnamon(units));
        } else if (name == "Chocolate") {
            _ingredients.push_back(new Chocolate(units));
        } else if (name == "Sugar") {
            _ingredients.push_back(new Sugar(units));
        } else if (name == "Cookie") {
            _ingredients.push_back(new Cookie(units));
        } else if (name == "Espresso") {
            _ingredients.push_back(new Espresso(units));
        } else if (name == "Milk") {
            _ingredients.push_back(new Milk(units));
        } else if (name == "MilkFoam") {
            _ingredients.push_back(new MilkFoam(units));
        } else if (name == "Water") {
            _ingredients.push_back(new Water(units));
        }
    }
}

EspressoBased::~EspressoBased() {
    for(const auto& i : _ingredients) {
        delete i;
    }
    _ingredients.clear();
}

std::vector<Ingredient*> &EspressoBased::get_ingredients() {
    return _ingredients;
}

void EspressoBased::brew() {
    // todo
}




