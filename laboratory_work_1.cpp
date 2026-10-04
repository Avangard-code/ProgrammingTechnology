// Лабораторная работа №1
// Выполнил студент
// группы: ИС-126
// Саратовцев Г.А
// Вариант: 10;


/*ОБЩИЙ ИМПОРТ*/
#include <iostream>
#include <cmath>

/*ИМПОРТ ДЛЯ СИСТЕМЫ WINDOWS*/
#include <windows.h>

/*ГЛОБАЛЬНЫЕ КОНСТАНТЫ*/
const int num_task = 2;                     // Выбор задания:
                                            // 1 - Задание 1;
                                            // 2 - Задание 2;

int main(void)
{
    SetConsoleCP(CP_UTF8);                  // Установка ввода с консоли UTF-8
    SetConsoleOutputCP(CP_UTF8);            // Установка вывода с консоли UTF-8

    /*ОБЬЯВЛЕНИЕ ПЕРЕМЕННЫХ*/
    double k;

    switch (num_task) {
    case 1:

        // Обьявление переменных
        int x,y,z;

        // Ввод значений с терминала
        std :: cout << "Ввод значений переменных:\n";
        std :: cout << "\tx = ";
        std :: cin >> x;
        std :: cout << "\n\ty = ";
        std :: cin >> y;
        std :: cout << "\n\tz = ";
        std :: cin >> z;

        // Расчет по формуле:
        // k = ln|(y-√|x|)*(x-y/(z+x^2/4))|
        k = log(abs((y-sqrt(abs(x)))* (x-((y)/(z+pow(x,2)/4.0)))));

        // Вывод результата в терминал
        std :: cout << "\nРезультат:";
        std :: cout << "\n\tk = " << k;

        break;

    case 2:

        // Обьявление переменных
        int f,q;

        // Ввод значений с терминала
        std :: cout << "Ввод значений переменных:\n";
        std :: cout << "\tf = ";
        std :: cin >> f;
        std :: cout << "\n\tq = ";
        std :: cin >> q;

        // Расчет по формуле:
        //       ln(|f|+|q|);   |f*q|>10
        //  k =  e^(f+q);       |f*q|<10
        //       f+q;           |f*q|=10
        if (abs(f*q)>10) k = log(abs(f)+abs(q));
        else if (abs(f*q)<10) k = exp(f+q);
        else if (abs(f*q)==10) k = f+q;

        // Вывод результата в терминал
        std :: cout << "\nРезультат:";
        std :: cout << "\n\tk = " << k;

        break;
    }

    return 0;
}



















































































































































































































































































//Fallen777Angel