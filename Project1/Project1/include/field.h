#pragma once
#include <ostream>
#include <vector>

const int M = 20;
const int N = 10;

class Field {
public:
    static std::vector<std::vector<int>> grid;
    static std::vector<std::vector<int>> figures;
    
    Field();
    Field(const Field& other);
    Field& operator=(const Field& other);

    int getCell(int x, int y) const;

    friend std::ostream& operator<<(std::ostream& os, const Field& field);
};
