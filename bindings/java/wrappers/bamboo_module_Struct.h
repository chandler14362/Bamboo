#include <jni.h>

#ifndef _Included_bamboo_module_Struct
#define _Included_bamboo_module_Struct

#ifdef __cplusplus
extern "C" {
#endif

JNIEXPORT jint JNICALL Java_bamboo_module_Struct_getId
  (JNIEnv *, jobject);

JNIEXPORT jstring JNICALL Java_bamboo_module_Struct_getName
  (JNIEnv *, jobject);

#ifdef __cplusplus
}
#endif

#endif
