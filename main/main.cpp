#include <main.h>

// ESP headers
#include <esp_log.h>
#include <esp_sleep.h>
#include <esp32/ulp.h>
// Auto generated headers
#include <ulp_wakeup.h>

#undef LOG_LOCAL_LEVEL
#define LOG_LOCAL_LEVEL CONFIG_APP_SANDBOX_LOG_LEVEL

static const char* TAG = "main";

extern const uint8_t ulp_main_bin_start[] 
	asm("_binary_ulp_wakeup_bin_start");
extern const uint8_t ulp_main_bin_end[]
	asm("_binary_ulp_wakeup_bin_end");

void app_main(void) {
	/*esp_sleep_wakeup_cause_t cause = esp_sleep_get_wakeup_cause();

	if (cause != ESP_SLEEP_WAKEUP_ULP) {
		ESP_ERROR_CHECK( ulp_load_binary(0, ulp_main_bin_start,
			(ulp_main_bin_end - ulp_main_bin_start) / sizeof(uint32_t)) );

		// Set ULP wakeup to 1ms
		ESP_ERROR_CHECK( ulp_set_wakeup_period(0, 1000) );

		// Start ULP
		ESP_ERROR_CHECK( ulp_run(&ulp_entry - RTC_SLOW_MEM) );
	}*/

	ESP_LOGI(TAG, "[%s]: Entering deep sleep", __func__);

	esp_deep_sleep(5000 * 1000);
}
