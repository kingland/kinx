#define KX_NOT_CODE() \
{ \
    KEX_GET_STACK_TOP(v1); \
    KX_IS_FALSE(v1, tf); \
    (v1)->value.iv = tf; \
    (v1)->type = KX_INT_T; \
    cur = cur->next; \
} \
/**/
