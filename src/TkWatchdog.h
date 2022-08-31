#ifndef WATCHDOG_h
#define WATCHDOG_h
#include "WatchdogAdapter.h"
#include <Arduino.h>
/*!
 * @brief The class of Watchdog
 */
class TkWatchdog : public WatchdogAdapter{

    public:
        TkWatchdog();
        /*!
        *    @brief  初始化看门狗
        *    @return 初始化成功则返回 true
        */
        virtual bool wdt_init(uint32_t timeout) override; 
        /*!
        *    @brief  取消初始化看门狗
        *    @return 取消成功返回 true
        */
        virtual bool wdt_deinit(void) override;
        /*!
        *    @brief  看门狗复位
        *    @return 复位成功返回 true
        */
        virtual bool wdt_reset(void) override;
};

#endif