#include "sl_event_handler.h"

#include "em_chip.h"
#include "sl_interrupt_manager.h"
#include "sl_clock_manager_init.h"
#include "sl_clock_manager.h"
#include "SEGGER_RTT.h"
#include "sl_memory_manager.h"
#include "pa_conversions_efr32.h"
#include "sl_rail_util_power_manager_init.h"
#include "sl_rail_util_pti.h"
#include "sl_rail_util_rf_path.h"
#include "zigbee-debug-extended.h"
#include "sl_zigbee_system_common.h"
#include "btl_interface.h"
#include "sl_sleeptimer.h"
#include "sl_debug_swo.h"
#include "sl_iostream_debug.h"
#include "sl_iostream_init_usart_instances.h"
#include "sl_iostream_vuart.h"
#include "hal.h"
#include "sl_mbedtls.h"
#include "nvm3_default.h"
#include "sl_iostream_init_instances.h"
#include "sl_power_manager.h"

void sl_platform_init(void)
{
  CHIP_Init();
  sl_interrupt_manager_init();
  sl_clock_manager_init();
  sl_clock_manager_runtime_init();
  SEGGER_RTT_Init();
  sl_memory_init();
  bootloader_init();
  halInit();
  nvm3_initDefault();
  sl_power_manager_init();
}

void sl_driver_init(void)
{
  sl_debug_swo_init();
}

void sl_service_init(void)
{
  sl_sleeptimer_init();
  sl_mbedtls_init();
  sl_iostream_init_instances();
}

void sl_stack_init(void)
{
  sl_rail_util_pa_init();
  sl_rail_util_power_manager_init();
  sl_rail_util_pti_init();
  sl_rail_util_rf_path_init();
  sli_zigbee_debug_extended_init();
  sli_zigbee_stack_init_callback();
  sli_zigbee_app_framework_init_callback();
  sli_zigbee_stack_sleep_init();
  sli_zigbee_ncp_init_callback();
}

void sl_internal_app_init(void)
{
}

void sl_platform_process_action(void)
{
}

void sl_service_process_action(void)
{
}

void sl_stack_process_action(void)
{
  sli_zigbee_stack_tick_callback();
  sli_zigbee_app_framework_tick_callback();
  sli_zigbee_ncp_tick_callback();
}

void sl_internal_app_process_action(void)
{
}

void sl_iostream_init_instances(void)
{
  sl_iostream_debug_init();
  sl_iostream_usart_init_instances();
  sl_iostream_vuart_init();
}

