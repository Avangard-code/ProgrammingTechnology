// Лабораторная работа №3
// Выполнил студент
// группы: ИС-126
// Саратовцев Г.А
// Вариант: 10;


/*ОБЩИЙ ИМПОРТ*/
#include <iostream>
#include <random>
#include <iomanip>

/*ИМПОРТ ДЛЯ СИСТЕМЫ WINDOWS*/
#include <windows.h>


/*ГЛОБАЛЬНЫЕ КОНСТАНТЫ*/
const int GLB_TASK = 3;                                                                                             // Выбор номера задания


/*ОТЛАДОЧНЫЕ ФУНКЦИИ*/
/*
```
    ГЕНЕРАТОР СЛУЧАЙНЫХ ЧИСЕЛ:
    Входные данные:
        int : min_limit - минимальное число
        int : max_limit - максимальное число
    Выходные данные:
        return - случайное число (int)
```
*/
int  random_gen_num (int min_limit,int max_limit)
{
    std::mt19937 gen(std::random_device{}());
    std::uniform_int_distribution<int> dist(min_limit, max_limit);
    return dist(gen);
}


int main(void)
{
    // НАСТРОЙКА ВВОДА/ВЫВОДА
    SetConsoleCP(CP_UTF8);                                                                                          // Установка ввода с консоли UTF-8
    SetConsoleOutputCP(CP_UTF8);                                                                                    // Установка вывода с консоли UTF-8


    // ВЫБОР ЗАДАНИЯ 
    switch (GLB_TASK)
    {
    case 1:
        {
            /*  
            ЗАДАНИЕ 1:
                Даны действительные числа a1,...,a30. Если в результате замены 
                отрицательных членов последовательности a1,...,a30 их квадратами члены 
                будут образовывать неубывающую последовательность, то получить сумму 
                членов исходной последовательности; в противном случае получить их 
                произведение.
            */

            // Инициализация констант
            const int 
            LOC_MAX_SIZE_ARR = 30;                                                                                  // Количество чисел в масиве;
            // Объявление переменных
            int
            loc_arr [LOC_MAX_SIZE_ARR],                                                                             // Маcсив чисел;
            loc_tmp_1,                                                                                              // Временная переменная 1;
            loc_tmp_2;                                                                                              // Временная переменная 2;
            bool 
            loc_flag_sequence;                                                                                      // Флаг последовательности:
                                                                                                                    //      true - последовательность не является неубывающей;
                                                                                                                    //      false - последовательность неубывающая;
            double 
            loc_result;                                                                                             // Результат;

            
            // Заполнение масива случайными числами и вывод в консоль
            std :: cout << "Исходные данные:\n";
            for (int i = 0; i < LOC_MAX_SIZE_ARR; i++)
            {
                loc_arr [i] = random_gen_num(-1000,1000);
                std :: cout << std::left << std::setw(6) <<  loc_arr [i] << " | ";
            }


            // Проверка последовательности
            loc_flag_sequence = false;
            for (int i = 0; i < LOC_MAX_SIZE_ARR - 1; i++)
            {
                loc_tmp_1 = loc_arr[i];
                loc_tmp_2 = loc_arr[i + 1];

                // Проверка на отрицательные числа
                if (loc_tmp_1 < 0)
                    loc_tmp_1 = loc_tmp_1 * loc_tmp_1;

                if (loc_tmp_2 < 0)
                    loc_tmp_2 = loc_tmp_2 * loc_tmp_2;

                // последовательность неубывающей
                if (loc_tmp_1 > loc_tmp_2)
                {
                    loc_flag_sequence = true;
                    break;
                }
            }

            // Последовательность убывающая
            if (loc_flag_sequence == true)
            {
                loc_result = 1;
                for (int i = 0; i < LOC_MAX_SIZE_ARR; i++)
                {
                    loc_result *= loc_arr[i];
                }
                
            }
            // Последовательность неубывающая
            else if (loc_flag_sequence == false)
            {
                loc_result = 0;
                for (int i = 0; i < LOC_MAX_SIZE_ARR; i++)
                {
                    loc_result += loc_arr[i];
                }
            }
            
            // Вывод результата в терминал
            std :: cout << "\nРезультат:\n" << loc_result;
            
            break;
        }
    case 2:
        {
            /*  
            ЗАДАНИЕ 2:
                В матрице Z(5,6) первый отрицательный элемент каждого 
                столбца заменить суммой оставшихся. Отрицательные элементы до замены 
                вывести в массив B. Вывести исходную и преобразованную матрицы, 
                полученный массив. 
            */

            // Инициализация констант
            const int 
            LOC_MAX_STRING_ARR = 5,                                                                                 // Количество строк
            LOC_MAX_COLUMN_ARR = 6;                                                                                 // Количество столбцов
            // Объявление переменных
            int 
            loc_arr_matrix_z [LOC_MAX_STRING_ARR] [LOC_MAX_COLUMN_ARR],                                             // Матрица Z
            loc_arr_b [LOC_MAX_COLUMN_ARR*LOC_MAX_STRING_ARR],                                                      // Массив отрицательных чисел B
            cnt_arr_b;                                                                                              // Счетчик первых отрицательных масива loc_arr_b
            bool
            flag_frist_neg_num;                                                                                     // Флаг обнаружения первого отрицательного элемента столбца
            

            // Наполнение масива случайными числами и вывод в консоль
            std :: cout << "Исходная матрица (Z):"; 
            for (int i = 0; i < LOC_MAX_STRING_ARR; i++)
            {
                std :: cout << "\n-------------------------------------------------------\n" << "| ";
                for (int j = 0; j < LOC_MAX_COLUMN_ARR; j++)
                {
                    loc_arr_matrix_z [i] [j] = random_gen_num(-1000,1000);
                    std :: cout << std::left << std::setw(6) << loc_arr_matrix_z [i] [j] << " | ";
                }
            }
            std :: cout << "\n-------------------------------------------------------\n";

            // Преобразование матрицы
            cnt_arr_b = 0;
            for (int j = 0; j < LOC_MAX_COLUMN_ARR; j++)
            {
                flag_frist_neg_num = false;
                for (int i = 0; i < LOC_MAX_STRING_ARR; i++)
                {
                    if (loc_arr_matrix_z[i][j] < 0)
                    {
                        flag_frist_neg_num = true;

                        loc_arr_b[cnt_arr_b] = loc_arr_matrix_z[i][j];
                        cnt_arr_b++;

                        // Сумма оставшихся элементов столбца
                        for (int a = i + 1; a < LOC_MAX_STRING_ARR; a++)
                        {
                            loc_arr_matrix_z[i][j] += loc_arr_matrix_z[a][j];
                        }
                        break;
                    }
                }
            }

            // Вывод в терминал преобразованной матрицы
            std :: cout << "\nПреобразованная матрица (Z):"; 
            for (int i = 0; i < LOC_MAX_STRING_ARR; i++)
            {
                std :: cout << "\n-------------------------------------------------------\n" << "| ";
                for (int j = 0; j < LOC_MAX_COLUMN_ARR; j++)
                {
                    std :: cout << std::left << std::setw(6) << loc_arr_matrix_z [i] [j] << " | ";
                }
            }
            std :: cout << "\n-------------------------------------------------------\n";

            // Вывод в терминал масива B
            std :: cout << "\nМасив отрицательных элементов (B):" << "\n| ";
            for (int i = 0; i < cnt_arr_b; i++)
            {
                std :: cout << std::left << std::setw(6) << loc_arr_b [i] << " | ";
            }
            
            break;
        }
    case 3:
        {
            /*  
            ЗАДАНИЕ 3:
                Ввести последовательность из 8 символов. Если код символа 
                четный, то заменить в нем младший бит единицей, иначе - заменить два 
                младших бита нулями. Вывести исходную и преобразованную 
                последовательности в символьной и восьмеричной формах.  
            */

            // Инициализация констант
            const int 
            MAX_SIZE_ARR = 8,                                                                                      // Максимальная длина масива
            MASK_1 = 1,                                                                                            // Маска 0000 0001
            MASK_2 = 252;                                                                                          // Маска 1111 1100
            // Объявление переменных
            char 
            loc_arr [MAX_SIZE_ARR];                                                                                // Масив символов

            // Наполнение массива случайными числами и вывод в консоль
            std :: cout << "Исходные данные:\n| ";
            for (int i = 0; i < MAX_SIZE_ARR; i++)
            {
                loc_arr [i] = random_gen_num(48,122);
                std :: cout << std::oct << std::left << std::setw(8) << (int) (unsigned char) loc_arr [i] << " | ";
            }
            std :: cout << "\n| ";
            for (int i = 0; i < MAX_SIZE_ARR; i++)
            {
                std :: cout << std::left << std::setw(8) << loc_arr [i] << " | ";
            }

            // Подмена младших битов
            for (int i = 0; i < MAX_SIZE_ARR; i++)
            {
                if (loc_arr[i]%2==0)
                {
                    loc_arr [i] = loc_arr [i] | MASK_1;     // Наложение маски 0000 0001
                }
                else
                {
                    loc_arr [i] = loc_arr [i] & MASK_2;     // Наложение маски 1111 1100
                }
            }

            // Вывод результата
            std :: cout << "\nРезультат:\n| ";
            for (int i = 0; i < MAX_SIZE_ARR; i++)
            {
                std :: cout << std::oct << std::left << std::setw(8) << (int) (unsigned char) loc_arr [i] << " | ";
            }
            std :: cout << "\n| ";
            for (int i = 0; i < MAX_SIZE_ARR; i++)
            {
                std :: cout << std::left << std::setw(8) << loc_arr [i] << " | ";
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