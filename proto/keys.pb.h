// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: keys.proto

#ifndef PROTOBUF_keys_2eproto__INCLUDED
#define PROTOBUF_keys_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3000000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3000000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/generated_enum_reflection.h>
// @@protoc_insertion_point(includes)

namespace msgs {

// Internal implementation detail -- do not call these.
void protobuf_AddDesc_keys_2eproto();
void protobuf_AssignDesc_keys_2eproto();
void protobuf_ShutdownFile_keys_2eproto();


enum Keycode {
  KeyUnknown = 0,
  KeyBackspace = 1,
  KeyTab = 2,
  KeyReturn = 3,
  KeyLShift = 4,
  KeyControl = 5,
  KeyAlt = 6,
  KeyMeta = 7,
  KeyA = 8,
  KeyB = 9,
  KeyC = 10,
  KeyD = 11,
  KeyE = 12,
  KeyF = 13,
  KeyG = 14,
  KeyH = 15,
  KeyI = 16,
  KeyJ = 17,
  KeyK = 18,
  KeyL = 19,
  KeyM = 20,
  KeyN = 21,
  KeyO = 22,
  KeyP = 23,
  KeyQ = 24,
  KeyR = 25,
  KeyS = 26,
  KeyT = 27,
  KeyU = 28,
  KeyV = 29,
  KeyW = 30,
  KeyX = 31,
  KeyY = 32,
  KeyZ = 33,
  Key0 = 34,
  Key1 = 35,
  Key2 = 36,
  Key3 = 37,
  Key4 = 38,
  Key5 = 39,
  Key6 = 40,
  Key7 = 41,
  Key8 = 42,
  Key9 = 43,
  KeyPause = 44,
  KeyCapsLock = 45,
  KeyEscape = 46,
  KeySpace = 47,
  KeyPageUp = 48,
  KeyPageDown = 49,
  KeyEnd = 50,
  KeyHome = 51,
  KeyLeft = 52,
  KeyUp = 53,
  KeyRight = 54,
  KeyDown = 55,
  KeySelect = 56,
  KeyPrint = 57,
  KeyExecute = 58,
  KeyInsert = 59,
  KeyDelete = 60,
  KeyHelp = 61,
  KeySleep = 62,
  KeyKeypad0 = 63,
  KeyKeypad1 = 64,
  KeyKeypad2 = 65,
  KeyKeypad3 = 66,
  KeyKeypad4 = 67,
  KeyKeypad5 = 68,
  KeyKeypad6 = 69,
  KeyKeypad7 = 70,
  KeyKeypad8 = 71,
  KeyKeypad9 = 72,
  KeyKeypadAsterisk = 73,
  KeyKeypadPlus = 74,
  KeyKeypadComma = 75,
  KeyKeypadMinus = 76,
  KeyKeypadPeriod = 77,
  KeyKeypadSlash = 78,
  KeyF1 = 79,
  KeyF2 = 80,
  KeyF3 = 81,
  KeyF4 = 82,
  KeyF5 = 83,
  KeyF6 = 84,
  KeyF7 = 85,
  KeyF8 = 86,
  KeyF9 = 87,
  KeyF10 = 88,
  KeyF11 = 89,
  KeyF12 = 90,
  KeyF13 = 91,
  KeyF14 = 92,
  KeyF15 = 93,
  KeyF16 = 94,
  KeyF17 = 95,
  KeyF18 = 96,
  KeyF19 = 97,
  KeyF20 = 98,
  KeyF21 = 99,
  KeyF22 = 100,
  KeyF23 = 101,
  KeyF24 = 102,
  KeyNumLock = 103,
  KeyScrollLock = 104,
  KeyBack = 105,
  KeyForward = 106,
  KeyRefresh = 107,
  KeyStop = 108,
  KeySearch = 109,
  KeyFavorites = 110,
  KeyHomePage = 111,
  KeyVolumeMute = 112,
  KeyVolumeDown = 113,
  KeyVolumeUp = 114,
  KeyMediaNext = 115,
  KeyMediaPrev = 116,
  KeyMediaStop = 117,
  KeyMediaTogglePlayPause = 118,
  KeyPlay = 119,
  KeyZoom = 120
};
bool Keycode_IsValid(int value);
const Keycode Keycode_MIN = KeyUnknown;
const Keycode Keycode_MAX = KeyZoom;
const int Keycode_ARRAYSIZE = Keycode_MAX + 1;

const ::google::protobuf::EnumDescriptor* Keycode_descriptor();
inline const ::std::string& Keycode_Name(Keycode value) {
  return ::google::protobuf::internal::NameOfEnum(
    Keycode_descriptor(), value);
}
inline bool Keycode_Parse(
    const ::std::string& name, Keycode* value) {
  return ::google::protobuf::internal::ParseNamedEnum<Keycode>(
    Keycode_descriptor(), name, value);
}
// ===================================================================


// ===================================================================


// ===================================================================

#if !PROTOBUF_INLINE_NOT_IN_HEADERS
#endif  // !PROTOBUF_INLINE_NOT_IN_HEADERS

// @@protoc_insertion_point(namespace_scope)

}  // namespace msgs

#ifndef SWIG
namespace google {
namespace protobuf {

template <> struct is_proto_enum< ::msgs::Keycode> : ::google::protobuf::internal::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::msgs::Keycode>() {
  return ::msgs::Keycode_descriptor();
}

}  // namespace protobuf
}  // namespace google
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_keys_2eproto__INCLUDED