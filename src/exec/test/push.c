#include <stdio.h>
#include <kinx.h>

int main()
{
    kvec_t(kx_code_t) code = {0};
    kvec_pt(kx_code_t) fixcode = {0};
    int items = 100;

    int start = kv_size(code);
            kv_push(kx_code_t, code, ((kx_code_t){ .op = KX_ENTER, .value1.i = items + 1, .value2.i = 10, .count = 10 }));
            kv_push(kx_code_t, code, ((kx_code_t){ .op = KX_PUSHI, .value1.i = 100 }));
            kv_push(kx_code_t, code, ((kx_code_t){ .op = KX_CHKVAL, .file = const_str(__FILE__), .line = __LINE__, .value1.i = KEX_INT, .value2.i = 100 }));
            kv_push(kx_code_t, code, ((kx_code_t){ .op = KX_STOREVX, .value1.i = 0, .value2.i = 0 }));
            kv_push(kx_code_t, code, ((kx_code_t){ .op = KX_PUSHD, .value1.d = 9.9 }));
            kv_push(kx_code_t, code, ((kx_code_t){ .op = KX_CHKVAL, .file = const_str(__FILE__), .line = __LINE__, .value1.i = KEX_DBL, .value2.d = 9.9 }));
            kv_push(kx_code_t, code, ((kx_code_t){ .op = KX_STOREVX, .value1.i = 0, .value2.i = 1 }));
            kv_push(kx_code_t, code, ((kx_code_t){ .op = KX_PUSHI, .value1.i = 10000 }));
            kv_push(kx_code_t, code, ((kx_code_t){ .op = KX_CHKVAL, .file = const_str(__FILE__), .line = __LINE__, .value1.i = KEX_INT, .value2.i = 10000 }));
            kv_push(kx_code_t, code, ((kx_code_t){ .op = KX_STOREVX, .value1.i = 0, .value2.i = 2 }));
            kv_push(kx_code_t, code, ((kx_code_t){ .op = KX_PUSHI, .value1.i = 100 }));
            kv_push(kx_code_t, code, ((kx_code_t){ .op = KX_CHKVAL, .file = const_str(__FILE__), .line = __LINE__, .value1.i = KEX_INT, .value2.i = 100 }));
            kv_push(kx_code_t, code, ((kx_code_t){ .op = KX_PUSHI, .value1.i = 200 }));
            kv_push(kx_code_t, code, ((kx_code_t){ .op = KX_CHKVAL, .file = const_str(__FILE__), .line = __LINE__, .value1.i = KEX_INT, .value2.i = 200 }));
            kv_push(kx_code_t, code, ((kx_code_t){ .op = KX_PUSHD, .value1.d = 5.5 }));
            kv_push(kx_code_t, code, ((kx_code_t){ .op = KX_CHKVAL, .file = const_str(__FILE__), .line = __LINE__, .value1.i = KEX_DBL, .value2.d = 5.5 }));
            kv_push(kx_code_t, code, ((kx_code_t){ .op = KX_PUSHS, .value1.s = "aaaaaa" }));
            kv_push(kx_code_t, code, ((kx_code_t){ .op = KX_CHKVAL, .file = const_str(__FILE__), .line = __LINE__, .value1.i = KEX_CSTR, .value2.s = "aaaaaa" }));
            kv_push(kx_code_t, code, ((kx_code_t){ .op = KX_PUSHF, .addr = 10 }));
            kv_push(kx_code_t, code, ((kx_code_t){ .op = KX_PUSHLV, .value1.i = 0, .value2.i = 0 }));
            kv_push(kx_code_t, code, ((kx_code_t){ .op = KX_CHKVAL, .file = const_str(__FILE__), .line = __LINE__, .value1.i = KEX_INT, .value2.i = 100 }));
            kv_push(kx_code_t, code, ((kx_code_t){ .op = KX_PUSHLV, .value1.i = 0, .value2.i = 1 }));
            kv_push(kx_code_t, code, ((kx_code_t){ .op = KX_CHKVAL, .file = const_str(__FILE__), .line = __LINE__, .value1.i = KEX_DBL, .value2.d = 9.9 }));
            kv_push(kx_code_t, code, ((kx_code_t){ .op = KX_PUSHV, .value1.i = 0, .value2.i = 0 }));
            kv_push(kx_code_t, code, ((kx_code_t){ .op = KX_CHKVAL, .file = const_str(__FILE__), .line = __LINE__, .value1.i = KEX_INT, .value2.i = 100 }));
            kv_push(kx_code_t, code, ((kx_code_t){ .op = KX_PUSHV, .value1.i = 0, .value2.i = 1 }));
            kv_push(kx_code_t, code, ((kx_code_t){ .op = KX_CHKVAL, .file = const_str(__FILE__), .line = __LINE__, .value1.i = KEX_DBL, .value2.d = 9.9 }));
            kv_push(kx_code_t, code, ((kx_code_t){ .op = KX_PUSHVL0, .value1.i = 0, .value2.i = 1 }));
            kv_push(kx_code_t, code, ((kx_code_t){ .op = KX_CHKVAL, .file = const_str(__FILE__), .line = __LINE__, .value1.i = KEX_DBL, .value2.d = 9.9 }));
            kv_push(kx_code_t, code, ((kx_code_t){ .op = KX_PUSHVL0, .value1.i = 0, .value2.i = 2 }));
            kv_push(kx_code_t, code, ((kx_code_t){ .op = KX_CHKVAL, .file = const_str(__FILE__), .line = __LINE__, .value1.i = KEX_INT, .value2.i = 10000 }));

    kv_push(kx_code_t, code, ((kx_code_t){ .op = KX_PUSHI, .value1.i = 0 }));
    kv_push(kx_code_t, code, ((kx_code_t){ .op = KX_HALT }));
    int l = kv_size(code);
    for (int i = 0; i < l; ++i) {
        kv_push(kx_code_t*, fixcode, &kv_A(code, i));
    }

    return ir_exec(&fixcode);
}
