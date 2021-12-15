#include <iostream>
#include <thread>
#include <vector>
#include "cabinet.h"
#include <mutex>

bool isNumber(std::string string) {
    for (int i = 0; i < string.length(); ++i) {
        if (!std::isdigit(string[i])) {
            return false;
        }
    }
    return true;
}

int validator() {
    bool is_correct_input = false;
    int value;
    while (!is_correct_input) {
        std::string line;
        std::getline(std::cin, line);
        if (isNumber(line)) {
            value = std::stoi(line);
            is_correct_input = true;
        }
        if (value <= 0 || value > 10) {
            is_correct_input = false;
            std::cout << "Неправильный ввод! Введите число посетителей (от 1 до 10):";
        }
    }
    return value;
}



int main() {
    std::cout << "Введите количество поситителей:\n";
    int visitors_number = validator();
    std::vector<std::thread> visitors_arr[visitors_number];
    for (int i = 0; i < visitors_number; ++i) {
        if (std::rand() % 2 == 0) {

            visitors_arr->emplace_back(Cabinet::visitCabinetFirst, i);
        } else {
            visitors_arr->emplace_back(Cabinet::visitCabinetSecond, i);

        }
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(10000));
    for (int i = 0; i < visitors_arr->size(); ++i) {
        visitors_arr->at(i).join();
    }
    return 0;
}
