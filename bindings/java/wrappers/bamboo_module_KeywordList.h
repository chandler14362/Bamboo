#include <jni.h>

#ifndef _Included_bamboo_module_KeywordList
#define _Included_bamboo_module_KeywordList

#ifdef __cplusplus
extern "C" {
#endif

JNIEXPORT jboolean JNICALL Java_bamboo_module_KeywordList_hasKeyword
  (JNIEnv *, jobject, jstring);

JNIEXPORT jint JNICALL Java_bamboo_module_KeywordList_getNumKeywords
  (JNIEnv *, jobject);

JNIEXPORT jstring JNICALL Java_bamboo_module_KeywordList_getKeyword
  (JNIEnv *, jobject, jint);

JNIEXPORT jboolean JNICALL Java_bamboo_module_KeywordList_hasMatchingKeywords
  (JNIEnv *, jobject, jobject);

JNIEXPORT void JNICALL Java_bamboo_module_KeywordList_copyKeywords
  (JNIEnv *, jobject, jobject);

JNIEXPORT jboolean JNICALL Java_bamboo_module_KeywordList_addKeyword
  (JNIEnv *, jobject, jstring);

#ifdef __cplusplus
}
#endif

#endif
