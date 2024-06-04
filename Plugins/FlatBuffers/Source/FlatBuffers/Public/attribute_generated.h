// automatically generated by the FlatBuffers compiler, do not modify


#ifndef FLATBUFFERS_GENERATED_ATTRIBUTE_FB_H_
#define FLATBUFFERS_GENERATED_ATTRIBUTE_FB_H_

#include "flatbuffers/flatbuffers.h"

// Ensure the included flatbuffers.h is the same version as when this file was
// generated, otherwise it may not be compatible.
static_assert(FLATBUFFERS_VERSION_MAJOR == 24 &&
              FLATBUFFERS_VERSION_MINOR == 3 &&
              FLATBUFFERS_VERSION_REVISION == 25,
             "Non-compatible flatbuffers version included");

namespace fb {

struct Attribute;
struct AttributeBuilder;
struct AttributeT;

struct AttributeRow;
struct AttributeRowBuilder;
struct AttributeRowT;

struct AttributeT : public ::flatbuffers::NativeTable {
  typedef Attribute TableType;
  std::vector<std::unique_ptr<fb::AttributeRowT>> Attributes{};
  AttributeT() = default;
  AttributeT(const AttributeT &o);
  AttributeT(AttributeT&&) FLATBUFFERS_NOEXCEPT = default;
  AttributeT &operator=(AttributeT o) FLATBUFFERS_NOEXCEPT;
};

struct Attribute FLATBUFFERS_FINAL_CLASS : private ::flatbuffers::Table {
  typedef AttributeT NativeTableType;
  typedef AttributeBuilder Builder;
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_ATTRIBUTES = 4
  };
  const ::flatbuffers::Vector<::flatbuffers::Offset<fb::AttributeRow>> *Attributes() const {
    return GetPointer<const ::flatbuffers::Vector<::flatbuffers::Offset<fb::AttributeRow>> *>(VT_ATTRIBUTES);
  }
  bool Verify(::flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyOffset(verifier, VT_ATTRIBUTES) &&
           verifier.VerifyVector(Attributes()) &&
           verifier.VerifyVectorOfTables(Attributes()) &&
           verifier.EndTable();
  }
  AttributeT *UnPack(const ::flatbuffers::resolver_function_t *_resolver = nullptr) const;
  void UnPackTo(AttributeT *_o, const ::flatbuffers::resolver_function_t *_resolver = nullptr) const;
  static ::flatbuffers::Offset<Attribute> Pack(::flatbuffers::FlatBufferBuilder &_fbb, const AttributeT* _o, const ::flatbuffers::rehasher_function_t *_rehasher = nullptr);
};

struct AttributeBuilder {
  typedef Attribute Table;
  ::flatbuffers::FlatBufferBuilder &fbb_;
  ::flatbuffers::uoffset_t start_;
  void add_Attributes(::flatbuffers::Offset<::flatbuffers::Vector<::flatbuffers::Offset<fb::AttributeRow>>> Attributes) {
    fbb_.AddOffset(Attribute::VT_ATTRIBUTES, Attributes);
  }
  explicit AttributeBuilder(::flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  ::flatbuffers::Offset<Attribute> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = ::flatbuffers::Offset<Attribute>(end);
    return o;
  }
};

inline ::flatbuffers::Offset<Attribute> CreateAttribute(
    ::flatbuffers::FlatBufferBuilder &_fbb,
    ::flatbuffers::Offset<::flatbuffers::Vector<::flatbuffers::Offset<fb::AttributeRow>>> Attributes = 0) {
  AttributeBuilder builder_(_fbb);
  builder_.add_Attributes(Attributes);
  return builder_.Finish();
}

inline ::flatbuffers::Offset<Attribute> CreateAttributeDirect(
    ::flatbuffers::FlatBufferBuilder &_fbb,
    std::vector<::flatbuffers::Offset<fb::AttributeRow>> *Attributes = nullptr) {
  auto Attributes__ = Attributes ? _fbb.CreateVectorOfSortedTables<fb::AttributeRow>(Attributes) : 0;
  return fb::CreateAttribute(
      _fbb,
      Attributes__);
}

::flatbuffers::Offset<Attribute> CreateAttribute(::flatbuffers::FlatBufferBuilder &_fbb, const AttributeT *_o, const ::flatbuffers::rehasher_function_t *_rehasher = nullptr);

struct AttributeRowT : public ::flatbuffers::NativeTable {
  typedef AttributeRow TableType;
  fb::AttributeType Type = fb::AttributeType_NONE;
  float InitValue = 0.0f;
};

struct AttributeRow FLATBUFFERS_FINAL_CLASS : private ::flatbuffers::Table {
  typedef AttributeRowT NativeTableType;
  typedef AttributeRowBuilder Builder;
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_TYPE = 4,
    VT_INITVALUE = 6
  };
  fb::AttributeType Type() const {
    return static_cast<fb::AttributeType>(GetField<int32_t>(VT_TYPE, 0));
  }
  bool KeyCompareLessThan(const AttributeRow * const o) const {
    return Type() < o->Type();
  }
  int KeyCompareWithValue(int32_t _Type) const {
    return static_cast<int>(Type() > _Type) - static_cast<int>(Type() < _Type);
  }
  float InitValue() const {
    return GetField<float>(VT_INITVALUE, 0.0f);
  }
  bool Verify(::flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<int32_t>(verifier, VT_TYPE, 4) &&
           VerifyField<float>(verifier, VT_INITVALUE, 4) &&
           verifier.EndTable();
  }
  AttributeRowT *UnPack(const ::flatbuffers::resolver_function_t *_resolver = nullptr) const;
  void UnPackTo(AttributeRowT *_o, const ::flatbuffers::resolver_function_t *_resolver = nullptr) const;
  static ::flatbuffers::Offset<AttributeRow> Pack(::flatbuffers::FlatBufferBuilder &_fbb, const AttributeRowT* _o, const ::flatbuffers::rehasher_function_t *_rehasher = nullptr);
};

struct AttributeRowBuilder {
  typedef AttributeRow Table;
  ::flatbuffers::FlatBufferBuilder &fbb_;
  ::flatbuffers::uoffset_t start_;
  void add_Type(fb::AttributeType Type) {
    fbb_.AddElement<int32_t>(AttributeRow::VT_TYPE, static_cast<int32_t>(Type), 0);
  }
  void add_InitValue(float InitValue) {
    fbb_.AddElement<float>(AttributeRow::VT_INITVALUE, InitValue, 0.0f);
  }
  explicit AttributeRowBuilder(::flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  ::flatbuffers::Offset<AttributeRow> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = ::flatbuffers::Offset<AttributeRow>(end);
    return o;
  }
};

inline ::flatbuffers::Offset<AttributeRow> CreateAttributeRow(
    ::flatbuffers::FlatBufferBuilder &_fbb,
    fb::AttributeType Type = fb::AttributeType_NONE,
    float InitValue = 0.0f) {
  AttributeRowBuilder builder_(_fbb);
  builder_.add_InitValue(InitValue);
  builder_.add_Type(Type);
  return builder_.Finish();
}

::flatbuffers::Offset<AttributeRow> CreateAttributeRow(::flatbuffers::FlatBufferBuilder &_fbb, const AttributeRowT *_o, const ::flatbuffers::rehasher_function_t *_rehasher = nullptr);

inline AttributeT::AttributeT(const AttributeT &o) {
  Attributes.reserve(o.Attributes.size());
  for (const auto &Attributes_ : o.Attributes) { Attributes.emplace_back((Attributes_) ? new fb::AttributeRowT(*Attributes_) : nullptr); }
}

inline AttributeT &AttributeT::operator=(AttributeT o) FLATBUFFERS_NOEXCEPT {
  std::swap(Attributes, o.Attributes);
  return *this;
}

inline AttributeT *Attribute::UnPack(const ::flatbuffers::resolver_function_t *_resolver) const {
  auto _o = std::unique_ptr<AttributeT>(new AttributeT());
  UnPackTo(_o.get(), _resolver);
  return _o.release();
}

inline void Attribute::UnPackTo(AttributeT *_o, const ::flatbuffers::resolver_function_t *_resolver) const {
  (void)_o;
  (void)_resolver;
  { auto _e = Attributes(); if (_e) { _o->Attributes.resize(_e->size()); for (::flatbuffers::uoffset_t _i = 0; _i < _e->size(); _i++) { if(_o->Attributes[_i]) { _e->Get(_i)->UnPackTo(_o->Attributes[_i].get(), _resolver); } else { _o->Attributes[_i] = std::unique_ptr<fb::AttributeRowT>(_e->Get(_i)->UnPack(_resolver)); }; } } else { _o->Attributes.resize(0); } }
}

inline ::flatbuffers::Offset<Attribute> Attribute::Pack(::flatbuffers::FlatBufferBuilder &_fbb, const AttributeT* _o, const ::flatbuffers::rehasher_function_t *_rehasher) {
  return CreateAttribute(_fbb, _o, _rehasher);
}

inline ::flatbuffers::Offset<Attribute> CreateAttribute(::flatbuffers::FlatBufferBuilder &_fbb, const AttributeT *_o, const ::flatbuffers::rehasher_function_t *_rehasher) {
  (void)_rehasher;
  (void)_o;
  struct _VectorArgs { ::flatbuffers::FlatBufferBuilder *__fbb; const AttributeT* __o; const ::flatbuffers::rehasher_function_t *__rehasher; } _va = { &_fbb, _o, _rehasher}; (void)_va;
  auto _Attributes = _o->Attributes.size() ? _fbb.CreateVector<::flatbuffers::Offset<fb::AttributeRow>> (_o->Attributes.size(), [](size_t i, _VectorArgs *__va) { return CreateAttributeRow(*__va->__fbb, __va->__o->Attributes[i].get(), __va->__rehasher); }, &_va ) : 0;
  return fb::CreateAttribute(
      _fbb,
      _Attributes);
}

inline AttributeRowT *AttributeRow::UnPack(const ::flatbuffers::resolver_function_t *_resolver) const {
  auto _o = std::unique_ptr<AttributeRowT>(new AttributeRowT());
  UnPackTo(_o.get(), _resolver);
  return _o.release();
}

inline void AttributeRow::UnPackTo(AttributeRowT *_o, const ::flatbuffers::resolver_function_t *_resolver) const {
  (void)_o;
  (void)_resolver;
  { auto _e = Type(); _o->Type = _e; }
  { auto _e = InitValue(); _o->InitValue = _e; }
}

inline ::flatbuffers::Offset<AttributeRow> AttributeRow::Pack(::flatbuffers::FlatBufferBuilder &_fbb, const AttributeRowT* _o, const ::flatbuffers::rehasher_function_t *_rehasher) {
  return CreateAttributeRow(_fbb, _o, _rehasher);
}

inline ::flatbuffers::Offset<AttributeRow> CreateAttributeRow(::flatbuffers::FlatBufferBuilder &_fbb, const AttributeRowT *_o, const ::flatbuffers::rehasher_function_t *_rehasher) {
  (void)_rehasher;
  (void)_o;
  struct _VectorArgs { ::flatbuffers::FlatBufferBuilder *__fbb; const AttributeRowT* __o; const ::flatbuffers::rehasher_function_t *__rehasher; } _va = { &_fbb, _o, _rehasher}; (void)_va;
  auto _Type = _o->Type;
  auto _InitValue = _o->InitValue;
  return fb::CreateAttributeRow(
      _fbb,
      _Type,
      _InitValue);
}

inline const fb::Attribute *GetAttribute(const void *buf) {
  return ::flatbuffers::GetRoot<fb::Attribute>(buf);
}

inline const fb::Attribute *GetSizePrefixedAttribute(const void *buf) {
  return ::flatbuffers::GetSizePrefixedRoot<fb::Attribute>(buf);
}

inline bool VerifyAttributeBuffer(
    ::flatbuffers::Verifier &verifier) {
  return verifier.VerifyBuffer<fb::Attribute>(nullptr);
}

inline bool VerifySizePrefixedAttributeBuffer(
    ::flatbuffers::Verifier &verifier) {
  return verifier.VerifySizePrefixedBuffer<fb::Attribute>(nullptr);
}

inline void FinishAttributeBuffer(
    ::flatbuffers::FlatBufferBuilder &fbb,
    ::flatbuffers::Offset<fb::Attribute> root) {
  fbb.Finish(root);
}

inline void FinishSizePrefixedAttributeBuffer(
    ::flatbuffers::FlatBufferBuilder &fbb,
    ::flatbuffers::Offset<fb::Attribute> root) {
  fbb.FinishSizePrefixed(root);
}

inline std::unique_ptr<fb::AttributeT> UnPackAttribute(
    const void *buf,
    const ::flatbuffers::resolver_function_t *res = nullptr) {
  return std::unique_ptr<fb::AttributeT>(GetAttribute(buf)->UnPack(res));
}

inline std::unique_ptr<fb::AttributeT> UnPackSizePrefixedAttribute(
    const void *buf,
    const ::flatbuffers::resolver_function_t *res = nullptr) {
  return std::unique_ptr<fb::AttributeT>(GetSizePrefixedAttribute(buf)->UnPack(res));
}

}  // namespace fb

#endif  // FLATBUFFERS_GENERATED_ATTRIBUTE_FB_H_
