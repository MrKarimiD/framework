// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: gamestate.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "gamestate.pb.h"

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

namespace amun {

namespace {

const ::google::protobuf::Descriptor* GameState_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  GameState_reflection_ = NULL;
const ::google::protobuf::EnumDescriptor* GameState_State_descriptor_ = NULL;

}  // namespace


void protobuf_AssignDesc_gamestate_2eproto() {
  protobuf_AddDesc_gamestate_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "gamestate.proto");
  GOOGLE_CHECK(file != NULL);
  GameState_descriptor_ = file->message_type(0);
  static const int GameState_offsets_[5] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameState, stage_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameState, stage_time_left_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameState, state_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameState, yellow_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameState, blue_),
  };
  GameState_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      GameState_descriptor_,
      GameState::default_instance_,
      GameState_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameState, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameState, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(GameState));
  GameState_State_descriptor_ = GameState_descriptor_->enum_type(0);
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_gamestate_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    GameState_descriptor_, &GameState::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_gamestate_2eproto() {
  delete GameState::default_instance_;
  delete GameState_reflection_;
}

void protobuf_AddDesc_gamestate_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::protobuf_AddDesc_ssl_5freferee_2eproto();
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\017gamestate.proto\022\004amun\032\021ssl_referee.pro"
    "to\"\210\004\n\tGameState\022!\n\005stage\030\001 \002(\0162\022.SSL_Re"
    "feree.Stage\022\027\n\017stage_time_left\030\002 \001(\021\022$\n\005"
    "state\030\003 \002(\0162\025.amun.GameState.State\022%\n\006ye"
    "llow\030\004 \002(\0132\025.SSL_Referee.TeamInfo\022#\n\004blu"
    "e\030\005 \002(\0132\025.SSL_Referee.TeamInfo\"\314\002\n\005State"
    "\022\010\n\004Halt\020\001\022\010\n\004Stop\020\002\022\010\n\004Game\020\003\022\r\n\tGameFo"
    "rce\020\004\022\030\n\024KickoffYellowPrepare\020\005\022\021\n\rKicko"
    "ffYellow\020\006\022\030\n\024PenaltyYellowPrepare\020\007\022\021\n\r"
    "PenaltyYellow\020\010\022\020\n\014DirectYellow\020\t\022\022\n\016Ind"
    "irectYellow\020\n\022\026\n\022KickoffBluePrepare\020\013\022\017\n"
    "\013KickoffBlue\020\014\022\026\n\022PenaltyBluePrepare\020\r\022\017"
    "\n\013PenaltyBlue\020\016\022\016\n\nDirectBlue\020\017\022\020\n\014Indir"
    "ectBlue\020\020\022\021\n\rTimeoutYellow\020\021\022\017\n\013TimeoutB"
    "lue\020\022", 565);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "gamestate.proto", &protobuf_RegisterTypes);
  GameState::default_instance_ = new GameState();
  GameState::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_gamestate_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_gamestate_2eproto {
  StaticDescriptorInitializer_gamestate_2eproto() {
    protobuf_AddDesc_gamestate_2eproto();
  }
} static_descriptor_initializer_gamestate_2eproto_;

// ===================================================================

const ::google::protobuf::EnumDescriptor* GameState_State_descriptor() {
  protobuf_AssignDescriptorsOnce();
  return GameState_State_descriptor_;
}
bool GameState_State_IsValid(int value) {
  switch(value) {
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
    case 16:
    case 17:
    case 18:
      return true;
    default:
      return false;
  }
}

#ifndef _MSC_VER
const GameState_State GameState::Halt;
const GameState_State GameState::Stop;
const GameState_State GameState::Game;
const GameState_State GameState::GameForce;
const GameState_State GameState::KickoffYellowPrepare;
const GameState_State GameState::KickoffYellow;
const GameState_State GameState::PenaltyYellowPrepare;
const GameState_State GameState::PenaltyYellow;
const GameState_State GameState::DirectYellow;
const GameState_State GameState::IndirectYellow;
const GameState_State GameState::KickoffBluePrepare;
const GameState_State GameState::KickoffBlue;
const GameState_State GameState::PenaltyBluePrepare;
const GameState_State GameState::PenaltyBlue;
const GameState_State GameState::DirectBlue;
const GameState_State GameState::IndirectBlue;
const GameState_State GameState::TimeoutYellow;
const GameState_State GameState::TimeoutBlue;
const GameState_State GameState::State_MIN;
const GameState_State GameState::State_MAX;
const int GameState::State_ARRAYSIZE;
#endif  // _MSC_VER
#ifndef _MSC_VER
const int GameState::kStageFieldNumber;
const int GameState::kStageTimeLeftFieldNumber;
const int GameState::kStateFieldNumber;
const int GameState::kYellowFieldNumber;
const int GameState::kBlueFieldNumber;
#endif  // !_MSC_VER

GameState::GameState()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void GameState::InitAsDefaultInstance() {
  yellow_ = const_cast< ::SSL_Referee_TeamInfo*>(&::SSL_Referee_TeamInfo::default_instance());
  blue_ = const_cast< ::SSL_Referee_TeamInfo*>(&::SSL_Referee_TeamInfo::default_instance());
}

GameState::GameState(const GameState& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void GameState::SharedCtor() {
  _cached_size_ = 0;
  stage_ = 0;
  stage_time_left_ = 0;
  state_ = 1;
  yellow_ = NULL;
  blue_ = NULL;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

GameState::~GameState() {
  SharedDtor();
}

void GameState::SharedDtor() {
  if (this != default_instance_) {
    delete yellow_;
    delete blue_;
  }
}

void GameState::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* GameState::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return GameState_descriptor_;
}

const GameState& GameState::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_gamestate_2eproto();
  return *default_instance_;
}

GameState* GameState::default_instance_ = NULL;

GameState* GameState::New() const {
  return new GameState;
}

void GameState::Clear() {
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    stage_ = 0;
    stage_time_left_ = 0;
    state_ = 1;
    if (has_yellow()) {
      if (yellow_ != NULL) yellow_->::SSL_Referee_TeamInfo::Clear();
    }
    if (has_blue()) {
      if (blue_ != NULL) blue_->::SSL_Referee_TeamInfo::Clear();
    }
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool GameState::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required .SSL_Referee.Stage stage = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
          int value;
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   int, ::google::protobuf::internal::WireFormatLite::TYPE_ENUM>(
                 input, &value)));
          if (::SSL_Referee_Stage_IsValid(value)) {
            set_stage(static_cast< ::SSL_Referee_Stage >(value));
          } else {
            mutable_unknown_fields()->AddVarint(1, value);
          }
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(16)) goto parse_stage_time_left;
        break;
      }

      // optional sint32 stage_time_left = 2;
      case 2: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_stage_time_left:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_SINT32>(
                 input, &stage_time_left_)));
          set_has_stage_time_left();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(24)) goto parse_state;
        break;
      }

      // required .amun.GameState.State state = 3;
      case 3: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_state:
          int value;
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   int, ::google::protobuf::internal::WireFormatLite::TYPE_ENUM>(
                 input, &value)));
          if (::amun::GameState_State_IsValid(value)) {
            set_state(static_cast< ::amun::GameState_State >(value));
          } else {
            mutable_unknown_fields()->AddVarint(3, value);
          }
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(34)) goto parse_yellow;
        break;
      }

      // required .SSL_Referee.TeamInfo yellow = 4;
      case 4: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_yellow:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_yellow()));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(42)) goto parse_blue;
        break;
      }

      // required .SSL_Referee.TeamInfo blue = 5;
      case 5: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_blue:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_blue()));
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

void GameState::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // required .SSL_Referee.Stage stage = 1;
  if (has_stage()) {
    ::google::protobuf::internal::WireFormatLite::WriteEnum(
      1, this->stage(), output);
  }

  // optional sint32 stage_time_left = 2;
  if (has_stage_time_left()) {
    ::google::protobuf::internal::WireFormatLite::WriteSInt32(2, this->stage_time_left(), output);
  }

  // required .amun.GameState.State state = 3;
  if (has_state()) {
    ::google::protobuf::internal::WireFormatLite::WriteEnum(
      3, this->state(), output);
  }

  // required .SSL_Referee.TeamInfo yellow = 4;
  if (has_yellow()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      4, this->yellow(), output);
  }

  // required .SSL_Referee.TeamInfo blue = 5;
  if (has_blue()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      5, this->blue(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* GameState::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // required .SSL_Referee.Stage stage = 1;
  if (has_stage()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteEnumToArray(
      1, this->stage(), target);
  }

  // optional sint32 stage_time_left = 2;
  if (has_stage_time_left()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteSInt32ToArray(2, this->stage_time_left(), target);
  }

  // required .amun.GameState.State state = 3;
  if (has_state()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteEnumToArray(
      3, this->state(), target);
  }

  // required .SSL_Referee.TeamInfo yellow = 4;
  if (has_yellow()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        4, this->yellow(), target);
  }

  // required .SSL_Referee.TeamInfo blue = 5;
  if (has_blue()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        5, this->blue(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int GameState::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required .SSL_Referee.Stage stage = 1;
    if (has_stage()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::EnumSize(this->stage());
    }

    // optional sint32 stage_time_left = 2;
    if (has_stage_time_left()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::SInt32Size(
          this->stage_time_left());
    }

    // required .amun.GameState.State state = 3;
    if (has_state()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::EnumSize(this->state());
    }

    // required .SSL_Referee.TeamInfo yellow = 4;
    if (has_yellow()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->yellow());
    }

    // required .SSL_Referee.TeamInfo blue = 5;
    if (has_blue()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->blue());
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

void GameState::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const GameState* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const GameState*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void GameState::MergeFrom(const GameState& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_stage()) {
      set_stage(from.stage());
    }
    if (from.has_stage_time_left()) {
      set_stage_time_left(from.stage_time_left());
    }
    if (from.has_state()) {
      set_state(from.state());
    }
    if (from.has_yellow()) {
      mutable_yellow()->::SSL_Referee_TeamInfo::MergeFrom(from.yellow());
    }
    if (from.has_blue()) {
      mutable_blue()->::SSL_Referee_TeamInfo::MergeFrom(from.blue());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void GameState::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void GameState::CopyFrom(const GameState& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool GameState::IsInitialized() const {
  if ((_has_bits_[0] & 0x0000001d) != 0x0000001d) return false;

  if (has_yellow()) {
    if (!this->yellow().IsInitialized()) return false;
  }
  if (has_blue()) {
    if (!this->blue().IsInitialized()) return false;
  }
  return true;
}

void GameState::Swap(GameState* other) {
  if (other != this) {
    std::swap(stage_, other->stage_);
    std::swap(stage_time_left_, other->stage_time_left_);
    std::swap(state_, other->state_);
    std::swap(yellow_, other->yellow_);
    std::swap(blue_, other->blue_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata GameState::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = GameState_descriptor_;
  metadata.reflection = GameState_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace amun

// @@protoc_insertion_point(global_scope)
