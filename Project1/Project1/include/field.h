#pragma once
#include <ostream>
#include <vector>

const int M = 20; ///< Количество строк в игровом поле.
const int N = 10; ///< Количество столбцов в игровом поле.

/**
 * @class Field
 * @brief Класс для управления игровым полем.
 */
class Field {
public:
    static std::vector<std::vector<int>> grid; ///< Матрица игрового поля.
    static std::vector<std::vector<int>> figures; ///< Набор фигур.

    /**
     * @brief Конструктор по умолчанию.
     */
    Field();

    /**
     * @brief Конструктор копирования.
     * @param other Другой объект Field.
     */
    Field(const Field& other);

    /**
     * @brief Оператор присваивания.
     * @param other Другой объект Field.
     * @return Ссылка на текущий объект.
     */
    Field& operator=(const Field& other);

    /**
     * @brief Получает значение ячейки.
     * @param x Координата X.
     * @param y Координата Y.
     * @return Значение в указанной ячейке.
     */
    int getCell(int x, int y) const;

    /**
     * @brief Перегруженный оператор вывода.
     * @param os Поток вывода.
     * @param field Игровое поле.
     * @return Ссылка на поток вывода.
     */
    friend std::ostream& operator<<(std::ostream& os, const Field& field);
};
