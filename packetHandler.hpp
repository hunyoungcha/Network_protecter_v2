#pragma once
#include "ini.hpp"
#include "configDB.hpp"

#include <PcapLiveDeviceList.h>
#include <PcapLiveDevice.h>
#include <Packet.h>
#include <TcpLayer.h>
#include <IPv4Layer.h>
#include <PcapFilter.h>


#include <thread>
#include <mutex>
#include <queue>
#include <condition_variable>

class CPacketHandler {
    public:
        int GetDeviceName();
        static void packetArrives(pcpp::RawPacket* rawPacket, pcpp::PcapLiveDevice* dev, void* userData);
        int RunPacketCapture();

    private:
        pcpp::PcapLiveDevice* m_device;
        std::queue<pcpp::RawPacket> m_phishingQueue, m_firewallQueue;
        std::mutex m_phishingMutex, m_firewallMutex;
        std::condition_variable m_phishingCV, m_firewallCV;
        
};