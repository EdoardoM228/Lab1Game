#include <iostream>
#include "../include/field.h"
#include "../include/clear.h"
#include "../include/figure.h"
#include "../include/point.h"

void testFieldInitialization() {
    Field field;
    bool passed = true;
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            if (field.getCell(j, i) != 0) {
                passed = false;
                break;
            }
        }
    }
    std::cout << "Test Field Initialization: " << (passed ? "PASSED" : "FAILED") << std::endl;
}

void testClearFullLines() {
    Field field;
    Cleaner cleaner;

    // Заполнение одной линии
    for (int j = 0; j < N; ++j) {
        Field::grid[M - 1][j] = 1;
    }

    cleaner.clearFullLines(field);

    bool passed = true;
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            if (Field::grid[i][j] != 0) {
                passed = false;
                break;
            }
        }
    }
    std::cout << "Test Clear Full Lines: " << (passed ? "PASSED" : "FAILED") << std::endl;
}

void testFigurePlacement() {
    generateNewFigure();
    placeFigure(1);

    bool passed = true;
    for (const auto& point : a) {
        if (Field::grid[point.y][point.x] != 1) {
            passed = false;
            break;
        }
    }
    std::cout << "Test Figure Placement: " << (passed ? "PASSED" : "FAILED") << std::endl;
}

int main() {
    std::cout << "Running Tests..." << std::endl;

    testFieldInitialization();
    testClearFullLines();
    testFigurePlacement();

    std::cout << "Tests Finished!" << std::endl;
    return 0;
}
