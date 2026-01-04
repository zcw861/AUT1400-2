
#include "cappuccino.h"
#include "ui_helpers.h"

Cappuccino::Cappuccino() {
    m_name = "Cappuccino";

    _ingredients.emplace_back(new Espresso(2));
    _ingredients.emplace_back(new Milk(2));
    _ingredients.emplace_back(new MilkFoam(1));
}

Cappuccino::Cappuccino(const Cappuccino &cap){
    m_name = cap.m_name;

    _ingredients.push_back(new Espresso(2));
    _ingredients.push_back(new Milk(2));
    _ingredients.push_back(new MilkFoam(1));

    for (const auto& item : cap.side_items) {
        std::string name = item->get_name();
        int units = item->get_units();
        if (name == "Cinnamon") {
            side_items.push_back(new Cinnamon(units));
        } else if (name == "Chocolate") {
            side_items.push_back(new Chocolate(units));
        } else if (name == "Sugar") {
            side_items.push_back(new Sugar(units));
        } else if (name == "Cookie") {
            side_items.push_back(new Cookie(units));
        } else if (name == "Espresso") {
            side_items.push_back(new Espresso(units));
        } else if (name == "Milk") {
            side_items.push_back(new Milk(units));
        } else if (name == "MilkFoam") {
            side_items.push_back(new MilkFoam(units));
        } else if (name == "Water") {
            side_items.push_back(new Water(units));
        }
    }
}

void Cappuccino::operator=(const Cappuccino &cap) {
    if (this == &cap) return;

    m_name = cap.m_name;

    for (const auto& ing : _ingredients) delete ing;
    for (const auto& item : side_items) delete item;
    _ingredients.clear();
    side_items.clear();

    _ingredients.push_back(new Espresso(2));
    _ingredients.push_back(new Milk(2));
    _ingredients.push_back(new MilkFoam(1));

    for (const auto& item : cap.side_items) {
        std::string name = item->get_name();
        int units = item->get_units();
        if (name == "Cinnamon") {
            side_items.push_back(new Cinnamon(units));
        } else if (name == "Chocolate") {
            side_items.push_back(new Chocolate(units));
        } else if (name == "Sugar") {
            side_items.push_back(new Sugar(units));
        } else if (name == "Cookie") {
            side_items.push_back(new Cookie(units));
        } else if (name == "Espresso") {
            side_items.push_back(new Espresso(units));
        } else if (name == "Milk") {
            side_items.push_back(new Milk(units));
        } else if (name == "MilkFoam") {
            side_items.push_back(new MilkFoam(units));
        } else if (name == "Water") {
            side_items.push_back(new Water(units));
        }
    }
}

Cappuccino::~Cappuccino()
{
    for(const auto& i : side_items) {
        delete i;
    }
    side_items.clear();
}

std::string Cappuccino::get_name() {
    return m_name;
}

void Cappuccino::add_side_item(Ingredient *side) {
    side_items.emplace_back(side);
}

std::vector<Ingredient *> &Cappuccino::get_side_items() {
    return side_items;
}

double Cappuccino::price() {
    double result = 0;
    for (const auto& ingredient : _ingredients) {
        result += ingredient->price();
    }
    for (const auto& side_item : side_items) {
        result += side_item->price();
    }
    return result;
}

void Cappuccino::brew() {
    using namespace TUI;

    clear_screen();
    std::cout << BOLD << GREEN << "\n☕ Brewing " << m_name << "...\n\n" << RESET;

    // 步骤列表
    std::vector<std::string> steps = {
        "Grinding coffee beans...",
        "Brewing espresso shots...",
        "Steaming milk...",
        "Frothing milk foam...",
        "Pouring into cup..."
    };

    // 模拟主 ingredients 步骤
    draw_box_top();
    for (size_t i = 0; i < steps.size(); ++i) {
        std::cout << "\033[3A\033[J"; // 清除上3行（覆盖进度）
        draw_box_top();
        print_progress(steps[i], static_cast<int>((i + 1) * 100 / steps.size()));
        draw_box_bottom();
        sleep_ms(200);
    }

    // 显示 side items
    if (!side_items.empty()) {
        sleep_ms(50);
        std::cout << "\n" << YELLOW << "Adding side items:\n" << RESET;
        for (const auto* item : side_items) {
            std::cout << "  ➤ " << item->get_name() << " x" << item->get_units() << "\n";
            sleep_ms(100);
        }
    }

    sleep_ms(600);
    std::cout << "\n" << BOLD << GREEN << "✅ Your " << m_name << " is ready! Enjoy!\n" << RESET;
}










