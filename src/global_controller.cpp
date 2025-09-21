#include "global_controller.h"

GlobalController* GlobalController::m_pInstance = NULL;

GlobalController* GlobalController::instance() {
    if (!m_pInstance) {
        m_pInstance = new GlobalController();
    }
    return m_pInstance;
}

bool GlobalController::init(void* param) {
    g_config = (SipLocalConfig*) param;
    if (!g_config) {
        return false;
    }
    if (!gThreadPool) {
        gThreadPool = new ThreadPool();
        gThreadPool -> createThreadPool(10);
    }
    return true;
}
