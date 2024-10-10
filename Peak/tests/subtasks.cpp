#include <iostream>
#include <vector>
#include "generator.hpp"


TestData::TestData(std::function<TestData(void)> func) {
    *this = func();
}

std::vector<std::function<TestData()>> subtasks = {
    []() { return TestData(Generator::testing); },
    []() { return TestData(Generator::subtask1); },
    []() { return TestData(Generator::Pick); },
    []() { return TestData(Generator::full); }
};

int main(int argc, char **argv) {
    if (argc > 1) {
        int subtask_index = atoi(argv[1]);
        auto generated_subtask = subtasks[subtask_index]();

        std::cout << generated_subtask.Q << std::endl;
        for (int i = 0; i < generated_subtask.Q; i++) {
            auto [a, b, c, d, s, t] = generated_subtask.v[i];
            std::cout << a << " " << b << " " << c << " " << d << " " << s << " " << t << std::endl;
        }
    } else {
        std::cout << "Must input a subtask number!\n";
    }
    return 0;
}
