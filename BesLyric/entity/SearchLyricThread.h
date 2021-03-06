/*
	BesLyric  一款 操作简单、功能实用的 专门用于制作网易云音乐滚动歌词的 歌词制作软件。
    Copyright (C) 2017  
	Author: BensonLaur <BensonLaur@163.com>
	Author:

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

/**
* @file       SearchLyricThread.h
* 
* Describe    启动一个线程，用于下载歌词
*/

#pragma once
#include "stdafx.h"
#include "../utility/WinFile.h"
#include "../utility/SSingleton.h"
using namespace SOUI;


class  CSearchLyricThread : public Singleton<CSearchLyricThread>
{
public:
	// 检查程序的完整性
	CSearchLyricThread():m_handleThreadSearch(NULL){}

	//开始线程
	bool Start(HWND hMainWnd, SStringW& strMusicName, SStringW& strMusicArtist);

private:

	// 线程执行地址
	static DWORD WINAPI ProcSearch(LPVOID pParam);

private:

	HANDLE		m_handleThreadSearch;	/* 当前线程句柄 */	
	HWND		m_hMainWnd;				/* 主窗口句柄 */

	SStringW	m_strMusicName;			
	SStringW	m_strMusicArtist;
};

