#include "soc/rtc_cntl_reg.h"
#include "soc/rtc_io_reg.h"
#include "soc/soc_ulp.h"

.bss

	.global local_wakeup_timer
local_wakeup_timer:
	.long 0

.text

	.global entry
entry:
	// Increment local_wakeup_timer by 1
	move r1, local_wakeup_timer
	ld r0, r1, 0
	add r0, r0, 1
	st r0, r1, 0

	jumpr ulp_halt, 3000, LT

ulp_wake:
	// Check if the system can be woken up
	READ_RTC_FIELD(RTC_CNTL_LOW_POWER_ST_REG, RTC_CNTL_RDY_FOR_WAKEUP)
	and r0, r0, 1
	jump ulp_halt, EQ

	// Reset the wakeup timer
	move r0, 0
	move r1, local_wakeup_timer
	st r0, r1, 0

	// Wake up the SoC, end program
	wake

ulp_halt:
	halt