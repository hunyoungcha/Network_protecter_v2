#include "packetHandler.hpp"

int CPacketHandler::GetDeviceName(){
    std::vector<pcpp::PcapLiveDevice*> vecDevices = pcpp::PcapLiveDeviceList::getInstance().getPcapLiveDevicesList();

    // if (vecDevices.empty()) {
    //     std::cerr << "사용 가능한 네트워크 디바이스가 없습니다." << std::endl;
    //     return nullptr;
    // }

    std::cout << "Devices List:" << std::endl;
    for (size_t i = 0; i < vecDevices.size(); ++i) {
        std::cout <<"    "<< i << ": " << vecDevices[i]->getName() 
                  << " (" << vecDevices[i]->getIPv4Address().toString() << ")" << std::endl;
    }


    int nDeviceIndex = -1;
    std::cout << "NUMBER: ";
    std::cin >> nDeviceIndex;

    // if (deviceIndex < 0 || deviceIndex >= vecDevices.size()) {
    //     std::cerr << "잘못된 번호를 입력했습니다." << std::endl;
    //     return nullptr;
    // }
    m_device= vecDevices[nDeviceIndex];
    

    return 0;
}

void CPacketHandler::packetArrives(pcpp::RawPacket* rawPacket, pcpp::PcapLiveDevice* dev, void* userData) {
    // RawPacket을 Packet 객체로 변환
    pcpp::Packet parsedPacket(rawPacket);

    // IP 레이어가 존재하는지 확인하고 출력
    pcpp::IPv4Layer* ipLayer = parsedPacket.getLayerOfType<pcpp::IPv4Layer>();
    if (ipLayer != nullptr) {    
        std::cout << "Source IP: " << ipLayer->getSrcIPAddress().toString() 
                  << " -> Destination IP: " << ipLayer->getDstIPAddress().toString() << std::endl;
    }

    // TCP 레이어가 존재하는지 확인하고 출력
    pcpp::TcpLayer* tcpLayer = parsedPacket.getLayerOfType<pcpp::TcpLayer>();
    if (tcpLayer != nullptr) {
        std::cout << "TCP Port: " << tcpLayer->getTcpHeader()->portSrc << " -> "
                  << tcpLayer->getTcpHeader()->portDst << std::endl;
    }
}

int CPacketHandler::RunPacketCapture(){
    if (!m_device->open()) {
        std::cerr << "인터페이스를 열 수 없습니다." << std::endl;
        return 1;
    }
    
    m_device->startCapture(CPacketHandler::packetArrives, nullptr);
    
    //캡처 stop하고 close하는 거 다시 구현 필요
    
    //입력 버퍼에 저장된 데이터 다 제거
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    //Enter를 트리거로 패킷 캡처 조절
    std::cin.get();
    m_device->stopCapture();
    m_device->close();
    return 0;
}