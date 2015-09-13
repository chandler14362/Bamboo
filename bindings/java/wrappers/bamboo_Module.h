#include <jni.h>

#ifndef _Included_bamboo_Module
#define _Included_bamboo_Module

#ifdef __cplusplus
extern "C" {
#endif

JNIEXPORT jobject JNICALL Java_bamboo_Module_readDCFile
  (JNIEnv *, jclass, jstring);

JNIEXPORT jboolean JNICALL Java_bamboo_Module_parseDCFile
  (JNIEnv *, jobject, jstring);

JNIEXPORT jlong JNICALL Java_bamboo_Module_calculateHash
  (JNIEnv *, jobject);

JNIEXPORT jint JNICALL Java_bamboo_Module_getNumStructs
  (JNIEnv *, jobject);

JNIEXPORT jobject JNICALL Java_bamboo_Module_getStruct
  (JNIEnv *, jobject, jint);

#ifdef __cplusplus
}
#endif

#endif
