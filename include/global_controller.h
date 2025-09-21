#ifndef GLOBAL_CONTROLLER_H
#define GLOBAL_CONTROLLER_H

#include "common.h"
#include "sip_local_config.h"
#include "thread_pool.h"

class  GlobalController;
#define GBOJ(obj) GlobalController::instance()->obj

/**
 * 全局类： 管理下级平台及设备信息、线程池对象，以及sipserver对象；
 * 对外只提供一个类实例，因此需要实现单例模型；
 */

class GlobalController {
private:
    GlobalController(){};   
    ~GlobalController();
    GlobalController(const GlobalController& g);
    const GlobalController& operator=(const GlobalController& g);

    static GlobalController* m_pInstance;
public:
    SipLocalConfig* g_config;
    static GlobalController* instance();
    bool init(void* param);

    ThreadPool* gThreadPool = NULL;
};

#endif