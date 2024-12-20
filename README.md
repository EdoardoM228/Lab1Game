# Lab1Game
Тетрис — это классическая головоломка, цель которой заключается в том, чтобы размещать падающие тетромино на игровом поле таким образом, чтобы заполнять горизонтальные линии. Заполненные линии исчезают, зарабатывая очки. Игра заканчивается, когда нет места для новых тетромино.

Эта реализация Тетриса создана с использованием библиотеки SFML (Simple and Fast Multimedia Library) для графического отображения. Включает основные игровые механики, такие как перемещение, вращение и очистка линий, а также простой графический интерфейс.

## Особенности

- **Падающие Тетромино**: Игра включает семь различных типов тетромино.
- **Вращение и Перемещение**: Игроки могут вращать и перемещать тетромино влево и вправо.
- **Очистка Линий**: Заполненные линии удаляются с игрового поля, зарабатывая очки.
- **Конец Игры**: Игра заканчивается, когда нет места для новых тетромино.

## Требования

- **SFML**: Убедитесь, что SFML установлена на вашей системе. Скачайте её с [официального сайта SFML](https://www.sfml-dev.org/download.php).
- **Компилятор C++**: Компилятор C++, поддерживающий C++11 или более позднюю версию.

## Управление

- **Стрелка влево**: Переместить тетромино влево.
- **Стрелка вправо**: Переместить тетромино вправо.
- **Стрелка вверх**: Повернуть тетромино.
- **Стрелка вниз**: Переместить тетромино вниз быстрее (мягкое падение).

## Как Играть

1. **Запустите Игру**: Выполните исполняемый файл, как описано выше.
2. **Управляйте Тетромино**: Используйте стрелки для перемещения и вращения падающих тетромино.
3. **Заполняйте Линии**: Старайтесь заполнять тетромино горизонтальные линии на поле. Заполненные линии исчезают и приносят очки.
4. **Избегайте Конца Игры**: Игра заканчивается, когда нет места для новых тетромино.

## Структура проекта

- `point.hpp` — содержит структуру для координат точки на игровом поле.
- `field.hpp` — объявляет игровое поле и фигуры.
- `figure.hpp` — содержит операции для работы с фигурами (проверка, вращение, генерация, размещение).
- `game.hpp` — содержит функции для обработки ввода и обновления состояния игры.
- `clear.hpp` — содержит функцию для очистки заполненных линий.

## Сборка

### Шаги для сборки проекта:

1. Убедитесь, что вы установили **MinGW** (64-битную версию, если используете 64-битную SFML) и добавили его в переменные окружения системы.
2. Скачайте и установите SFML 2.6.1 с [официального сайта](https://www.sfml-dev.org/download.php). Разархивируйте SFML в подходящую директорию, например, `H:/SFML-2.6.1`.
3. Убедитесь, что пути к SFML указаны правильно в файле `Makefile`.

### Makefile:

```makefile
SFML_INCLUDE = src/include
SFML_LIB = src/lib

all: TetrisGame

TetrisGame: figure.o game.o clear.o field.o point.o main.o
	g++ -o Tetris.exe figure.o game.o clear.o field.o point.o main.o -L"$(SFML_LIB)" -lsfml-graphics -lsfml-window -lsfml-system

figure.o:
	g++ figure.cpp -o figure.o -c -I"$(SFML_INCLUDE)"

game.o:
	g++ game.cpp -o game.o -c -I"$(SFML_INCLUDE)"

clear.o:
	g++ clear.cpp -o clear.o -c -I"$(SFML_INCLUDE)"

field.o:
	g++ field.cpp -o field.o -c -I"$(SFML_INCLUDE)"

point.o:
	g++ point.cpp -o point.o -c -I"$(SFML_INCLUDE)"

main.o:
	g++ main.cpp -o main.o -c -I"$(SFML_INCLUDE)"

clean:
	rm -f *.o *.exe
```
## Используемые Операторы
### Класс `Point`
- **Конструктор**: используется для инициализации координат точки.
- **Оператор вывода**: перегружен для отображения координат точки на экране.

### Класс `Field`
- **Конструктор**: инициализирует игровое поле нулями.
- **Копирующий конструктор**: создает копию другого объекта `Field`.
- **Оператор присваивания**: перегружен для глубокого копирования содержимого поля.
- **Статические члены**: `grid` и `figures` объявлены как статические массивы, чтобы делиться ими между всеми объектами класса.

### Класс `Figure`
- **Конструктор**: инициализирует фигуру и ее начальные координаты.
- **Оператор копирования**: используется для создания копии фигуры.
- **Методы**: включает методы для проверки, вращения и генерации фигур, но не перегруженные операторы.

### Класс `Game`
- **Конструктор**: инициализирует параметры игры, такие как скорость и цвет.
- **Оператор вывода**: перегружен для отображения состояния игры на экране.

### Класс `Clear`
- **Методы**: класс не имеет перегруженных операторов, но содержит методы для очистки заполненных линий на игровом поле.
- 
## Абстрактные классы
- **Абстрактный класс**: `GameObject` (пример, если вы решили создать интерфейс для всех игровых объектов)
  - Чисто виртуальные методы: 
    - `virtual void draw() = 0;`
    - `virtual void update() = 0;`
  - Позволяет обеспечить полиморфизм и общие интерфейсы для всех игровых объектов.

Используемые Стандарты и Библиотеки
Контейнеры и Алгоритмы STL
Вместо использования C-стиля массивов, в проекте применялись контейнеры стандартной библиотеки (STL), такие как std::vector. Это обеспечивает динамическое управление памятью и более удобное обращение с данными. Например, в классе Field используется std::vector<std::vector<int>> grid для представления игрового поля.

Также в проекте активно использовались алгоритмы STL для различных операций, включая:

Поиск: Для нахождения элементов в контейнерах.
Сравнение: Для сравнения значений, например, при проверке наличия заполненных линий.
Копирование: Для копирования содержимого полей и фигур.
Сортировка: В случаях, когда необходимо упорядочить элементы.
Строки std::string
В проекте использовались строки типа std::string для обработки текстовой информации, например, для хранения сообщений об ошибках, отображаемых на экране. Это позволяет более гибко управлять текстом, а также использовать встроенные методы для обработки строк, такие как поиск подстрок и конкатенация.


Изменил makefile 
# Директории
SRC_DIR = src
LIB_DIR = libs
INCLUDE_DIR = include
SFML_INCLUDE = src/include
SFML_LIB = src/lib

# Компилятор и флаги
CC = g++
CFLAGS = -I$(INCLUDE_DIR) -I$(SFML_INCLUDE) -c
AR = ar
ARFLAGS = rcs

# Библиотеки
LIB_FIELD = $(LIB_DIR)/libField.a
LIB_FIGURE = $(LIB_DIR)/libFigure.a
LIB_CLEANER = $(LIB_DIR)/libCleaner.a
LIB_GAME = $(LIB_DIR)/libGame.a
LIB_POINT = $(LIB_DIR)/libPoint.a

# Все библиотеки
LIBRARIES = $(LIB_FIELD) $(LIB_FIGURE) $(LIB_CLEANER) $(LIB_GAME) $(LIB_POINT)

# Исходные файлы
MAIN = $(SRC_DIR)/main.cpp

# Объектные файлы
OBJ_FIELD = $(SRC_DIR)/field.o
OBJ_FIGURE = $(SRC_DIR)/figure.o
OBJ_CLEANER = $(SRC_DIR)/clear.o
OBJ_GAME = $(SRC_DIR)/game.o
OBJ_POINT = $(SRC_DIR)/point.o
OBJ_MAIN = $(SRC_DIR)/main.o

# Цель по умолчанию
all: TetrisGame

# Основное приложение
TetrisGame: $(OBJ_MAIN) $(LIBRARIES)
	$(CC) -o TetrisGame $(OBJ_MAIN) -L$(LIB_DIR) -L$(SFML_LIB) -lField -lFigure -lCleaner -lGame -lPoint -lsfml-graphics -lsfml-window -lsfml-system

# Компиляция main.cpp
$(OBJ_MAIN): $(MAIN)
	$(CC) $(CFLAGS) $(MAIN) -o $(OBJ_MAIN)

# Библиотека Field
$(LIB_FIELD): $(OBJ_FIELD)
	$(AR) $(ARFLAGS) $(LIB_FIELD) $(OBJ_FIELD)

$(OBJ_FIELD): $(SRC_DIR)/field.cpp $(INCLUDE_DIR)/field.h
	$(CC) $(CFLAGS) $(SRC_DIR)/field.cpp -o $(OBJ_FIELD)

# Библиотека Figure
$(LIB_FIGURE): $(OBJ_FIGURE)
	$(AR) $(ARFLAGS) $(LIB_FIGURE) $(OBJ_FIGURE)

$(OBJ_FIGURE): $(SRC_DIR)/figure.cpp $(INCLUDE_DIR)/figure.h
	$(CC) $(CFLAGS) $(SRC_DIR)/figure.cpp -o $(OBJ_FIGURE)

# Библиотека Cleaner
$(LIB_CLEANER): $(OBJ_CLEANER)
	$(AR) $(ARFLAGS) $(LIB_CLEANER) $(OBJ_CLEANER)

$(OBJ_CLEANER): $(SRC_DIR)/clear.cpp $(INCLUDE_DIR)/clear.h
	$(CC) $(CFLAGS) $(SRC_DIR)/clear.cpp -o $(OBJ_CLEANER)

# Библиотека Game
$(LIB_GAME): $(OBJ_GAME)
	$(AR) $(ARFLAGS) $(LIB_GAME) $(OBJ_GAME)

$(OBJ_GAME): $(SRC_DIR)/game.cpp $(INCLUDE_DIR)/game.h
	$(CC) $(CFLAGS) $(SRC_DIR)/game.cpp -o $(OBJ_GAME)

# Библиотека Point
$(LIB_POINT): $(OBJ_POINT)
	$(AR) $(ARFLAGS) $(LIB_POINT) $(OBJ_POINT)

$(OBJ_POINT): $(SRC_DIR)/point.cpp $(INCLUDE_DIR)/point.h
	$(CC) $(CFLAGS) $(SRC_DIR)/point.cpp -o $(OBJ_POINT)

# Удаление временных файлов
clean:
	rm -f $(SRC_DIR)/*.o TetrisGame $(LIBRARIES)

добавил папку libs для хранения статических библиотек с расрширением .a можно посмотреть в коммите их 

использование Doxygen документации, а так же тесты я добавил в make file и при вызове команды в терминале make tests он вызывает все тесты
# Директории
SRC_DIR = src
LIB_DIR = libs
INCLUDE_DIR = include
SFML_INCLUDE = src/include
SFML_LIB = src/lib
TESTS_DIR = tests

# Компилятор и флаги
CC = g++
CFLAGS = -I$(INCLUDE_DIR) -I$(SFML_INCLUDE) -c
AR = ar
ARFLAGS = rcs

# Библиотеки
LIB_FIELD = $(LIB_DIR)/libField.a
LIB_FIGURE = $(LIB_DIR)/libFigure.a
LIB_CLEANER = $(LIB_DIR)/libCleaner.a
LIB_GAME = $(LIB_DIR)/libGame.a
LIB_POINT = $(LIB_DIR)/libPoint.a

# Все библиотеки
LIBRARIES = $(LIB_FIELD) $(LIB_FIGURE) $(LIB_CLEANER) $(LIB_GAME) $(LIB_POINT)

# Исходные файлы
MAIN = $(SRC_DIR)/main.cpp

# Объектные файлы
OBJ_FIELD = $(SRC_DIR)/field.o
OBJ_FIGURE = $(SRC_DIR)/figure.o
OBJ_CLEANER = $(SRC_DIR)/clear.o
OBJ_GAME = $(SRC_DIR)/game.o
OBJ_POINT = $(SRC_DIR)/point.o
OBJ_MAIN = $(SRC_DIR)/main.o

# Тесты
TEST_SRC = $(TESTS_DIR)/main.cpp
TEST_OBJ = $(TESTS_DIR)/main.o
TEST_BIN = $(TESTS_DIR)/test_runner

# Цель по умолчанию
all: TetrisGame

# Основное приложение
TetrisGame: $(OBJ_MAIN) $(LIBRARIES)
	$(CC) -o TetrisGame $(OBJ_MAIN) -L$(LIB_DIR) -L$(SFML_LIB) -lField -lFigure -lCleaner -lGame -lPoint -lsfml-graphics -lsfml-window -lsfml-system

# Компиляция main.cpp
$(OBJ_MAIN): $(MAIN)
	$(CC) $(CFLAGS) $(MAIN) -o $(OBJ_MAIN)

# Библиотека Field
$(LIB_FIELD): $(OBJ_FIELD)
	$(AR) $(ARFLAGS) $(LIB_FIELD) $(OBJ_FIELD)

$(OBJ_FIELD): $(SRC_DIR)/field.cpp $(INCLUDE_DIR)/field.h
	$(CC) $(CFLAGS) $(SRC_DIR)/field.cpp -o $(OBJ_FIELD)

# Библиотека Figure
$(LIB_FIGURE): $(OBJ_FIGURE)
	$(AR) $(ARFLAGS) $(LIB_FIGURE) $(OBJ_FIGURE)

$(OBJ_FIGURE): $(SRC_DIR)/figure.cpp $(INCLUDE_DIR)/figure.h
	$(CC) $(CFLAGS) $(SRC_DIR)/figure.cpp -o $(OBJ_FIGURE)

# Библиотека Cleaner
$(LIB_CLEANER): $(OBJ_CLEANER)
	$(AR) $(ARFLAGS) $(LIB_CLEANER) $(OBJ_CLEANER)

$(OBJ_CLEANER): $(SRC_DIR)/clear.cpp $(INCLUDE_DIR)/clear.h
	$(CC) $(CFLAGS) $(SRC_DIR)/clear.cpp -o $(OBJ_CLEANER)

# Библиотека Game
$(LIB_GAME): $(OBJ_GAME)
	$(AR) $(ARFLAGS) $(LIB_GAME) $(OBJ_GAME)

$(OBJ_GAME): $(SRC_DIR)/game.cpp $(INCLUDE_DIR)/game.h
	$(CC) $(CFLAGS) $(SRC_DIR)/game.cpp -o $(OBJ_GAME)

# Библиотека Point
$(LIB_POINT): $(OBJ_POINT)
	$(AR) $(ARFLAGS) $(LIB_POINT) $(OBJ_POINT)

$(OBJ_POINT): $(SRC_DIR)/point.cpp $(INCLUDE_DIR)/point.h
	$(CC) $(CFLAGS) $(SRC_DIR)/point.cpp -o $(OBJ_POINT)

# Сборка тестов
$(TEST_BIN): $(TEST_OBJ) $(LIBRARIES)
	$(CC) -o $(TEST_BIN) $(TEST_OBJ) -L$(LIB_DIR) -lField -lFigure -lCleaner -lPoint -lGame

$(TEST_OBJ): $(TEST_SRC)
	$(CC) $(CFLAGS) $(TEST_SRC) -o $(TEST_OBJ)

test: $(TEST_BIN)
	./$(TEST_BIN)

# Удаление временных файлов
clean:
	rm -f $(SRC_DIR)/*.o $(TESTS_DIR)/*.o TetrisGame $(TEST_BIN) $(LIBRARIES)
# Директории
SRC_DIR = src
LIB_DIR = libs
INCLUDE_DIR = include
SFML_INCLUDE = src/include
SFML_LIB = src/lib
TESTS_DIR = tests

# Компилятор и флаги
CC = g++
CFLAGS = -I$(INCLUDE_DIR) -I$(SFML_INCLUDE) -c
AR = ar
ARFLAGS = rcs

# Библиотеки
LIB_FIELD = $(LIB_DIR)/libField.a
LIB_FIGURE = $(LIB_DIR)/libFigure.a
LIB_CLEANER = $(LIB_DIR)/libCleaner.a
LIB_GAME = $(LIB_DIR)/libGame.a
LIB_POINT = $(LIB_DIR)/libPoint.a

# Все библиотеки
LIBRARIES = $(LIB_FIELD) $(LIB_FIGURE) $(LIB_CLEANER) $(LIB_GAME) $(LIB_POINT)

# Исходные файлы
MAIN = $(SRC_DIR)/main.cpp

# Объектные файлы
OBJ_FIELD = $(SRC_DIR)/field.o
OBJ_FIGURE = $(SRC_DIR)/figure.o
OBJ_CLEANER = $(SRC_DIR)/clear.o
OBJ_GAME = $(SRC_DIR)/game.o
OBJ_POINT = $(SRC_DIR)/point.o
OBJ_MAIN = $(SRC_DIR)/main.o

# Тесты
TEST_SRC = $(TESTS_DIR)/main.cpp
TEST_OBJ = $(TESTS_DIR)/main.o
TEST_BIN = $(TESTS_DIR)/test_runner

# Цель по умолчанию
all: TetrisGame

# Основное приложение
TetrisGame: $(OBJ_MAIN) $(LIBRARIES)
	$(CC) -o TetrisGame $(OBJ_MAIN) -L$(LIB_DIR) -L$(SFML_LIB) -lField -lFigure -lCleaner -lGame -lPoint -lsfml-graphics -lsfml-window -lsfml-system

# Компиляция main.cpp
$(OBJ_MAIN): $(MAIN)
	$(CC) $(CFLAGS) $(MAIN) -o $(OBJ_MAIN)

# Библиотека Field
$(LIB_FIELD): $(OBJ_FIELD)
	$(AR) $(ARFLAGS) $(LIB_FIELD) $(OBJ_FIELD)

$(OBJ_FIELD): $(SRC_DIR)/field.cpp $(INCLUDE_DIR)/field.h
	$(CC) $(CFLAGS) $(SRC_DIR)/field.cpp -o $(OBJ_FIELD)

# Библиотека Figure
$(LIB_FIGURE): $(OBJ_FIGURE)
	$(AR) $(ARFLAGS) $(LIB_FIGURE) $(OBJ_FIGURE)

$(OBJ_FIGURE): $(SRC_DIR)/figure.cpp $(INCLUDE_DIR)/figure.h
	$(CC) $(CFLAGS) $(SRC_DIR)/figure.cpp -o $(OBJ_FIGURE)

# Библиотека Cleaner
$(LIB_CLEANER): $(OBJ_CLEANER)
	$(AR) $(ARFLAGS) $(LIB_CLEANER) $(OBJ_CLEANER)

$(OBJ_CLEANER): $(SRC_DIR)/clear.cpp $(INCLUDE_DIR)/clear.h
	$(CC) $(CFLAGS) $(SRC_DIR)/clear.cpp -o $(OBJ_CLEANER)

# Библиотека Game
$(LIB_GAME): $(OBJ_GAME)
	$(AR) $(ARFLAGS) $(LIB_GAME) $(OBJ_GAME)

$(OBJ_GAME): $(SRC_DIR)/game.cpp $(INCLUDE_DIR)/game.h
	$(CC) $(CFLAGS) $(SRC_DIR)/game.cpp -o $(OBJ_GAME)

# Библиотека Point
$(LIB_POINT): $(OBJ_POINT)
	$(AR) $(ARFLAGS) $(LIB_POINT) $(OBJ_POINT)

$(OBJ_POINT): $(SRC_DIR)/point.cpp $(INCLUDE_DIR)/point.h
	$(CC) $(CFLAGS) $(SRC_DIR)/point.cpp -o $(OBJ_POINT)

# Сборка тестов
$(TEST_BIN): $(TEST_OBJ) $(LIBRARIES)
	$(CC) -o $(TEST_BIN) $(TEST_OBJ) -L$(LIB_DIR) -lField -lFigure -lCleaner -lPoint -lGame

$(TEST_OBJ): $(TEST_SRC)
	$(CC) $(CFLAGS) $(TEST_SRC) -o $(TEST_OBJ)

test: $(TEST_BIN)
	./$(TEST_BIN)

# Удаление временных файлов
clean:
	rm -f $(SRC_DIR)/*.o $(TESTS_DIR)/*.o TetrisGame $(TEST_BIN) $(LIBRARIES)

