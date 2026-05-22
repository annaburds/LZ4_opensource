// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtb_sub_per_hash.h for the primary calling header

#ifndef VERILATED_VTB_SUB_PER_HASH___024ROOT_H_
#define VERILATED_VTB_SUB_PER_HASH___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vtb_sub_per_hash__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtb_sub_per_hash___024root final {
  public:

    // DESIGN SPECIFIC STATE
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __VstlPhaseResult;
    CData/*0:0*/ __VactPhaseResult;
    CData/*0:0*/ __VinactPhaseResult;
    CData/*0:0*/ __VnbaPhaseResult;
    IData/*31:0*/ tb_sub_per_hash__DOT__data_i;
    IData/*31:0*/ tb_sub_per_hash__DOT__DUT__DOT__permuted;
    IData/*31:0*/ tb_sub_per_hash__DOT__DUT__DOT__xored;
    IData/*31:0*/ __VactIterCount;
    IData/*31:0*/ __VinactIterCount;
    IData/*31:0*/ __Vi;
    VlUnpacked<VlUnpacked<IData/*31:0*/, 32>, 1> tb_sub_per_hash__DOT__DUT__DOT__Permutations;
    VlUnpacked<VlUnpacked<VlUnpacked<IData/*31:0*/, 3>, 32>, 1> tb_sub_per_hash__DOT__DUT__DOT__XorStages;
    VlUnpacked<QData/*63:0*/, 1> __VstlTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VactTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VactTriggeredAcc;
    VlUnpacked<QData/*63:0*/, 1> __VnbaTriggered;
    VlDelayScheduler __VdlySched;

    // INTERNAL VARIABLES
    Vtb_sub_per_hash__Syms* vlSymsp;
    const char* vlNamep;

    // CONSTRUCTORS
    Vtb_sub_per_hash___024root(Vtb_sub_per_hash__Syms* symsp, const char* namep);
    ~Vtb_sub_per_hash___024root();
    VL_UNCOPYABLE(Vtb_sub_per_hash___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
