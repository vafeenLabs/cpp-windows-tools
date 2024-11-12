#include"headOfProgram.hpp"


void menu()
{
	cout << "Windows tools by Albarracin";
	cout << "\n  1.Восстановление системных файлов"
		<< "\n  2.Диагностика компонентов DirectX"
		<< "\n  3.Проверка оперативной памяти на ошибки"
		<< "\n  4.Создание точки восстановление вручную"
		<< "\n  5.Автоматическое создание точки восстановления(без подтверждения)"
		<< "\n  6.Выборочное удаление точек восстановления"
		<< "\n  7.Создание базовых файлов стопками"
		<< "\n  8.Таблица символов"
		<< "\n  9.СПРАВКА f1: отключение"
		<< "\n  10.СПРАВКА f1: включение"
		<< "\n  11.Параметры проводника и очистка истории открытых файлов"
		<< "\n  12.Диспетчер устройств"
		<< "\n  13.Мониторинг ресурсов ПК (позволяет увидеть загрузку комплектующих)"
		<< "\n  14.Настройки учетных записей пользователей"
		<< "\n  15.Завершение работы через 60 секунд"
		<< "\n  16.Перезапуск через 60 секунд"
		<< "\n  17.Смена пользователя"
		<< "\n  18.Очистка кэша DNS(посещения сайтов)"
		<< "\n  19.Серийный номер устройства"
		<< "\n  20.Модель матплаты"
		<< "\n  21.Версия матплаты"
		<< "\n  22.Версия BIOS"
		<< "\n  23.Название видеокарты"
		<< "\n  24.Информация о Windows"
		<< "\n  25.Версия Windows"
		<< "\n  26.Подробная информация о системе"
		<< "\n  27.Сведения об ОС, изготовителе,процессоре, объеме ОП, сетевом адаптере, BOIS, дата инсталляции"
		<< "\n  28.Свойства системы"
		<< "\n  29.Сетевые подключения"
		<< "\n  30.Активация Windows"
		<< "\n  31.Максимально возможный оъем оперативной памяти"
		<< '\n';
}

void system_command(const string& command)
{
	system(command.c_str());
	//если string, то string.c_str()
	//cout << command;
}

void filecreater()
{
	cout << "\n1.БЛОКНОТ (txt)\n2.WORD (docx)\n3.EXCEL (xlsx)\n4.ACCESS (accdb)\n5.POWER POINT (pptx)\n";
metka:cout << "Выберите номер типа файлов и их количество\n -> -> ";
	int type, number_of_files;
	cin >> type >> number_of_files;
	ofstream filew;
	int x = 1;
	string name_of_file, extension;
	switch (type)
	{
	case 1:
	{
		name_of_file = "TXT";
		extension = ".txt";
		break;
	}
	case 2:
	{
		name_of_file = "DOCX";
		extension = ".docx";
		break;
	}
	case 3:
	{
		name_of_file = "EXCEL";
		extension = ".xlsx";
		break;
	}
	case 4:
	{
		name_of_file = "ACCESS";
		extension = ".accdb";
		break;
	}
	case 5:
	{
		name_of_file = "POWER POINT";
		extension = ".pptx";
		break;
	}
	default:
	{
		cout << "В работе программы произошла ошибка, повторите процедуру!\n\n";
		goto metka;
	}
	}
	for (int i = 0; i < number_of_files; i++)
	{
		while (true)
		{
			string name = "[" + to_string(x) + "]" + name_of_file + extension;
			if (!exists(name))
			{
				filew.open(name);
				filew.close();
				break;
			}
			else
			{
				x++;
			}
		}
	}
}

bool protect() 
{
	cout << "Нажмите ctrl+V,A,F\n";
	int x = _getch();
	if (x == 22)
	{
		cout << 'V' << ' ';
		int y = _getch();
		if (y == 1)
		{
			cout << 'A' << ' ';
			int z = _getch();
			if (z == 6)
			{
				cout << "F I N\n";
				return true;
			}
		}
		
	}
	cout << "Возврат в меню...\n";
	return false;
}