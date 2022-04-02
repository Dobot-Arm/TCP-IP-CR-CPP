#include "DobotMove.h"
#include <sstream>

namespace Dobot
{
    CDobotMove::CDobotMove() {}
    CDobotMove::~CDobotMove() {}

    void CDobotMove::OnConnected()
    {}
    void CDobotMove::OnDisconnected()
    {}

    std::string CDobotMove::MoveJog(std::string s)
    {
        if (!IsConnected())
        {
            return "device does not connected!!!";
        }

        std::string str;
        if (s.empty())
        {
            str = "MoveJog()";
        }
        else
        {
            str = "MoveJog(" + s + ")";
        }
        if (!SendData(str))
        {
            return str + ":send error";
        }

        return WaitReply(5000);
    }

    std::string CDobotMove::StopMoveJog()
    {
        return MoveJog("");
    }

    std::string CDobotMove::MovJ(const CDescartesPoint& pt)
    {
        if (!IsConnected())
        {
            return "device does not connected!!!";
        }

        std::ostringstream oss;
        oss << "MovJ(" << pt.x << ',' << pt.y << ',' << pt.z << ',' << pt.rx << ',' << pt.ry << ',' << pt.rz<<')';
        std::string str = oss.str();
        if (!SendData(str))
        {
            return str + ":send error";
        }

        return WaitReply(5000);
    }

    std::string CDobotMove::MovL(const CDescartesPoint& pt)
    {
        if (!IsConnected())
        {
            return "device does not connected!!!";
        }

        std::ostringstream oss;
        oss << "MovL(" << pt.x << ',' << pt.y << ',' << pt.z << ',' << pt.rx << ',' << pt.ry << ',' << pt.rz << ')';
        std::string str = oss.str();
        if (!SendData(str))
        {
            return str + ":send error";
        }

        return WaitReply(5000);
    }

    std::string CDobotMove::JointMovJ(const CJointPoint& pt)
    {
        if (!IsConnected())
        {
            return "device does not connected!!!";
        }

        std::ostringstream oss;
        oss << "JointMovJ(" << pt.j1 << ',' << pt.j2 << ',' << pt.j3 << ',' << pt.j4 << ',' << pt.j5 << ',' << pt.j6 << ')';
        std::string str = oss.str();
        if (!SendData(str))
        {
            return str + ":send error";
        }

        return WaitReply(5000);
    }
}
