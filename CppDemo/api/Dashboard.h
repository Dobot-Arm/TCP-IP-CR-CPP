#pragma once

#include "DobotClient.h"

namespace Dobot
{
    class CDashboard : public CDobotClient
    {
    public:
        CDashboard();
        virtual ~CDashboard();

        /// <summary>
        /// 复位，用于清除错误
        /// </summary>
        /// <returns>返回执行结果的描述信息</returns>
        std::string ClearError();

        /// <summary>
        /// 机器人上电
        /// </summary>
        /// <returns>返回执行结果的描述信息</returns>
        std::string PowerOn();

        /// <summary>
        /// 急停
        /// </summary>
        /// <returns>返回执行结果的描述信息</returns>
        std::string PowerOff();

        /// <summary>
        /// 急停
        /// </summary>
        /// <returns>返回执行结果的描述信息</returns>
        std::string EmergencyStop();

        /// <summary>
        /// 使能机器人
        /// </summary>
        /// <returns>返回执行结果的描述信息</returns>
        std::string EnableRobot();

        /// <summary>
        /// 下使能机器人
        /// </summary>
        /// <returns>返回执行结果的描述信息</returns>
        std::string DisableRobot();

        /// <summary>
        /// 机器人停止
        /// </summary>
        /// <returns>返回执行结果的描述信息</returns>
        std::string ResetRobot();

        /// <summary>
        /// 设置全局速度比例。
        /// </summary>
        /// <param name="ratio">运动速度比例，取值范围：1~100</param>
        /// <returns>返回执行结果的描述信息</returns>
        std::string SpeedFactor(int ratio);

        /// <summary>
        /// 设置数字输出端口状态（队列指令）
        /// </summary>
        /// <param name="index">数字输出索引，取值范围：1~16或100~1000</param>
        /// <param name="status">数字输出端口状态，true：高电平；false：低电平</param>
        /// <returns>返回执行结果的描述信息</returns>
        std::string DigitalOutputs(int index, bool status);

        /// <summary>
        /// 获取错误ID
        /// </summary>
        /// <returns>返回执行结果的描述信息</returns>
        std::string GetErrorID();

    protected:
        void OnConnected() override;
        void OnDisconnected() override;
    };
}

