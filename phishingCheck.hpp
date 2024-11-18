#include "ini.hpp"
#include "queueManager.hpp"

#include <condition_variable>
#include <thread>
#include <mutex>


class CPhishingCheck{
    public:
        CPhishingCheck(CQueueManager& manager) : queueManager(manager){};
        void tmp();

    private:
        CQueueManager& queueManager;
};