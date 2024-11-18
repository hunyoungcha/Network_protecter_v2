#include "phishingCheck.hpp"

void CPhishingCheck::tmp(){
    while (true){
        auto packet = queueManager.GetFromQueue();
        if(packet){
            std::cout << "packet!" <<std::endl;
        }
    }
}