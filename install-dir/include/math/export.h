
#ifndef MATH_EXPORT_H
#define MATH_EXPORT_H

#ifdef MATH_STATIC_DEFINE
#  define MATH_EXPORT
#  define MATH_NO_EXPORT
#else
#  ifndef MATH_EXPORT
#    ifdef math_EXPORTS
        /* We are building this library */
#      define MATH_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define MATH_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef MATH_NO_EXPORT
#    define MATH_NO_EXPORT 
#  endif
#endif

#ifndef MATH_DEPRECATED
#  define MATH_DEPRECATED __declspec(deprecated)
#endif

#ifndef MATH_DEPRECATED_EXPORT
#  define MATH_DEPRECATED_EXPORT MATH_EXPORT MATH_DEPRECATED
#endif

#ifndef MATH_DEPRECATED_NO_EXPORT
#  define MATH_DEPRECATED_NO_EXPORT MATH_NO_EXPORT MATH_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef MATH_NO_DEPRECATED
#    define MATH_NO_DEPRECATED
#  endif
#endif

#endif /* MATH_EXPORT_H */
