#ifndef HID_MONITOR_H
#define HID_MONITOR_H

#include <vector>

#include "hiddevice.h"


class HIDMonitor
{
public:
    /* Constructors */
    HIDMonitor(void);

    /* Destructors */
    virtual ~HIDMonitor();

    /* Methods */
    const std::vector<HIDDevice>& get_hid_devices(void) const;

private:
    /* Attribute */
    std::vector<HIDDevice> hid_devices_;

};

#endif