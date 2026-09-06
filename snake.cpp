#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/select.h>

using namespace std;

const int WIDTH = 20;
const int HEIGHT = 10;

struct Point { int x, y; };

struct TermiosGuard {
    termios oldt;
    TermiosGuard() {
        tcgetattr(STDIN_FILENO, &oldt);
        termios newt = oldt;
        newt.c_lflag &= ~(ICANON | ECHO);
        newt.c_cc[VMIN] = 0;
        newt.c_cc[VTIME] = 0;
        tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    }
    ~TermiosGuard() { tcsetattr(STDIN_FILENO, TCSANOW, &oldt); }
};

enum Key { K_UP, K_DOWN, K_LEFT, K_RIGHT, K_QUIT, K_NONE };

Key readKey() {
    char c;
    if (read(STDIN_FILENO, &c, 1) != 1) return K_NONE;
    if (c == 27) {
        char seq[2];
        if (read(STDIN_FILENO, &seq[0], 1) != 1) return K_NONE;
        if (read(STDIN_FILENO, &seq[1], 1) != 1) return K_NONE;
        if (seq[0] == '[') {
            if (seq[1] == 'A') return K_UP;
            if (seq[1] == 'B') return K_DOWN;
            if (seq[1] == 'C') return K_RIGHT;
            if (seq[1] == 'D') return K_LEFT;
        }
        return K_NONE;
    }
    if (c == 'q' || c == 'Q') return K_QUIT;
    return K_NONE;
}

void sleepMs(int ms) {
    usleep(ms * 1000);
}

int main() {
    srand((unsigned)time(0));
    TermiosGuard guard;
    vector<Point> snake = {{WIDTH / 2, HEIGHT / 2}};
    Point food = {rand() % WIDTH, rand() % HEIGHT};
    int dx = 1, dy = 0;
    bool gameOver = false;

    while (!gameOver) {
        cout << "\033[2J\033[H";
        for (int i = 0; i < WIDTH + 2; i++) cout << '#';
        cout << "\n";

        for (int y = 0; y < HEIGHT; y++) {
            cout << '#';
            for (int x = 0; x < WIDTH; x++) {
                bool printed = false;
                if (x == snake[0].x && y == snake[0].y) { cout << 'O'; printed = true; }
                else {
                    for (size_t i = 1; i < snake.size(); i++) {
                        if (snake[i].x == x && snake[i].y == y) { cout << 'o'; printed = true; break; }
                    }
                }
                if (!printed) {
                    if (x == food.x && y == food.y) cout << '*';
                    else cout << ' ';
                }
            }
            cout << "#\n";
        }

        for (int i = 0; i < WIDTH + 2; i++) cout << '#';
        cout << "\nScore: " << snake.size() - 1 << "\n";

        Key k = readKey();
        if (k == K_UP && dy != 1)    { dx = 0; dy = -1; }
        if (k == K_DOWN && dy != -1) { dx = 0; dy = 1;  }
        if (k == K_LEFT && dx != 1)  { dx = -1; dy = 0; }
        if (k == K_RIGHT && dx != -1){ dx = 1;  dy = 0; }
        if (k == K_QUIT) gameOver = true;

        Point head = {snake[0].x + dx, snake[0].y + dy};
        if (head.x < 0 || head.x >= WIDTH || head.y < 0 || head.y >= HEIGHT) gameOver = true;
        for (auto& s : snake)
            if (s.x == head.x && s.y == head.y) gameOver = true;

        if (!gameOver) {
            snake.insert(snake.begin(), head);
            if (head.x == food.x && head.y == food.y)
                food = {rand() % WIDTH, rand() % HEIGHT};
            else
                snake.pop_back();
        }

        sleepMs(100);
    }

    cout << "\033[2J\033[H";
    cout << "Game Over! Score: " << snake.size() - 1 << endl;
    return 0;
}