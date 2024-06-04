// automatically generated by the FlatBuffers compiler, do not modify


#ifndef FLATBUFFERS_GENERATED_INTERACTIONGROUP_FB_H_
#define FLATBUFFERS_GENERATED_INTERACTIONGROUP_FB_H_

#include "flatbuffers/flatbuffers.h"

// Ensure the included flatbuffers.h is the same version as when this file was
// generated, otherwise it may not be compatible.
static_assert(FLATBUFFERS_VERSION_MAJOR == 24 &&
              FLATBUFFERS_VERSION_MINOR == 3 &&
              FLATBUFFERS_VERSION_REVISION == 25,
             "Non-compatible flatbuffers version included");

namespace fb {

struct InteractionGroup;
struct InteractionGroupBuilder;
struct InteractionGroupT;

struct InteractionGroupRow;
struct InteractionGroupRowBuilder;
struct InteractionGroupRowT;

struct InteractionGroupT : public ::flatbuffers::NativeTable {
  typedef InteractionGroup TableType;
  std::vector<std::unique_ptr<fb::InteractionGroupRowT>> InteractionGroups{};
  InteractionGroupT() = default;
  InteractionGroupT(const InteractionGroupT &o);
  InteractionGroupT(InteractionGroupT&&) FLATBUFFERS_NOEXCEPT = default;
  InteractionGroupT &operator=(InteractionGroupT o) FLATBUFFERS_NOEXCEPT;
};

struct InteractionGroup FLATBUFFERS_FINAL_CLASS : private ::flatbuffers::Table {
  typedef InteractionGroupT NativeTableType;
  typedef InteractionGroupBuilder Builder;
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_INTERACTIONGROUPS = 4
  };
  const ::flatbuffers::Vector<::flatbuffers::Offset<fb::InteractionGroupRow>> *InteractionGroups() const {
    return GetPointer<const ::flatbuffers::Vector<::flatbuffers::Offset<fb::InteractionGroupRow>> *>(VT_INTERACTIONGROUPS);
  }
  bool Verify(::flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyOffset(verifier, VT_INTERACTIONGROUPS) &&
           verifier.VerifyVector(InteractionGroups()) &&
           verifier.VerifyVectorOfTables(InteractionGroups()) &&
           verifier.EndTable();
  }
  InteractionGroupT *UnPack(const ::flatbuffers::resolver_function_t *_resolver = nullptr) const;
  void UnPackTo(InteractionGroupT *_o, const ::flatbuffers::resolver_function_t *_resolver = nullptr) const;
  static ::flatbuffers::Offset<InteractionGroup> Pack(::flatbuffers::FlatBufferBuilder &_fbb, const InteractionGroupT* _o, const ::flatbuffers::rehasher_function_t *_rehasher = nullptr);
};

struct InteractionGroupBuilder {
  typedef InteractionGroup Table;
  ::flatbuffers::FlatBufferBuilder &fbb_;
  ::flatbuffers::uoffset_t start_;
  void add_InteractionGroups(::flatbuffers::Offset<::flatbuffers::Vector<::flatbuffers::Offset<fb::InteractionGroupRow>>> InteractionGroups) {
    fbb_.AddOffset(InteractionGroup::VT_INTERACTIONGROUPS, InteractionGroups);
  }
  explicit InteractionGroupBuilder(::flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  ::flatbuffers::Offset<InteractionGroup> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = ::flatbuffers::Offset<InteractionGroup>(end);
    return o;
  }
};

inline ::flatbuffers::Offset<InteractionGroup> CreateInteractionGroup(
    ::flatbuffers::FlatBufferBuilder &_fbb,
    ::flatbuffers::Offset<::flatbuffers::Vector<::flatbuffers::Offset<fb::InteractionGroupRow>>> InteractionGroups = 0) {
  InteractionGroupBuilder builder_(_fbb);
  builder_.add_InteractionGroups(InteractionGroups);
  return builder_.Finish();
}

inline ::flatbuffers::Offset<InteractionGroup> CreateInteractionGroupDirect(
    ::flatbuffers::FlatBufferBuilder &_fbb,
    std::vector<::flatbuffers::Offset<fb::InteractionGroupRow>> *InteractionGroups = nullptr) {
  auto InteractionGroups__ = InteractionGroups ? _fbb.CreateVectorOfSortedTables<fb::InteractionGroupRow>(InteractionGroups) : 0;
  return fb::CreateInteractionGroup(
      _fbb,
      InteractionGroups__);
}

::flatbuffers::Offset<InteractionGroup> CreateInteractionGroup(::flatbuffers::FlatBufferBuilder &_fbb, const InteractionGroupT *_o, const ::flatbuffers::rehasher_function_t *_rehasher = nullptr);

struct InteractionGroupRowT : public ::flatbuffers::NativeTable {
  typedef InteractionGroupRow TableType;
  uint32_t Id = 0;
  uint32_t UnlockEvent = 0;
  uint32_t CloseEvent = 0;
  fb::InteractionDisplayType DisplayRule = fb::InteractionDisplayType_NONE;
  uint32_t Property = 0;
  std::vector<std::unique_ptr<fb::tuple_uint32_uint32T>> Interactions{};
  InteractionGroupRowT() = default;
  InteractionGroupRowT(const InteractionGroupRowT &o);
  InteractionGroupRowT(InteractionGroupRowT&&) FLATBUFFERS_NOEXCEPT = default;
  InteractionGroupRowT &operator=(InteractionGroupRowT o) FLATBUFFERS_NOEXCEPT;
};

struct InteractionGroupRow FLATBUFFERS_FINAL_CLASS : private ::flatbuffers::Table {
  typedef InteractionGroupRowT NativeTableType;
  typedef InteractionGroupRowBuilder Builder;
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_ID = 4,
    VT_UNLOCKEVENT = 6,
    VT_CLOSEEVENT = 8,
    VT_DISPLAYRULE = 10,
    VT_PROPERTY = 12,
    VT_INTERACTIONS = 14
  };
  uint32_t Id() const {
    return GetField<uint32_t>(VT_ID, 0);
  }
  bool KeyCompareLessThan(const InteractionGroupRow * const o) const {
    return Id() < o->Id();
  }
  int KeyCompareWithValue(uint32_t _Id) const {
    return static_cast<int>(Id() > _Id) - static_cast<int>(Id() < _Id);
  }
  uint32_t UnlockEvent() const {
    return GetField<uint32_t>(VT_UNLOCKEVENT, 0);
  }
  uint32_t CloseEvent() const {
    return GetField<uint32_t>(VT_CLOSEEVENT, 0);
  }
  fb::InteractionDisplayType DisplayRule() const {
    return static_cast<fb::InteractionDisplayType>(GetField<int32_t>(VT_DISPLAYRULE, 0));
  }
  uint32_t Property() const {
    return GetField<uint32_t>(VT_PROPERTY, 0);
  }
  const ::flatbuffers::Vector<::flatbuffers::Offset<fb::tuple_uint32_uint32>> *Interactions() const {
    return GetPointer<const ::flatbuffers::Vector<::flatbuffers::Offset<fb::tuple_uint32_uint32>> *>(VT_INTERACTIONS);
  }
  bool Verify(::flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<uint32_t>(verifier, VT_ID, 4) &&
           VerifyField<uint32_t>(verifier, VT_UNLOCKEVENT, 4) &&
           VerifyField<uint32_t>(verifier, VT_CLOSEEVENT, 4) &&
           VerifyField<int32_t>(verifier, VT_DISPLAYRULE, 4) &&
           VerifyField<uint32_t>(verifier, VT_PROPERTY, 4) &&
           VerifyOffset(verifier, VT_INTERACTIONS) &&
           verifier.VerifyVector(Interactions()) &&
           verifier.VerifyVectorOfTables(Interactions()) &&
           verifier.EndTable();
  }
  InteractionGroupRowT *UnPack(const ::flatbuffers::resolver_function_t *_resolver = nullptr) const;
  void UnPackTo(InteractionGroupRowT *_o, const ::flatbuffers::resolver_function_t *_resolver = nullptr) const;
  static ::flatbuffers::Offset<InteractionGroupRow> Pack(::flatbuffers::FlatBufferBuilder &_fbb, const InteractionGroupRowT* _o, const ::flatbuffers::rehasher_function_t *_rehasher = nullptr);
};

struct InteractionGroupRowBuilder {
  typedef InteractionGroupRow Table;
  ::flatbuffers::FlatBufferBuilder &fbb_;
  ::flatbuffers::uoffset_t start_;
  void add_Id(uint32_t Id) {
    fbb_.AddElement<uint32_t>(InteractionGroupRow::VT_ID, Id, 0);
  }
  void add_UnlockEvent(uint32_t UnlockEvent) {
    fbb_.AddElement<uint32_t>(InteractionGroupRow::VT_UNLOCKEVENT, UnlockEvent, 0);
  }
  void add_CloseEvent(uint32_t CloseEvent) {
    fbb_.AddElement<uint32_t>(InteractionGroupRow::VT_CLOSEEVENT, CloseEvent, 0);
  }
  void add_DisplayRule(fb::InteractionDisplayType DisplayRule) {
    fbb_.AddElement<int32_t>(InteractionGroupRow::VT_DISPLAYRULE, static_cast<int32_t>(DisplayRule), 0);
  }
  void add_Property(uint32_t Property) {
    fbb_.AddElement<uint32_t>(InteractionGroupRow::VT_PROPERTY, Property, 0);
  }
  void add_Interactions(::flatbuffers::Offset<::flatbuffers::Vector<::flatbuffers::Offset<fb::tuple_uint32_uint32>>> Interactions) {
    fbb_.AddOffset(InteractionGroupRow::VT_INTERACTIONS, Interactions);
  }
  explicit InteractionGroupRowBuilder(::flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  ::flatbuffers::Offset<InteractionGroupRow> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = ::flatbuffers::Offset<InteractionGroupRow>(end);
    return o;
  }
};

inline ::flatbuffers::Offset<InteractionGroupRow> CreateInteractionGroupRow(
    ::flatbuffers::FlatBufferBuilder &_fbb,
    uint32_t Id = 0,
    uint32_t UnlockEvent = 0,
    uint32_t CloseEvent = 0,
    fb::InteractionDisplayType DisplayRule = fb::InteractionDisplayType_NONE,
    uint32_t Property = 0,
    ::flatbuffers::Offset<::flatbuffers::Vector<::flatbuffers::Offset<fb::tuple_uint32_uint32>>> Interactions = 0) {
  InteractionGroupRowBuilder builder_(_fbb);
  builder_.add_Interactions(Interactions);
  builder_.add_Property(Property);
  builder_.add_DisplayRule(DisplayRule);
  builder_.add_CloseEvent(CloseEvent);
  builder_.add_UnlockEvent(UnlockEvent);
  builder_.add_Id(Id);
  return builder_.Finish();
}

inline ::flatbuffers::Offset<InteractionGroupRow> CreateInteractionGroupRowDirect(
    ::flatbuffers::FlatBufferBuilder &_fbb,
    uint32_t Id = 0,
    uint32_t UnlockEvent = 0,
    uint32_t CloseEvent = 0,
    fb::InteractionDisplayType DisplayRule = fb::InteractionDisplayType_NONE,
    uint32_t Property = 0,
    const std::vector<::flatbuffers::Offset<fb::tuple_uint32_uint32>> *Interactions = nullptr) {
  auto Interactions__ = Interactions ? _fbb.CreateVector<::flatbuffers::Offset<fb::tuple_uint32_uint32>>(*Interactions) : 0;
  return fb::CreateInteractionGroupRow(
      _fbb,
      Id,
      UnlockEvent,
      CloseEvent,
      DisplayRule,
      Property,
      Interactions__);
}

::flatbuffers::Offset<InteractionGroupRow> CreateInteractionGroupRow(::flatbuffers::FlatBufferBuilder &_fbb, const InteractionGroupRowT *_o, const ::flatbuffers::rehasher_function_t *_rehasher = nullptr);

inline InteractionGroupT::InteractionGroupT(const InteractionGroupT &o) {
  InteractionGroups.reserve(o.InteractionGroups.size());
  for (const auto &InteractionGroups_ : o.InteractionGroups) { InteractionGroups.emplace_back((InteractionGroups_) ? new fb::InteractionGroupRowT(*InteractionGroups_) : nullptr); }
}

inline InteractionGroupT &InteractionGroupT::operator=(InteractionGroupT o) FLATBUFFERS_NOEXCEPT {
  std::swap(InteractionGroups, o.InteractionGroups);
  return *this;
}

inline InteractionGroupT *InteractionGroup::UnPack(const ::flatbuffers::resolver_function_t *_resolver) const {
  auto _o = std::unique_ptr<InteractionGroupT>(new InteractionGroupT());
  UnPackTo(_o.get(), _resolver);
  return _o.release();
}

inline void InteractionGroup::UnPackTo(InteractionGroupT *_o, const ::flatbuffers::resolver_function_t *_resolver) const {
  (void)_o;
  (void)_resolver;
  { auto _e = InteractionGroups(); if (_e) { _o->InteractionGroups.resize(_e->size()); for (::flatbuffers::uoffset_t _i = 0; _i < _e->size(); _i++) { if(_o->InteractionGroups[_i]) { _e->Get(_i)->UnPackTo(_o->InteractionGroups[_i].get(), _resolver); } else { _o->InteractionGroups[_i] = std::unique_ptr<fb::InteractionGroupRowT>(_e->Get(_i)->UnPack(_resolver)); }; } } else { _o->InteractionGroups.resize(0); } }
}

inline ::flatbuffers::Offset<InteractionGroup> InteractionGroup::Pack(::flatbuffers::FlatBufferBuilder &_fbb, const InteractionGroupT* _o, const ::flatbuffers::rehasher_function_t *_rehasher) {
  return CreateInteractionGroup(_fbb, _o, _rehasher);
}

inline ::flatbuffers::Offset<InteractionGroup> CreateInteractionGroup(::flatbuffers::FlatBufferBuilder &_fbb, const InteractionGroupT *_o, const ::flatbuffers::rehasher_function_t *_rehasher) {
  (void)_rehasher;
  (void)_o;
  struct _VectorArgs { ::flatbuffers::FlatBufferBuilder *__fbb; const InteractionGroupT* __o; const ::flatbuffers::rehasher_function_t *__rehasher; } _va = { &_fbb, _o, _rehasher}; (void)_va;
  auto _InteractionGroups = _o->InteractionGroups.size() ? _fbb.CreateVector<::flatbuffers::Offset<fb::InteractionGroupRow>> (_o->InteractionGroups.size(), [](size_t i, _VectorArgs *__va) { return CreateInteractionGroupRow(*__va->__fbb, __va->__o->InteractionGroups[i].get(), __va->__rehasher); }, &_va ) : 0;
  return fb::CreateInteractionGroup(
      _fbb,
      _InteractionGroups);
}

inline InteractionGroupRowT::InteractionGroupRowT(const InteractionGroupRowT &o)
      : Id(o.Id),
        UnlockEvent(o.UnlockEvent),
        CloseEvent(o.CloseEvent),
        DisplayRule(o.DisplayRule),
        Property(o.Property) {
  Interactions.reserve(o.Interactions.size());
  for (const auto &Interactions_ : o.Interactions) { Interactions.emplace_back((Interactions_) ? new fb::tuple_uint32_uint32T(*Interactions_) : nullptr); }
}

inline InteractionGroupRowT &InteractionGroupRowT::operator=(InteractionGroupRowT o) FLATBUFFERS_NOEXCEPT {
  std::swap(Id, o.Id);
  std::swap(UnlockEvent, o.UnlockEvent);
  std::swap(CloseEvent, o.CloseEvent);
  std::swap(DisplayRule, o.DisplayRule);
  std::swap(Property, o.Property);
  std::swap(Interactions, o.Interactions);
  return *this;
}

inline InteractionGroupRowT *InteractionGroupRow::UnPack(const ::flatbuffers::resolver_function_t *_resolver) const {
  auto _o = std::unique_ptr<InteractionGroupRowT>(new InteractionGroupRowT());
  UnPackTo(_o.get(), _resolver);
  return _o.release();
}

inline void InteractionGroupRow::UnPackTo(InteractionGroupRowT *_o, const ::flatbuffers::resolver_function_t *_resolver) const {
  (void)_o;
  (void)_resolver;
  { auto _e = Id(); _o->Id = _e; }
  { auto _e = UnlockEvent(); _o->UnlockEvent = _e; }
  { auto _e = CloseEvent(); _o->CloseEvent = _e; }
  { auto _e = DisplayRule(); _o->DisplayRule = _e; }
  { auto _e = Property(); _o->Property = _e; }
  { auto _e = Interactions(); if (_e) { _o->Interactions.resize(_e->size()); for (::flatbuffers::uoffset_t _i = 0; _i < _e->size(); _i++) { if(_o->Interactions[_i]) { _e->Get(_i)->UnPackTo(_o->Interactions[_i].get(), _resolver); } else { _o->Interactions[_i] = std::unique_ptr<fb::tuple_uint32_uint32T>(_e->Get(_i)->UnPack(_resolver)); }; } } else { _o->Interactions.resize(0); } }
}

inline ::flatbuffers::Offset<InteractionGroupRow> InteractionGroupRow::Pack(::flatbuffers::FlatBufferBuilder &_fbb, const InteractionGroupRowT* _o, const ::flatbuffers::rehasher_function_t *_rehasher) {
  return CreateInteractionGroupRow(_fbb, _o, _rehasher);
}

inline ::flatbuffers::Offset<InteractionGroupRow> CreateInteractionGroupRow(::flatbuffers::FlatBufferBuilder &_fbb, const InteractionGroupRowT *_o, const ::flatbuffers::rehasher_function_t *_rehasher) {
  (void)_rehasher;
  (void)_o;
  struct _VectorArgs { ::flatbuffers::FlatBufferBuilder *__fbb; const InteractionGroupRowT* __o; const ::flatbuffers::rehasher_function_t *__rehasher; } _va = { &_fbb, _o, _rehasher}; (void)_va;
  auto _Id = _o->Id;
  auto _UnlockEvent = _o->UnlockEvent;
  auto _CloseEvent = _o->CloseEvent;
  auto _DisplayRule = _o->DisplayRule;
  auto _Property = _o->Property;
  auto _Interactions = _o->Interactions.size() ? _fbb.CreateVector<::flatbuffers::Offset<fb::tuple_uint32_uint32>> (_o->Interactions.size(), [](size_t i, _VectorArgs *__va) { return Createtuple_uint32_uint32(*__va->__fbb, __va->__o->Interactions[i].get(), __va->__rehasher); }, &_va ) : 0;
  return fb::CreateInteractionGroupRow(
      _fbb,
      _Id,
      _UnlockEvent,
      _CloseEvent,
      _DisplayRule,
      _Property,
      _Interactions);
}

inline const fb::InteractionGroup *GetInteractionGroup(const void *buf) {
  return ::flatbuffers::GetRoot<fb::InteractionGroup>(buf);
}

inline const fb::InteractionGroup *GetSizePrefixedInteractionGroup(const void *buf) {
  return ::flatbuffers::GetSizePrefixedRoot<fb::InteractionGroup>(buf);
}

inline bool VerifyInteractionGroupBuffer(
    ::flatbuffers::Verifier &verifier) {
  return verifier.VerifyBuffer<fb::InteractionGroup>(nullptr);
}

inline bool VerifySizePrefixedInteractionGroupBuffer(
    ::flatbuffers::Verifier &verifier) {
  return verifier.VerifySizePrefixedBuffer<fb::InteractionGroup>(nullptr);
}

inline void FinishInteractionGroupBuffer(
    ::flatbuffers::FlatBufferBuilder &fbb,
    ::flatbuffers::Offset<fb::InteractionGroup> root) {
  fbb.Finish(root);
}

inline void FinishSizePrefixedInteractionGroupBuffer(
    ::flatbuffers::FlatBufferBuilder &fbb,
    ::flatbuffers::Offset<fb::InteractionGroup> root) {
  fbb.FinishSizePrefixed(root);
}

inline std::unique_ptr<fb::InteractionGroupT> UnPackInteractionGroup(
    const void *buf,
    const ::flatbuffers::resolver_function_t *res = nullptr) {
  return std::unique_ptr<fb::InteractionGroupT>(GetInteractionGroup(buf)->UnPack(res));
}

inline std::unique_ptr<fb::InteractionGroupT> UnPackSizePrefixedInteractionGroup(
    const void *buf,
    const ::flatbuffers::resolver_function_t *res = nullptr) {
  return std::unique_ptr<fb::InteractionGroupT>(GetSizePrefixedInteractionGroup(buf)->UnPack(res));
}

}  // namespace fb

#endif  // FLATBUFFERS_GENERATED_INTERACTIONGROUP_FB_H_
