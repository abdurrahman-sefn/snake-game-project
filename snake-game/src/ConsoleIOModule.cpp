#include "utils/ConsoleIOModule.hpp"

ConsoleKey ConsoleIOModule::ReadKey()
{
    char key;
    std::cin >> key;
    // normalize
    key = std::tolower(key);
    switch (key)
    {
    case 'w':
        return ConsoleKey::Up;

    case 's':
        return ConsoleKey::Down;

    case 'a':
        return ConsoleKey::Left;

    case 'd':
        return ConsoleKey::Right;

    case 'p':
        return ConsoleKey::Pause;

    case 'q':
        return ConsoleKey::Escape;

    default:
        return ConsoleKey::None;
    }
}

void ConsoleIOModule::Draw(const Snake *snake)
{
    std::vector<std::vector<char>> *grid =
        snake->GetGridToDraw();

    // Move cursor to the top-left.
    std::cout.clear();

    for (const auto &row : *grid)
    {
        for (char cell : row)
        {
            std::cout << cell;
        }

        std::cout << '\n';
    }

    std::cout.flush();
    delete grid;
    grid = nullptr;
}