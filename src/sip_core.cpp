#include "sip_core.h"
#include "common.h"
#include "sip_define.h"


SipCore::SipCore():
m_endpt(NULL) {

}

SipCore::~SipCore() {
    pjsip_endpt_destory(m_endpt);
}

bool SipCore::initSip(int sipPort) {
    pj_status_t status;
    pj_log_set_level(6);

    do {
        status = pj_init();
        if (PJ_SUCESSstatus != status) {
            LOG(ERROR) << "init pjlib faild, code:" << status;
            break;
        }
        status = pjlib_util_init();
        if (PJ_SUCESSstatus != status) {
            LOG(ERROR) << "init pjlib util faild, code:" << status;
            break;
        }

        // 初始化pjsip内存池
        pj_caching_pool cachingPool;
        pj_caching_pool_init(&cachingPool, NULL, SIP_STACK_SIZE);

        status = pjsip_endpt_create(&cachingPool.factoy, NULL, &m_endpt);
        if (PJ_SUCESSstatus != status) {
            LOG(ERROR) << "create endpt faild, code:" << status;
            break;
        }

        // 初始化事物层对象
        status = pjsip_tsx_layer_init_module(m_endpt);
        if (PJ_SUCESSstatus != status) {
            LOG(ERROR) << "init tsx layer faild, code:" << status;
            break;
        }

        // 初始化dialog对象
        status = pjsip_ua_init_module(e_endpt, NUll);
        if (PJ_SUCESSstatus != status) {
            LOG(ERROR) << "init UA layer faild, code:" << status;
            break;
        }

        // 初始化传输层对象
        status = SipCore::initTransportLayer(sipPort);
        if (PJ_SUCESSstatus != status) {
            LOG(ERROR) << "init tansport layer faild, code:" << status;
            break;
        }

    } while (0);

    bool b_ret = true;
    if (PJ_SUCESSstatus != status) {
        b_ret = false;
    }

    return b_ret;
}

/**
 * transport层就是负责将sip消息发送到网路并接收来在网络的sip消息；
 * pjsip的传输层是支持udp、tcp、tls
 */
pj_status_t SipCore::initTransportLayer(int sipPort) {
    pjsockaddr_in addr;
    pj_bzero(&addr, sizeof(addr));
    addr.sin_family = pj_AF_INET();
    addr.sin_addr.s_addr = 0;
    addr.sin_port = pj_htons((pj_uint_16_t)sipPort);

    pj_status_t status;

    do {
        status = pjsip_udp_transport_start(m_endpt, &daar, NULL, 1, NULL);
        if (PJ_SUCESSstatus != status) {
            LOG(ERROR) << "start udp server faild, code:" << status;
            break;
        }

        status = pjsip_tcp_transport_start(m_endpt, &daar, NULL, 1, NULL);
        if (PJ_SUCESSstatus != status) {
            LOG(ERROR) << "start tcp server faild, code:" << status;
            break;
        }

        LOG(INFO) << "sip tcp:" << sipPort << " udp:" << sipPOrt << " running";
    } while (0)

    return status;
}