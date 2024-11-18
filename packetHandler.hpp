#pragma once
#include "ini.hpp"
#include "configDB.hpp"
#include "queueManager.hpp"


#include <PcapLiveDeviceList.h>
#include <PcapLiveDevice.h>
#include <Packet.h>
#include <TcpLayer.h>
#include <IPv4Layer.h>
#include <PcapFilter.h>
#include <arpa/inet.h>


class CPacketHandler {
    public:
        CPacketHandler(CQueueManager& Qmanager) : queueManager(Qmanager) {};


        int GetDeviceName();
        static void packetArrives(pcpp::RawPacket* rawPacket, pcpp::PcapLiveDevice* dev, void* userData);
        int RunPacketCapture();
        
    private:
        pcpp::PcapLiveDevice* m_device;
        CQueueManager& queueManager;
};