#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h>
#include <random>
#include <conio.h>
#include <vector>
#include <thread>
#include <fstream> //File handler
#include <time.h>
#include <chrono>
#include <mutex>
#include <algorithm>
#include <array>

#pragma region Namespace
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::setw;
using std::vector;
using std::ios;
using std::fstream;
using std::ifstream;
using std::ofstream;
using std::streampos;
using std::ostream;
using std::thread;
using std::mutex;

using std::begin;
using std::end;
using std::random_shuffle;

using std::random_device;
using std::mt19937_64;
using std::uniform_int_distribution;
using std::default_random_engine;
#pragma endregion