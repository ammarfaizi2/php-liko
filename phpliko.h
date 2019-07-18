
#ifndef LIKO_H
#define LIKO_H

	#define LIKO_VERSION "0.1"

	#include "php.h"

	#ifdef HAVE_CONFIG_H
		#include "config.h"
	#endif

	#ifdef ZTS
		#include "TSRM.h"
	#endif

	PHP_INI_BEGIN()
	PHP_INI_END()

	extern zend_module_entry liko_module_entry;

	// Define methods here...



	// End...

	ZEND_BEGIN_MODULE_GLOBALS(liko)
	ZEND_END_MODULE_GLOBALS(liko)
	ZEND_EXTERN_MODULE_GLOBALS(liko)
	#define PHPLIKOG(v) ZEND_MODULE_GLOBALS_ACCESSOR(liko, v)


	#if defined(ZTS) && defined(COMPILE_DL_SAMPLE)
		ZEND_TSRMLS_CACHE_EXTERN()
	#endif

	#ifdef COMPILE_DL_LIKO
	    #ifdef ZTS
	        ZEND_TSRMLS_CACHE_DEFINE()
	    #endif
	    ZEND_GET_MODULE(liko)
	#endif

	#define phpext_liko_ptr &liko_module_entry
#endif
