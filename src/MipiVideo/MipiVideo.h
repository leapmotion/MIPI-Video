#pragma once

#ifdef _cplusplus
extern "C" {
#endif

#ifdef _MSC_VER
#define LV_CALL __stdcall
#else
#define LV_CALL
#endif

/// <summary>
/// Primary initialization routine for all video processing callbacks
/// </summary>
void LV_CALL MipiVideoInit(void);

#ifdef _cplusplus
}
#endif
