<!--
 * @Author: 星年 && jixingnian@gmail.com
 * @Date: 2025-11-22 15:20:30
 * @LastEditors: xingnian jixingnian@gmail.com
 * @LastEditTime: 2025-11-22 16:25:32
 * @FilePath: \xn_web_wifi_config\README.md
 * @Description: 
 * 
 * Copyright (c) 2025 by ${git_name_email}, All Rights Reserved. 
-->
esp32 网页WiFi配网组件

状态机
    1、WiFi已连接
        检测掉线》》》切换到WiFi未连接
    2、WiFi未连接
        尝试连接WiFi
            失败》》》切换到WiFi连接失败
            成功》》》切换到WiFi已连接
    3、WiFi连接失败
       定时尝试连接WiFi




    上电初始化
        初始化WiFi
        初始化Web服务器
        初始化NVS
        初始化文件系统
        切换到WiFi未连接

