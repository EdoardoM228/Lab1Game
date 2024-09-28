#include "clear.h"
#include "field.h"

void clearFullLines() {
    int k = M - 1;
    for (int i = M - 1; i > 0; i--) {
        int count = 0;
        for (int j = 0; j < N; j++) {
            if (field[i][j]) count++;
            field[k][j] = field[i][j];
        }
        if (count < N) k--;  
    }
}