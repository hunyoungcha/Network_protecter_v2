#include "phishingCheck.hpp"

void CPhishingCheck::tmp(){
    while (true){
        auto packet = queueManager.GetFromQueue();
        if(packet){
            auto* ipv4Layer = packet->getLayerOfType<pcpp::IPv4Layer>();
            if (ipv4Layer) {
                std::cout << "Src IP: " << ipv4Layer->getSrcIPAddress() << std::endl;
                std::cout << "Dst IP: " << ipv4Layer->getDstIPAddress() << std::endl;
            }
        }
    }
}