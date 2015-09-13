#pragma once
namespace jbamboo { // open namespace jbamboo


inline jfieldID get_handle_field(JNIEnv *env, jobject obj)
{
    jclass c = env->GetObjectClass(obj);
    return env->GetFieldID(c, "_handle", "J");
}

template <typename T>
inline T *get_handle(JNIEnv *env, jobject obj)
{
    jlong handle = env->GetLongField(obj, get_handle_field(env, obj));
    return reinterpret_cast<T *>(handle);
}

template <typename T>
inline void set_handle(JNIEnv *env, jobject obj, T *t)
{
    jlong handle = reinterpret_cast<jlong>(t);
    env->SetLongField(obj, get_handle_field(env, obj), handle);
}

inline jobject init_obj_with_handle(JNIEnv *env, const char *clspath, jlong handle)
{
    jclass cls = env->FindClass(clspath);
    jmethodID ctor = env->GetMethodID(cls, "<init>", "(J)V");
    jobject obj = env->NewObject(cls, ctor, handle);
    return obj;
}


} // close namespace jbamboo
