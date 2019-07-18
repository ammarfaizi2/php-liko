
dnl config.m4 extension liko

PHP_ARG_ENABLE(phpnasm, for phpnasm support,
[  --enable-liko            Include liko support])

if test "$PHP_LIKO" != "no"; then
  PHP_NEW_EXTENSION(liko, phpliko.c, $ext_shared)
  PHP_SUBST(liko_SHARED_LIBADD)
fi
