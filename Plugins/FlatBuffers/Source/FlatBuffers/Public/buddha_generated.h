// automatically generated by the FlatBuffers compiler, do not modify


#ifndef FLATBUFFERS_GENERATED_BUDDHA_FB_H_
#define FLATBUFFERS_GENERATED_BUDDHA_FB_H_

#include "flatbuffers/flatbuffers.h"

// Ensure the included flatbuffers.h is the same version as when this file was
// generated, otherwise it may not be compatible.
static_assert(FLATBUFFERS_VERSION_MAJOR == 24 &&
              FLATBUFFERS_VERSION_MINOR == 3 &&
              FLATBUFFERS_VERSION_REVISION == 25,
             "Non-compatible flatbuffers version included");

namespace fb {

struct Buddha;
struct BuddhaBuilder;
struct BuddhaT;

struct BuddhaRow;
struct BuddhaRowBuilder;
struct BuddhaRowT;

struct BuddhaT : public ::flatbuffers::NativeTable {
  typedef Buddha TableType;
  std::vector<std::unique_ptr<fb::BuddhaRowT>> Buddhas{};
  BuddhaT() = default;
  BuddhaT(const BuddhaT &o);
  BuddhaT(BuddhaT&&) FLATBUFFERS_NOEXCEPT = default;
  BuddhaT &operator=(BuddhaT o) FLATBUFFERS_NOEXCEPT;
};

struct Buddha FLATBUFFERS_FINAL_CLASS : private ::flatbuffers::Table {
  typedef BuddhaT NativeTableType;
  typedef BuddhaBuilder Builder;
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_BUDDHAS = 4
  };
  const ::flatbuffers::Vector<::flatbuffers::Offset<fb::BuddhaRow>> *Buddhas() const {
    return GetPointer<const ::flatbuffers::Vector<::flatbuffers::Offset<fb::BuddhaRow>> *>(VT_BUDDHAS);
  }
  bool Verify(::flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyOffset(verifier, VT_BUDDHAS) &&
           verifier.VerifyVector(Buddhas()) &&
           verifier.VerifyVectorOfTables(Buddhas()) &&
           verifier.EndTable();
  }
  BuddhaT *UnPack(const ::flatbuffers::resolver_function_t *_resolver = nullptr) const;
  void UnPackTo(BuddhaT *_o, const ::flatbuffers::resolver_function_t *_resolver = nullptr) const;
  static ::flatbuffers::Offset<Buddha> Pack(::flatbuffers::FlatBufferBuilder &_fbb, const BuddhaT* _o, const ::flatbuffers::rehasher_function_t *_rehasher = nullptr);
};

struct BuddhaBuilder {
  typedef Buddha Table;
  ::flatbuffers::FlatBufferBuilder &fbb_;
  ::flatbuffers::uoffset_t start_;
  void add_Buddhas(::flatbuffers::Offset<::flatbuffers::Vector<::flatbuffers::Offset<fb::BuddhaRow>>> Buddhas) {
    fbb_.AddOffset(Buddha::VT_BUDDHAS, Buddhas);
  }
  explicit BuddhaBuilder(::flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  ::flatbuffers::Offset<Buddha> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = ::flatbuffers::Offset<Buddha>(end);
    return o;
  }
};

inline ::flatbuffers::Offset<Buddha> CreateBuddha(
    ::flatbuffers::FlatBufferBuilder &_fbb,
    ::flatbuffers::Offset<::flatbuffers::Vector<::flatbuffers::Offset<fb::BuddhaRow>>> Buddhas = 0) {
  BuddhaBuilder builder_(_fbb);
  builder_.add_Buddhas(Buddhas);
  return builder_.Finish();
}

inline ::flatbuffers::Offset<Buddha> CreateBuddhaDirect(
    ::flatbuffers::FlatBufferBuilder &_fbb,
    std::vector<::flatbuffers::Offset<fb::BuddhaRow>> *Buddhas = nullptr) {
  auto Buddhas__ = Buddhas ? _fbb.CreateVectorOfSortedTables<fb::BuddhaRow>(Buddhas) : 0;
  return fb::CreateBuddha(
      _fbb,
      Buddhas__);
}

::flatbuffers::Offset<Buddha> CreateBuddha(::flatbuffers::FlatBufferBuilder &_fbb, const BuddhaT *_o, const ::flatbuffers::rehasher_function_t *_rehasher = nullptr);

struct BuddhaRowT : public ::flatbuffers::NativeTable {
  typedef BuddhaRow TableType;
  uint32_t Id = 0;
  uint32_t WorldTypeId = 0;
  bool InitCreate = false;
  std::unique_ptr<fb::tuple_float32_float32_float32T> RevivePosition{};
  std::unique_ptr<fb::tuple_float32_float32_float32_float32T> ReviveRotation{};
  std::unique_ptr<fb::tuple_float32_float32_float32T> CenterPosition{};
  std::unique_ptr<fb::tuple_float32_float32_float32_float32T> Rotation{};
  std::unique_ptr<fb::tuple_float32_float32_float32T> Scale{};
  std::string PrefabPath{};
  BuddhaRowT() = default;
  BuddhaRowT(const BuddhaRowT &o);
  BuddhaRowT(BuddhaRowT&&) FLATBUFFERS_NOEXCEPT = default;
  BuddhaRowT &operator=(BuddhaRowT o) FLATBUFFERS_NOEXCEPT;
};

struct BuddhaRow FLATBUFFERS_FINAL_CLASS : private ::flatbuffers::Table {
  typedef BuddhaRowT NativeTableType;
  typedef BuddhaRowBuilder Builder;
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_ID = 4,
    VT_WORLDTYPEID = 6,
    VT_INITCREATE = 8,
    VT_REVIVEPOSITION = 10,
    VT_REVIVEROTATION = 12,
    VT_CENTERPOSITION = 14,
    VT_ROTATION = 16,
    VT_SCALE = 18,
    VT_PREFABPATH = 20
  };
  uint32_t Id() const {
    return GetField<uint32_t>(VT_ID, 0);
  }
  bool KeyCompareLessThan(const BuddhaRow * const o) const {
    return Id() < o->Id();
  }
  int KeyCompareWithValue(uint32_t _Id) const {
    return static_cast<int>(Id() > _Id) - static_cast<int>(Id() < _Id);
  }
  uint32_t WorldTypeId() const {
    return GetField<uint32_t>(VT_WORLDTYPEID, 0);
  }
  bool InitCreate() const {
    return GetField<uint8_t>(VT_INITCREATE, 0) != 0;
  }
  const fb::tuple_float32_float32_float32 *RevivePosition() const {
    return GetPointer<const fb::tuple_float32_float32_float32 *>(VT_REVIVEPOSITION);
  }
  const fb::tuple_float32_float32_float32_float32 *ReviveRotation() const {
    return GetPointer<const fb::tuple_float32_float32_float32_float32 *>(VT_REVIVEROTATION);
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
           VerifyField<uint8_t>(verifier, VT_INITCREATE, 1) &&
           VerifyOffset(verifier, VT_REVIVEPOSITION) &&
           verifier.VerifyTable(RevivePosition()) &&
           VerifyOffset(verifier, VT_REVIVEROTATION) &&
           verifier.VerifyTable(ReviveRotation()) &&
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
  BuddhaRowT *UnPack(const ::flatbuffers::resolver_function_t *_resolver = nullptr) const;
  void UnPackTo(BuddhaRowT *_o, const ::flatbuffers::resolver_function_t *_resolver = nullptr) const;
  static ::flatbuffers::Offset<BuddhaRow> Pack(::flatbuffers::FlatBufferBuilder &_fbb, const BuddhaRowT* _o, const ::flatbuffers::rehasher_function_t *_rehasher = nullptr);
};

struct BuddhaRowBuilder {
  typedef BuddhaRow Table;
  ::flatbuffers::FlatBufferBuilder &fbb_;
  ::flatbuffers::uoffset_t start_;
  void add_Id(uint32_t Id) {
    fbb_.AddElement<uint32_t>(BuddhaRow::VT_ID, Id, 0);
  }
  void add_WorldTypeId(uint32_t WorldTypeId) {
    fbb_.AddElement<uint32_t>(BuddhaRow::VT_WORLDTYPEID, WorldTypeId, 0);
  }
  void add_InitCreate(bool InitCreate) {
    fbb_.AddElement<uint8_t>(BuddhaRow::VT_INITCREATE, static_cast<uint8_t>(InitCreate), 0);
  }
  void add_RevivePosition(::flatbuffers::Offset<fb::tuple_float32_float32_float32> RevivePosition) {
    fbb_.AddOffset(BuddhaRow::VT_REVIVEPOSITION, RevivePosition);
  }
  void add_ReviveRotation(::flatbuffers::Offset<fb::tuple_float32_float32_float32_float32> ReviveRotation) {
    fbb_.AddOffset(BuddhaRow::VT_REVIVEROTATION, ReviveRotation);
  }
  void add_CenterPosition(::flatbuffers::Offset<fb::tuple_float32_float32_float32> CenterPosition) {
    fbb_.AddOffset(BuddhaRow::VT_CENTERPOSITION, CenterPosition);
  }
  void add_Rotation(::flatbuffers::Offset<fb::tuple_float32_float32_float32_float32> Rotation) {
    fbb_.AddOffset(BuddhaRow::VT_ROTATION, Rotation);
  }
  void add_Scale(::flatbuffers::Offset<fb::tuple_float32_float32_float32> Scale) {
    fbb_.AddOffset(BuddhaRow::VT_SCALE, Scale);
  }
  void add_PrefabPath(::flatbuffers::Offset<::flatbuffers::String> PrefabPath) {
    fbb_.AddOffset(BuddhaRow::VT_PREFABPATH, PrefabPath);
  }
  explicit BuddhaRowBuilder(::flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  ::flatbuffers::Offset<BuddhaRow> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = ::flatbuffers::Offset<BuddhaRow>(end);
    return o;
  }
};

inline ::flatbuffers::Offset<BuddhaRow> CreateBuddhaRow(
    ::flatbuffers::FlatBufferBuilder &_fbb,
    uint32_t Id = 0,
    uint32_t WorldTypeId = 0,
    bool InitCreate = false,
    ::flatbuffers::Offset<fb::tuple_float32_float32_float32> RevivePosition = 0,
    ::flatbuffers::Offset<fb::tuple_float32_float32_float32_float32> ReviveRotation = 0,
    ::flatbuffers::Offset<fb::tuple_float32_float32_float32> CenterPosition = 0,
    ::flatbuffers::Offset<fb::tuple_float32_float32_float32_float32> Rotation = 0,
    ::flatbuffers::Offset<fb::tuple_float32_float32_float32> Scale = 0,
    ::flatbuffers::Offset<::flatbuffers::String> PrefabPath = 0) {
  BuddhaRowBuilder builder_(_fbb);
  builder_.add_PrefabPath(PrefabPath);
  builder_.add_Scale(Scale);
  builder_.add_Rotation(Rotation);
  builder_.add_CenterPosition(CenterPosition);
  builder_.add_ReviveRotation(ReviveRotation);
  builder_.add_RevivePosition(RevivePosition);
  builder_.add_WorldTypeId(WorldTypeId);
  builder_.add_Id(Id);
  builder_.add_InitCreate(InitCreate);
  return builder_.Finish();
}

inline ::flatbuffers::Offset<BuddhaRow> CreateBuddhaRowDirect(
    ::flatbuffers::FlatBufferBuilder &_fbb,
    uint32_t Id = 0,
    uint32_t WorldTypeId = 0,
    bool InitCreate = false,
    ::flatbuffers::Offset<fb::tuple_float32_float32_float32> RevivePosition = 0,
    ::flatbuffers::Offset<fb::tuple_float32_float32_float32_float32> ReviveRotation = 0,
    ::flatbuffers::Offset<fb::tuple_float32_float32_float32> CenterPosition = 0,
    ::flatbuffers::Offset<fb::tuple_float32_float32_float32_float32> Rotation = 0,
    ::flatbuffers::Offset<fb::tuple_float32_float32_float32> Scale = 0,
    const char *PrefabPath = nullptr) {
  auto PrefabPath__ = PrefabPath ? _fbb.CreateString(PrefabPath) : 0;
  return fb::CreateBuddhaRow(
      _fbb,
      Id,
      WorldTypeId,
      InitCreate,
      RevivePosition,
      ReviveRotation,
      CenterPosition,
      Rotation,
      Scale,
      PrefabPath__);
}

::flatbuffers::Offset<BuddhaRow> CreateBuddhaRow(::flatbuffers::FlatBufferBuilder &_fbb, const BuddhaRowT *_o, const ::flatbuffers::rehasher_function_t *_rehasher = nullptr);

inline BuddhaT::BuddhaT(const BuddhaT &o) {
  Buddhas.reserve(o.Buddhas.size());
  for (const auto &Buddhas_ : o.Buddhas) { Buddhas.emplace_back((Buddhas_) ? new fb::BuddhaRowT(*Buddhas_) : nullptr); }
}

inline BuddhaT &BuddhaT::operator=(BuddhaT o) FLATBUFFERS_NOEXCEPT {
  std::swap(Buddhas, o.Buddhas);
  return *this;
}

inline BuddhaT *Buddha::UnPack(const ::flatbuffers::resolver_function_t *_resolver) const {
  auto _o = std::unique_ptr<BuddhaT>(new BuddhaT());
  UnPackTo(_o.get(), _resolver);
  return _o.release();
}

inline void Buddha::UnPackTo(BuddhaT *_o, const ::flatbuffers::resolver_function_t *_resolver) const {
  (void)_o;
  (void)_resolver;
  { auto _e = Buddhas(); if (_e) { _o->Buddhas.resize(_e->size()); for (::flatbuffers::uoffset_t _i = 0; _i < _e->size(); _i++) { if(_o->Buddhas[_i]) { _e->Get(_i)->UnPackTo(_o->Buddhas[_i].get(), _resolver); } else { _o->Buddhas[_i] = std::unique_ptr<fb::BuddhaRowT>(_e->Get(_i)->UnPack(_resolver)); }; } } else { _o->Buddhas.resize(0); } }
}

inline ::flatbuffers::Offset<Buddha> Buddha::Pack(::flatbuffers::FlatBufferBuilder &_fbb, const BuddhaT* _o, const ::flatbuffers::rehasher_function_t *_rehasher) {
  return CreateBuddha(_fbb, _o, _rehasher);
}

inline ::flatbuffers::Offset<Buddha> CreateBuddha(::flatbuffers::FlatBufferBuilder &_fbb, const BuddhaT *_o, const ::flatbuffers::rehasher_function_t *_rehasher) {
  (void)_rehasher;
  (void)_o;
  struct _VectorArgs { ::flatbuffers::FlatBufferBuilder *__fbb; const BuddhaT* __o; const ::flatbuffers::rehasher_function_t *__rehasher; } _va = { &_fbb, _o, _rehasher}; (void)_va;
  auto _Buddhas = _o->Buddhas.size() ? _fbb.CreateVector<::flatbuffers::Offset<fb::BuddhaRow>> (_o->Buddhas.size(), [](size_t i, _VectorArgs *__va) { return CreateBuddhaRow(*__va->__fbb, __va->__o->Buddhas[i].get(), __va->__rehasher); }, &_va ) : 0;
  return fb::CreateBuddha(
      _fbb,
      _Buddhas);
}

inline BuddhaRowT::BuddhaRowT(const BuddhaRowT &o)
      : Id(o.Id),
        WorldTypeId(o.WorldTypeId),
        InitCreate(o.InitCreate),
        RevivePosition((o.RevivePosition) ? new fb::tuple_float32_float32_float32T(*o.RevivePosition) : nullptr),
        ReviveRotation((o.ReviveRotation) ? new fb::tuple_float32_float32_float32_float32T(*o.ReviveRotation) : nullptr),
        CenterPosition((o.CenterPosition) ? new fb::tuple_float32_float32_float32T(*o.CenterPosition) : nullptr),
        Rotation((o.Rotation) ? new fb::tuple_float32_float32_float32_float32T(*o.Rotation) : nullptr),
        Scale((o.Scale) ? new fb::tuple_float32_float32_float32T(*o.Scale) : nullptr),
        PrefabPath(o.PrefabPath) {
}

inline BuddhaRowT &BuddhaRowT::operator=(BuddhaRowT o) FLATBUFFERS_NOEXCEPT {
  std::swap(Id, o.Id);
  std::swap(WorldTypeId, o.WorldTypeId);
  std::swap(InitCreate, o.InitCreate);
  std::swap(RevivePosition, o.RevivePosition);
  std::swap(ReviveRotation, o.ReviveRotation);
  std::swap(CenterPosition, o.CenterPosition);
  std::swap(Rotation, o.Rotation);
  std::swap(Scale, o.Scale);
  std::swap(PrefabPath, o.PrefabPath);
  return *this;
}

inline BuddhaRowT *BuddhaRow::UnPack(const ::flatbuffers::resolver_function_t *_resolver) const {
  auto _o = std::unique_ptr<BuddhaRowT>(new BuddhaRowT());
  UnPackTo(_o.get(), _resolver);
  return _o.release();
}

inline void BuddhaRow::UnPackTo(BuddhaRowT *_o, const ::flatbuffers::resolver_function_t *_resolver) const {
  (void)_o;
  (void)_resolver;
  { auto _e = Id(); _o->Id = _e; }
  { auto _e = WorldTypeId(); _o->WorldTypeId = _e; }
  { auto _e = InitCreate(); _o->InitCreate = _e; }
  { auto _e = RevivePosition(); if (_e) { if(_o->RevivePosition) { _e->UnPackTo(_o->RevivePosition.get(), _resolver); } else { _o->RevivePosition = std::unique_ptr<fb::tuple_float32_float32_float32T>(_e->UnPack(_resolver)); } } else if (_o->RevivePosition) { _o->RevivePosition.reset(); } }
  { auto _e = ReviveRotation(); if (_e) { if(_o->ReviveRotation) { _e->UnPackTo(_o->ReviveRotation.get(), _resolver); } else { _o->ReviveRotation = std::unique_ptr<fb::tuple_float32_float32_float32_float32T>(_e->UnPack(_resolver)); } } else if (_o->ReviveRotation) { _o->ReviveRotation.reset(); } }
  { auto _e = CenterPosition(); if (_e) { if(_o->CenterPosition) { _e->UnPackTo(_o->CenterPosition.get(), _resolver); } else { _o->CenterPosition = std::unique_ptr<fb::tuple_float32_float32_float32T>(_e->UnPack(_resolver)); } } else if (_o->CenterPosition) { _o->CenterPosition.reset(); } }
  { auto _e = Rotation(); if (_e) { if(_o->Rotation) { _e->UnPackTo(_o->Rotation.get(), _resolver); } else { _o->Rotation = std::unique_ptr<fb::tuple_float32_float32_float32_float32T>(_e->UnPack(_resolver)); } } else if (_o->Rotation) { _o->Rotation.reset(); } }
  { auto _e = Scale(); if (_e) { if(_o->Scale) { _e->UnPackTo(_o->Scale.get(), _resolver); } else { _o->Scale = std::unique_ptr<fb::tuple_float32_float32_float32T>(_e->UnPack(_resolver)); } } else if (_o->Scale) { _o->Scale.reset(); } }
  { auto _e = PrefabPath(); if (_e) _o->PrefabPath = _e->str(); }
}

inline ::flatbuffers::Offset<BuddhaRow> BuddhaRow::Pack(::flatbuffers::FlatBufferBuilder &_fbb, const BuddhaRowT* _o, const ::flatbuffers::rehasher_function_t *_rehasher) {
  return CreateBuddhaRow(_fbb, _o, _rehasher);
}

inline ::flatbuffers::Offset<BuddhaRow> CreateBuddhaRow(::flatbuffers::FlatBufferBuilder &_fbb, const BuddhaRowT *_o, const ::flatbuffers::rehasher_function_t *_rehasher) {
  (void)_rehasher;
  (void)_o;
  struct _VectorArgs { ::flatbuffers::FlatBufferBuilder *__fbb; const BuddhaRowT* __o; const ::flatbuffers::rehasher_function_t *__rehasher; } _va = { &_fbb, _o, _rehasher}; (void)_va;
  auto _Id = _o->Id;
  auto _WorldTypeId = _o->WorldTypeId;
  auto _InitCreate = _o->InitCreate;
  auto _RevivePosition = _o->RevivePosition ? Createtuple_float32_float32_float32(_fbb, _o->RevivePosition.get(), _rehasher) : 0;
  auto _ReviveRotation = _o->ReviveRotation ? Createtuple_float32_float32_float32_float32(_fbb, _o->ReviveRotation.get(), _rehasher) : 0;
  auto _CenterPosition = _o->CenterPosition ? Createtuple_float32_float32_float32(_fbb, _o->CenterPosition.get(), _rehasher) : 0;
  auto _Rotation = _o->Rotation ? Createtuple_float32_float32_float32_float32(_fbb, _o->Rotation.get(), _rehasher) : 0;
  auto _Scale = _o->Scale ? Createtuple_float32_float32_float32(_fbb, _o->Scale.get(), _rehasher) : 0;
  auto _PrefabPath = _o->PrefabPath.empty() ? 0 : _fbb.CreateString(_o->PrefabPath);
  return fb::CreateBuddhaRow(
      _fbb,
      _Id,
      _WorldTypeId,
      _InitCreate,
      _RevivePosition,
      _ReviveRotation,
      _CenterPosition,
      _Rotation,
      _Scale,
      _PrefabPath);
}

inline const fb::Buddha *GetBuddha(const void *buf) {
  return ::flatbuffers::GetRoot<fb::Buddha>(buf);
}

inline const fb::Buddha *GetSizePrefixedBuddha(const void *buf) {
  return ::flatbuffers::GetSizePrefixedRoot<fb::Buddha>(buf);
}

inline bool VerifyBuddhaBuffer(
    ::flatbuffers::Verifier &verifier) {
  return verifier.VerifyBuffer<fb::Buddha>(nullptr);
}

inline bool VerifySizePrefixedBuddhaBuffer(
    ::flatbuffers::Verifier &verifier) {
  return verifier.VerifySizePrefixedBuffer<fb::Buddha>(nullptr);
}

inline void FinishBuddhaBuffer(
    ::flatbuffers::FlatBufferBuilder &fbb,
    ::flatbuffers::Offset<fb::Buddha> root) {
  fbb.Finish(root);
}

inline void FinishSizePrefixedBuddhaBuffer(
    ::flatbuffers::FlatBufferBuilder &fbb,
    ::flatbuffers::Offset<fb::Buddha> root) {
  fbb.FinishSizePrefixed(root);
}

inline std::unique_ptr<fb::BuddhaT> UnPackBuddha(
    const void *buf,
    const ::flatbuffers::resolver_function_t *res = nullptr) {
  return std::unique_ptr<fb::BuddhaT>(GetBuddha(buf)->UnPack(res));
}

inline std::unique_ptr<fb::BuddhaT> UnPackSizePrefixedBuddha(
    const void *buf,
    const ::flatbuffers::resolver_function_t *res = nullptr) {
  return std::unique_ptr<fb::BuddhaT>(GetSizePrefixedBuddha(buf)->UnPack(res));
}

}  // namespace fb

#endif  // FLATBUFFERS_GENERATED_BUDDHA_FB_H_
