//I WANT TO PLAY WITH YOU
//        YOUR FRIEND, AI
#include <stdio.h>

#define WIDTH 80
#define HEIGHT 25
#define PADDLE_SIZE 3 // размер ракетки по вертикаи
#define WIN_SCORE 21

void clearScreen();
void draw();
void update();
void input();



// решить задачу отчистки экрана // TODO
void clearScreen() {
  //system("clear");
  printf("\033[0d\033[2J");
  //printf ("\f"); 
}
// отрис поля
void draw() {
int ballX = WIDTH / 2, ballY = HEIGHT / 2; // нач позиция мяча в центте

int paddleLeftY = HEIGHT / 2 - PADDLE_SIZE / 2; // нач поз левой ракеты
int paddleRightY = HEIGHT / 2 - PADDLE_SIZE / 2; // нач поз правой ракеты
int scoreLeft = 0, scoreRight = 0;               // счета игроков
  clearScreen(); // очистка перед игрой
  int counter;
  // отрисовка по строкам поля
  for (int y = 0; y < HEIGHT; y++) {
    // по столбцам
    for (int x = 0; x < WIDTH; x++) {
      // вертикальные границы
      //int temp = x;
      if (x == 0 || x == WIDTH - 1) {
        printf("**");
      } else if (x == WIDTH / 2 && y != HEIGHT / 2 && counter == 0) {
        printf("|");
        //temp++;
        counter++;
      } else if( x == WIDTH / 2 && counter > 0) {
        printf("I");
      }
        else if (y == 0 || y == HEIGHT - 1) {// границы по горизонтали
        printf("*");
        // отрисовка левой ракеты
      } else if (x == 2 && y >= paddleLeftY && y < paddleLeftY + PADDLE_SIZE) {
        printf("|");
        // отрисовка правой
      } else if (x == WIDTH - 3 && y >= paddleRightY &&
                 y < paddleRightY + PADDLE_SIZE) {
        printf("|");
        // мяч
      } else if (x == ballX && y == ballY) {
        printf("O");
      } else {
        printf(" "); // пустое поле
      }
    }
    printf("\n");
  }
  // вывод каррент счета
  printf("Score: %d - %d\n", scoreLeft, scoreRight);
}
// обновление гейм стейта
void update() {
int ballX = WIDTH / 2, ballY = HEIGHT / 2; // нач позиция мяча в центте
int ballDirX = 1, ballDirY = 1; // направление мяч движения по х и по у
int paddleLeftY = HEIGHT / 2 - PADDLE_SIZE / 2; // нач поз левой ракеты
int paddleRightY = HEIGHT / 2 - PADDLE_SIZE / 2; // нач поз правой ракеты
int scoreLeft = 0, scoreRight = 0;               // счета игроков
  ballX += ballDirX; // обн мяча по гор
  ballY += ballDirY; // обн мяча по верт

  // отскок мяча от верха и низа
  if (ballY <= 1 || ballY >= HEIGHT - 2) {
    ballDirY = -ballDirY; // изм напр во верт
  }
  // отскок мяча от левой рак
  if (ballX == 3 && ballY >= paddleLeftY && ballY < paddleLeftY + PADDLE_SIZE) {
    ballDirX = -ballDirX; // изм напр гор
  }
  // отскок мяча от прав рак
  if (ballX == WIDTH - 4 && ballY >= paddleRightY &&
      ballY < paddleRightY + PADDLE_SIZE) {
    ballDirX = -ballDirX; // изм напр гор
  }
  // если мяч пересек лев границу - (+)очко праавого
  if (ballX <= 0) {
    scoreRight++;
    ballX = WIDTH / 2; // сброс мяча к центру
    ballY = HEIGHT / 2;
    ballDirX = 1; // мяч в право напрвлен
  }
  // если мяч пересек прав границу - (+)очко лев
  if (ballX >= WIDTH - 1) {
    scoreLeft++;
    ballX = WIDTH / 2;
    ballY = HEIGHT / 2;
    ballDirX = -1; // обратное действие
  }
}

// инпут функ
void input() {

  int paddleLeftY = HEIGHT / 2 - PADDLE_SIZE / 2; // нач поз левой ракеты 
  int paddleRightY = HEIGHT / 2 - PADDLE_SIZE / 2; // нач поз правой ракеты

  char ch;
  if (scanf("%c", &ch) == 1) {
    switch (ch) {
    case 'a':
      if (paddleLeftY > 1)
        paddleLeftY--;
      break; // движ лев ракетки вверх
    case 'z':
      if (paddleLeftY < HEIGHT - PADDLE_SIZE - 1)
        paddleLeftY++;
      break; // движ лев ракетки вниз
    case 'k':
      if (paddleRightY > 1)
        paddleRightY--;
      break; // движ пр ракетки вверх
    case 'm':
      if (paddleRightY < HEIGHT - PADDLE_SIZE - 1)
        paddleRightY++;
      break; // движ пр ракетки вниз
    case ' ':
      update();
      break; // обнов состояния игры (ускорение мача) нажатие пробела будет
             // вызыв метод update и мяч будет быстрее итерационного цикла
    }
  }
}

int main() {

  int scoreLeft = 0, scoreRight = 0;               // счета игроков
  while (scoreLeft < WIN_SCORE && scoreRight < WIN_SCORE) {
    draw();
    input();
  }
  clearScreen();
  if (scoreLeft >= WIN_SCORE) {
    printf("Player 1 wins!\n");
  } else {
    printf("Player 2 wins!\n");
  }
  return 0;
}




