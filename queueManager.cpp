#include "queueManager.hpp"

void CQueueManager::AddToQueue(std::shared_ptr<pcpp::Packet> packet){
    {
        std::lock_guard<std::mutex> lock(m_queueMutex);
        m_packetQueue.push(packet);
    }
    m_condition.notify_one();
}

std::shared_ptr<pcpp::Packet> CQueueManager::GetFromQueue(){
    std::unique_lock<std::mutex> lock(m_queueMutex);

    m_condition.wait(lock, [this]() {return !m_packetQueue.empty();});

    auto packet= m_packetQueue.front();
    m_packetQueue.pop();

    return packet;
}