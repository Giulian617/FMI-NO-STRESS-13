#include <iostream>
#include <vector>
#include "generator.hpp"


TestData::TestData(std::function<TestData(void)> func) {
    *this = func();
}

std::vector<std::function<TestData()>> subtasks = {
    []() { return TestData(Generator::testing); },
    []() { return TestData(Generator::subtask1); },
    []() { return TestData(Generator::full); }
};

int main(int argc, char **argv) {
    if (argc > 1) {
        int subtask_index = atoi(argv[1]);
        auto generated_subtask = subtasks[subtask_index]();

        std::cout << generated_subtask.q << std::endl;
        for (int i = 0; i < generated_subtask.q; i++) {
            std::cout << generated_subtask.x[i] << std::endl;
        }
    } else {
        std::cout << "Usage: ./generator <subtask_index>" << std::endl;
    }
    return 0;
}
