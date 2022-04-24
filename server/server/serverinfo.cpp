#include <stdio.h>
#include <winsock2.h>

#pragma comment(lib, "ws2_32")
#pragma warning(disable:4996)

int main()
{
    WSADATA wsa;
    WSAStartup(MAKEWORD(2, 2), &wsa);

    
    SOCKET listener = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

 
    SOCKADDR_IN addr;
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    addr.sin_port = htons(8000);

    int ret;
    bind(listener, (SOCKADDR*)&addr, sizeof(addr));

  
    listen(listener, 5);

 
    SOCKET client = accept(listener, NULL, NULL);



    char buf[256];
    while (1)
    {
        ret = recv(client, buf, sizeof(buf), 0);
        if (ret <= 0)
            break;

        buf[ret] = 0;
        printf("%s", buf);
    }

   
    closesocket(client);
    closesocket(listener);
    WSACleanup();
}