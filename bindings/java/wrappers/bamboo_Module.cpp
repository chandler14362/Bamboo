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

JNIEXPORT jlong JNICALL Java_bamboo_Module_calculateHash
  (JNIEnv *env, jobject obj)
{
    bamboo::Module *module = jbamboo::get_handle<bamboo::Module>(env, obj);
    return bamboo::legacy_hash(module);
}
