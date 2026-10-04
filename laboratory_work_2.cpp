// Лабораторная работа №2
// Выполнил студент
// группы: ИС-126
// Саратовцев Г.А
// Вариант: 10;


/*ОБЩИЙ ИМПОРТ*/
#include <iostream>
#include <cmath>
#include <iomanip>

/*ИМПОРТ ДЛЯ СИСТЕМЫ WINDOWS*/
#include <windows.h>

/*ГЛОБАЛЬНЫЕ КОНСТАНТЫ*/
const int GLB_METHOD = 2;                   // Выбор метода табуляции:
                                            // 1 - Цикл for;
                                            // 2 - Цикл while;

/*
Табуляция функции:

    x*sh(2x);     x>0
y = 0;            x=0
    -x^3*e^x;     x<0
    
x∈[-0.5,0.5] h=0.1
*/
int main(void)
{
    // НАСТРОЙКА ВВОДА/ВЫВОДА
    SetConsoleCP(CP_UTF8);                  // Установка ввода с консоли UTF-8
    SetConsoleOutputCP(CP_UTF8);            // Установка вывода с консоли UTF-8

    // ИНИЦИАЛИЗАИЯ КОНСТАНТ
    const double 
    h = 0.1,                                // Шаг функции
    EPS = 0.000000001,                      // Константа коррекция формата с плавающей точкой
    x [2] = {-0.5,0.5};                     // Множество функции

    // ОБЬЯВЛЕНИЕ ПЕРЕМЕННЫХ
    double 
    tmp_cnt,                                 // Счетчик с шагом h (равен переменной x) для цикла while
    y;                                       // Значение функции (y)

    // ШАПКА ТАБЛИЦЫ
    std :: cout << " --------------------------------------------------------------- \n";
    std :: cout << "|               x               |               y               |\n";
    std :: cout << "|---------------------------------------------------------------|\n";

    // ВЫБОР МЕТОДА ТАБУЛЯЦИИ
    switch (GLB_METHOD)
    {
    case 1:
        {
            for (double i = x[0]; i<=x[1]+EPS; i+=h)
            {
                // Расчет по формуле:
                //     x*sh(2x);     x>0
                // y = 0;            x=0
                //    -x^3*e^x;      x<0
                if (i>EPS)
                {
                    y = i*sinh(2.0*i);
                }
                else if (i<-EPS)
                {
                    y = pow(-i,3)*exp(i);
                }
                else
                {
                    y = 0.0;
                }
                std :: cout << "|" << std::left << std::setw(31) << std::fixed << i;
                std :: cout << "|" << std::left << std::setw(31) << std::fixed << y << "|\n";
                std :: cout << "|_______________________________|_______________________________|\n";
            }

            break;
        }
    case 2:
        {   
            // Инициализация x
            tmp_cnt = x[0];
            while (tmp_cnt<=x[1]+EPS)
            {
                // Расчет по формуле:
                //     x*sh(2x);     x>0
                // y = 0;            x=0
                //    -x^3*e^x;      x<0
                if (tmp_cnt>EPS)
                {
                    y = tmp_cnt*sinh(2.0*tmp_cnt);
                }
                else if (tmp_cnt<-EPS)
                {
                    y = pow(-tmp_cnt,3)*exp(tmp_cnt);
                }
                else
                {
                    y = 0.0;
                }

                std :: cout << "|" << std::left << std::setw(31) << std::fixed << tmp_cnt;
                std :: cout << "|" << std::left << std::setw(31) << std::fixed << y << "|\n";
                std :: cout << "|_______________________________|_______________________________|\n";
                // Сдвиг по x на шаг h
                tmp_cnt+=h;
            }

            break;
        }
    default:
        {
            break;
        }
    }

    return 0;
}



















































































































































































































































































//Fallen777Angel