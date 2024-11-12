#pragma once
#include <iostream>
#include<conio.h>
#include<vector>
#include<Windows.h>
#include<fstream> 
#include<filesystem>
#define CTRL(x) (#x[0] - 'a' + 1)

using std:: cin;
using std:: cout;
using std:: string;
using std:: vector;
using std:: ofstream;
using std:: to_string;
using std:: filesystem::exists;
using std:: filesystem::create_directory;

void menu();

void system_command(const string & command);

void filecreater();

bool protect();