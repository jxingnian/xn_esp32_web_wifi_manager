/*
 * @Author: 星年 && jixingnian@gmail.com
 * @Date: 2025-11-22 16:24:42
 * @LastEditors: xingnian jixingnian@gmail.com
 * @LastEditTime: 2025-11-22 17:15:18
 * @FilePath: \xn_web_wifi_config\components\xn_web_wifi_manger\src\xn_wifi_manage.c
 * @Description: WiFi 管理模块实现。
 */

#include <string.h>

#include "freertos/FreeRTOS.h"
#include "freertos/timers.h"

#include "xn_wifi_manage.h"

/* 日志 TAG，用于 ESP_LOGx 系列接口（如果后续需要打印日志，可直接使用此 TAG） */
static const char *TAG = "xn_wifi_manage";

/* WiFi 管理状态机当前状态。 */
static wifi_manage_state_t s_wifi_manage_state = WIFI_MANAGE_STATE_DISCONNECTED;
static wifi_manage_config_t s_wifi_cfg;

/**
 * @brief WiFi 管理状态机
 *
 */
static void xn_wifi_manage_state_machine_step(void)
{
    /* 根据当前记录的状态，选择相应的处理分支 */
    switch (s_wifi_manage_state) {
    case WIFI_MANAGE_STATE_DISCONNECTED:
        /* 状态：WIFI_MANAGE_STATE_DISCONNECTED（WiFi 已断开/尚未连接）
         * 
         */
        break;

    case WIFI_MANAGE_STATE_CONNECTED:
        /* 状态：WIFI_MANAGE_STATE_CONNECTED（WiFi 已成功连接）
         * 
         */
        break;

    case WIFI_MANAGE_STATE_CONNECT_FAILED:
        /* 状态：WIFI_MANAGE_STATE_CONNECT_FAILED（WiFi 连接失败）
         * 
         */
        break;

    default:
        /* 理论上不应到达此分支，保留用于兜底保护或调试。 */
        break;
    }
}

/**
 * @brief  WiFi 管理模块初始化
 *
 * @param config  用户传入的 WiFi 管理配置（可为 NULL，此时使用默认值）
 * @return esp_err_t
 *         - ESP_OK        : 初始化成功
 *         - ESP_ERR_NO_MEM: 创建重试定时器失败
 */
esp_err_t xn_wifi_manage_init(const wifi_manage_config_t *config)
{
    if (config == NULL) {
        s_wifi_cfg = WIFI_MANAGE_DEFAULT_CONFIG();
    } else {
        s_wifi_cfg = *config;
    }

    return ESP_OK;
}
