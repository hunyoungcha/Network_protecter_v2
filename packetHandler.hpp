#pragma once
#include "ini.hpp"
#include "configDB.hpp"

#include <pcapplusplus/PcapLiveDeviceList.h>
#include <pcapplusplus/PcapLiveDevice.h>
#include <pcapplusplus/Packet.h>
#include <pcapplusplus/TcpLayer.h>
#include <pcapplusplus/IPv4Layer.h>

class CPacketHandler {
    public:
        int GetDeviceName();
        static void packetArrives(pcpp::RawPacket* rawPacket, pcpp::PcapLiveDevice* dev, void* userData);
        int RunPacketCapture();

    private:
        pcpp::PcapLiveDevice* m_device;
};