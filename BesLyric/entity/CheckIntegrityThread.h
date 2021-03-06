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
* @file       CheckIntegrity.h
* 
* Describe    启动一个线程，用于检测程序完整性，自动下载需要的组件
*/

#pragma once
#include "stdafx.h"
#include "../utility/WinFile.h"
#include "../utility/SSingleton.h"
using namespace SOUI;


class  CCheckIntegrityThread : public Singleton<CCheckIntegrityThread>
{
public:
	// 检查程序的完整性
	CCheckIntegrityThread():m_handleThreadCheking(NULL),m_handleThreadUI(NULL),m_hCheckWnd(NULL),m_EventWndInitDone(NULL), m_bIsChecking(false),m_nPercentage(0){}

	//开始线程
	bool Start(bool bShowPassTip);

	//结束线程
	void Stop();

private:

	//检测（与下载） 线程执行地址
	static DWORD WINAPI ProcChecking(LPVOID pParam);

	//UI 线程执行地址
	static DWORD WINAPI ProcUI(LPVOID pParam);

	
	//检查ffmpeg.exe 是否存在，不存在则下载
	bool CheckFFmpeg();

	//更新UI界面
	void UpdateProgressUI(int nPercentage, const WCHAR* pszTip);
	
	void RestoreProcess();
	void CloseProgressUI();

private:
	HWND		m_hCheckWnd;			/* 显示检测进度窗口的句柄 */

	HANDLE		m_handleThreadCheking;	/* 当前线程句柄 */
	HANDLE		m_handleThreadUI;		/* UI线程句柄 */
	
	HANDLE		m_EventWndInitDone;		/* 停止等待时间 */

	bool		m_bShowPassTip;			/* 表示在检查后，结果为完整时，进行提示 */
	bool		m_bIsChecking;			/* 表示是否正在检测 */

	int			m_nPercentage;			/* 最后一次记录的进度百分比 */
	WCHAR		m_szTip[MAX_BUFFER_SIZE];/* 最后一次记录的进度消息 */				
};

