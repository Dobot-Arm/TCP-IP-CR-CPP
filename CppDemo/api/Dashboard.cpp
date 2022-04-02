#include "Dashboard.h"
#include <sstream>

namespace Dobot
{
    CDashboard::CDashboard(){}
    CDashboard::~CDashboard() {}

    void CDashboard::OnConnected()
    {}
    void CDashboard::OnDisconnected()
    {}

    std::string CDashboard::ClearError()
    {
        if (!IsConnected())
        {
            return "device does not connected!!!";
        }

        std::string str = "ClearError()";
        if (!SendData(str))
        {
            return str + ":send error";
        }

        return WaitReply(5000);
    }

    std::string CDashboard::PowerOn()
    {
        if (!IsConnected())
        {
            return "device does not connected!!!";
        }

        std::string str = "PowerOn()";
        if (!SendData(str))
        {
            return str + ":send error";
        }

        return WaitReply(15000);
    }

    std::string CDashboard::PowerOff()
    {
        return EmergencyStop();
    }

    std::string CDashboard::EmergencyStop()
    {
        if (!IsConnected())
        {
            return "device does not connected!!!";
        }

        std::string str = "EmergencyStop()";
        if (!SendData(str))
        {
            return str + ":send error";
        }

        return WaitReply(15000);
    }

    std::string CDashboard::EnableRobot()
    {
        if (!IsConnected())
        {
            return "device does not connected!!!";
        }

        std::string str = "EnableRobot()";
        if (!SendData(str))
        {
            return str + ":send error";
        }

        return WaitReply(20000);
    }

    std::string CDashboard::DisableRobot()
    {
        if (!IsConnected())
        {
            return "device does not connected!!!";
        }

        std::string str = "DisableRobot()";
        if (!SendData(str))
        {
            return str + ":send error";
        }

        return WaitReply(20000);
    }

    std::string CDashboard::ResetRobot()
    {
        if (!IsConnected())
        {
            return "device does not connected!!!";
        }

        std::string str = "ResetRobot()";
        if (!SendData(str))
        {
            return str + ":send error";
        }

        return WaitReply(20000);
    }

    std::string CDashboard::SpeedFactor(int ratio)
    {
        if (!IsConnected())
        {
            return "device does not connected!!!";
        }

        std::ostringstream oss;
        oss << "SpeedFactor(" << ratio << ")";
        std::string str = oss.str();
        if (!SendData(str))
        {
            return str + ":send error";
        }

        return WaitReply(5000);
    }

    std::string CDashboard::DigitalOutputs(int index, bool status)
    {
        if (!IsConnected())
        {
            return "device does not connected!!!";
        }

        std::ostringstream oss;
        oss << "DO(" << index << "," << (status ? 1 : 0) << ")";
        std::string str = oss.str();
        if (!SendData(str))
        {
            return str + ":send error";
        }

        return WaitReply(5000);
    }

    std::string CDashboard::GetErrorID()
    {
        if (!IsConnected())
        {
            return "device does not connected!!!";
        }

        std::string str = "GetErrorID()";
        if (!SendData(str))
        {
            return str + ":send error";
        }

        return WaitReply(5000);
    }
}