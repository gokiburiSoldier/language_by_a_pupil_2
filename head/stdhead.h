#ifndef _NING_STH_H
#define _NING_STH_H

#include <iostream>
#include <stdio.h>
/* byt: byte的缩写 */
#define byt char
using namespace std;

const int nml_version=1003; /* 每次都得改 */

/* 下面的慎看 */
#ifdef __linux__
std::string sys="Linux";
#elif __APPLE__
std::string sys="Apple Device";
#elif _WIN32
std::string sys="Windows";
#elif __unix__
std::string sys="Unix";
#else
std::string sys="Unknown OS";
#endif

#endif