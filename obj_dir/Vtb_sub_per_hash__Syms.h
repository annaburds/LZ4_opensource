// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VTB_SUB_PER_HASH__SYMS_H_
#define VERILATED_VTB_SUB_PER_HASH__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vtb_sub_per_hash.h"

// INCLUDE MODULE CLASSES
#include "Vtb_sub_per_hash___024root.h"

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES) Vtb_sub_per_hash__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vtb_sub_per_hash* const __Vm_modelp;
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vtb_sub_per_hash___024root     TOP;

    // CONSTRUCTORS
    Vtb_sub_per_hash__Syms(VerilatedContext* contextp, const char* namep, Vtb_sub_per_hash* modelp);
    ~Vtb_sub_per_hash__Syms();

    // METHODS
    const char* name() const { return TOP.vlNamep; }
};

#endif  // guard
