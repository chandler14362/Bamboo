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

JNIEXPORT jboolean JNICALL Java_bamboo_Module_hasKeyword
  (JNIEnv *, jobject, jstring);

JNIEXPORT jint JNICALL Java_bamboo_Module_getNumKeywords
  (JNIEnv *, jobject);

JNIEXPORT jstring JNICALL Java_bamboo_Module_getKeyword
  (JNIEnv *, jobject, jint);

JNIEXPORT jint JNICALL Java_bamboo_Module_getNumStructs
  (JNIEnv *, jobject);

JNIEXPORT jobject JNICALL Java_bamboo_Module_getStruct
  (JNIEnv *, jobject, jint);

JNIEXPORT jlong JNICALL Java_bamboo_Module_calculateHash
  (JNIEnv *, jobject);

#ifdef __cplusplus
}
#endif

#endif
