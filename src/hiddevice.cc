#include <libudev.h>

#include "hiddevice.h"

/**
** \brief HIDDevice constructor
**
** \param name The name of the device
*/
HIDDevice::HIDDevice(const std::string& name)
    : name_(name)
{
}

/**
** \brief HIDDevice destructor
*/
HIDDevice::~HIDDevice()
{
}

/**
** \brief Get all the HID devices currently plugged on te sytem
**
** \return The HID devices in a vector
*/
std::vector<HIDDevice>
    HIDDevice::get_devices(void)
{
    /* Create vector */
    auto hid_devices = std::vector<HIDDevice>();

    /* New udev context */
    struct udev *udev = udev_new();
    if (udev == nullptr)
        return hid_devices;

    /* Enumerate HID devices */
    struct udev_enumerate *enumeration =
        udev_enumerate_new(udev);
    if (enumeration == nullptr)
        return hid_devices;

    /* Add hiraw subsystem */
    if (udev_enumerate_add_match_subsystem(
            enumeration,
            "hidraw") < 0)
        return hid_devices;

    /* Scan devices */
    if (udev_enumerate_scan_devices(enumeration) < 0)
        return hid_devices;

    /* Get devices list */
    struct udev_list_entry *udev_hid_device_entry =
        udev_enumerate_get_list_entry(enumeration);
    while (udev_hid_device_entry != nullptr)
    {
        /* Construct */
        const char *name =
            udev_list_entry_get_name(udev_hid_device_entry);
        if (name != nullptr)
            hid_devices.push_back(std::string(name));

        /* Next */
        udev_hid_device_entry =
            udev_list_entry_get_next(udev_hid_device_entry);
    }

    return hid_devices;
}
