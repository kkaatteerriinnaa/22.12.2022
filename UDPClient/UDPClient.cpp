#pragma comment(lib, "Ws2_32.lib")
#include <WinSock2.h>
#include <WS2tcpip.h>

#include <iostream>
using namespace std;

int main()
{
    WSADATA wsadata;

    int res = WSAStartup(MAKEWORD(2, 2), &wsadata);
    if (res != NO_ERROR)
    {
        cout << "WSAStartup failked with error " << res << endl;
        return 1;
    }

    SOCKET udpSocket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (udpSocket == INVALID_SOCKET)
    {
        cout << "socket failed with error " << WSAGetLastError() << endl;
        return 2;
    }  

    sockaddr_in addrTo;
    addrTo.sin_family = AF_INET;
    addrTo.sin_port = htons(23000);
    inet_pton(AF_INET, "127.0.0.1", &addrTo.sin_addr.s_addr);

    const size_t sendBufSize = 1024;
    char sendBuf[sendBufSize] = "Hello from UDPClient";

    cout << "Sending data...." << endl;
    int sendResult = sendto(udpSocket, sendBuf, strlen(sendBuf), 0, (SOCKADDR*)&addrTo, sizeof(addrTo));
    if (sendResult == SOCKET_ERROR)
    {
        cout << "sendto failed with error " << WSAGetLastError() << endl;
        return 4;
    }

    const size_t receiveBufSize = 1024;
    char receiveBuf[receiveBufSize];

    sockaddr_in addrFrom;
    int addrFromSize = sizeof(addrFrom);

    cout << "Receiving data...." << endl;
    int bytesReceived = recvfrom(udpSocket, receiveBuf, receiveBufSize, 0, (SOCKADDR*)&addrFrom, &addrFromSize);

    if (bytesReceived == SOCKET_ERROR)
    {
        cout << "recvfrom failed with error " << WSAGetLastError() << endl;
        return 4;
    }

    receiveBuf[bytesReceived] = '\0';
    cout << "Received from " << addrFrom.sin_addr.s_host << endl;
    cout << "Data: " << receiveBuf << endl;

    string word, s, g, p;
    s = "sprite";
    g = "hamburger";
    p = "free potato";

    while (true)
    {
        cin >> word;
        int pos1 = word.find(s);
        int pos2 = word.find(g);
        int pos3 = word.find(p);

        if (pos1 != -1) // ���� �����
        {
            int time =+ 1;
        }
        if (pos1 != -1) // ���� ���������
        {
            int time =+ 5;
        }
        if (pos1 != -1) // ���� ��������
        {
            int time =+ 3;
        }
        cout << "�� ������������� ������ ������ ���������� " << time << " ���������� ��������";
        Sleep(9000);
    }
    closesocket(udpSocket);
    WSACleanup();
}

