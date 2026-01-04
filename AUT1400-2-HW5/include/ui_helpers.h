#pragma once

#include <iostream>
#include <thread>
#include <chrono>
#include <string>

namespace TUI {

    // 颜色代码
    const std::string RESET = "\033[0m";
    const std::string RED = "\033[31m";
    const std:: string GREEN = "\033[32m";
    const std::string YELLOW = "\033[33m";
    const std::string BLUE = "\033[34m";
    const std::string MAGENTA = "\033[35m";
    const std::string CYAN = "\033[36m";
    const std::string BOLD = "\033[1m";

    inline void clear_screen() {
        std::cout << "\033[2J\033[H"; // Clear screen and move cursor to top-left
    }

    inline void sleep_ms(int ms) {
        std::this_thread::sleep_for(std::chrono::milliseconds(ms));
    }

    inline void print_progress(const std::string& step, int percent) {
        const int width = 20;
        int filled = (percent * width) / 100;
        if (filled < 0) filled = 0;
        if (filled > width) filled = width;

        std::string bar = "[";
        for (int i = 0; i < width; ++i) {
            bar += (i < filled) ? '#' : '-';
        }
        bar += "] " + std::to_string(percent) + "%";

        // 安全填充：确保不会负数
        int step_pad = std::max(0, 28 - static_cast<int>(step.length()));
        int bar_pad = std::max(0, 28 - static_cast<int>(bar.length()));

        std::cout << BOLD << CYAN
                  << "│ " << step << std::string(step_pad, ' ') << " │\n"
                  << "│ " << bar << std::string(bar_pad, ' ') << " │"
                  << RESET << "\n";
    }

    inline void draw_box_top() {
        std::cout << BOLD << "┌──────────────────────────────┐" << RESET << "\n";
    }

    inline void draw_box_bottom() {
        std::cout << BOLD << "└──────────────────────────────┘" << RESET << "\n";
    }

    inline void print_centered(const std::string& text) {
        int len = static_cast<int>(text.length());
        int padding = std::max(0, (30 - len) / 2);
        int right_pad = std::max(0, 30 - padding - len);
        std::cout << BOLD << "│"
                  << std::string(padding, ' ')
                  << text
                  << std::string(right_pad, ' ')
                  << "│" << RESET << "\n";
    }
}