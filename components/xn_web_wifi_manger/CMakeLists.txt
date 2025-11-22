idf_component_register(
    SRCS 
        "src/xn_wifi.c" 
        "src/xn_web.c"
    INCLUDE_DIRS 
        "include"
    REQUIRES 
        esp_http_server  
        spiffs         
        esp_wifi
        nvs_flash
)

# 创建SPIFFS分区镜像
spiffs_create_partition_image(wifi_spiffs wifi_spiffs FLASH_IN_PROJECT)