#ifndef SIP_CORE_H
#define SIP_CORE_H

#include <pjlib>
#include <pjlib-util.h>
#include <pjmedia.h>
#include <pjsip.h>
#include <pjsip_ua.h>
#include <pjsip/sip_auth.h>

class SipCore {
private:
    pjsip_endpoint* m_endpt;
public:
    SipCore();
    ~SipCore();

    bool initSip();

    pj_status_t initTransportLayer(int sipPort);
};


#endif