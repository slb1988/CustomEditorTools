// automatically generated by the FlatBuffers compiler, do not modify


#ifndef FLATBUFFERS_GENERATED_TASKCONDITION_FB_H_
#define FLATBUFFERS_GENERATED_TASKCONDITION_FB_H_

#include "flatbuffers/flatbuffers.h"

// Ensure the included flatbuffers.h is the same version as when this file was
// generated, otherwise it may not be compatible.
static_assert(FLATBUFFERS_VERSION_MAJOR == 24 &&
              FLATBUFFERS_VERSION_MINOR == 3 &&
              FLATBUFFERS_VERSION_REVISION == 25,
             "Non-compatible flatbuffers version included");

namespace fb {

struct TaskCondition;
struct TaskConditionBuilder;
struct TaskConditionT;

struct TaskConditionRow;
struct TaskConditionRowBuilder;
struct TaskConditionRowT;

struct TaskConditionT : public ::flatbuffers::NativeTable {
  typedef TaskCondition TableType;
  std::vector<std::unique_ptr<fb::TaskConditionRowT>> TaskConditions{};
  TaskConditionT() = default;
  TaskConditionT(const TaskConditionT &o);
  TaskConditionT(TaskConditionT&&) FLATBUFFERS_NOEXCEPT = default;
  TaskConditionT &operator=(TaskConditionT o) FLATBUFFERS_NOEXCEPT;
};

struct TaskCondition FLATBUFFERS_FINAL_CLASS : private ::flatbuffers::Table {
  typedef TaskConditionT NativeTableType;
  typedef TaskConditionBuilder Builder;
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_TASKCONDITIONS = 4
  };
  const ::flatbuffers::Vector<::flatbuffers::Offset<fb::TaskConditionRow>> *TaskConditions() const {
    return GetPointer<const ::flatbuffers::Vector<::flatbuffers::Offset<fb::TaskConditionRow>> *>(VT_TASKCONDITIONS);
  }
  bool Verify(::flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyOffset(verifier, VT_TASKCONDITIONS) &&
           verifier.VerifyVector(TaskConditions()) &&
           verifier.VerifyVectorOfTables(TaskConditions()) &&
           verifier.EndTable();
  }
  TaskConditionT *UnPack(const ::flatbuffers::resolver_function_t *_resolver = nullptr) const;
  void UnPackTo(TaskConditionT *_o, const ::flatbuffers::resolver_function_t *_resolver = nullptr) const;
  static ::flatbuffers::Offset<TaskCondition> Pack(::flatbuffers::FlatBufferBuilder &_fbb, const TaskConditionT* _o, const ::flatbuffers::rehasher_function_t *_rehasher = nullptr);
};

struct TaskConditionBuilder {
  typedef TaskCondition Table;
  ::flatbuffers::FlatBufferBuilder &fbb_;
  ::flatbuffers::uoffset_t start_;
  void add_TaskConditions(::flatbuffers::Offset<::flatbuffers::Vector<::flatbuffers::Offset<fb::TaskConditionRow>>> TaskConditions) {
    fbb_.AddOffset(TaskCondition::VT_TASKCONDITIONS, TaskConditions);
  }
  explicit TaskConditionBuilder(::flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  ::flatbuffers::Offset<TaskCondition> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = ::flatbuffers::Offset<TaskCondition>(end);
    return o;
  }
};

inline ::flatbuffers::Offset<TaskCondition> CreateTaskCondition(
    ::flatbuffers::FlatBufferBuilder &_fbb,
    ::flatbuffers::Offset<::flatbuffers::Vector<::flatbuffers::Offset<fb::TaskConditionRow>>> TaskConditions = 0) {
  TaskConditionBuilder builder_(_fbb);
  builder_.add_TaskConditions(TaskConditions);
  return builder_.Finish();
}

inline ::flatbuffers::Offset<TaskCondition> CreateTaskConditionDirect(
    ::flatbuffers::FlatBufferBuilder &_fbb,
    std::vector<::flatbuffers::Offset<fb::TaskConditionRow>> *TaskConditions = nullptr) {
  auto TaskConditions__ = TaskConditions ? _fbb.CreateVectorOfSortedTables<fb::TaskConditionRow>(TaskConditions) : 0;
  return fb::CreateTaskCondition(
      _fbb,
      TaskConditions__);
}

::flatbuffers::Offset<TaskCondition> CreateTaskCondition(::flatbuffers::FlatBufferBuilder &_fbb, const TaskConditionT *_o, const ::flatbuffers::rehasher_function_t *_rehasher = nullptr);

struct TaskConditionRowT : public ::flatbuffers::NativeTable {
  typedef TaskConditionRow TableType;
  uint32_t Id = 0;
  fb::ConditionType Type = fb::ConditionType_NONE;
  std::string Desc{};
  int32_t ProcessDesc = 0;
  bool Addable = false;
  uint32_t Value = 0;
  uint32_t Param1 = 0;
  uint32_t Param2 = 0;
  uint32_t Param3 = 0;
  uint32_t Param4 = 0;
};

struct TaskConditionRow FLATBUFFERS_FINAL_CLASS : private ::flatbuffers::Table {
  typedef TaskConditionRowT NativeTableType;
  typedef TaskConditionRowBuilder Builder;
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_ID = 4,
    VT_TYPE = 6,
    VT_DESC = 8,
    VT_PROCESSDESC = 10,
    VT_ADDABLE = 12,
    VT_VALUE = 14,
    VT_PARAM1 = 16,
    VT_PARAM2 = 18,
    VT_PARAM3 = 20,
    VT_PARAM4 = 22
  };
  uint32_t Id() const {
    return GetField<uint32_t>(VT_ID, 0);
  }
  bool KeyCompareLessThan(const TaskConditionRow * const o) const {
    return Id() < o->Id();
  }
  int KeyCompareWithValue(uint32_t _Id) const {
    return static_cast<int>(Id() > _Id) - static_cast<int>(Id() < _Id);
  }
  fb::ConditionType Type() const {
    return static_cast<fb::ConditionType>(GetField<int32_t>(VT_TYPE, 0));
  }
  const ::flatbuffers::String *Desc() const {
    return GetPointer<const ::flatbuffers::String *>(VT_DESC);
  }
  int32_t ProcessDesc() const {
    return GetField<int32_t>(VT_PROCESSDESC, 0);
  }
  bool Addable() const {
    return GetField<uint8_t>(VT_ADDABLE, 0) != 0;
  }
  uint32_t Value() const {
    return GetField<uint32_t>(VT_VALUE, 0);
  }
  uint32_t Param1() const {
    return GetField<uint32_t>(VT_PARAM1, 0);
  }
  uint32_t Param2() const {
    return GetField<uint32_t>(VT_PARAM2, 0);
  }
  uint32_t Param3() const {
    return GetField<uint32_t>(VT_PARAM3, 0);
  }
  uint32_t Param4() const {
    return GetField<uint32_t>(VT_PARAM4, 0);
  }
  bool Verify(::flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<uint32_t>(verifier, VT_ID, 4) &&
           VerifyField<int32_t>(verifier, VT_TYPE, 4) &&
           VerifyOffset(verifier, VT_DESC) &&
           verifier.VerifyString(Desc()) &&
           VerifyField<int32_t>(verifier, VT_PROCESSDESC, 4) &&
           VerifyField<uint8_t>(verifier, VT_ADDABLE, 1) &&
           VerifyField<uint32_t>(verifier, VT_VALUE, 4) &&
           VerifyField<uint32_t>(verifier, VT_PARAM1, 4) &&
           VerifyField<uint32_t>(verifier, VT_PARAM2, 4) &&
           VerifyField<uint32_t>(verifier, VT_PARAM3, 4) &&
           VerifyField<uint32_t>(verifier, VT_PARAM4, 4) &&
           verifier.EndTable();
  }
  TaskConditionRowT *UnPack(const ::flatbuffers::resolver_function_t *_resolver = nullptr) const;
  void UnPackTo(TaskConditionRowT *_o, const ::flatbuffers::resolver_function_t *_resolver = nullptr) const;
  static ::flatbuffers::Offset<TaskConditionRow> Pack(::flatbuffers::FlatBufferBuilder &_fbb, const TaskConditionRowT* _o, const ::flatbuffers::rehasher_function_t *_rehasher = nullptr);
};

struct TaskConditionRowBuilder {
  typedef TaskConditionRow Table;
  ::flatbuffers::FlatBufferBuilder &fbb_;
  ::flatbuffers::uoffset_t start_;
  void add_Id(uint32_t Id) {
    fbb_.AddElement<uint32_t>(TaskConditionRow::VT_ID, Id, 0);
  }
  void add_Type(fb::ConditionType Type) {
    fbb_.AddElement<int32_t>(TaskConditionRow::VT_TYPE, static_cast<int32_t>(Type), 0);
  }
  void add_Desc(::flatbuffers::Offset<::flatbuffers::String> Desc) {
    fbb_.AddOffset(TaskConditionRow::VT_DESC, Desc);
  }
  void add_ProcessDesc(int32_t ProcessDesc) {
    fbb_.AddElement<int32_t>(TaskConditionRow::VT_PROCESSDESC, ProcessDesc, 0);
  }
  void add_Addable(bool Addable) {
    fbb_.AddElement<uint8_t>(TaskConditionRow::VT_ADDABLE, static_cast<uint8_t>(Addable), 0);
  }
  void add_Value(uint32_t Value) {
    fbb_.AddElement<uint32_t>(TaskConditionRow::VT_VALUE, Value, 0);
  }
  void add_Param1(uint32_t Param1) {
    fbb_.AddElement<uint32_t>(TaskConditionRow::VT_PARAM1, Param1, 0);
  }
  void add_Param2(uint32_t Param2) {
    fbb_.AddElement<uint32_t>(TaskConditionRow::VT_PARAM2, Param2, 0);
  }
  void add_Param3(uint32_t Param3) {
    fbb_.AddElement<uint32_t>(TaskConditionRow::VT_PARAM3, Param3, 0);
  }
  void add_Param4(uint32_t Param4) {
    fbb_.AddElement<uint32_t>(TaskConditionRow::VT_PARAM4, Param4, 0);
  }
  explicit TaskConditionRowBuilder(::flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  ::flatbuffers::Offset<TaskConditionRow> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = ::flatbuffers::Offset<TaskConditionRow>(end);
    return o;
  }
};

inline ::flatbuffers::Offset<TaskConditionRow> CreateTaskConditionRow(
    ::flatbuffers::FlatBufferBuilder &_fbb,
    uint32_t Id = 0,
    fb::ConditionType Type = fb::ConditionType_NONE,
    ::flatbuffers::Offset<::flatbuffers::String> Desc = 0,
    int32_t ProcessDesc = 0,
    bool Addable = false,
    uint32_t Value = 0,
    uint32_t Param1 = 0,
    uint32_t Param2 = 0,
    uint32_t Param3 = 0,
    uint32_t Param4 = 0) {
  TaskConditionRowBuilder builder_(_fbb);
  builder_.add_Param4(Param4);
  builder_.add_Param3(Param3);
  builder_.add_Param2(Param2);
  builder_.add_Param1(Param1);
  builder_.add_Value(Value);
  builder_.add_ProcessDesc(ProcessDesc);
  builder_.add_Desc(Desc);
  builder_.add_Type(Type);
  builder_.add_Id(Id);
  builder_.add_Addable(Addable);
  return builder_.Finish();
}

inline ::flatbuffers::Offset<TaskConditionRow> CreateTaskConditionRowDirect(
    ::flatbuffers::FlatBufferBuilder &_fbb,
    uint32_t Id = 0,
    fb::ConditionType Type = fb::ConditionType_NONE,
    const char *Desc = nullptr,
    int32_t ProcessDesc = 0,
    bool Addable = false,
    uint32_t Value = 0,
    uint32_t Param1 = 0,
    uint32_t Param2 = 0,
    uint32_t Param3 = 0,
    uint32_t Param4 = 0) {
  auto Desc__ = Desc ? _fbb.CreateString(Desc) : 0;
  return fb::CreateTaskConditionRow(
      _fbb,
      Id,
      Type,
      Desc__,
      ProcessDesc,
      Addable,
      Value,
      Param1,
      Param2,
      Param3,
      Param4);
}

::flatbuffers::Offset<TaskConditionRow> CreateTaskConditionRow(::flatbuffers::FlatBufferBuilder &_fbb, const TaskConditionRowT *_o, const ::flatbuffers::rehasher_function_t *_rehasher = nullptr);

inline TaskConditionT::TaskConditionT(const TaskConditionT &o) {
  TaskConditions.reserve(o.TaskConditions.size());
  for (const auto &TaskConditions_ : o.TaskConditions) { TaskConditions.emplace_back((TaskConditions_) ? new fb::TaskConditionRowT(*TaskConditions_) : nullptr); }
}

inline TaskConditionT &TaskConditionT::operator=(TaskConditionT o) FLATBUFFERS_NOEXCEPT {
  std::swap(TaskConditions, o.TaskConditions);
  return *this;
}

inline TaskConditionT *TaskCondition::UnPack(const ::flatbuffers::resolver_function_t *_resolver) const {
  auto _o = std::unique_ptr<TaskConditionT>(new TaskConditionT());
  UnPackTo(_o.get(), _resolver);
  return _o.release();
}

inline void TaskCondition::UnPackTo(TaskConditionT *_o, const ::flatbuffers::resolver_function_t *_resolver) const {
  (void)_o;
  (void)_resolver;
  { auto _e = TaskConditions(); if (_e) { _o->TaskConditions.resize(_e->size()); for (::flatbuffers::uoffset_t _i = 0; _i < _e->size(); _i++) { if(_o->TaskConditions[_i]) { _e->Get(_i)->UnPackTo(_o->TaskConditions[_i].get(), _resolver); } else { _o->TaskConditions[_i] = std::unique_ptr<fb::TaskConditionRowT>(_e->Get(_i)->UnPack(_resolver)); }; } } else { _o->TaskConditions.resize(0); } }
}

inline ::flatbuffers::Offset<TaskCondition> TaskCondition::Pack(::flatbuffers::FlatBufferBuilder &_fbb, const TaskConditionT* _o, const ::flatbuffers::rehasher_function_t *_rehasher) {
  return CreateTaskCondition(_fbb, _o, _rehasher);
}

inline ::flatbuffers::Offset<TaskCondition> CreateTaskCondition(::flatbuffers::FlatBufferBuilder &_fbb, const TaskConditionT *_o, const ::flatbuffers::rehasher_function_t *_rehasher) {
  (void)_rehasher;
  (void)_o;
  struct _VectorArgs { ::flatbuffers::FlatBufferBuilder *__fbb; const TaskConditionT* __o; const ::flatbuffers::rehasher_function_t *__rehasher; } _va = { &_fbb, _o, _rehasher}; (void)_va;
  auto _TaskConditions = _o->TaskConditions.size() ? _fbb.CreateVector<::flatbuffers::Offset<fb::TaskConditionRow>> (_o->TaskConditions.size(), [](size_t i, _VectorArgs *__va) { return CreateTaskConditionRow(*__va->__fbb, __va->__o->TaskConditions[i].get(), __va->__rehasher); }, &_va ) : 0;
  return fb::CreateTaskCondition(
      _fbb,
      _TaskConditions);
}

inline TaskConditionRowT *TaskConditionRow::UnPack(const ::flatbuffers::resolver_function_t *_resolver) const {
  auto _o = std::unique_ptr<TaskConditionRowT>(new TaskConditionRowT());
  UnPackTo(_o.get(), _resolver);
  return _o.release();
}

inline void TaskConditionRow::UnPackTo(TaskConditionRowT *_o, const ::flatbuffers::resolver_function_t *_resolver) const {
  (void)_o;
  (void)_resolver;
  { auto _e = Id(); _o->Id = _e; }
  { auto _e = Type(); _o->Type = _e; }
  { auto _e = Desc(); if (_e) _o->Desc = _e->str(); }
  { auto _e = ProcessDesc(); _o->ProcessDesc = _e; }
  { auto _e = Addable(); _o->Addable = _e; }
  { auto _e = Value(); _o->Value = _e; }
  { auto _e = Param1(); _o->Param1 = _e; }
  { auto _e = Param2(); _o->Param2 = _e; }
  { auto _e = Param3(); _o->Param3 = _e; }
  { auto _e = Param4(); _o->Param4 = _e; }
}

inline ::flatbuffers::Offset<TaskConditionRow> TaskConditionRow::Pack(::flatbuffers::FlatBufferBuilder &_fbb, const TaskConditionRowT* _o, const ::flatbuffers::rehasher_function_t *_rehasher) {
  return CreateTaskConditionRow(_fbb, _o, _rehasher);
}

inline ::flatbuffers::Offset<TaskConditionRow> CreateTaskConditionRow(::flatbuffers::FlatBufferBuilder &_fbb, const TaskConditionRowT *_o, const ::flatbuffers::rehasher_function_t *_rehasher) {
  (void)_rehasher;
  (void)_o;
  struct _VectorArgs { ::flatbuffers::FlatBufferBuilder *__fbb; const TaskConditionRowT* __o; const ::flatbuffers::rehasher_function_t *__rehasher; } _va = { &_fbb, _o, _rehasher}; (void)_va;
  auto _Id = _o->Id;
  auto _Type = _o->Type;
  auto _Desc = _o->Desc.empty() ? 0 : _fbb.CreateString(_o->Desc);
  auto _ProcessDesc = _o->ProcessDesc;
  auto _Addable = _o->Addable;
  auto _Value = _o->Value;
  auto _Param1 = _o->Param1;
  auto _Param2 = _o->Param2;
  auto _Param3 = _o->Param3;
  auto _Param4 = _o->Param4;
  return fb::CreateTaskConditionRow(
      _fbb,
      _Id,
      _Type,
      _Desc,
      _ProcessDesc,
      _Addable,
      _Value,
      _Param1,
      _Param2,
      _Param3,
      _Param4);
}

inline const fb::TaskCondition *GetTaskCondition(const void *buf) {
  return ::flatbuffers::GetRoot<fb::TaskCondition>(buf);
}

inline const fb::TaskCondition *GetSizePrefixedTaskCondition(const void *buf) {
  return ::flatbuffers::GetSizePrefixedRoot<fb::TaskCondition>(buf);
}

inline bool VerifyTaskConditionBuffer(
    ::flatbuffers::Verifier &verifier) {
  return verifier.VerifyBuffer<fb::TaskCondition>(nullptr);
}

inline bool VerifySizePrefixedTaskConditionBuffer(
    ::flatbuffers::Verifier &verifier) {
  return verifier.VerifySizePrefixedBuffer<fb::TaskCondition>(nullptr);
}

inline void FinishTaskConditionBuffer(
    ::flatbuffers::FlatBufferBuilder &fbb,
    ::flatbuffers::Offset<fb::TaskCondition> root) {
  fbb.Finish(root);
}

inline void FinishSizePrefixedTaskConditionBuffer(
    ::flatbuffers::FlatBufferBuilder &fbb,
    ::flatbuffers::Offset<fb::TaskCondition> root) {
  fbb.FinishSizePrefixed(root);
}

inline std::unique_ptr<fb::TaskConditionT> UnPackTaskCondition(
    const void *buf,
    const ::flatbuffers::resolver_function_t *res = nullptr) {
  return std::unique_ptr<fb::TaskConditionT>(GetTaskCondition(buf)->UnPack(res));
}

inline std::unique_ptr<fb::TaskConditionT> UnPackSizePrefixedTaskCondition(
    const void *buf,
    const ::flatbuffers::resolver_function_t *res = nullptr) {
  return std::unique_ptr<fb::TaskConditionT>(GetSizePrefixedTaskCondition(buf)->UnPack(res));
}

}  // namespace fb

#endif  // FLATBUFFERS_GENERATED_TASKCONDITION_FB_H_
