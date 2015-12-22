#include "rooibos/identifiers.hh"

#include <llvm/ADT/Twine.h>

using std::make_shared;
using std::shared_ptr;
using std::string;

using llvm::Instruction;
using llvm::Twine;

namespace
{
  shared_ptr<rooibos::IdentifierAST>
  mkid(const std::string & name)
  {
    return make_shared<rooibos::IdentifierAST>(name);
  }
}

namespace rooibos
{
  Identifiers::Identifiers()
  : adaptors(mkid("adaptors")),
    ArrayBuffer(mkid("ArrayBuffer")),
    ASM(mkid("ASM")),
    asm_(mkid("asm")),
    asmExtern(mkid("ASM")),
    ffi(mkid("ffi")),
    Float64Array(mkid("Float64Array")),
    FP(mkid("FP")),
    globals(mkid("globals")),
    heap(mkid("heap")),
    HEAP32(mkid("HEAP32")),
    HEAP64F(mkid("HEAP64F")),
    Int32Array(mkid("Int32Array")),
    SP(mkid("SP")),
    stdlib(mkid("stdlib")),
    this_(mkid("this"))
  {}

  IdentifierAST::ptr
  Identifiers::forFunction(const string & name)
  {
    return IdentifierAST::create("f_" + name);
  }

  IdentifierAST::ptr
  Identifiers::forFunctionExtern(const string & name)
  {
    return IdentifierAST::create(name);
  }

  IdentifierAST::ptr
  Identifiers::forInstruction(const Instruction & inst)
  {
    unsigned int id;
    if(_instIDMap.count(&inst))
    {
      id = _instIDMap[&inst];
    }
      else
    {
      id = _nextInstID++;
      _instIDMap[&inst] = id;
    }
    auto ident = ("l_" + Twine(id)).str();
    return IdentifierAST::create(ident);
  }

  IdentifierAST::ptr
  Identifiers::forParameter(const string & name)
  {
    return IdentifierAST::create("p_" + name);
  }

  IdentifierAST::ptr
  Identifiers::forStdlibFunc(const string & name)
  {
    return IdentifierAST::create("stdlib_" + name);
  }
}
