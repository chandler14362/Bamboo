#include "bamboo_module_Struct.h"
#include "handle.h"
#include "util.h"

#include "module/Module.h"

JNIEXPORT jint JNICALL Java_bamboo_module_Struct_getId
  (JNIEnv *env, jobject obj)
{
    bamboo::Struct *dstruct = jbamboo::get_handle<bamboo::Struct>(env, obj);
    return dstruct->id();
}

JNIEXPORT jstring JNICALL Java_bamboo_module_Struct_getName
  (JNIEnv *env, jobject obj)
{
    bamboo::Struct *dstruct = jbamboo::get_handle<bamboo::Struct>(env, obj);
    return env->NewStringUTF(dstruct->name().c_str());
}
