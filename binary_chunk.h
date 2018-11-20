#ifndef __binary_chunk_h__
#define __binary_chunk_h__

#include "unidef.h"

#define LUA_SIGNATURE       "\x1bLua"
#define LUAC_VERSION        0x53
#define LUAC_FORMAT         0
#define LUAC_DATA           "\x19\x93\r\n\x1a\n"
#define CINT_SIZE           4
#define CSIZET_SIZE         8
#define INSTRUCTION_SIZE    4
#define LUA_INTEGER_SIZE    8
#define LUA_NUMBER_SIZE     8
#define LUAC_INT            0x5678
#define LUAC_NUM            370.5

#define TAG_NIL             0x00
#define TAG_BOOLEAN         0x01
#define TAG_NUMBER          0x03
#define TAG_INTEGER         0x13
#define TAG_SHORT_STR       0x04
#define TAG_LONG_STR        0x14

typedef struct _header {
    
    byte    signature[4];
    byte    version;
    byte    format;
    byte    luacData[6];
    byte    cintSize;
    byte    sizetSize;
    byte    instructionSize;
    byte    luaIntegerSize;
    byte    luaNumberSize;
    int64   luacInt;
    float64 luacNum;

} Header;

typedef struct _constant {

    byte tag;
    union {
    };

} Constant;

typedef struct _upvalue {

} Upvalue;

typedef struct _locVar {

} LocVar;

typedef struct _prototype {
    
    unsigned char       * source;
    uint32              lineDefined;
    uint32              lastLineDefined;
    byte                numParams;
    byte                isVararg;
    byte                maxStackSize;
    uint32              * code;
    Constant            * constants;
    Upvalue             * upvalues;
    struct _prototype   * protos;
    uint32              * lineInfo;
    LocVar              * locVars;
    unsigned char       ** upvalueNames;

} Prototype;

typedef struct _binaryChunk {

    Header      *header;
    byte        sizeUpvalues;
    Prototype   *mainFunc;
    
} BinaryChunk;

#endif /* __binary_chunk_h__ */