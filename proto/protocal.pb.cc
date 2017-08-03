// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: protocal.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "protocal.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace zeta {

namespace {

const ::google::protobuf::Descriptor* login_info_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  login_info_reflection_ = NULL;
const ::google::protobuf::Descriptor* logout_info_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  logout_info_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_protocal_2eproto() {
  protobuf_AddDesc_protocal_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "protocal.proto");
  GOOGLE_CHECK(file != NULL);
  login_info_descriptor_ = file->message_type(0);
  static const int login_info_offsets_[3] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(login_info, head_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(login_info, userid_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(login_info, pwd_),
  };
  login_info_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      login_info_descriptor_,
      login_info::default_instance_,
      login_info_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(login_info, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(login_info, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(login_info));
  logout_info_descriptor_ = file->message_type(1);
  static const int logout_info_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(logout_info, head_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(logout_info, userid_),
  };
  logout_info_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      logout_info_descriptor_,
      logout_info::default_instance_,
      logout_info_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(logout_info, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(logout_info, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(logout_info));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_protocal_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    login_info_descriptor_, &login_info::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    logout_info_descriptor_, &logout_info::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_protocal_2eproto() {
  delete login_info::default_instance_;
  delete login_info_reflection_;
  delete logout_info::default_instance_;
  delete logout_info_reflection_;
}

void protobuf_AddDesc_protocal_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::zeta::protobuf_AddDesc_basehead_2eproto();
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\016protocal.proto\022\004zeta\032\016basehead.proto\"K"
    "\n\nlogin_info\022 \n\004head\030\001 \002(\0132\022.zeta.messag"
    "e_head\022\016\n\006userid\030\002 \001(\005\022\013\n\003pwd\030\003 \001(\t\"\?\n\013l"
    "ogout_info\022 \n\004head\030\001 \002(\0132\022.zeta.message_"
    "head\022\016\n\006userid\030\002 \001(\005", 180);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "protocal.proto", &protobuf_RegisterTypes);
  login_info::default_instance_ = new login_info();
  logout_info::default_instance_ = new logout_info();
  login_info::default_instance_->InitAsDefaultInstance();
  logout_info::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_protocal_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_protocal_2eproto {
  StaticDescriptorInitializer_protocal_2eproto() {
    protobuf_AddDesc_protocal_2eproto();
  }
} static_descriptor_initializer_protocal_2eproto_;

// ===================================================================

#ifndef _MSC_VER
const int login_info::kHeadFieldNumber;
const int login_info::kUseridFieldNumber;
const int login_info::kPwdFieldNumber;
#endif  // !_MSC_VER

login_info::login_info()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void login_info::InitAsDefaultInstance() {
  head_ = const_cast< ::zeta::message_head*>(&::zeta::message_head::default_instance());
}

login_info::login_info(const login_info& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void login_info::SharedCtor() {
  _cached_size_ = 0;
  head_ = NULL;
  userid_ = 0;
  pwd_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

login_info::~login_info() {
  SharedDtor();
}

void login_info::SharedDtor() {
  if (pwd_ != &::google::protobuf::internal::kEmptyString) {
    delete pwd_;
  }
  if (this != default_instance_) {
    delete head_;
  }
}

void login_info::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* login_info::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return login_info_descriptor_;
}

const login_info& login_info::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_protocal_2eproto();
  return *default_instance_;
}

login_info* login_info::default_instance_ = NULL;

login_info* login_info::New() const {
  return new login_info;
}

void login_info::Clear() {
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (has_head()) {
      if (head_ != NULL) head_->::zeta::message_head::Clear();
    }
    userid_ = 0;
    if (has_pwd()) {
      if (pwd_ != &::google::protobuf::internal::kEmptyString) {
        pwd_->clear();
      }
    }
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool login_info::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required .zeta.message_head head = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_head()));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(16)) goto parse_userid;
        break;
      }

      // optional int32 userid = 2;
      case 2: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_userid:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &userid_)));
          set_has_userid();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(26)) goto parse_pwd;
        break;
      }

      // optional string pwd = 3;
      case 3: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_pwd:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_pwd()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8String(
            this->pwd().data(), this->pwd().length(),
            ::google::protobuf::internal::WireFormat::PARSE);
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectAtEnd()) return true;
        break;
      }

      default: {
      handle_uninterpreted:
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          return true;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
  return true;
#undef DO_
}

void login_info::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // required .zeta.message_head head = 1;
  if (has_head()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->head(), output);
  }

  // optional int32 userid = 2;
  if (has_userid()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(2, this->userid(), output);
  }

  // optional string pwd = 3;
  if (has_pwd()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->pwd().data(), this->pwd().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    ::google::protobuf::internal::WireFormatLite::WriteString(
      3, this->pwd(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* login_info::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // required .zeta.message_head head = 1;
  if (has_head()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->head(), target);
  }

  // optional int32 userid = 2;
  if (has_userid()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(2, this->userid(), target);
  }

  // optional string pwd = 3;
  if (has_pwd()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->pwd().data(), this->pwd().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        3, this->pwd(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int login_info::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required .zeta.message_head head = 1;
    if (has_head()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->head());
    }

    // optional int32 userid = 2;
    if (has_userid()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->userid());
    }

    // optional string pwd = 3;
    if (has_pwd()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->pwd());
    }

  }
  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void login_info::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const login_info* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const login_info*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void login_info::MergeFrom(const login_info& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_head()) {
      mutable_head()->::zeta::message_head::MergeFrom(from.head());
    }
    if (from.has_userid()) {
      set_userid(from.userid());
    }
    if (from.has_pwd()) {
      set_pwd(from.pwd());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void login_info::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void login_info::CopyFrom(const login_info& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool login_info::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000001) != 0x00000001) return false;

  if (has_head()) {
    if (!this->head().IsInitialized()) return false;
  }
  return true;
}

void login_info::Swap(login_info* other) {
  if (other != this) {
    std::swap(head_, other->head_);
    std::swap(userid_, other->userid_);
    std::swap(pwd_, other->pwd_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata login_info::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = login_info_descriptor_;
  metadata.reflection = login_info_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int logout_info::kHeadFieldNumber;
const int logout_info::kUseridFieldNumber;
#endif  // !_MSC_VER

logout_info::logout_info()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void logout_info::InitAsDefaultInstance() {
  head_ = const_cast< ::zeta::message_head*>(&::zeta::message_head::default_instance());
}

logout_info::logout_info(const logout_info& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void logout_info::SharedCtor() {
  _cached_size_ = 0;
  head_ = NULL;
  userid_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

logout_info::~logout_info() {
  SharedDtor();
}

void logout_info::SharedDtor() {
  if (this != default_instance_) {
    delete head_;
  }
}

void logout_info::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* logout_info::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return logout_info_descriptor_;
}

const logout_info& logout_info::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_protocal_2eproto();
  return *default_instance_;
}

logout_info* logout_info::default_instance_ = NULL;

logout_info* logout_info::New() const {
  return new logout_info;
}

void logout_info::Clear() {
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (has_head()) {
      if (head_ != NULL) head_->::zeta::message_head::Clear();
    }
    userid_ = 0;
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool logout_info::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required .zeta.message_head head = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_head()));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(16)) goto parse_userid;
        break;
      }

      // optional int32 userid = 2;
      case 2: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_userid:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &userid_)));
          set_has_userid();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectAtEnd()) return true;
        break;
      }

      default: {
      handle_uninterpreted:
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          return true;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
  return true;
#undef DO_
}

void logout_info::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // required .zeta.message_head head = 1;
  if (has_head()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->head(), output);
  }

  // optional int32 userid = 2;
  if (has_userid()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(2, this->userid(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* logout_info::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // required .zeta.message_head head = 1;
  if (has_head()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->head(), target);
  }

  // optional int32 userid = 2;
  if (has_userid()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(2, this->userid(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int logout_info::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required .zeta.message_head head = 1;
    if (has_head()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->head());
    }

    // optional int32 userid = 2;
    if (has_userid()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->userid());
    }

  }
  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void logout_info::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const logout_info* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const logout_info*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void logout_info::MergeFrom(const logout_info& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_head()) {
      mutable_head()->::zeta::message_head::MergeFrom(from.head());
    }
    if (from.has_userid()) {
      set_userid(from.userid());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void logout_info::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void logout_info::CopyFrom(const logout_info& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool logout_info::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000001) != 0x00000001) return false;

  if (has_head()) {
    if (!this->head().IsInitialized()) return false;
  }
  return true;
}

void logout_info::Swap(logout_info* other) {
  if (other != this) {
    std::swap(head_, other->head_);
    std::swap(userid_, other->userid_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata logout_info::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = logout_info_descriptor_;
  metadata.reflection = logout_info_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace zeta

// @@protoc_insertion_point(global_scope)