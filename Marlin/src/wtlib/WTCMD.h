/**
* Copyright (C) 2020 Wiibooxtech Perron
*/

#ifndef WTCMD_H
#define WTCMD_H

#include "stdint.h"

#define SPARK_IDLE		0
#define SPARK_PAUSED	1
#define SPARK_PRINTING	2
#define SPARK_LOST		3

#define HOST_WIIBUILDER	0
#define HOST_SPARK		1

#define WIFI_UNKNOWN	0
#define WIFI_OFF		1
#define WIFI_OK			2

enum WT_STATUS : char 
{
	WS_IDLE = 0, 
	WS_PRINTING = 1,
	WS_PAUSE = 2,
	WS_ABORT = 3,
	WS_FINISH = 4,
    WS_UPLOADING = 5,
    WS_ERROR = 6
};

enum WT_MAIN_ACTION : char
{
	WMA_IDLE = 0,
	WMA_PAUSE = 1,
	WMA_RESUME = 2
};

extern WT_STATUS wt_machineStatus;

extern WT_MAIN_ACTION wt_mainloop_action;

#ifdef AUTOPOWEROFF
void setup_autopoweroffpin();
#endif

extern uint8_t progress_bar_percent;

void WTCMD_Process();

// ESP32进入smart config模式
void WT_Set_SmartConfig();

// 读取ESP32的IP地址
void WT_Get_IP();

// ESP32立即重启
void WT_ESP32_Restart();

// 读取ESP32的硬件和固件版本
void WT_Get_ESP32Version();

// 从默认网址OTA升级
void WT_OTA_Default();

// 从指定网址OTA升级
void WT_OTA_URI(const char * uri);

// 从指定网络OTA至指定版本
void WT_OTA_Force(const char * uri, const char * ver);

// 连接工厂默认WIFI网
void WT_WIFI_Default();

// 连接到指定的WIFI网
void WT_WIFI_Join();

// 关闭电源
void wt_PowerOff();

// 停止SD卡打印
void wt_sdcard_stop();

// 暂停SD卡打印
void wt_sdcard_pause(bool showMessage = true);

// 恢复SD卡打印
void wt_sdcard_resume();

// 打开喷头降温风扇
void wt_OpenExtruder0Fan();

// 关闭喷头降温风扇
void wt_CloseExtruder0Fan();

// 打开空滤风扇
void wt_OpenAirFan();

// 关闭空滤风扇
void wt_CloseAirFan();

// WEEDO云连接状态
void WT_TB_STATE();

// 获取已连接AP名
void WT_AP_NAME();

// 向Spark发送暂停打印请求
void wt_online_pause();

// 向Spark发送恢复打印请求
void wt_online_resume();

// 向Spark发送取消打印请求
void wt_online_cancel();

// 读取主机模式
uint8_t wt_get_hostmode(void);

// 保存主机模式
void wt_set_hostmode(const uint8_t mode);

// restart
void wt_restart();

// send buffer count
void wt_echo_buffer_count();

// get machine status
void GetMachineStatus();

// 将WIFI通讯数据发送至串口1
void wifi_debug(const char* message, bool incoming);

// request ndisk page count
void wt_ndisk_read_page_count(void);

// read ndisk file page
void wt_ndisk_read_page();

// read ndisk file info
void wt_ndisk_read_fileinfo(void);

// print ndisk selected file
void wt_ndisk_print(void);

void host_action_start(void);

void host_action_finish(void);

// main loop action
void wt_loopaction(void);

#endif

