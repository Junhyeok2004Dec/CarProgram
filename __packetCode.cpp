//packet 관련 데이터


int main() {
    // Sample hex data (each element is a byte)
    std::vector<uint8_t> samplePacket = { 0x12, 0x34, 0x56, 0x78, 0x9A, 0xBC, 0xDE, 0xF0 };

    // Create an instance of Packet
    Packet myPacket(samplePacket);

    // Print the entire packet
    myPacket.printPacket();

    // Retrieve the 3rd element of size 4 bytes (0-based index)
    std::vector<uint8_t> element = myPacket.getElement(2, 4);

    // Print the retrieved element in hex
    for (uint8_t byte : element) {
        std::cout << std::setw(2) << std::setfill('0') << std::hex << static_cast<int>(byte) << " ";
    }
    std::cout << std::endl;

    return 0;
}



int main() {
    // Sample hex string
    std::string sampleHexString = "00312491040948ff3fb0123a007f";

    // Parse the hex string into a vector of uint8_t
    std::vector<uint8_t> samplePacket = parseHexString(sampleHexString);

    // Create an instance of Packet
    Packet myPacket(samplePacket);

    // Print the entire packet
    myPacket.printPacket();

    // Retrieve elements from index 2 to 6 (0-based index)
    std::string element = myPacket.getElement(2, 6);

    // Print the retrieved elements in hex
    std::cout << element << std::endl;

    return 0;
}
