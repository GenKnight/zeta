// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: basehead.proto

#ifndef PROTOBUF_basehead_2eproto__INCLUDED
#define PROTOBUF_basehead_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 2005000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 2005000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)

namespace zeta {

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_basehead_2eproto();
void protobuf_AssignDesc_basehead_2eproto();
void protobuf_ShutdownFile_basehead_2eproto();

class message_head;

// ===================================================================

class message_head : public ::google::protobuf::Message {
 public:
  message_head();
  virtual ~message_head();

  message_head(const message_head& from);

  inline message_head& operator=(const message_head& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const message_head& default_instance();

  void Swap(message_head* other);

  // implements Message ----------------------------------------------

  message_head* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const message_head& from);
  void MergeFrom(const message_head& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // required int32 size = 1;
  inline bool has_size() const;
  inline void clear_size();
  static const int kSizeFieldNumber = 1;
  inline ::google::protobuf::int32 size() const;
  inline void set_size(::google::protobuf::int32 value);

  // optional int32 type = 2;
  inline bool has_type() const;
  inline void clear_type();
  static const int kTypeFieldNumber = 2;
  inline ::google::protobuf::int32 type() const;
  inline void set_type(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:zeta.message_head)
 private:
  inline void set_has_size();
  inline void clear_has_size();
  inline void set_has_type();
  inline void clear_has_type();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::int32 size_;
  ::google::protobuf::int32 type_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(2 + 31) / 32];

  friend void  protobuf_AddDesc_basehead_2eproto();
  friend void protobuf_AssignDesc_basehead_2eproto();
  friend void protobuf_ShutdownFile_basehead_2eproto();

  void InitAsDefaultInstance();
  static message_head* default_instance_;
};
// ===================================================================


// ===================================================================

// message_head

// required int32 size = 1;
inline bool message_head::has_size() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void message_head::set_has_size() {
  _has_bits_[0] |= 0x00000001u;
}
inline void message_head::clear_has_size() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void message_head::clear_size() {
  size_ = 0;
  clear_has_size();
}
inline ::google::protobuf::int32 message_head::size() const {
  return size_;
}
inline void message_head::set_size(::google::protobuf::int32 value) {
  set_has_size();
  size_ = value;
}

// optional int32 type = 2;
inline bool message_head::has_type() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void message_head::set_has_type() {
  _has_bits_[0] |= 0x00000002u;
}
inline void message_head::clear_has_type() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void message_head::clear_type() {
  type_ = 0;
  clear_has_type();
}
inline ::google::protobuf::int32 message_head::type() const {
  return type_;
}
inline void message_head::set_type(::google::protobuf::int32 value) {
  set_has_type();
  type_ = value;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace zeta

#ifndef SWIG
namespace google {
namespace protobuf {


}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_basehead_2eproto__INCLUDED
