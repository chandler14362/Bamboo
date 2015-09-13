#pragma once

#include <string>

namespace jbamboo { // open namespace jbamboo


inline std::string jstring_to_string(JNIEnv *env, jstring jstr)
{
    const char *cstr = env->GetStringUTFChars(jstr, 0);
    std::string str(cstr);
    env->ReleaseStringUTFChars(jstr, cstr);
    return str;
}


} // close namespace jbamboo
