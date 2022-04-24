#include <stdio.h>
#include <winsock2.h>

#pragma comment(lib, "ws2_32")
#pragma warning(disable:4996)

int main()
{
    // Khoi tao thu vien
    WSADATA wsa;
    WSAStartup(MAKEWORD(2, 2), &wsa);

    // Tao socket
    SOCKET listener = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    // Khai bao dia chi server
    SOCKADDR_IN addr;
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    addr.sin_port = htons(8000);

    
    // Gan cau truc dia chi voi socket
    bind(listener, (SOCKADDR*)&addr, sizeof(addr));

    // Chuyen sang trang thai cho ket noi
    listen(listener, 5);

    // Cho ket noi moi
     // Cho ket noi moi
   


    int ret;
    char buf[256];
    while (1)
    {
        SOCKET client = accept(listener, NULL, NULL);
        ret = recv(client, buf, sizeof(buf), 0);
        if (ret <= 0)
            break;

        
        buf[ret] = 0;
        printf("%s", buf);
        closesocket(client);
    }

    // Dong ket noi va giai phong thu vien
   
    closesocket(listener);
    WSACleanup();
}