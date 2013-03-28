#include "std.h"
#include "Socks.h"

int WINAPI WinMain(HINSTANCE,HINSTANCE,LPSTR,int)
{
	WSADATA wdata;
	WSAStartup(0x0202,&wdata);
	Socks5 *s5 = new Socks5("0.0.0.0",6000);
	s5->Start();
	s5->Wait();
	return 0;
}
