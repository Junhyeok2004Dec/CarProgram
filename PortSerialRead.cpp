//#include <winsock2.h>
//#include <ws2tcpip.h>
//#include <iostream>
//#include <string>
//#include "pch.h"
//
//// 링크 라이브러리
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
//// Winsock 초기화
//int iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
//if (iResult != 0) {
//std::cerr << "WSAStartup failed with error: " << iResult << std::endl;
//return 1;
//}
//
//// 주소 정보 설정
//ZeroMemory(&hints, sizeof(hints));
//hints.ai_family = AF_INET;
//hints.ai_socktype = SOCK_STREAM;
//hints.ai_protocol = IPPROTO_TCP;
//hints.ai_flags = AI_PASSIVE;
//
//// 주소와 포트에 바인딩할 소켓 생성
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
//// 소켓과 주소 바인딩
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
//// 연결 요청 대기
//if (listen(ListenSocket, SOMAXCONN) == SOCKET_ERROR) {
//std::cerr << "listen failed with error: " << WSAGetLastError() << std::endl;
//closesocket(ListenSocket);
//WSACleanup();
//return 1;
//}
//
//std::cout << "Waiting for a connection on port " << PORT << "..." << std::endl;
//
//// 클라이언트 연결 수락
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
//// 데이터 수신 및 출력
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
//// 패킷을 문자열로 변환
//std::string packet(buffer, valread);
//
//// 문자열 출력
//std::cout << "Received packet: " << packet << std::endl;
//
//// 버퍼 초기화
//memset(buffer, 0, BUFFER_SIZE);
//}
//
//// 클라이언트 소켓 종료
//closesocket(ClientSocket);
//closesocket(ListenSocket);
//WSACleanup();
//return 0;
//}
//