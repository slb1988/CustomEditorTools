// automatically generated by the FlatBuffers compiler, do not modify


#ifndef FLATBUFFERS_GENERATED_SCENEBUFFTRIGGER_FB_H_
#define FLATBUFFERS_GENERATED_SCENEBUFFTRIGGER_FB_H_

#include "flatbuffers/flatbuffers.h"

// Ensure the included flatbuffers.h is the same version as when this file was
// generated, otherwise it may not be compatible.
static_assert(FLATBUFFERS_VERSION_MAJOR == 24 &&
              FLATBUFFERS_VERSION_MINOR == 3 &&
              FLATBUFFERS_VERSION_REVISION == 25,
             "Non-compatible flatbuffers version included");

namespace fb {

struct SceneBuffTrigger;
struct SceneBuffTriggerBuilder;
struct SceneBuffTriggerT;

struct SceneBuffTriggerRow;
struct SceneBuffTriggerRowBuilder;
struct SceneBuffTriggerRowT;

struct SceneBuffTriggerT : public ::flatbuffers::NativeTable {
  typedef SceneBuffTrigger TableType;
  std::vector<std::unique_ptr<fb::SceneBuffTriggerRowT>> SceneBuffTriggers{};
  SceneBuffTriggerT() = default;
  SceneBuffTriggerT(const SceneBuffTriggerT &o);
  SceneBuffTriggerT(SceneBuffTriggerT&&) FLATBUFFERS_NOEXCEPT = default;
  SceneBuffTriggerT &operator=(SceneBuffTriggerT o) FLATBUFFERS_NOEXCEPT;
};

struct SceneBuffTrigger FLATBUFFERS_FINAL_CLASS : private ::flatbuffers::Table {
  typedef SceneBuffTriggerT NativeTableType;
  typedef SceneBuffTriggerBuilder Builder;
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_SCENEBUFFTRIGGERS = 4
  };
  const ::flatbuffers::Vector<::flatbuffers::Offset<fb::SceneBuffTriggerRow>> *SceneBuffTriggers() const {
    return GetPointer<const ::flatbuffers::Vector<::flatbuffers::Offset<fb::SceneBuffTriggerRow>> *>(VT_SCENEBUFFTRIGGERS);
  }
  bool Verify(::flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyOffset(verifier, VT_SCENEBUFFTRIGGERS) &&
           verifier.VerifyVector(SceneBuffTriggers()) &&
           verifier.VerifyVectorOfTables(SceneBuffTriggers()) &&
           verifier.EndTable();
  }
  SceneBuffTriggerT *UnPack(const ::flatbuffers::resolver_function_t *_resolver = nullptr) const;
  void UnPackTo(SceneBuffTriggerT *_o, const ::flatbuffers::resolver_function_t *_resolver = nullptr) const;
  static ::flatbuffers::Offset<SceneBuffTrigger> Pack(::flatbuffers::FlatBufferBuilder &_fbb, const SceneBuffTriggerT* _o, const ::flatbuffers::rehasher_function_t *_rehasher = nullptr);
};

struct SceneBuffTriggerBuilder {
  typedef SceneBuffTrigger Table;
  ::flatbuffers::FlatBufferBuilder &fbb_;
  ::flatbuffers::uoffset_t start_;
  void add_SceneBuffTriggers(::flatbuffers::Offset<::flatbuffers::Vector<::flatbuffers::Offset<fb::SceneBuffTriggerRow>>> SceneBuffTriggers) {
    fbb_.AddOffset(SceneBuffTrigger::VT_SCENEBUFFTRIGGERS, SceneBuffTriggers);
  }
  explicit SceneBuffTriggerBuilder(::flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  ::flatbuffers::Offset<SceneBuffTrigger> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = ::flatbuffers::Offset<SceneBuffTrigger>(end);
    return o;
  }
};

inline ::flatbuffers::Offset<SceneBuffTrigger> CreateSceneBuffTrigger(
    ::flatbuffers::FlatBufferBuilder &_fbb,
    ::flatbuffers::Offset<::flatbuffers::Vector<::flatbuffers::Offset<fb::SceneBuffTriggerRow>>> SceneBuffTriggers = 0) {
  SceneBuffTriggerBuilder builder_(_fbb);
  builder_.add_SceneBuffTriggers(SceneBuffTriggers);
  return builder_.Finish();
}

inline ::flatbuffers::Offset<SceneBuffTrigger> CreateSceneBuffTriggerDirect(
    ::flatbuffers::FlatBufferBuilder &_fbb,
    std::vector<::flatbuffers::Offset<fb::SceneBuffTriggerRow>> *SceneBuffTriggers = nullptr) {
  auto SceneBuffTriggers__ = SceneBuffTriggers ? _fbb.CreateVectorOfSortedTables<fb::SceneBuffTriggerRow>(SceneBuffTriggers) : 0;
  return fb::CreateSceneBuffTrigger(
      _fbb,
      SceneBuffTriggers__);
}

::flatbuffers::Offset<SceneBuffTrigger> CreateSceneBuffTrigger(::flatbuffers::FlatBufferBuilder &_fbb, const SceneBuffTriggerT *_o, const ::flatbuffers::rehasher_function_t *_rehasher = nullptr);

struct SceneBuffTriggerRowT : public ::flatbuffers::NativeTable {
  typedef SceneBuffTriggerRow TableType;
  uint32_t Id = 0;
  uint32_t WorldTypeId = 0;
  std::vector<uint32_t> IssueBuffIds{};
  std::vector<uint32_t> IssueBuffDuration{};
  std::vector<uint32_t> RecycleBuffTypes{};
  std::vector<uint32_t> BannedBuffTypes{};
  std::unique_ptr<fb::tuple_float32_float32_float32T> CenterPosition{};
  std::unique_ptr<fb::tuple_float32_float32_float32_float32T> Rotation{};
  std::unique_ptr<fb::tuple_float32_float32_float32T> Scale{};
  std::string PrefabPath{};
  SceneBuffTriggerRowT() = default;
  SceneBuffTriggerRowT(const SceneBuffTriggerRowT &o);
  SceneBuffTriggerRowT(SceneBuffTriggerRowT&&) FLATBUFFERS_NOEXCEPT = default;
  SceneBuffTriggerRowT &operator=(SceneBuffTriggerRowT o) FLATBUFFERS_NOEXCEPT;
};

struct SceneBuffTriggerRow FLATBUFFERS_FINAL_CLASS : private ::flatbuffers::Table {
  typedef SceneBuffTriggerRowT NativeTableType;
  typedef SceneBuffTriggerRowBuilder Builder;
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_ID = 4,
    VT_WORLDTYPEID = 6,
    VT_ISSUEBUFFIDS = 8,
    VT_ISSUEBUFFDURATION = 10,
    VT_RECYCLEBUFFTYPES = 12,
    VT_BANNEDBUFFTYPES = 14,
    VT_CENTERPOSITION = 16,
    VT_ROTATION = 18,
    VT_SCALE = 20,
    VT_PREFABPATH = 22
  };
  uint32_t Id() const {
    return GetField<uint32_t>(VT_ID, 0);
  }
  bool KeyCompareLessThan(const SceneBuffTriggerRow * const o) const {
    return Id() < o->Id();
  }
  int KeyCompareWithValue(uint32_t _Id) const {
    return static_cast<int>(Id() > _Id) - static_cast<int>(Id() < _Id);
  }
  uint32_t WorldTypeId() const {
    return GetField<uint32_t>(VT_WORLDTYPEID, 0);
  }
  const ::flatbuffers::Vector<uint32_t> *IssueBuffIds() const {
    return GetPointer<const ::flatbuffers::Vector<uint32_t> *>(VT_ISSUEBUFFIDS);
  }
  const ::flatbuffers::Vector<uint32_t> *IssueBuffDuration() const {
    return GetPointer<const ::flatbuffers::Vector<uint32_t> *>(VT_ISSUEBUFFDURATION);
  }
  const ::flatbuffers::Vector<uint32_t> *RecycleBuffTypes() const {
    return GetPointer<const ::flatbuffers::Vector<uint32_t> *>(VT_RECYCLEBUFFTYPES);
  }
  const ::flatbuffers::Vector<uint32_t> *BannedBuffTypes() const {
    return GetPointer<const ::flatbuffers::Vector<uint32_t> *>(VT_BANNEDBUFFTYPES);
  }
  const fb::tuple_float32_float32_float32 *CenterPosition() const {
    return GetPointer<const fb::tuple_float32_float32_float32 *>(VT_CENTERPOSITION);
  }
  const fb::tuple_float32_float32_float32_float32 *Rotation() const {
    return GetPointer<const fb::tuple_float32_float32_float32_float32 *>(VT_ROTATION);
  }
  const fb::tuple_float32_float32_float32 *Scale() const {
    return GetPointer<const fb::tuple_float32_float32_float32 *>(VT_SCALE);
  }
  const ::flatbuffers::String *PrefabPath() const {
    return GetPointer<const ::flatbuffers::String *>(VT_PREFABPATH);
  }
  bool Verify(::flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<uint32_t>(verifier, VT_ID, 4) &&
           VerifyField<uint32_t>(verifier, VT_WORLDTYPEID, 4) &&
           VerifyOffset(verifier, VT_ISSUEBUFFIDS) &&
           verifier.VerifyVector(IssueBuffIds()) &&
           VerifyOffset(verifier, VT_ISSUEBUFFDURATION) &&
           verifier.VerifyVector(IssueBuffDuration()) &&
           VerifyOffset(verifier, VT_RECYCLEBUFFTYPES) &&
           verifier.VerifyVector(RecycleBuffTypes()) &&
           VerifyOffset(verifier, VT_BANNEDBUFFTYPES) &&
           verifier.VerifyVector(BannedBuffTypes()) &&
           VerifyOffset(verifier, VT_CENTERPOSITION) &&
           verifier.VerifyTable(CenterPosition()) &&
           VerifyOffset(verifier, VT_ROTATION) &&
           verifier.VerifyTable(Rotation()) &&
           VerifyOffset(verifier, VT_SCALE) &&
           verifier.VerifyTable(Scale()) &&
           VerifyOffset(verifier, VT_PREFABPATH) &&
           verifier.VerifyString(PrefabPath()) &&
           verifier.EndTable();
  }
  SceneBuffTriggerRowT *UnPack(const ::flatbuffers::resolver_function_t *_resolver = nullptr) const;
  void UnPackTo(SceneBuffTriggerRowT *_o, const ::flatbuffers::resolver_function_t *_resolver = nullptr) const;
  static ::flatbuffers::Offset<SceneBuffTriggerRow> Pack(::flatbuffers::FlatBufferBuilder &_fbb, const SceneBuffTriggerRowT* _o, const ::flatbuffers::rehasher_function_t *_rehasher = nullptr);
};

struct SceneBuffTriggerRowBuilder {
  typedef SceneBuffTriggerRow Table;
  ::flatbuffers::FlatBufferBuilder &fbb_;
  ::flatbuffers::uoffset_t start_;
  void add_Id(uint32_t Id) {
    fbb_.AddElement<uint32_t>(SceneBuffTriggerRow::VT_ID, Id, 0);
  }
  void add_WorldTypeId(uint32_t WorldTypeId) {
    fbb_.AddElement<uint32_t>(SceneBuffTriggerRow::VT_WORLDTYPEID, WorldTypeId, 0);
  }
  void add_IssueBuffIds(::flatbuffers::Offset<::flatbuffers::Vector<uint32_t>> IssueBuffIds) {
    fbb_.AddOffset(SceneBuffTriggerRow::VT_ISSUEBUFFIDS, IssueBuffIds);
  }
  void add_IssueBuffDuration(::flatbuffers::Offset<::flatbuffers::Vector<uint32_t>> IssueBuffDuration) {
    fbb_.AddOffset(SceneBuffTriggerRow::VT_ISSUEBUFFDURATION, IssueBuffDuration);
  }
  void add_RecycleBuffTypes(::flatbuffers::Offset<::flatbuffers::Vector<uint32_t>> RecycleBuffTypes) {
    fbb_.AddOffset(SceneBuffTriggerRow::VT_RECYCLEBUFFTYPES, RecycleBuffTypes);
  }
  void add_BannedBuffTypes(::flatbuffers::Offset<::flatbuffers::Vector<uint32_t>> BannedBuffTypes) {
    fbb_.AddOffset(SceneBuffTriggerRow::VT_BANNEDBUFFTYPES, BannedBuffTypes);
  }
  void add_CenterPosition(::flatbuffers::Offset<fb::tuple_float32_float32_float32> CenterPosition) {
    fbb_.AddOffset(SceneBuffTriggerRow::VT_CENTERPOSITION, CenterPosition);
  }
  void add_Rotation(::flatbuffers::Offset<fb::tuple_float32_float32_float32_float32> Rotation) {
    fbb_.AddOffset(SceneBuffTriggerRow::VT_ROTATION, Rotation);
  }
  void add_Scale(::flatbuffers::Offset<fb::tuple_float32_float32_float32> Scale) {
    fbb_.AddOffset(SceneBuffTriggerRow::VT_SCALE, Scale);
  }
  void add_PrefabPath(::flatbuffers::Offset<::flatbuffers::String> PrefabPath) {
    fbb_.AddOffset(SceneBuffTriggerRow::VT_PREFABPATH, PrefabPath);
  }
  explicit SceneBuffTriggerRowBuilder(::flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  ::flatbuffers::Offset<SceneBuffTriggerRow> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = ::flatbuffers::Offset<SceneBuffTriggerRow>(end);
    return o;
  }
};

inline ::flatbuffers::Offset<SceneBuffTriggerRow> CreateSceneBuffTriggerRow(
    ::flatbuffers::FlatBufferBuilder &_fbb,
    uint32_t Id = 0,
    uint32_t WorldTypeId = 0,
    ::flatbuffers::Offset<::flatbuffers::Vector<uint32_t>> IssueBuffIds = 0,
    ::flatbuffers::Offset<::flatbuffers::Vector<uint32_t>> IssueBuffDuration = 0,
    ::flatbuffers::Offset<::flatbuffers::Vector<uint32_t>> RecycleBuffTypes = 0,
    ::flatbuffers::Offset<::flatbuffers::Vector<uint32_t>> BannedBuffTypes = 0,
    ::flatbuffers::Offset<fb::tuple_float32_float32_float32> CenterPosition = 0,
    ::flatbuffers::Offset<fb::tuple_float32_float32_float32_float32> Rotation = 0,
    ::flatbuffers::Offset<fb::tuple_float32_float32_float32> Scale = 0,
    ::flatbuffers::Offset<::flatbuffers::String> PrefabPath = 0) {
  SceneBuffTriggerRowBuilder builder_(_fbb);
  builder_.add_PrefabPath(PrefabPath);
  builder_.add_Scale(Scale);
  builder_.add_Rotation(Rotation);
  builder_.add_CenterPosition(CenterPosition);
  builder_.add_BannedBuffTypes(BannedBuffTypes);
  builder_.add_RecycleBuffTypes(RecycleBuffTypes);
  builder_.add_IssueBuffDuration(IssueBuffDuration);
  builder_.add_IssueBuffIds(IssueBuffIds);
  builder_.add_WorldTypeId(WorldTypeId);
  builder_.add_Id(Id);
  return builder_.Finish();
}

inline ::flatbuffers::Offset<SceneBuffTriggerRow> CreateSceneBuffTriggerRowDirect(
    ::flatbuffers::FlatBufferBuilder &_fbb,
    uint32_t Id = 0,
    uint32_t WorldTypeId = 0,
    const std::vector<uint32_t> *IssueBuffIds = nullptr,
    const std::vector<uint32_t> *IssueBuffDuration = nullptr,
    const std::vector<uint32_t> *RecycleBuffTypes = nullptr,
    const std::vector<uint32_t> *BannedBuffTypes = nullptr,
    ::flatbuffers::Offset<fb::tuple_float32_float32_float32> CenterPosition = 0,
    ::flatbuffers::Offset<fb::tuple_float32_float32_float32_float32> Rotation = 0,
    ::flatbuffers::Offset<fb::tuple_float32_float32_float32> Scale = 0,
    const char *PrefabPath = nullptr) {
  auto IssueBuffIds__ = IssueBuffIds ? _fbb.CreateVector<uint32_t>(*IssueBuffIds) : 0;
  auto IssueBuffDuration__ = IssueBuffDuration ? _fbb.CreateVector<uint32_t>(*IssueBuffDuration) : 0;
  auto RecycleBuffTypes__ = RecycleBuffTypes ? _fbb.CreateVector<uint32_t>(*RecycleBuffTypes) : 0;
  auto BannedBuffTypes__ = BannedBuffTypes ? _fbb.CreateVector<uint32_t>(*BannedBuffTypes) : 0;
  auto PrefabPath__ = PrefabPath ? _fbb.CreateString(PrefabPath) : 0;
  return fb::CreateSceneBuffTriggerRow(
      _fbb,
      Id,
      WorldTypeId,
      IssueBuffIds__,
      IssueBuffDuration__,
      RecycleBuffTypes__,
      BannedBuffTypes__,
      CenterPosition,
      Rotation,
      Scale,
      PrefabPath__);
}

::flatbuffers::Offset<SceneBuffTriggerRow> CreateSceneBuffTriggerRow(::flatbuffers::FlatBufferBuilder &_fbb, const SceneBuffTriggerRowT *_o, const ::flatbuffers::rehasher_function_t *_rehasher = nullptr);

inline SceneBuffTriggerT::SceneBuffTriggerT(const SceneBuffTriggerT &o) {
  SceneBuffTriggers.reserve(o.SceneBuffTriggers.size());
  for (const auto &SceneBuffTriggers_ : o.SceneBuffTriggers) { SceneBuffTriggers.emplace_back((SceneBuffTriggers_) ? new fb::SceneBuffTriggerRowT(*SceneBuffTriggers_) : nullptr); }
}

inline SceneBuffTriggerT &SceneBuffTriggerT::operator=(SceneBuffTriggerT o) FLATBUFFERS_NOEXCEPT {
  std::swap(SceneBuffTriggers, o.SceneBuffTriggers);
  return *this;
}

inline SceneBuffTriggerT *SceneBuffTrigger::UnPack(const ::flatbuffers::resolver_function_t *_resolver) const {
  auto _o = std::unique_ptr<SceneBuffTriggerT>(new SceneBuffTriggerT());
  UnPackTo(_o.get(), _resolver);
  return _o.release();
}

inline void SceneBuffTrigger::UnPackTo(SceneBuffTriggerT *_o, const ::flatbuffers::resolver_function_t *_resolver) const {
  (void)_o;
  (void)_resolver;
  { auto _e = SceneBuffTriggers(); if (_e) { _o->SceneBuffTriggers.resize(_e->size()); for (::flatbuffers::uoffset_t _i = 0; _i < _e->size(); _i++) { if(_o->SceneBuffTriggers[_i]) { _e->Get(_i)->UnPackTo(_o->SceneBuffTriggers[_i].get(), _resolver); } else { _o->SceneBuffTriggers[_i] = std::unique_ptr<fb::SceneBuffTriggerRowT>(_e->Get(_i)->UnPack(_resolver)); }; } } else { _o->SceneBuffTriggers.resize(0); } }
}

inline ::flatbuffers::Offset<SceneBuffTrigger> SceneBuffTrigger::Pack(::flatbuffers::FlatBufferBuilder &_fbb, const SceneBuffTriggerT* _o, const ::flatbuffers::rehasher_function_t *_rehasher) {
  return CreateSceneBuffTrigger(_fbb, _o, _rehasher);
}

inline ::flatbuffers::Offset<SceneBuffTrigger> CreateSceneBuffTrigger(::flatbuffers::FlatBufferBuilder &_fbb, const SceneBuffTriggerT *_o, const ::flatbuffers::rehasher_function_t *_rehasher) {
  (void)_rehasher;
  (void)_o;
  struct _VectorArgs { ::flatbuffers::FlatBufferBuilder *__fbb; const SceneBuffTriggerT* __o; const ::flatbuffers::rehasher_function_t *__rehasher; } _va = { &_fbb, _o, _rehasher}; (void)_va;
  auto _SceneBuffTriggers = _o->SceneBuffTriggers.size() ? _fbb.CreateVector<::flatbuffers::Offset<fb::SceneBuffTriggerRow>> (_o->SceneBuffTriggers.size(), [](size_t i, _VectorArgs *__va) { return CreateSceneBuffTriggerRow(*__va->__fbb, __va->__o->SceneBuffTriggers[i].get(), __va->__rehasher); }, &_va ) : 0;
  return fb::CreateSceneBuffTrigger(
      _fbb,
      _SceneBuffTriggers);
}

inline SceneBuffTriggerRowT::SceneBuffTriggerRowT(const SceneBuffTriggerRowT &o)
      : Id(o.Id),
        WorldTypeId(o.WorldTypeId),
        IssueBuffIds(o.IssueBuffIds),
        IssueBuffDuration(o.IssueBuffDuration),
        RecycleBuffTypes(o.RecycleBuffTypes),
        BannedBuffTypes(o.BannedBuffTypes),
        CenterPosition((o.CenterPosition) ? new fb::tuple_float32_float32_float32T(*o.CenterPosition) : nullptr),
        Rotation((o.Rotation) ? new fb::tuple_float32_float32_float32_float32T(*o.Rotation) : nullptr),
        Scale((o.Scale) ? new fb::tuple_float32_float32_float32T(*o.Scale) : nullptr),
        PrefabPath(o.PrefabPath) {
}

inline SceneBuffTriggerRowT &SceneBuffTriggerRowT::operator=(SceneBuffTriggerRowT o) FLATBUFFERS_NOEXCEPT {
  std::swap(Id, o.Id);
  std::swap(WorldTypeId, o.WorldTypeId);
  std::swap(IssueBuffIds, o.IssueBuffIds);
  std::swap(IssueBuffDuration, o.IssueBuffDuration);
  std::swap(RecycleBuffTypes, o.RecycleBuffTypes);
  std::swap(BannedBuffTypes, o.BannedBuffTypes);
  std::swap(CenterPosition, o.CenterPosition);
  std::swap(Rotation, o.Rotation);
  std::swap(Scale, o.Scale);
  std::swap(PrefabPath, o.PrefabPath);
  return *this;
}

inline SceneBuffTriggerRowT *SceneBuffTriggerRow::UnPack(const ::flatbuffers::resolver_function_t *_resolver) const {
  auto _o = std::unique_ptr<SceneBuffTriggerRowT>(new SceneBuffTriggerRowT());
  UnPackTo(_o.get(), _resolver);
  return _o.release();
}

inline void SceneBuffTriggerRow::UnPackTo(SceneBuffTriggerRowT *_o, const ::flatbuffers::resolver_function_t *_resolver) const {
  (void)_o;
  (void)_resolver;
  { auto _e = Id(); _o->Id = _e; }
  { auto _e = WorldTypeId(); _o->WorldTypeId = _e; }
  { auto _e = IssueBuffIds(); if (_e) { _o->IssueBuffIds.resize(_e->size()); for (::flatbuffers::uoffset_t _i = 0; _i < _e->size(); _i++) { _o->IssueBuffIds[_i] = _e->Get(_i); } } else { _o->IssueBuffIds.resize(0); } }
  { auto _e = IssueBuffDuration(); if (_e) { _o->IssueBuffDuration.resize(_e->size()); for (::flatbuffers::uoffset_t _i = 0; _i < _e->size(); _i++) { _o->IssueBuffDuration[_i] = _e->Get(_i); } } else { _o->IssueBuffDuration.resize(0); } }
  { auto _e = RecycleBuffTypes(); if (_e) { _o->RecycleBuffTypes.resize(_e->size()); for (::flatbuffers::uoffset_t _i = 0; _i < _e->size(); _i++) { _o->RecycleBuffTypes[_i] = _e->Get(_i); } } else { _o->RecycleBuffTypes.resize(0); } }
  { auto _e = BannedBuffTypes(); if (_e) { _o->BannedBuffTypes.resize(_e->size()); for (::flatbuffers::uoffset_t _i = 0; _i < _e->size(); _i++) { _o->BannedBuffTypes[_i] = _e->Get(_i); } } else { _o->BannedBuffTypes.resize(0); } }
  { auto _e = CenterPosition(); if (_e) { if(_o->CenterPosition) { _e->UnPackTo(_o->CenterPosition.get(), _resolver); } else { _o->CenterPosition = std::unique_ptr<fb::tuple_float32_float32_float32T>(_e->UnPack(_resolver)); } } else if (_o->CenterPosition) { _o->CenterPosition.reset(); } }
  { auto _e = Rotation(); if (_e) { if(_o->Rotation) { _e->UnPackTo(_o->Rotation.get(), _resolver); } else { _o->Rotation = std::unique_ptr<fb::tuple_float32_float32_float32_float32T>(_e->UnPack(_resolver)); } } else if (_o->Rotation) { _o->Rotation.reset(); } }
  { auto _e = Scale(); if (_e) { if(_o->Scale) { _e->UnPackTo(_o->Scale.get(), _resolver); } else { _o->Scale = std::unique_ptr<fb::tuple_float32_float32_float32T>(_e->UnPack(_resolver)); } } else if (_o->Scale) { _o->Scale.reset(); } }
  { auto _e = PrefabPath(); if (_e) _o->PrefabPath = _e->str(); }
}

inline ::flatbuffers::Offset<SceneBuffTriggerRow> SceneBuffTriggerRow::Pack(::flatbuffers::FlatBufferBuilder &_fbb, const SceneBuffTriggerRowT* _o, const ::flatbuffers::rehasher_function_t *_rehasher) {
  return CreateSceneBuffTriggerRow(_fbb, _o, _rehasher);
}

inline ::flatbuffers::Offset<SceneBuffTriggerRow> CreateSceneBuffTriggerRow(::flatbuffers::FlatBufferBuilder &_fbb, const SceneBuffTriggerRowT *_o, const ::flatbuffers::rehasher_function_t *_rehasher) {
  (void)_rehasher;
  (void)_o;
  struct _VectorArgs { ::flatbuffers::FlatBufferBuilder *__fbb; const SceneBuffTriggerRowT* __o; const ::flatbuffers::rehasher_function_t *__rehasher; } _va = { &_fbb, _o, _rehasher}; (void)_va;
  auto _Id = _o->Id;
  auto _WorldTypeId = _o->WorldTypeId;
  auto _IssueBuffIds = _o->IssueBuffIds.size() ? _fbb.CreateVector(_o->IssueBuffIds) : 0;
  auto _IssueBuffDuration = _o->IssueBuffDuration.size() ? _fbb.CreateVector(_o->IssueBuffDuration) : 0;
  auto _RecycleBuffTypes = _o->RecycleBuffTypes.size() ? _fbb.CreateVector(_o->RecycleBuffTypes) : 0;
  auto _BannedBuffTypes = _o->BannedBuffTypes.size() ? _fbb.CreateVector(_o->BannedBuffTypes) : 0;
  auto _CenterPosition = _o->CenterPosition ? Createtuple_float32_float32_float32(_fbb, _o->CenterPosition.get(), _rehasher) : 0;
  auto _Rotation = _o->Rotation ? Createtuple_float32_float32_float32_float32(_fbb, _o->Rotation.get(), _rehasher) : 0;
  auto _Scale = _o->Scale ? Createtuple_float32_float32_float32(_fbb, _o->Scale.get(), _rehasher) : 0;
  auto _PrefabPath = _o->PrefabPath.empty() ? 0 : _fbb.CreateString(_o->PrefabPath);
  return fb::CreateSceneBuffTriggerRow(
      _fbb,
      _Id,
      _WorldTypeId,
      _IssueBuffIds,
      _IssueBuffDuration,
      _RecycleBuffTypes,
      _BannedBuffTypes,
      _CenterPosition,
      _Rotation,
      _Scale,
      _PrefabPath);
}

inline const fb::SceneBuffTrigger *GetSceneBuffTrigger(const void *buf) {
  return ::flatbuffers::GetRoot<fb::SceneBuffTrigger>(buf);
}

inline const fb::SceneBuffTrigger *GetSizePrefixedSceneBuffTrigger(const void *buf) {
  return ::flatbuffers::GetSizePrefixedRoot<fb::SceneBuffTrigger>(buf);
}

inline bool VerifySceneBuffTriggerBuffer(
    ::flatbuffers::Verifier &verifier) {
  return verifier.VerifyBuffer<fb::SceneBuffTrigger>(nullptr);
}

inline bool VerifySizePrefixedSceneBuffTriggerBuffer(
    ::flatbuffers::Verifier &verifier) {
  return verifier.VerifySizePrefixedBuffer<fb::SceneBuffTrigger>(nullptr);
}

inline void FinishSceneBuffTriggerBuffer(
    ::flatbuffers::FlatBufferBuilder &fbb,
    ::flatbuffers::Offset<fb::SceneBuffTrigger> root) {
  fbb.Finish(root);
}

inline void FinishSizePrefixedSceneBuffTriggerBuffer(
    ::flatbuffers::FlatBufferBuilder &fbb,
    ::flatbuffers::Offset<fb::SceneBuffTrigger> root) {
  fbb.FinishSizePrefixed(root);
}

inline std::unique_ptr<fb::SceneBuffTriggerT> UnPackSceneBuffTrigger(
    const void *buf,
    const ::flatbuffers::resolver_function_t *res = nullptr) {
  return std::unique_ptr<fb::SceneBuffTriggerT>(GetSceneBuffTrigger(buf)->UnPack(res));
}

inline std::unique_ptr<fb::SceneBuffTriggerT> UnPackSizePrefixedSceneBuffTrigger(
    const void *buf,
    const ::flatbuffers::resolver_function_t *res = nullptr) {
  return std::unique_ptr<fb::SceneBuffTriggerT>(GetSizePrefixedSceneBuffTrigger(buf)->UnPack(res));
}

}  // namespace fb

#endif  // FLATBUFFERS_GENERATED_SCENEBUFFTRIGGER_FB_H_
