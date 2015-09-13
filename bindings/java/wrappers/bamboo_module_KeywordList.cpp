#include "bamboo_module_KeywordList.h"
#include "handle.h"
#include "util.h"

#include "module/Module.h"

JNIEXPORT jboolean JNICALL Java_bamboo_module_KeywordList_hasKeyword
  (JNIEnv *env, jobject obj, jstring jstr)
{
    bamboo::KeywordList *kw = jbamboo::get_handle<bamboo::KeywordList>(env, obj);
    return kw->has_keyword(jbamboo::jstring_to_string(env, jstr));
}

JNIEXPORT jint JNICALL Java_bamboo_module_KeywordList_getNumKeywords
  (JNIEnv *env, jobject obj)
{
    bamboo::KeywordList *kw = jbamboo::get_handle<bamboo::KeywordList>(env, obj);
    return kw->num_keywords();
}

JNIEXPORT jstring JNICALL Java_bamboo_module_KeywordList_getKeyword
  (JNIEnv *env, jobject obj, jint n)
{
    bamboo::KeywordList *kw = jbamboo::get_handle<bamboo::KeywordList>(env, obj);
    return env->NewStringUTF(kw->get_keyword(n).c_str());
}

JNIEXPORT jboolean JNICALL Java_bamboo_module_KeywordList_hasMatchingKeywords
  (JNIEnv *env, jobject obj, jobject other)
{
    bamboo::KeywordList *kw = jbamboo::get_handle<bamboo::KeywordList>(env, obj);
    bamboo::KeywordList *okw = jbamboo::get_handle<bamboo::KeywordList>(env, other);
    return kw->has_matching_keywords(*okw);
}

JNIEXPORT void JNICALL Java_bamboo_module_KeywordList_copyKeywords
  (JNIEnv *env, jobject obj, jobject other)
{
    bamboo::KeywordList *kw = jbamboo::get_handle<bamboo::KeywordList>(env, obj);
    bamboo::KeywordList *okw = jbamboo::get_handle<bamboo::KeywordList>(env, other);
    kw->copy_keywords(*okw);
}

JNIEXPORT jboolean JNICALL Java_bamboo_module_KeywordList_addKeyword
  (JNIEnv *env, jobject obj, jstring jstr)
{
    bamboo::KeywordList *kw = jbamboo::get_handle<bamboo::KeywordList>(env, obj);
    return kw->add_keyword(jbamboo::jstring_to_string(env, jstr));
}
