#ifndef HID_DEVICE_H
#define HID_DEVICE_H

#include <string>
#include <vector>



class HIDDevice
{
public:
    /* Constrcutors */
    HIDDevice(void) = delete;
    HIDDevice(const std::string& name);

    /* Destructor */
    virtual ~HIDDevice();

    /* Methods */
    static std::vector<HIDDevice>
        get_devices(void);

private:
    std::string name_;
};

#endif