#include <libudev.h>


#include "hidmonitor.h"

/**
** \brief HIDMonitor constructor
*/
HIDMonitor::HIDMonitor(void)
    : hid_devices_(HIDDevice::get_devices())
{
}

/**
** \brief HIDMonitor destructor
*/
HIDMonitor::~HIDMonitor()
{
}

/**
** \brief Get all the HID devices monitored
**
** \return The HID devices monitores in a vector
*/
const std::vector<HIDDevice>&
    HIDMonitor::get_hid_devices(void) const
{
    return this->hid_devices_;
}
