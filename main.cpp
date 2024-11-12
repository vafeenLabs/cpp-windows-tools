#include"headOfProgram.hpp"

int main()
{
    //system("mode con cols=150 lines=35");
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
    int key = 0;
    bool program = true;
    while (program)
    {
        switch (key)
        {
        case 0:
        {
            menu();
            cout << "\nВыберите номер пункта!\n->";
            cin >> key;
            break;
        }
        case 1:
        {
            //cout << "Утилита проверки системных файлов проверяет целостность системных файлов Windows и при необходимости исправит их";
            if (protect())
                system_command("sfc.exe /scannow");
            key = 0;
            break;
        }
        case 2:
        {
            //dxdiag — диагностика компонентов DirectX;
            if (protect())
                system_command("dxdiag");
            key = 0;
            break;

        }
        case 3:
        {
            //mdsched — проверка оперативной памяти на ошибки;
            if (protect())
                system_command("mdsched");
            key = 0;
            break;

        }
        case 4:
        {
            //sysdm.cpl - Создать точку восстановления ОС в окне "Защита системы".
            system_command("sysdm.cpl");
            key = 0;
            break;

        }
        case 5:
        {
            //wmic.exe /Namespace:\\root\default Path system_commandRestore Call CreateRestorePoint “MyRestorePoint”, 100, 7 - создание точки восстановление без лишних вопросов(автоматическое)
            //В кавычках вместо «MyRestorepointName» может быть любое другое название для создаваемой контрольной точки.
            system_command("wmic.exe /Namespace:\\\\root\\default Path SystemRestore Call CreateRestorePoint “Point V”, 100, 7");
            key = 0;
            break;

        }
        case 6:
        {
            cout << "Выберите точку восстановления!! Скопируйте ее id в буфер обмена!\n\n";
            string name;
            while (1)
            {
                system("cls");
                system_command("vssadmin list shadows");
                cout << "\n\nID теневой копии:\n\t---------->";

                cin >> name;
                if (name == "0")
                    break;
                cout << "\nНажмите \'Д\', чтобы удалить выбранную точку восстановления!\n\n";
                system_command("vssadmin delete shadows /Shadow={" + name + "}");
            }

            key = 0;
            break;
        }
        case 7:
        {
            filecreater();

            key = 0;
            break;
        }

        case 8:
        {
            //Charmap.exe — открывает таблицу символов.
            system_command("charmap.exe");
            key = 0;
            break;
        }
        case 9:
        {
            //СПРАВКА f1: отключение

            system_command("reg add HKEY_CURRENT_USER\\Software\\Classes\\TypeLib\\{8cec5860-07a1-11d9-b15e-000d56bfe6ee}\\1.0\\0\\win32 /f");
            system_command("reg add HKEY_CURRENT_USER\\Software\\Classes\\TypeLib\\{8cec5860-07a1-11d9-b15e-000d56bfe6ee}\\1.0\\0\\win64 /f");

            key = 0;
            break;
        }
        case 10:
        {
            //СПРАВКА f1: включение

            system_command("reg delete HKEY_CURRENT_USER\\Software\\Classes\\TypeLib\\{8cec5860-07a1-11d9-b15e-000d56bfe6ee} /f");
            key = 0;
            break;
        }
        case 11:
        {
            //control folders - параметры проводника и очистка истории открытых файлов
            system_command("control folders");
            key = 0;
            break;

        }
        case 12:
        {
            //devmgmt.msc - диспетчер устройств
            system_command("devmgmt.msc");
            key = 0;
            break;
        }


        case 13:
        {
            //perfmon /res — мониторинг ресурсов ПК, позволяет увидеть загрузку комплектующих;
            system_command("perfmon /res");
            key = 0;
            break;

        }
        case 14:
        {
            //netplwiz — открывает настройки учетных записей пользователей;
            system_command("netplwiz");
            key = 0;
            break;

        }

        case 15:
        {
            //shutdown /s /t 45 - завершение работы через 60 секунд
            if (protect())
                system_command("shutdown /s /t 60");
            key = 0;
            break;

        }
        case 16:
        {
            //shutdown /r /t 0 - перезагрузак через 60 секунд 
            if (protect())
                system_command("shutdown /r /t 60");
            key = 0;
            break;

        }
        case 17:
        {
            //shutdown /l - смена пользователя
            if (protect())
                system_command("shutdown /l");
            key = 0;
            break;

        }
        case 18:
        {
            //Кэш DNS является своеобразным журналом, куда записываются все посещения интернет ресурсов. Из кэша DNS можно частично восстановить удаленную историю браузера, а также вспомнить важные сайты. Иногда записей становится настолько много, что кэш нуждается в очистке ipconfig /flushdns
            system_command("ipconfig /flushdns");
            key = 0;
            break;

        }
        case 19:
        {
            //wmic bios get serialnumber - Серийный номер устройства (ноутбука, например).
            system_command("wmic bios get serialnumber");
            key = 0;
            break;

        }
        case 20:
        {
            //wmic baseboard get product - модель матплаты
            system_command("wmic baseboard get product");
            key = 0;
            break;

        }
        case 21:
        {
            //wmic baseboard get version - версия матплаты 
            system_command("wmic baseboard get version");
            key = 0;
            break;

        }
        case 22:
        {
            //wmic bios get SMBIOSBIOSVersion - версия BIOS
            system_command("wmic bios get SMBIOSBIOSVersion");
            key = 0;
            break;

        }
        case 23:
        {
            //wmic path win32_VideoController get name - название видеокарты
            system_command("wmic path win32_VideoController get name");
            key = 0;
            break;

        }
        case 24:
        {
            //wmic OS get Caption,OSArchitecture,Version - информация о Windows - 64\32
            system_command("wmic OS get Caption,OSArchitecture,Version");
            key = 0;
            break;

        }

        case 25:
        {
            //winver.exe - версия Windows.
            system_command("winver.exe");
            key = 0;
            break;

        }
        case 26:
        {
            //msinfo32 - подробная информация о системе
            system_command("msinfo32");
            key = 0;
            break;

        }
        case 27:
        {
            //system_commandinfo. Позволяет получить подробную информацию о конфигурации компьютера и установленной на нём операционной системе, включая сведения об изготовителе ПК, процессоре, объёме оперативной памяти, сетевом адаптере, версии BIOS/UEFI, поддержке технологий виртуализации, дате инсталляции ОС и прочие данные.
            system_command("systeminfo");
            key = 0;
            break;

        }
        case 28:
        {
            //sysdm.cpl — открывает «Свойства системы»;
            system_command("sysdm.cpl");
            key = 0;
            break;

        }

        case 29:
        {
            //ncpa.cpl — открывает сетевые подключения;
            system_command("ncpa.cpl");
            key = 0;
            break;

        }
        case 30:
        {
            //Активация Windows
            if (protect())
            {
                system_command("slmgr /ipk TX9XD-98N7V-6WMQ6-BX7FG-H8Q99");
                system_command("slmgr /skms kms8.msguides.com");
                system_command("slmgr /ato");
            }

            key = 0;
            break;
        }
        case 31:
        {
            cout << "\nДелить на 1024*1024\n\n";
            system_command("wmic memphysical get MaxCapacity, MemoryDevices");

            key = 0;
            break;
        }
        }

        if (key == 0)
        {
            cout << "\nЩелкните любую клавишу для продолжения ... ";
            _getch();
        }
        system("cls");
    }

    //перезагрузка, если выполнялись определенные действия, например была создана точка отката и .д.
    //shutdown /r /c “Этот сервер будет перезагружен через 60 секунд.”
    _getch();
    return 0;
}