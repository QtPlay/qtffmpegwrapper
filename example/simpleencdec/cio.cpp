/*
   console io

   Copyright (C) 2008,2009:
         Daniel Roggen, droggen@gmail.com

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/

#include <stdio.h>
//#include <unistd.h>
//#include <conio.h>
#include <stdlib.h>
#include <string.h>
//#include <wincon.h>
//#include <windows.h>
#include <string>


#ifdef WIN32

#include <wtypes.h>
int ConsoleInit(void)
{
	//create debug console
	AllocConsole();
 
	//initial screen buffer so console commands will work	
 	HANDLE hStdout=CreateConsoleScreenBuffer(GENERIC_WRITE|GENERIC_READ,FILE_SHARE_WRITE, NULL,CONSOLE_TEXTMODE_BUFFER, NULL);
 	
	//error check
	if(hStdout==0) 
		return 1;
 		
	SetConsoleActiveScreenBuffer(hStdout);
 	
	//lets text formating (ie newlines, etc)  work with writeconsole()
	SetConsoleMode(hStdout, ENABLE_PROCESSED_OUTPUT);
 
	//redirects std output to console buffer, so that printf works
	//freopen( "CON", "w", stdout );  //redirects stdout to console, but 
	//doesn"t work after SetConsoleActiveScreenBuffer issued
   freopen("CONOUT$", "wta", stdout);
	//freopen("CONOUT$", "wta+", stdout);
 	
	//Also let us read from console with c library, since I can"t get 
	//ReadConsole to work
	freopen("CONIN$","r",stdin);
 	
	//set console title
	char *title="Console";
#ifdef UNICODE
	 // Convert to a wchar_t*
    size_t origsize = strlen(title) + 1;
    const size_t newsize = 128;
    size_t convertedChars = 0;
    wchar_t wcstring[newsize];
    mbstowcs(wcstring, title, newsize);
//    wcscat_s(wcstring, L" (wchar_t *)");

	SetConsoleTitle(wcstring);
#endif
#ifndef UNICODE
	SetConsoleTitle(title);
#endif
 	
	//set buffer size
	COORD crd;
	crd.X=80;
	crd.Y=3000;
	SetConsoleScreenBufferSize(hStdout, crd);	
}
#endif


#ifdef LINUX

int ConsoleInit(void)
{
	return 0;
}

#endif





