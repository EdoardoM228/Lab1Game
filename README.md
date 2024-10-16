# Lab1Game
Это 1 лабораторная работа по C++ 

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
