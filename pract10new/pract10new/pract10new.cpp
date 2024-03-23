// pract10new.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <windows.h>
#include <conio.h>
#include <iostream>
#include <math.h>

//6
DWORD WINAPI ThreadFlow1(LPVOID lpParam) {
    std::cout << "1 поток.\n";

    int num1 = 5;
    std::cout << "Число 5 которое умножиться на 9 \n";
    
    int result = num1 * 9;


    std::cout << "Результат " << result << std::endl;
    _getch();
    return 0;
}

DWORD WINAPI ThreadFlow2(LPVOID lpParam) {
    std::cout << "2 поток.\n";
    double num2 = 8;
    std::cout << "Число 8  которое  поделиться на 3 \n";
    
    double result = num2 / 3;


    std::cout << "Результат " << result << std::endl;
    
    _getch();
    return 0;
}
DWORD WINAPI ThreadFlow3(LPVOID lpParam) {
    std::cout << "3 поток.\n";

    int num3 = 7;
    std::cout << "Число 7  в  степени 5 \n";
    
    int result = pow(num3, 5);


    std::cout << "Результат " << result << std::endl;
    _getch();
    return 0;

   
}



int main(int argc, char* argv[])
{
    PROCESS_INFORMATION piApp;
    setlocale(LC_ALL, "rus");
    int valueReceived;

    

    valueReceived = atoi(argv[1]);
    std::cout << "Значение которое было передано: " << valueReceived << std::endl;

   


   
    int result = valueReceived * 9 / 3;
     std::cout << "Результат: " <<result << std::endl;
     _getch();

     HANDLE hThread1 = NULL;
     HANDLE hThread2 = NULL;
     HANDLE hThread3 = NULL;
     while (true) {
         std::cout << "6 и 7 задания:" << std::endl;
         int choice;
         std::cout << "Что хотите сделать?: \n ";
         std::cout << "Нажмите -1- если хотите создать 1 поток \n ";
         std::cout << "Нажмите -2- если хотите создать 2 поток \n";
         std::cout << "Нажмите -3- если хотите создать 3 поток  \n ";
         std::cin >> choice;

         if (choice == 1)
         {
             if (hThread1 == NULL) {
                 std::cout << "Поток 1 создался  \n";
               
                 hThread1 = CreateThread(NULL, 0, ThreadFlow1, NULL, 0, NULL);
                 WaitForSingleObject(hThread1, 1000);
                 _getch();
                
                 TerminateThread(hThread1, 0);
                 std::cout << " Поток 1 завершился  \n";
             }
         }

         else if (choice == 2)
         {
             if (hThread2 == NULL) {
                 std::cout << "Поток 2 создался  \n";
                 hThread2 = CreateThread(NULL, 0, ThreadFlow2, NULL, 0, NULL);
                 WaitForSingleObject(hThread2, 1000);
                 _getch();
                 
                 TerminateThread(hThread2, 0);
                 
                 std::cout << "  Поток 2 завершился  \n";
             }
         }
         else if (choice == 3)
         {
             if (hThread3 == NULL) {
                 std::cout << "Поток 3 создался  \n";
                 hThread3 = CreateThread(NULL, 0, ThreadFlow3, NULL, 0, NULL);
                 WaitForSingleObject(hThread3, 1000);
                 _getch();
                 
                 TerminateThread(hThread3, 0);
                 std::cout << "Поток 3 завершился  \n";
             }
         }
         else
         {
             std::cout << "Увы, возможно создать только 3" << std::endl;
         }
     }



    _getch();
    return 0;
}





// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
