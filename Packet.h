#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <sstream>
#include <algorithm>

//uint8_t를 이용한 String을 hex로 파싱
std::vector<uint8_t> parseHexString(const std::string& hexStr) {
    std::vector<uint8_t> result;
    for (size_t i = 0; i < hexStr.length(); i += 2) {
        std::string byteString = hexStr.substr(i, 2);
        uint8_t byte = static_cast<uint8_t>(std::stoi(byteString, nullptr, 16));
        result.push_back(byte);
    }
    return result;
}

class Packet {
private:
    std::vector<uint8_t> packet;

public:
    Packet(const std::vector<uint8_t>& packet) {
        this->packet = packet;
    }

    std::string getElement(size_t parserStart, size_t parserEnd) {
        std::stringstream ss;
        if (parserStart < parserEnd && parserEnd <= packet.size()) {
            for (size_t i = parserStart
                ; i < parserEnd; ++i) {
                ss << std::setw(2) << std::setfill('0') << std::hex << static_cast<int>(packet[i]);
                if (i < parserEnd - 1) ss << " ";
            }
        }
        else {
            std::cerr << "Index out of bounds" << std::endl;
        }
        return ss.str();
    }

    // Method to print the packet data in hex
    void printPacket() {
        for (uint8_t byte : packet) {
            std::cout << std::setw(2) << std::setfill('0') << std::hex << static_cast<int>(byte) << " ";
        }
        std::cout << std::endl;
    }
};
