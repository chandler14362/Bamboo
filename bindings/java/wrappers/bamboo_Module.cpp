#include "bamboo_Module.h"
#include "classes.h"
#include "handle.h"
#include "util.h"

#include "module/Module.h"
#include "dcfile/parse.h"
#include "traits/hashes.h"

JNIEXPORT jobject JNICALL Java_bamboo_Module_readDCFile
  (JNIEnv *env, jclass cls, jstring jstr)
{
    std::string filename = jbamboo::jstring_to_string(env, jstr);
    bamboo::Module *module = bamboo::read_dcfile(filename);
    return jbamboo::init_obj_with_handle(env, jbamboo::module_cls, (jlong)module);
}

JNIEXPORT jboolean JNICALL Java_bamboo_Module_parseDCFile
  (JNIEnv *env, jobject obj, jstring jstr)
{
    bamboo::Module *module = jbamboo::get_handle<bamboo::Module>(env, obj);
    std::string filename = jbamboo::jstring_to_string(env, jstr);
    return parse_dcfile(module, filename);
}

JNIEXPORT jboolean JNICALL Java_bamboo_Module_hasKeyword
  (JNIEnv *env, jobject obj, jstring jstr)
{
    bamboo::Module *module = jbamboo::get_handle<bamboo::Module>(env, obj);
    std::string keyword = jbamboo::jstring_to_string(env, jstr);
    return module->has_keyword(keyword);
}

JNIEXPORT jint JNICALL Java_bamboo_Module_getNumKeywords
  (JNIEnv *env, jobject obj)
{
    bamboo::Module *module = jbamboo::get_handle<bamboo::Module>(env, obj);
    return module->num_keywords();
}

JNIEXPORT jstring JNICALL Java_bamboo_Module_getKeyword
  (JNIEnv *env, jobject obj, jint n)
{
    bamboo::Module *module = jbamboo::get_handle<bamboo::Module>(env, obj);
    return env->NewStringUTF(module->get_keyword(n).c_str());
}

JNIEXPORT jint JNICALL Java_bamboo_Module_getNumStructs
  (JNIEnv *env, jobject obj)
{
    bamboo::Module *module = jbamboo::get_handle<bamboo::Module>(env, obj);
    return module->num_structs();
}

JNIEXPORT jobject JNICALL Java_bamboo_Module_getStruct
  (JNIEnv *env, jobject obj, jint n)
{
    bamboo::Module *module = jbamboo::get_handle<bamboo::Module>(env, obj);
    bamboo::Struct *dstruct = module->get_struct(n);
    return jbamboo::init_obj_with_handle(env, jbamboo::struct_cls, (jlong)dstruct);
}

JNIEXPORT jlong JNICALL Java_bamboo_Module_calculateHash
  (JNIEnv *env, jobject obj)
{
    bamboo::Module *module = jbamboo::get_handle<bamboo::Module>(env, obj);
    return bamboo::legacy_hash(module);
}
