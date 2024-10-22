#include <iomanip>
#include <iostream>
#include <vector>
#include "generator.hpp"


TestData::TestData(std::function<TestData(void)> func) {
    *this = func();
}

std::vector<std::function<TestData()>> subtasks = {
    []() { return TestData(Generator::testing); },
    []() { return TestData(Generator::full); }
};

int main(int argc, char **argv) {
    if (argc > 1) {
        int subtask_index = atoi(argv[1]);
        auto generated_subtask = subtasks[subtask_index]();

        std::cout << generated_subtask.N << std::endl;
        for (int i = 0; i < generated_subtask.N; i++) {
            auto [x, y, z] = generated_subtask.stars[i];
            std::cout << std::fixed << std::setprecision(2);
            std::cout << x << " " << y << " " << z << std::endl;
        }
        std::cout << generated_subtask.L << std::endl;
        for (int i = 0; i < generated_subtask.L; i++) {
            auto lantern = generated_subtask.lanterns[i];
            std::cout << std::fixed << std::setprecision(2);
            std::cout << lantern.x << " " << lantern.y << " " << lantern.z << " ";
            std::cout << std::fixed << std::setprecision(4) << lantern.phi << std::endl;
        }
    } else {
        std::cout << "Must input a subtask number!\n";
    }
    return 0;
}
