// Filename: NumericRange.h
#pragma once
#include <math.h> // INFINITY
#include <stdint.h>
namespace bamboo { // open namespace bamboo


// A Number represent any C++ numeric type.
struct Number {
    enum Type {
        kNan = 0,
        kInt,
        kUint,
        kFloat,
    };

    Type type;
    union {
        int64_t integer;
        uint64_t uinteger;
        double floating;

    };

    Number()           : type(kNan),  integer(0)  {}
    Number(int32_t n)  : type(kInt),   integer(n)  {}
    Number(int64_t n)  : type(kInt),   integer(n)  {}
    Number(uint32_t n) : type(kUint),  uinteger(n) {}
    Number(uint64_t n) : type(kUint),  uinteger(n) {}
    Number(double n)   : type(kFloat), floating(n) {}
    Number operator=(int64_t n)  { return Number(n); }
    Number operator=(uint64_t n) { return Number(n); }
    Number operator=(double n)   { return Number(n); }
};

inline bool operator==(const Number& a, const Number& b) {
    return a.type == b.type && a.uinteger == b.uinteger;
}

// A NumericRange represents a range of integer or floating-point values.
//     This is used to limit numeric types; or array, string, or blob sizes.
struct NumericRange {
    Number::Type type;
    Number min;
    Number max;

    inline NumericRange() : type(Number::kNan) {
        min.type = max.type = Number::kNan;
        min.floating = -INFINITY;
        max.floating =  INFINITY;
    }
    inline NumericRange(int32_t min, int32_t max)   : type(Number::kInt),   min(min), max(max) {}
    inline NumericRange(int64_t min, int64_t max)   : type(Number::kInt),   min(min), max(max) {}
    inline NumericRange(uint32_t min, uint32_t max) : type(Number::kUint),  min(min), max(max) {}
    inline NumericRange(uint64_t min, uint64_t max) : type(Number::kUint),  min(min), max(max) {}
    inline NumericRange(double min, double max)     : type(Number::kFloat), min(min), max(max) {}

    inline bool contains(Number num) const {
        switch(min.type) {
            case Number::kNan:
                return true;
            case Number::kInt:
                return (min.integer <= num.integer && num.integer <= max.integer);
            case Number::kUint:
                return (min.uinteger <= num.uinteger && num.uinteger <= max.uinteger);
            case Number::kFloat:
                return (min.floating <= num.floating && num.floating <= max.floating);
        }
    }

    inline bool is_empty() const {
        return (type == Number::kNan);
    }
};


} // close namespace bamboo
