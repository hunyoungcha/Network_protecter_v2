#include "ini.hpp"
#include "queueManager.hpp"

#include <condition_variable>
#include <thread>
#include <mutex>
#include <Packet.h>
#include <TcpLayer.h>
#include <IPv4Layer.h>
#include <arpa/inet.h>


class CPhishingCheck{
    public:
        CPhishingCheck(CQueueManager& manager) : queueManager(manager){};
        void tmp();

    private:
        CQueueManager& queueManager;
};