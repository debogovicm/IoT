// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: weatherData.proto

#include "weatherData.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>

PROTOBUF_PRAGMA_INIT_SEG

namespace _pb = ::PROTOBUF_NAMESPACE_ID;
namespace _pbi = _pb::internal;

PROTOBUF_CONSTEXPR WeatherData::WeatherData(
    ::_pbi::ConstantInitialized): _impl_{
    /*decltype(_impl_.winddirection_)*/0
  , /*decltype(_impl_._temperature_)*/{}
  , /*decltype(_impl_._UVindex_)*/{}
  , /*decltype(_impl_._humidity_)*/{}
  , /*decltype(_impl_._cloudCover_)*/{}
  , /*decltype(_impl_._windSpeed_)*/{}
  , /*decltype(_impl_._cached_size_)*/{}
  , /*decltype(_impl_._oneof_case_)*/{}} {}
struct WeatherDataDefaultTypeInternal {
  PROTOBUF_CONSTEXPR WeatherDataDefaultTypeInternal()
      : _instance(::_pbi::ConstantInitialized{}) {}
  ~WeatherDataDefaultTypeInternal() {}
  union {
    WeatherData _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 WeatherDataDefaultTypeInternal _WeatherData_default_instance_;
static ::_pb::Metadata file_level_metadata_weatherData_2eproto[1];
static const ::_pb::EnumDescriptor* file_level_enum_descriptors_weatherData_2eproto[1];
static constexpr ::_pb::ServiceDescriptor const** file_level_service_descriptors_weatherData_2eproto = nullptr;

const uint32_t TableStruct_weatherData_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::WeatherData, _internal_metadata_),
  ~0u,  // no _extensions_
  PROTOBUF_FIELD_OFFSET(::WeatherData, _impl_._oneof_case_[0]),
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  ::_pbi::kInvalidFieldOffsetTag,
  ::_pbi::kInvalidFieldOffsetTag,
  ::_pbi::kInvalidFieldOffsetTag,
  ::_pbi::kInvalidFieldOffsetTag,
  ::_pbi::kInvalidFieldOffsetTag,
  PROTOBUF_FIELD_OFFSET(::WeatherData, _impl_.winddirection_),
  PROTOBUF_FIELD_OFFSET(::WeatherData, _impl_._temperature_),
  PROTOBUF_FIELD_OFFSET(::WeatherData, _impl_._UVindex_),
  PROTOBUF_FIELD_OFFSET(::WeatherData, _impl_._humidity_),
  PROTOBUF_FIELD_OFFSET(::WeatherData, _impl_._cloudCover_),
  PROTOBUF_FIELD_OFFSET(::WeatherData, _impl_._windSpeed_),
};
static const ::_pbi::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, -1, sizeof(::WeatherData)},
};

static const ::_pb::Message* const file_default_instances[] = {
  &::_WeatherData_default_instance_._instance,
};

const char descriptor_table_protodef_weatherData_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\021weatherData.proto\"\335\001\n\013WeatherData\022\025\n\013t"
  "emperature\030\001 \001(\005H\000\022\021\n\007UVindex\030\002 \001(\rH\001\022\022\n"
  "\010humidity\030\003 \001(\rH\002\022\024\n\ncloudCover\030\004 \001(\rH\003\022"
  "\023\n\twindSpeed\030\005 \001(\rH\004\022\037\n\rwindDirection\030\006 "
  "\001(\0162\010.WindDirB\016\n\014_temperatureB\n\n\010_UVinde"
  "xB\013\n\t_humidityB\r\n\013_cloudCoverB\014\n\n_windSp"
  "eed*V\n\007WindDir\022\017\n\013UNSPECIFIED\020\000\022\005\n\001N\020\001\022\006"
  "\n\002NE\020\002\022\005\n\001E\020\003\022\006\n\002SE\020\004\022\005\n\001S\020\005\022\006\n\002SW\020\006\022\005\n\001"
  "W\020\007\022\006\n\002NW\020\010b\006proto3"
  ;
static ::_pbi::once_flag descriptor_table_weatherData_2eproto_once;
const ::_pbi::DescriptorTable descriptor_table_weatherData_2eproto = {
    false, false, 339, descriptor_table_protodef_weatherData_2eproto,
    "weatherData.proto",
    &descriptor_table_weatherData_2eproto_once, nullptr, 0, 1,
    schemas, file_default_instances, TableStruct_weatherData_2eproto::offsets,
    file_level_metadata_weatherData_2eproto, file_level_enum_descriptors_weatherData_2eproto,
    file_level_service_descriptors_weatherData_2eproto,
};
PROTOBUF_ATTRIBUTE_WEAK const ::_pbi::DescriptorTable* descriptor_table_weatherData_2eproto_getter() {
  return &descriptor_table_weatherData_2eproto;
}

// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY2 static ::_pbi::AddDescriptorsRunner dynamic_init_dummy_weatherData_2eproto(&descriptor_table_weatherData_2eproto);
const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* WindDir_descriptor() {
  ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&descriptor_table_weatherData_2eproto);
  return file_level_enum_descriptors_weatherData_2eproto[0];
}
bool WindDir_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
      return true;
    default:
      return false;
  }
}


// ===================================================================

class WeatherData::_Internal {
 public:
};

WeatherData::WeatherData(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor(arena, is_message_owned);
  // @@protoc_insertion_point(arena_constructor:WeatherData)
}
WeatherData::WeatherData(const WeatherData& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  WeatherData* const _this = this; (void)_this;
  new (&_impl_) Impl_{
      decltype(_impl_.winddirection_){}
    , decltype(_impl_._temperature_){}
    , decltype(_impl_._UVindex_){}
    , decltype(_impl_._humidity_){}
    , decltype(_impl_._cloudCover_){}
    , decltype(_impl_._windSpeed_){}
    , /*decltype(_impl_._cached_size_)*/{}
    , /*decltype(_impl_._oneof_case_)*/{}};

  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  _this->_impl_.winddirection_ = from._impl_.winddirection_;
  clear_has__temperature();
  switch (from._temperature_case()) {
    case kTemperature: {
      _this->_internal_set_temperature(from._internal_temperature());
      break;
    }
    case _TEMPERATURE_NOT_SET: {
      break;
    }
  }
  clear_has__UVindex();
  switch (from._UVindex_case()) {
    case kUVindex: {
      _this->_internal_set_uvindex(from._internal_uvindex());
      break;
    }
    case _UVINDEX_NOT_SET: {
      break;
    }
  }
  clear_has__humidity();
  switch (from._humidity_case()) {
    case kHumidity: {
      _this->_internal_set_humidity(from._internal_humidity());
      break;
    }
    case _HUMIDITY_NOT_SET: {
      break;
    }
  }
  clear_has__cloudCover();
  switch (from._cloudCover_case()) {
    case kCloudCover: {
      _this->_internal_set_cloudcover(from._internal_cloudcover());
      break;
    }
    case _CLOUDCOVER_NOT_SET: {
      break;
    }
  }
  clear_has__windSpeed();
  switch (from._windSpeed_case()) {
    case kWindSpeed: {
      _this->_internal_set_windspeed(from._internal_windspeed());
      break;
    }
    case _WINDSPEED_NOT_SET: {
      break;
    }
  }
  // @@protoc_insertion_point(copy_constructor:WeatherData)
}

inline void WeatherData::SharedCtor(
    ::_pb::Arena* arena, bool is_message_owned) {
  (void)arena;
  (void)is_message_owned;
  new (&_impl_) Impl_{
      decltype(_impl_.winddirection_){0}
    , decltype(_impl_._temperature_){}
    , decltype(_impl_._UVindex_){}
    , decltype(_impl_._humidity_){}
    , decltype(_impl_._cloudCover_){}
    , decltype(_impl_._windSpeed_){}
    , /*decltype(_impl_._cached_size_)*/{}
    , /*decltype(_impl_._oneof_case_)*/{}
  };
  clear_has__temperature();
  clear_has__UVindex();
  clear_has__humidity();
  clear_has__cloudCover();
  clear_has__windSpeed();
}

WeatherData::~WeatherData() {
  // @@protoc_insertion_point(destructor:WeatherData)
  if (auto *arena = _internal_metadata_.DeleteReturnArena<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>()) {
  (void)arena;
    return;
  }
  SharedDtor();
}

inline void WeatherData::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
  if (has__temperature()) {
    clear__temperature();
  }
  if (has__UVindex()) {
    clear__UVindex();
  }
  if (has__humidity()) {
    clear__humidity();
  }
  if (has__cloudCover()) {
    clear__cloudCover();
  }
  if (has__windSpeed()) {
    clear__windSpeed();
  }
}

void WeatherData::SetCachedSize(int size) const {
  _impl_._cached_size_.Set(size);
}

void WeatherData::clear__temperature() {
// @@protoc_insertion_point(one_of_clear_start:WeatherData)
  switch (_temperature_case()) {
    case kTemperature: {
      // No need to clear
      break;
    }
    case _TEMPERATURE_NOT_SET: {
      break;
    }
  }
  _impl_._oneof_case_[0] = _TEMPERATURE_NOT_SET;
}

void WeatherData::clear__UVindex() {
// @@protoc_insertion_point(one_of_clear_start:WeatherData)
  switch (_UVindex_case()) {
    case kUVindex: {
      // No need to clear
      break;
    }
    case _UVINDEX_NOT_SET: {
      break;
    }
  }
  _impl_._oneof_case_[1] = _UVINDEX_NOT_SET;
}

void WeatherData::clear__humidity() {
// @@protoc_insertion_point(one_of_clear_start:WeatherData)
  switch (_humidity_case()) {
    case kHumidity: {
      // No need to clear
      break;
    }
    case _HUMIDITY_NOT_SET: {
      break;
    }
  }
  _impl_._oneof_case_[2] = _HUMIDITY_NOT_SET;
}

void WeatherData::clear__cloudCover() {
// @@protoc_insertion_point(one_of_clear_start:WeatherData)
  switch (_cloudCover_case()) {
    case kCloudCover: {
      // No need to clear
      break;
    }
    case _CLOUDCOVER_NOT_SET: {
      break;
    }
  }
  _impl_._oneof_case_[3] = _CLOUDCOVER_NOT_SET;
}

void WeatherData::clear__windSpeed() {
// @@protoc_insertion_point(one_of_clear_start:WeatherData)
  switch (_windSpeed_case()) {
    case kWindSpeed: {
      // No need to clear
      break;
    }
    case _WINDSPEED_NOT_SET: {
      break;
    }
  }
  _impl_._oneof_case_[4] = _WINDSPEED_NOT_SET;
}


void WeatherData::Clear() {
// @@protoc_insertion_point(message_clear_start:WeatherData)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  _impl_.winddirection_ = 0;
  clear__temperature();
  clear__UVindex();
  clear__humidity();
  clear__cloudCover();
  clear__windSpeed();
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* WeatherData::_InternalParse(const char* ptr, ::_pbi::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    uint32_t tag;
    ptr = ::_pbi::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // int32 temperature = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 8)) {
          _internal_set_temperature(::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr));
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // uint32 UVindex = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 16)) {
          _internal_set_uvindex(::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr));
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // uint32 humidity = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 24)) {
          _internal_set_humidity(::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr));
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // uint32 cloudCover = 4;
      case 4:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 32)) {
          _internal_set_cloudcover(::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr));
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // uint32 windSpeed = 5;
      case 5:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 40)) {
          _internal_set_windspeed(::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr));
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // .WindDir windDirection = 6;
      case 6:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 48)) {
          uint64_t val = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
          _internal_set_winddirection(static_cast<::WindDir>(val));
        } else
          goto handle_unusual;
        continue;
      default:
        goto handle_unusual;
    }  // switch
  handle_unusual:
    if ((tag == 0) || ((tag & 7) == 4)) {
      CHK_(ptr);
      ctx->SetLastTag(tag);
      goto message_done;
    }
    ptr = UnknownFieldParse(
        tag,
        _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
        ptr, ctx);
    CHK_(ptr != nullptr);
  }  // while
message_done:
  return ptr;
failure:
  ptr = nullptr;
  goto message_done;
#undef CHK_
}

uint8_t* WeatherData::_InternalSerialize(
    uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:WeatherData)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  // int32 temperature = 1;
  if (_internal_has_temperature()) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteInt32ToArray(1, this->_internal_temperature(), target);
  }

  // uint32 UVindex = 2;
  if (_internal_has_uvindex()) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteUInt32ToArray(2, this->_internal_uvindex(), target);
  }

  // uint32 humidity = 3;
  if (_internal_has_humidity()) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteUInt32ToArray(3, this->_internal_humidity(), target);
  }

  // uint32 cloudCover = 4;
  if (_internal_has_cloudcover()) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteUInt32ToArray(4, this->_internal_cloudcover(), target);
  }

  // uint32 windSpeed = 5;
  if (_internal_has_windspeed()) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteUInt32ToArray(5, this->_internal_windspeed(), target);
  }

  // .WindDir windDirection = 6;
  if (this->_internal_winddirection() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteEnumToArray(
      6, this->_internal_winddirection(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:WeatherData)
  return target;
}

size_t WeatherData::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:WeatherData)
  size_t total_size = 0;

  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // .WindDir windDirection = 6;
  if (this->_internal_winddirection() != 0) {
    total_size += 1 +
      ::_pbi::WireFormatLite::EnumSize(this->_internal_winddirection());
  }

  switch (_temperature_case()) {
    // int32 temperature = 1;
    case kTemperature: {
      total_size += ::_pbi::WireFormatLite::Int32SizePlusOne(this->_internal_temperature());
      break;
    }
    case _TEMPERATURE_NOT_SET: {
      break;
    }
  }
  switch (_UVindex_case()) {
    // uint32 UVindex = 2;
    case kUVindex: {
      total_size += ::_pbi::WireFormatLite::UInt32SizePlusOne(this->_internal_uvindex());
      break;
    }
    case _UVINDEX_NOT_SET: {
      break;
    }
  }
  switch (_humidity_case()) {
    // uint32 humidity = 3;
    case kHumidity: {
      total_size += ::_pbi::WireFormatLite::UInt32SizePlusOne(this->_internal_humidity());
      break;
    }
    case _HUMIDITY_NOT_SET: {
      break;
    }
  }
  switch (_cloudCover_case()) {
    // uint32 cloudCover = 4;
    case kCloudCover: {
      total_size += ::_pbi::WireFormatLite::UInt32SizePlusOne(this->_internal_cloudcover());
      break;
    }
    case _CLOUDCOVER_NOT_SET: {
      break;
    }
  }
  switch (_windSpeed_case()) {
    // uint32 windSpeed = 5;
    case kWindSpeed: {
      total_size += ::_pbi::WireFormatLite::UInt32SizePlusOne(this->_internal_windspeed());
      break;
    }
    case _WINDSPEED_NOT_SET: {
      break;
    }
  }
  return MaybeComputeUnknownFieldsSize(total_size, &_impl_._cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData WeatherData::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSourceCheck,
    WeatherData::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*WeatherData::GetClassData() const { return &_class_data_; }


void WeatherData::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg) {
  auto* const _this = static_cast<WeatherData*>(&to_msg);
  auto& from = static_cast<const WeatherData&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:WeatherData)
  GOOGLE_DCHECK_NE(&from, _this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  if (from._internal_winddirection() != 0) {
    _this->_internal_set_winddirection(from._internal_winddirection());
  }
  switch (from._temperature_case()) {
    case kTemperature: {
      _this->_internal_set_temperature(from._internal_temperature());
      break;
    }
    case _TEMPERATURE_NOT_SET: {
      break;
    }
  }
  switch (from._UVindex_case()) {
    case kUVindex: {
      _this->_internal_set_uvindex(from._internal_uvindex());
      break;
    }
    case _UVINDEX_NOT_SET: {
      break;
    }
  }
  switch (from._humidity_case()) {
    case kHumidity: {
      _this->_internal_set_humidity(from._internal_humidity());
      break;
    }
    case _HUMIDITY_NOT_SET: {
      break;
    }
  }
  switch (from._cloudCover_case()) {
    case kCloudCover: {
      _this->_internal_set_cloudcover(from._internal_cloudcover());
      break;
    }
    case _CLOUDCOVER_NOT_SET: {
      break;
    }
  }
  switch (from._windSpeed_case()) {
    case kWindSpeed: {
      _this->_internal_set_windspeed(from._internal_windspeed());
      break;
    }
    case _WINDSPEED_NOT_SET: {
      break;
    }
  }
  _this->_internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void WeatherData::CopyFrom(const WeatherData& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:WeatherData)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool WeatherData::IsInitialized() const {
  return true;
}

void WeatherData::InternalSwap(WeatherData* other) {
  using std::swap;
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  swap(_impl_.winddirection_, other->_impl_.winddirection_);
  swap(_impl_._temperature_, other->_impl_._temperature_);
  swap(_impl_._UVindex_, other->_impl_._UVindex_);
  swap(_impl_._humidity_, other->_impl_._humidity_);
  swap(_impl_._cloudCover_, other->_impl_._cloudCover_);
  swap(_impl_._windSpeed_, other->_impl_._windSpeed_);
  swap(_impl_._oneof_case_[0], other->_impl_._oneof_case_[0]);
  swap(_impl_._oneof_case_[1], other->_impl_._oneof_case_[1]);
  swap(_impl_._oneof_case_[2], other->_impl_._oneof_case_[2]);
  swap(_impl_._oneof_case_[3], other->_impl_._oneof_case_[3]);
  swap(_impl_._oneof_case_[4], other->_impl_._oneof_case_[4]);
}

::PROTOBUF_NAMESPACE_ID::Metadata WeatherData::GetMetadata() const {
  return ::_pbi::AssignDescriptors(
      &descriptor_table_weatherData_2eproto_getter, &descriptor_table_weatherData_2eproto_once,
      file_level_metadata_weatherData_2eproto[0]);
}

// @@protoc_insertion_point(namespace_scope)
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::WeatherData*
Arena::CreateMaybeMessage< ::WeatherData >(Arena* arena) {
  return Arena::CreateMessageInternal< ::WeatherData >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
