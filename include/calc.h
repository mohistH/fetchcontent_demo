#pragma once
#ifndef _lib_sp_api_
#define _lib_sp_api_	__declspec(dllexport)
#else
#define _lib_sp_api_	__declspec(dllimport)
#endif /// !_lib_pipe_api_





class _lib_sp_api_ calc
{
public:
	int add(int a = 0, int b = 2);
};
