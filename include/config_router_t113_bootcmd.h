#ifndef _CONFIG_ROUTER_T113_BOOTCMD_H
#define _CONFIG_ROUTER_T113_BOOTCMD_H

#ifndef __STR
#define __STR(x) #x
#endif
#ifndef STR
#define STR(x) __STR(x)
#endif

#ifndef CONFIG_USE_BOOTARGS
    #define CONFIG_STR_BOOTARGS "bootcmd=ubi part firmware; ubi read " STR(CONFIG_SYS_LOAD_ADDR) " kernel; bootm " STR(CONFIG_SYS_LOAD_ADDR) "\0"
#else
    #define CONFIG_STR_BOOTARGS
#endif

#ifdef CONFIG_SERIAL
    #define CONSOLE_STR "console=ttyS0," STR(CONFIG_BAUDRATE) " "
#endif

#ifndef CONFIG_BOOTCOMMAND
    #define CONFIG_STR_BOOTCOMMAND "bootargs=mem=" STR(CONFIG_SUNXI_MINIMUM_DRAM_MB) "M " \
    CONSOLE_STR \
    "loglevel=8 ubi.mtd=firmware rootfstype=squashfs rootwait\0"
#else
    #define CONFIG_STR_BOOTCOMMAND
#endif

#define BOOTENV             \
    CONFIG_STR_BOOTARGS     \
    CONFIG_STR_BOOTCOMMAND

#endif //_CONFIG_ROUTER_T113_BOOTCMD_H