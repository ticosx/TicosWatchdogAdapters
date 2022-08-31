
#include "esp_task_wdt.h"
#include "TkWatchdog.h"
#include "Log.h"

TkWatchdog::TkWatchdog()  {

}

bool TkWatchdog::wdt_init(uint32_t timeout) 
{
    int ret = 0;
    ret = esp_task_wdt_init(timeout, true);
    if(ret == 0){
        ret = esp_task_wdt_add(NULL);
        if(ret == 0){
           logInfo("Watchdog init OK \n");
        }
        else{
           logInfo("Watchdog init failed,ret:0x%03x \n",ret);
           return false ;
        }
    }
    else{
        logInfo("Watchdog init failed,ret:0x%03x \n",ret);
        return false ;
    }

    return true;
}

bool TkWatchdog::wdt_deinit(void) 
{
    esp_task_wdt_deinit();
    logInfo("Watchdog deinit \n");
    return true;
}

bool TkWatchdog::wdt_reset(void)
{
     int ret = 0;
     ret = esp_task_wdt_reset();
     if(ret == 0){
        //logInfo("watchdog reset ok \n");
     }
     else{
         logInfo("Watchdog reset failed, ret:0x%03x\n",ret);
         return false ;
     }
     return true ;
}
