// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vtb_sub_per_hash__pch.h"

//============================================================
// Constructors

Vtb_sub_per_hash::Vtb_sub_per_hash(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vtb_sub_per_hash__Syms(contextp(), _vcname__, this)}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vtb_sub_per_hash::Vtb_sub_per_hash(const char* _vcname__)
    : Vtb_sub_per_hash(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vtb_sub_per_hash::~Vtb_sub_per_hash() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vtb_sub_per_hash___024root___eval_debug_assertions(Vtb_sub_per_hash___024root* vlSelf);
#endif  // VL_DEBUG
void Vtb_sub_per_hash___024root___eval_static(Vtb_sub_per_hash___024root* vlSelf);
void Vtb_sub_per_hash___024root___eval_initial(Vtb_sub_per_hash___024root* vlSelf);
void Vtb_sub_per_hash___024root___eval_settle(Vtb_sub_per_hash___024root* vlSelf);
void Vtb_sub_per_hash___024root___eval(Vtb_sub_per_hash___024root* vlSelf);

void Vtb_sub_per_hash::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vtb_sub_per_hash::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vtb_sub_per_hash___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vtb_sub_per_hash___024root___eval_static(&(vlSymsp->TOP));
        Vtb_sub_per_hash___024root___eval_initial(&(vlSymsp->TOP));
        Vtb_sub_per_hash___024root___eval_settle(&(vlSymsp->TOP));
        vlSymsp->__Vm_didInit = true;
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vtb_sub_per_hash___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vtb_sub_per_hash::eventsPending() { return !vlSymsp->TOP.__VdlySched.empty() && !contextp()->gotFinish(); }

uint64_t Vtb_sub_per_hash::nextTimeSlot() { return vlSymsp->TOP.__VdlySched.nextTimeSlot(); }

//============================================================
// Utilities

const char* Vtb_sub_per_hash::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vtb_sub_per_hash___024root___eval_final(Vtb_sub_per_hash___024root* vlSelf);

VL_ATTR_COLD void Vtb_sub_per_hash::final() {
    contextp()->executingFinal(true);
    Vtb_sub_per_hash___024root___eval_final(&(vlSymsp->TOP));
    contextp()->executingFinal(false);
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vtb_sub_per_hash::hierName() const { return vlSymsp->name(); }
const char* Vtb_sub_per_hash::modelName() const { return "Vtb_sub_per_hash"; }
unsigned Vtb_sub_per_hash::threads() const { return 1; }
void Vtb_sub_per_hash::prepareClone() const { contextp()->prepareClone(); }
void Vtb_sub_per_hash::atClone() const {
    contextp()->threadPoolpOnClone();
}
