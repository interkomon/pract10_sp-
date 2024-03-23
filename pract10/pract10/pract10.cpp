// pract10.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <windows.h>
#include <conio.h>
#include <iostream>



    //wchar_t lpszAppName[] = L"C:\\Program Files\\Windows NT\\Accessories\\wordpad.exe";
int main()
{
    setlocale(LC_ALL, "rus");
    char lpzComline[80];

   // wchar_t lpszAppName[] = L"C:\\Users\\Andrey\\Desktop\\pract10new\\x64\\Debug\\pract10new.exe";
    STARTUPINFO si;
    PROCESS_INFORMATION piApp;

    HANDLE hProcess;
    //дескриптор наследования
    HANDLE InheritProcess ;

    hProcess = GetCurrentProcess();

    int number;
    std::cout << "Введите число для передачи: ";
    std::cin >> number;
   
    if (!DuplicateHandle(GetCurrentProcess(),hProcess, GetCurrentProcess(),  &InheritProcess,  0,TRUE,DUPLICATE_SAME_ACCESS)) 
    {
        _cputs("The pseudodescriptor is not created(((\n");
        _cputs("Check a name of the process\n");
        _cputs("Press any key to finish.\n");
        _getch();
        return 0;
    }
    std::cout << "Duplicate pseudodescreptors create." << std::endl;

    _getch();

    ZeroMemory(&si, sizeof(STARTUPINFO));
    si.cb = sizeof(STARTUPINFO);

    wsprintf(lpzComline,"C:\\Users\\Andrey\\Desktop\\pract10new\\x64\\Debug\\pract10new.exe %d", &InheritProcess);


    if (!CreateProcess(NULL, lpzComline, NULL, NULL, FALSE,
        CREATE_NEW_CONSOLE, NULL, NULL, &si, &piApp))
    {
        
        
        _cputs("The new process is not created\n");
        _cputs("Check a name of the process\n");
        _cputs("Press any key to finish\n");
        _getch();
        return 0;
    }
   
        _cputs("The new process is created.\n");
        std::cout << "PID: " << piApp.dwProcessId << std::endl;
        std::cout << "handle: " << piApp.hProcess << std::endl;

        Sleep(5000);
        while (true)
        {
            char c;
            _cputs("Input 't' to terminate the new console process: ");
            c = _getch();
            if (c == 't')
            {
                _cputs("t\n");
               
                bool a = TerminateProcess(piApp.hProcess, 1);
                if (!a)
                {
                    _cputs("Failed to terminate process\n");
                }
                else
                {
                    _cputs("Process has been completed successfully\n");
                }
                break;
            }
        }
       
        WaitForSingleObject(piApp.hProcess, INFINITE);

        TerminateThread(piApp.hThread, 0);
        TerminateProcess(piApp.hProcess, 0);

     
        CloseHandle(piApp.hProcess);
        CloseHandle(piApp.hThread);

       

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
