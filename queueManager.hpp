#pragma once

#include "ini.hpp"

#include <Packet.h>
#include <queue>
#include <mutex>
#include <condition_variable>
#include <memory>




class CQueueManager{
    public:
        void AddToQueue(std::shared_ptr<pcpp::Packet> packet);
        std::shared_ptr<pcpp::Packet> GetFromQueue();

    private:
        std::queue<std::shared_ptr<pcpp::Packet>> m_packetQueue;
        std::mutex m_queueMutex;
        std::condition_variable m_condition;
};