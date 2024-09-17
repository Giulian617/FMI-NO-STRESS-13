#include <iostream>
#include <vector>
#include "generator.hpp"


TestData::TestData(std::function<TestData(void)> func) {
    *this = func();
}

std::vector<std::function<TestData()>> subtasks = {
    []() { return TestData(Generator::testing); },
    []() { return TestData(Generator::subtask1); },
    []() { return TestData(Generator::subtask2); },
    []() { return TestData(Generator::subtask3); },
    []() { return TestData(Generator::subtask4); },
    []() { return TestData(Generator::subtask5); },
    []() { return TestData(Generator::full); }
};

int main(int argc, char **argv) {
    if (argc > 1) {
        int subtask_index = atoi(argv[1]);
        auto generated_subtask = subtasks[subtask_index]();

        std::cout << generated_subtask.n << ' ' << generated_subtask.m << std::endl;
        for (int i = 0; i < generated_subtask.m; i++) {
            std::cout << generated_subtask.t[i];
            if (i != generated_subtask.m - 1) {
                std::cout << ' ';
            }
        }
        std::cout << std::endl;
        std::cout << std::endl;
    } else {
        std::cout << "Must input a subtask number!\n";
    }
    return 0;
}
