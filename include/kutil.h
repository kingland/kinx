#ifndef KX_KUTIL_H
#define KX_KUTIL_H

#include <kinx.h>

#if defined(_WIN32) || defined(_WIN64)
#include <windows.h>
typedef struct timer_ {
    LARGE_INTEGER freq;
    LARGE_INTEGER start;
} systemtimer_t;
#else
#include <sys/time.h>
#include <unistd.h>
#include <sys/resource.h>
typedef struct timer_ {
    struct timeval s;
} systemtimer_t;
#endif

static inline void sleep_ms(kx_context_t *ctx, int msec)
{
    #if defined(_WIN32) || defined(_WIN64)
    systemtimer_t v = {0};
    QueryPerformanceFrequency(&(v.freq));
    QueryPerformanceCounter(&(v.start));

    if (msec == 0) {
        Sleep(1);
    } else {
        double endtm = (double)msec / 1000;
        double elapsed = 0.0;
        while (elapsed < endtm) {
            volatile uint8_t signal = ctx->signal.signal_received;
            if (signal) {
                break;
            }
            LARGE_INTEGER end;
            QueryPerformanceCounter(&end);
            elapsed = (double)(end.QuadPart - (v.start).QuadPart) / (v.freq).QuadPart;
            int sl = (int)((endtm - elapsed) * 1000);
            Sleep(sl > 100 ? 100 : ((sl > 0) ? sl : 1));
        }
    }
    #else
    usleep((msec <= 0 ? 1 : msec) * 1000);
    #endif
}

#endif /* KX_KUTIL_H */