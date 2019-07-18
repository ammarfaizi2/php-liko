
#include "phpliko.h"

ZEND_DECLARE_MODULE_GLOBALS(liko);

static zend_class_entry *liko_class_entry;
#define liko_ce liko_class_entry

const zend_function_entry liko_lang_class_methods[] = {
};

/**
 * Init.
 */
static PHP_MINIT_FUNCTION(liko)
{
    zend_class_entry ce;
    INIT_NS_CLASS_ENTRY(ce, "Liko", "Liko", liko_lang_class_methods);
    liko_class_entry = zend_register_internal_class(&ce TSRMLS_CC);
    REGISTER_INI_ENTRIES();
    return SUCCESS;
}


/**
 * Shutdown.
 */
static PHP_MSHUTDOWN_FUNCTION(liko)
{
    UNREGISTER_INI_ENTRIES();
    return SUCCESS;
}

/**
 * Global init.
 */
static PHP_GINIT_FUNCTION(liko)
{
    #if defined(COMPILE_DL_ASTKIT) && defined(ZTS)
        ZEND_TSRMLS_CACHE_UPDATE();
    #endif
}

zend_module_entry liko_module_entry = {
    STANDARD_MODULE_HEADER,
    "liko",
    NULL, /* functions */
    PHP_MINIT(liko),
    PHP_MSHUTDOWN(liko),
    NULL, /* RINIT */
    NULL, /* RSHUTDOWN */
    NULL, /* MINFO */
    LIKO_VERSION,
    PHP_MODULE_GLOBALS(liko),
    PHP_GINIT(liko),
    NULL, /* GSHUTDOWN */
    NULL, /* RPOSTSHUTDOWN */
    STANDARD_MODULE_PROPERTIES_EX
};
