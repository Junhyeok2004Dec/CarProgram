//#include <winsock2.h>
//#include <ws2tcpip.h>
//#include <iostream>
//#include <string>
//#include "pch.h"
//
//// ��ũ ���̺귯��
//#pragma comment(lib, "Ws2_32.lib")
//
//const int PORT = 8080;
//const int BUFFER_SIZE = 1024;
//
//int main() {
//WSADATA wsaData;
//SOCKET ListenSocket = INVALID_SOCKET;
//SOCKET ClientSocket = INVALID_SOCKET;
//struct addrinfo* result = NULL, hints;
//char buffer[BUFFER_SIZE] = { 0 };
//
//// Winsock �ʱ�ȭ
//int iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
//if (iResult != 0) {
//std::cerr << "WSAStartup failed with error: " << iResult << std::endl;
//return 1;
//}
//
//// �ּ� ���� ����
//ZeroMemory(&hints, sizeof(hints));
//hints.ai_family = AF_INET;
//hints.ai_socktype = SOCK_STREAM;
//hints.ai_protocol = IPPROTO_TCP;
//hints.ai_flags = AI_PASSIVE;
//
//// �ּҿ� ��Ʈ�� ���ε��� ���� ����
//iResult = getaddrinfo(NULL, std::to_string(PORT).c_str(), &hints, &result);
//if (iResult != 0) {
//std::cerr << "getaddrinfo failed with error: " << iResult << std::endl;
//WSACleanup();
//return 1;
//}
//
//ListenSocket = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
//if (ListenSocket == INVALID_SOCKET) {
//std::cerr << "socket failed with error: " << WSAGetLastError() << std::endl;
//freeaddrinfo(result);
//WSACleanup();
//return 1;
//}
//
//// ���ϰ� �ּ� ���ε�
//iResult = bind(ListenSocket, result->ai_addr, (int)result->ai_addrlen);
//if (iResult == SOCKET_ERROR) {
//std::cerr << "bind failed with error: " << WSAGetLastError() << std::endl;
//freeaddrinfo(result);
//closesocket(ListenSocket);
//WSACleanup();
//return 1;
//}
//
//freeaddrinfo(result);
//
//// ���� ��û ���
//if (listen(ListenSocket, SOMAXCONN) == SOCKET_ERROR) {
//std::cerr << "listen failed with error: " << WSAGetLastError() << std::endl;
//closesocket(ListenSocket);
//WSACleanup();
//return 1;
//}
//
//std::cout << "Waiting for a connection on port " << PORT << "..." << std::endl;
//
//// Ŭ���̾�Ʈ ���� ����
//ClientSocket = accept(ListenSocket, NULL, NULL);
//if (ClientSocket == INVALID_SOCKET) {
//std::cerr << "accept failed with error: " << WSAGetLastError() << std::endl;
//closesocket(ListenSocket);
//WSACleanup();
//return 1;
//}
//
//std::cout << "Connection established." << std::endl;
//
//// ������ ���� �� ���
//while (true) {
//int valread = recv(ClientSocket, buffer, BUFFER_SIZE, 0);
//if (valread == SOCKET_ERROR) {
//std::cerr << "recv failed with error: " << WSAGetLastError() << std::endl;
//break;
//}
//if (valread == 0) {
//std::cout << "Connection closed by client." << std::endl;
//break;
//}
//
//// ��Ŷ�� ���ڿ��� ��ȯ
//std::string packet(buffer, valread);
//
//// ���ڿ� ���
//std::cout << "Received packet: " << packet << std::endl;
//
//// ���� �ʱ�ȭ
//memset(buffer, 0, BUFFER_SIZE);
//}
//
//// Ŭ���̾�Ʈ ���� ����
//closesocket(ClientSocket);
//closesocket(ListenSocket);
//WSACleanup();
//return 0;
//}
//