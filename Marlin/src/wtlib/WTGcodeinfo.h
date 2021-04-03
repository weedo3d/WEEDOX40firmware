/**
* Copyright (C) 2019 Wiibooxtech Perron
*/

#pragma once

#ifndef __WT_GCODE_INFO_H
#define __WT_GCODE_INFO_H

#define MAX_COMMENT_LINE_LENGTH		100
#define PIC_MAX_LINE			300
#define NOPIC_MAX_LINE			30


typedef struct 
{
	char machine[20];		// 适配机型
	char material[10];		// 耗材类型
	char layerheight[10];	// 打印层高
	char density[10];		// 填充率
	char temp0[10];			// 喷头0温度
	char totaltime[10];		// 打印时间 xxhxxm
	char filament[10];		// 使用料丝 xxxg
	float f_filament;		// 浮点格式料丝用量
	uint32_t i_totaltime;	// 整形格式打印时间
	char filename[27];		// 文件名
	bool b_image;			// 是否包含图片
    bool b_multi;           // 是否为双喷头模型
	uint8_t i_line;			// 图片指令行数
    float x_min, x_max, y_min, y_max, z_min, z_max;
} wt_gcode_info_t;

class WTGcodeinfo
{
public:
	WTGcodeinfo() {};

	// 读取并分析gcode文件
	void parse(char* filename);

	// 发送图片
	void load_jpg(char* filename);

	// 发送一行jpg数据
	void send_jpg_line(const char* data);

	wt_gcode_info_t info;


private:
	char linebuffer[MAX_COMMENT_LINE_LENGTH];
	uint8_t jpgbuffer[MAX_COMMENT_LINE_LENGTH / 2];
	uint16_t sd_count;

	void reset(void);
	void getvalue(char* data);
};

extern WTGcodeinfo gcodeinfo;

#endif

