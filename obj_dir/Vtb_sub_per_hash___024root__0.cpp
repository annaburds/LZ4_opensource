// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_sub_per_hash.h for the primary calling header

#include "Vtb_sub_per_hash__pch.h"

VL_ATTR_COLD void Vtb_sub_per_hash___024root___eval_initial__TOP(Vtb_sub_per_hash___024root* vlSelf);
VlCoroutine Vtb_sub_per_hash___024root___eval_initial__TOP__Vtiming__0(Vtb_sub_per_hash___024root* vlSelf);

void Vtb_sub_per_hash___024root___eval_initial(Vtb_sub_per_hash___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_sub_per_hash___024root___eval_initial\n"); );
    Vtb_sub_per_hash__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtb_sub_per_hash___024root___eval_initial__TOP(vlSelf);
    Vtb_sub_per_hash___024root___eval_initial__TOP__Vtiming__0(vlSelf);
}

VlCoroutine Vtb_sub_per_hash___024root___eval_initial__TOP__Vtiming__0(Vtb_sub_per_hash___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_sub_per_hash___024root___eval_initial__TOP__Vtiming__0\n"); );
    Vtb_sub_per_hash__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSymsp->_vm_contextp__->dumpfile("wave.vcd"s);
    VL_PRINTF_MT("-Info: sv/tb_sub_per_hash.sv:17: $dumpvar ignored, as Verilated without --trace\n");
    vlSelfRef.tb_sub_per_hash__DOT__data_i = 0U;
    co_await vlSelfRef.__VdlySched.delay(1ULL, nullptr, 
                                         "sv/tb_sub_per_hash.sv", 
                                         21);
    VL_WRITEF_NX("data word 0x%h --> hash 0x%h\n",2
                 , '#',32,vlSelfRef.tb_sub_per_hash__DOT__data_i
                 , '#',5,(0x0000001fU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__xored));
    vlSelfRef.tb_sub_per_hash__DOT__data_i = 0xffffffffU;
    co_await vlSelfRef.__VdlySched.delay(1ULL, nullptr, 
                                         "sv/tb_sub_per_hash.sv", 
                                         25);
    VL_WRITEF_NX("data word 0x%h --> hash 0x%h\n",2
                 , '#',32,vlSelfRef.tb_sub_per_hash__DOT__data_i
                 , '#',5,(0x0000001fU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__xored));
    vlSelfRef.tb_sub_per_hash__DOT__data_i = 0xdeadbeefU;
    co_await vlSelfRef.__VdlySched.delay(1ULL, nullptr, 
                                         "sv/tb_sub_per_hash.sv", 
                                         30);
    VL_WRITEF_NX("data word 0x%h --> hash 0x%h\n",2
                 , '#',32,vlSelfRef.tb_sub_per_hash__DOT__data_i
                 , '#',5,(0x0000001fU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__xored));
    VL_FINISH_MT("sv/tb_sub_per_hash.sv", 33, "");
    co_return;
}

void Vtb_sub_per_hash___024root___eval_triggers_vec__act(Vtb_sub_per_hash___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_sub_per_hash___024root___eval_triggers_vec__act\n"); );
    Vtb_sub_per_hash__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered[0U] = (QData)((IData)(vlSelfRef.__VdlySched.awaitingCurrentTime()));
}

bool Vtb_sub_per_hash___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_sub_per_hash___024root___trigger_anySet__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        if (in[n]) {
            return (1U);
        }
        n = ((IData)(1U) + n);
    } while ((1U > n));
    return (0U);
}

void Vtb_sub_per_hash___024root___act_sequent__TOP__0(Vtb_sub_per_hash___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_sub_per_hash___024root___act_sequent__TOP__0\n"); );
    Vtb_sub_per_hash__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__permuted 
        = ((0xfffffffeU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__permuted) 
           | (1U & (vlSelfRef.tb_sub_per_hash__DOT__data_i 
                    >> (0x0000001fU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__Permutations[0U][0U]))));
    vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__permuted 
        = ((0xfffffffdU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__permuted) 
           | (2U & ((vlSelfRef.tb_sub_per_hash__DOT__data_i 
                     >> (0x0000001fU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__Permutations[0U][1U])) 
                    << 1U)));
    vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__permuted 
        = ((0xfffffffbU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__permuted) 
           | (4U & ((vlSelfRef.tb_sub_per_hash__DOT__data_i 
                     >> (0x0000001fU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__Permutations[0U][2U])) 
                    << 2U)));
    vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__permuted 
        = ((0xfffffff7U & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__permuted) 
           | (8U & ((vlSelfRef.tb_sub_per_hash__DOT__data_i 
                     >> (0x0000001fU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__Permutations[0U][3U])) 
                    << 3U)));
    vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__permuted 
        = ((0xffffffefU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__permuted) 
           | (0x00000010U & ((vlSelfRef.tb_sub_per_hash__DOT__data_i 
                              >> (0x0000001fU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__Permutations[0U][4U])) 
                             << 4U)));
    vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__permuted 
        = ((0xffffffdfU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__permuted) 
           | (0x00000020U & ((vlSelfRef.tb_sub_per_hash__DOT__data_i 
                              >> (0x0000001fU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__Permutations[0U][5U])) 
                             << 5U)));
    vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__permuted 
        = ((0xffffffbfU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__permuted) 
           | (0x00000040U & ((vlSelfRef.tb_sub_per_hash__DOT__data_i 
                              >> (0x0000001fU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__Permutations[0U][6U])) 
                             << 6U)));
    vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__permuted 
        = ((0xffffff7fU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__permuted) 
           | (0x00000080U & ((vlSelfRef.tb_sub_per_hash__DOT__data_i 
                              >> (0x0000001fU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__Permutations[0U][7U])) 
                             << 7U)));
    vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__permuted 
        = ((0xfffffeffU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__permuted) 
           | (0x00000100U & ((vlSelfRef.tb_sub_per_hash__DOT__data_i 
                              >> (0x0000001fU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__Permutations[0U][8U])) 
                             << 8U)));
    vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__permuted 
        = ((0xfffffdffU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__permuted) 
           | (0x00000200U & ((vlSelfRef.tb_sub_per_hash__DOT__data_i 
                              >> (0x0000001fU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__Permutations[0U][9U])) 
                             << 9U)));
    vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__permuted 
        = ((0xfffffbffU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__permuted) 
           | (0x00000400U & ((vlSelfRef.tb_sub_per_hash__DOT__data_i 
                              >> (0x0000001fU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__Permutations[0U][10U])) 
                             << 0x0000000aU)));
    vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__permuted 
        = ((0xfffff7ffU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__permuted) 
           | (0x00000800U & ((vlSelfRef.tb_sub_per_hash__DOT__data_i 
                              >> (0x0000001fU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__Permutations[0U][11U])) 
                             << 0x0000000bU)));
    vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__permuted 
        = ((0xffffefffU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__permuted) 
           | (0x00001000U & ((vlSelfRef.tb_sub_per_hash__DOT__data_i 
                              >> (0x0000001fU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__Permutations[0U][12U])) 
                             << 0x0000000cU)));
    vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__permuted 
        = ((0xffffdfffU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__permuted) 
           | (0x00002000U & ((vlSelfRef.tb_sub_per_hash__DOT__data_i 
                              >> (0x0000001fU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__Permutations[0U][13U])) 
                             << 0x0000000dU)));
    vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__permuted 
        = ((0xffffbfffU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__permuted) 
           | (0x00004000U & ((vlSelfRef.tb_sub_per_hash__DOT__data_i 
                              >> (0x0000001fU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__Permutations[0U][14U])) 
                             << 0x0000000eU)));
    vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__permuted 
        = ((0xffff7fffU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__permuted) 
           | (0x00008000U & ((vlSelfRef.tb_sub_per_hash__DOT__data_i 
                              >> (0x0000001fU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__Permutations[0U][15U])) 
                             << 0x0000000fU)));
    vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__permuted 
        = ((0xfffeffffU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__permuted) 
           | (0x00010000U & ((vlSelfRef.tb_sub_per_hash__DOT__data_i 
                              >> (0x0000001fU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__Permutations[0U][16U])) 
                             << 0x00000010U)));
    vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__permuted 
        = ((0xfffdffffU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__permuted) 
           | (0x00020000U & ((vlSelfRef.tb_sub_per_hash__DOT__data_i 
                              >> (0x0000001fU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__Permutations[0U][17U])) 
                             << 0x00000011U)));
    vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__permuted 
        = ((0xfffbffffU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__permuted) 
           | (0x00040000U & ((vlSelfRef.tb_sub_per_hash__DOT__data_i 
                              >> (0x0000001fU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__Permutations[0U][18U])) 
                             << 0x00000012U)));
    vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__permuted 
        = ((0xfff7ffffU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__permuted) 
           | (0x00080000U & ((vlSelfRef.tb_sub_per_hash__DOT__data_i 
                              >> (0x0000001fU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__Permutations[0U][19U])) 
                             << 0x00000013U)));
    vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__permuted 
        = ((0xffefffffU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__permuted) 
           | (0x00100000U & ((vlSelfRef.tb_sub_per_hash__DOT__data_i 
                              >> (0x0000001fU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__Permutations[0U][20U])) 
                             << 0x00000014U)));
    vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__permuted 
        = ((0xffdfffffU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__permuted) 
           | (0x00200000U & ((vlSelfRef.tb_sub_per_hash__DOT__data_i 
                              >> (0x0000001fU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__Permutations[0U][21U])) 
                             << 0x00000015U)));
    vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__permuted 
        = ((0xffbfffffU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__permuted) 
           | (0x00400000U & ((vlSelfRef.tb_sub_per_hash__DOT__data_i 
                              >> (0x0000001fU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__Permutations[0U][22U])) 
                             << 0x00000016U)));
    vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__permuted 
        = ((0xff7fffffU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__permuted) 
           | (0x00800000U & ((vlSelfRef.tb_sub_per_hash__DOT__data_i 
                              >> (0x0000001fU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__Permutations[0U][23U])) 
                             << 0x00000017U)));
    vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__permuted 
        = ((0xfeffffffU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__permuted) 
           | (0x01000000U & ((vlSelfRef.tb_sub_per_hash__DOT__data_i 
                              >> (0x0000001fU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__Permutations[0U][24U])) 
                             << 0x00000018U)));
    vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__permuted 
        = ((0xfdffffffU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__permuted) 
           | (0x02000000U & ((vlSelfRef.tb_sub_per_hash__DOT__data_i 
                              >> (0x0000001fU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__Permutations[0U][25U])) 
                             << 0x00000019U)));
    vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__permuted 
        = ((0xfbffffffU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__permuted) 
           | (0x04000000U & ((vlSelfRef.tb_sub_per_hash__DOT__data_i 
                              >> (0x0000001fU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__Permutations[0U][26U])) 
                             << 0x0000001aU)));
    vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__permuted 
        = ((0xf7ffffffU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__permuted) 
           | (0x08000000U & ((vlSelfRef.tb_sub_per_hash__DOT__data_i 
                              >> (0x0000001fU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__Permutations[0U][27U])) 
                             << 0x0000001bU)));
    vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__permuted 
        = ((0xefffffffU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__permuted) 
           | (0x10000000U & ((vlSelfRef.tb_sub_per_hash__DOT__data_i 
                              >> (0x0000001fU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__Permutations[0U][28U])) 
                             << 0x0000001cU)));
    vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__permuted 
        = ((0xdfffffffU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__permuted) 
           | (0x20000000U & ((vlSelfRef.tb_sub_per_hash__DOT__data_i 
                              >> (0x0000001fU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__Permutations[0U][29U])) 
                             << 0x0000001dU)));
    vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__permuted 
        = ((0xbfffffffU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__permuted) 
           | (0x40000000U & ((vlSelfRef.tb_sub_per_hash__DOT__data_i 
                              >> (0x0000001fU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__Permutations[0U][30U])) 
                             << 0x0000001eU)));
    vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__permuted 
        = ((0x7fffffffU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__permuted) 
           | ((vlSelfRef.tb_sub_per_hash__DOT__data_i 
               >> (0x0000001fU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__Permutations[0U][31U])) 
              << 0x0000001fU));
    vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__xored 
        = ((0xfffffffeU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__xored) 
           | (1U & (((vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__permuted 
                      >> (0x0000001fU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__XorStages[0U][0U][0U])) 
                     ^ (vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__permuted 
                        >> (0x0000001fU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__XorStages[0U][0U][1U]))) 
                    ^ (vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__permuted 
                       >> (0x0000001fU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__XorStages[0U][0U][2U])))));
    vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__xored 
        = ((0xfffffffdU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__xored) 
           | (2U & ((((vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__permuted 
                       >> (0x0000001fU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__XorStages[0U][1U][0U])) 
                      ^ (vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__permuted 
                         >> (0x0000001fU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__XorStages[0U][1U][1U]))) 
                     ^ (vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__permuted 
                        >> (0x0000001fU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__XorStages[0U][1U][2U]))) 
                    << 1U)));
    vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__xored 
        = ((0xfffffffbU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__xored) 
           | (4U & ((((vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__permuted 
                       >> (0x0000001fU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__XorStages[0U][2U][0U])) 
                      ^ (vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__permuted 
                         >> (0x0000001fU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__XorStages[0U][2U][1U]))) 
                     ^ (vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__permuted 
                        >> (0x0000001fU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__XorStages[0U][2U][2U]))) 
                    << 2U)));
    vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__xored 
        = ((0xfffffff7U & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__xored) 
           | (8U & ((((vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__permuted 
                       >> (0x0000001fU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__XorStages[0U][3U][0U])) 
                      ^ (vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__permuted 
                         >> (0x0000001fU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__XorStages[0U][3U][1U]))) 
                     ^ (vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__permuted 
                        >> (0x0000001fU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__XorStages[0U][3U][2U]))) 
                    << 3U)));
    vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__xored 
        = ((0xffffffefU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__xored) 
           | (0x00000010U & ((((vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__permuted 
                                >> (0x0000001fU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__XorStages[0U][4U][0U])) 
                               ^ (vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__permuted 
                                  >> (0x0000001fU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__XorStages[0U][4U][1U]))) 
                              ^ (vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__permuted 
                                 >> (0x0000001fU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__XorStages[0U][4U][2U]))) 
                             << 4U)));
    vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__xored 
        = ((0xffffffdfU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__xored) 
           | (0x00000020U & ((((vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__permuted 
                                >> (0x0000001fU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__XorStages[0U][5U][0U])) 
                               ^ (vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__permuted 
                                  >> (0x0000001fU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__XorStages[0U][5U][1U]))) 
                              ^ (vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__permuted 
                                 >> (0x0000001fU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__XorStages[0U][5U][2U]))) 
                             << 5U)));
    vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__xored 
        = ((0xffffffbfU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__xored) 
           | (0x00000040U & ((((vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__permuted 
                                >> (0x0000001fU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__XorStages[0U][6U][0U])) 
                               ^ (vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__permuted 
                                  >> (0x0000001fU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__XorStages[0U][6U][1U]))) 
                              ^ (vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__permuted 
                                 >> (0x0000001fU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__XorStages[0U][6U][2U]))) 
                             << 6U)));
    vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__xored 
        = ((0xffffff7fU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__xored) 
           | (0x00000080U & ((((vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__permuted 
                                >> (0x0000001fU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__XorStages[0U][7U][0U])) 
                               ^ (vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__permuted 
                                  >> (0x0000001fU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__XorStages[0U][7U][1U]))) 
                              ^ (vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__permuted 
                                 >> (0x0000001fU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__XorStages[0U][7U][2U]))) 
                             << 7U)));
    vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__xored 
        = ((0xfffffeffU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__xored) 
           | (0x00000100U & ((((vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__permuted 
                                >> (0x0000001fU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__XorStages[0U][8U][0U])) 
                               ^ (vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__permuted 
                                  >> (0x0000001fU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__XorStages[0U][8U][1U]))) 
                              ^ (vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__permuted 
                                 >> (0x0000001fU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__XorStages[0U][8U][2U]))) 
                             << 8U)));
    vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__xored 
        = ((0xfffffdffU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__xored) 
           | (0x00000200U & ((((vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__permuted 
                                >> (0x0000001fU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__XorStages[0U][9U][0U])) 
                               ^ (vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__permuted 
                                  >> (0x0000001fU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__XorStages[0U][9U][1U]))) 
                              ^ (vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__permuted 
                                 >> (0x0000001fU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__XorStages[0U][9U][2U]))) 
                             << 9U)));
    vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__xored 
        = ((0xfffffbffU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__xored) 
           | (0x00000400U & ((((vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__permuted 
                                >> (0x0000001fU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__XorStages[0U][10U][0U])) 
                               ^ (vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__permuted 
                                  >> (0x0000001fU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__XorStages[0U][10U][1U]))) 
                              ^ (vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__permuted 
                                 >> (0x0000001fU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__XorStages[0U][10U][2U]))) 
                             << 0x0000000aU)));
    vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__xored 
        = ((0xfffff7ffU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__xored) 
           | (0x00000800U & ((((vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__permuted 
                                >> (0x0000001fU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__XorStages[0U][11U][0U])) 
                               ^ (vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__permuted 
                                  >> (0x0000001fU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__XorStages[0U][11U][1U]))) 
                              ^ (vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__permuted 
                                 >> (0x0000001fU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__XorStages[0U][11U][2U]))) 
                             << 0x0000000bU)));
    vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__xored 
        = ((0xffffefffU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__xored) 
           | (0x00001000U & ((((vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__permuted 
                                >> (0x0000001fU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__XorStages[0U][12U][0U])) 
                               ^ (vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__permuted 
                                  >> (0x0000001fU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__XorStages[0U][12U][1U]))) 
                              ^ (vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__permuted 
                                 >> (0x0000001fU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__XorStages[0U][12U][2U]))) 
                             << 0x0000000cU)));
    vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__xored 
        = ((0xffffdfffU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__xored) 
           | (0x00002000U & ((((vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__permuted 
                                >> (0x0000001fU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__XorStages[0U][13U][0U])) 
                               ^ (vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__permuted 
                                  >> (0x0000001fU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__XorStages[0U][13U][1U]))) 
                              ^ (vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__permuted 
                                 >> (0x0000001fU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__XorStages[0U][13U][2U]))) 
                             << 0x0000000dU)));
    vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__xored 
        = ((0xffffbfffU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__xored) 
           | (0x00004000U & ((((vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__permuted 
                                >> (0x0000001fU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__XorStages[0U][14U][0U])) 
                               ^ (vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__permuted 
                                  >> (0x0000001fU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__XorStages[0U][14U][1U]))) 
                              ^ (vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__permuted 
                                 >> (0x0000001fU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__XorStages[0U][14U][2U]))) 
                             << 0x0000000eU)));
    vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__xored 
        = ((0xffff7fffU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__xored) 
           | (0x00008000U & ((((vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__permuted 
                                >> (0x0000001fU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__XorStages[0U][15U][0U])) 
                               ^ (vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__permuted 
                                  >> (0x0000001fU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__XorStages[0U][15U][1U]))) 
                              ^ (vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__permuted 
                                 >> (0x0000001fU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__XorStages[0U][15U][2U]))) 
                             << 0x0000000fU)));
    vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__xored 
        = ((0xfffeffffU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__xored) 
           | (0x00010000U & ((((vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__permuted 
                                >> (0x0000001fU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__XorStages[0U][16U][0U])) 
                               ^ (vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__permuted 
                                  >> (0x0000001fU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__XorStages[0U][16U][1U]))) 
                              ^ (vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__permuted 
                                 >> (0x0000001fU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__XorStages[0U][16U][2U]))) 
                             << 0x00000010U)));
    vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__xored 
        = ((0xfffdffffU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__xored) 
           | (0x00020000U & ((((vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__permuted 
                                >> (0x0000001fU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__XorStages[0U][17U][0U])) 
                               ^ (vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__permuted 
                                  >> (0x0000001fU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__XorStages[0U][17U][1U]))) 
                              ^ (vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__permuted 
                                 >> (0x0000001fU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__XorStages[0U][17U][2U]))) 
                             << 0x00000011U)));
    vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__xored 
        = ((0xfffbffffU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__xored) 
           | (0x00040000U & ((((vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__permuted 
                                >> (0x0000001fU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__XorStages[0U][18U][0U])) 
                               ^ (vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__permuted 
                                  >> (0x0000001fU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__XorStages[0U][18U][1U]))) 
                              ^ (vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__permuted 
                                 >> (0x0000001fU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__XorStages[0U][18U][2U]))) 
                             << 0x00000012U)));
    vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__xored 
        = ((0xfff7ffffU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__xored) 
           | (0x00080000U & ((((vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__permuted 
                                >> (0x0000001fU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__XorStages[0U][19U][0U])) 
                               ^ (vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__permuted 
                                  >> (0x0000001fU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__XorStages[0U][19U][1U]))) 
                              ^ (vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__permuted 
                                 >> (0x0000001fU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__XorStages[0U][19U][2U]))) 
                             << 0x00000013U)));
    vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__xored 
        = ((0xffefffffU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__xored) 
           | (0x00100000U & ((((vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__permuted 
                                >> (0x0000001fU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__XorStages[0U][20U][0U])) 
                               ^ (vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__permuted 
                                  >> (0x0000001fU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__XorStages[0U][20U][1U]))) 
                              ^ (vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__permuted 
                                 >> (0x0000001fU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__XorStages[0U][20U][2U]))) 
                             << 0x00000014U)));
    vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__xored 
        = ((0xffdfffffU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__xored) 
           | (0x00200000U & ((((vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__permuted 
                                >> (0x0000001fU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__XorStages[0U][21U][0U])) 
                               ^ (vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__permuted 
                                  >> (0x0000001fU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__XorStages[0U][21U][1U]))) 
                              ^ (vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__permuted 
                                 >> (0x0000001fU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__XorStages[0U][21U][2U]))) 
                             << 0x00000015U)));
    vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__xored 
        = ((0xffbfffffU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__xored) 
           | (0x00400000U & ((((vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__permuted 
                                >> (0x0000001fU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__XorStages[0U][22U][0U])) 
                               ^ (vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__permuted 
                                  >> (0x0000001fU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__XorStages[0U][22U][1U]))) 
                              ^ (vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__permuted 
                                 >> (0x0000001fU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__XorStages[0U][22U][2U]))) 
                             << 0x00000016U)));
    vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__xored 
        = ((0xff7fffffU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__xored) 
           | (0x00800000U & ((((vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__permuted 
                                >> (0x0000001fU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__XorStages[0U][23U][0U])) 
                               ^ (vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__permuted 
                                  >> (0x0000001fU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__XorStages[0U][23U][1U]))) 
                              ^ (vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__permuted 
                                 >> (0x0000001fU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__XorStages[0U][23U][2U]))) 
                             << 0x00000017U)));
    vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__xored 
        = ((0xfeffffffU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__xored) 
           | (0x01000000U & ((((vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__permuted 
                                >> (0x0000001fU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__XorStages[0U][24U][0U])) 
                               ^ (vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__permuted 
                                  >> (0x0000001fU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__XorStages[0U][24U][1U]))) 
                              ^ (vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__permuted 
                                 >> (0x0000001fU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__XorStages[0U][24U][2U]))) 
                             << 0x00000018U)));
    vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__xored 
        = ((0xfdffffffU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__xored) 
           | (0x02000000U & ((((vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__permuted 
                                >> (0x0000001fU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__XorStages[0U][25U][0U])) 
                               ^ (vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__permuted 
                                  >> (0x0000001fU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__XorStages[0U][25U][1U]))) 
                              ^ (vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__permuted 
                                 >> (0x0000001fU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__XorStages[0U][25U][2U]))) 
                             << 0x00000019U)));
    vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__xored 
        = ((0xfbffffffU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__xored) 
           | (0x04000000U & ((((vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__permuted 
                                >> (0x0000001fU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__XorStages[0U][26U][0U])) 
                               ^ (vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__permuted 
                                  >> (0x0000001fU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__XorStages[0U][26U][1U]))) 
                              ^ (vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__permuted 
                                 >> (0x0000001fU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__XorStages[0U][26U][2U]))) 
                             << 0x0000001aU)));
    vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__xored 
        = ((0xf7ffffffU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__xored) 
           | (0x08000000U & ((((vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__permuted 
                                >> (0x0000001fU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__XorStages[0U][27U][0U])) 
                               ^ (vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__permuted 
                                  >> (0x0000001fU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__XorStages[0U][27U][1U]))) 
                              ^ (vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__permuted 
                                 >> (0x0000001fU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__XorStages[0U][27U][2U]))) 
                             << 0x0000001bU)));
    vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__xored 
        = ((0xefffffffU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__xored) 
           | (0x10000000U & ((((vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__permuted 
                                >> (0x0000001fU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__XorStages[0U][28U][0U])) 
                               ^ (vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__permuted 
                                  >> (0x0000001fU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__XorStages[0U][28U][1U]))) 
                              ^ (vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__permuted 
                                 >> (0x0000001fU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__XorStages[0U][28U][2U]))) 
                             << 0x0000001cU)));
    vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__xored 
        = ((0xdfffffffU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__xored) 
           | (0x20000000U & ((((vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__permuted 
                                >> (0x0000001fU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__XorStages[0U][29U][0U])) 
                               ^ (vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__permuted 
                                  >> (0x0000001fU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__XorStages[0U][29U][1U]))) 
                              ^ (vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__permuted 
                                 >> (0x0000001fU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__XorStages[0U][29U][2U]))) 
                             << 0x0000001dU)));
    vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__xored 
        = ((0xbfffffffU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__xored) 
           | (0x40000000U & ((((vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__permuted 
                                >> (0x0000001fU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__XorStages[0U][30U][0U])) 
                               ^ (vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__permuted 
                                  >> (0x0000001fU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__XorStages[0U][30U][1U]))) 
                              ^ (vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__permuted 
                                 >> (0x0000001fU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__XorStages[0U][30U][2U]))) 
                             << 0x0000001eU)));
    vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__xored 
        = ((0x7fffffffU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__xored) 
           | ((((vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__permuted 
                 >> (0x0000001fU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__XorStages[0U][31U][0U])) 
                ^ (vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__permuted 
                   >> (0x0000001fU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__XorStages[0U][31U][1U]))) 
               ^ (vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__permuted 
                  >> (0x0000001fU & vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__XorStages[0U][31U][2U]))) 
              << 0x0000001fU));
}

void Vtb_sub_per_hash___024root___eval_act(Vtb_sub_per_hash___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_sub_per_hash___024root___eval_act\n"); );
    Vtb_sub_per_hash__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VactTriggered[0U])) {
        Vtb_sub_per_hash___024root___act_sequent__TOP__0(vlSelf);
    }
}

void Vtb_sub_per_hash___024root___eval_nba(Vtb_sub_per_hash___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_sub_per_hash___024root___eval_nba\n"); );
    Vtb_sub_per_hash__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtb_sub_per_hash___024root___act_sequent__TOP__0(vlSelf);
    }
}

void Vtb_sub_per_hash___024root___timing_resume(Vtb_sub_per_hash___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_sub_per_hash___024root___timing_resume\n"); );
    Vtb_sub_per_hash__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VactTriggered[0U])) {
        vlSelfRef.__VdlySched.resume();
    }
}

void Vtb_sub_per_hash___024root___trigger_orInto__act_vec_vec(VlUnpacked<QData/*63:0*/, 1> &out, const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_sub_per_hash___024root___trigger_orInto__act_vec_vec\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = (out[n] | in[n]);
        n = ((IData)(1U) + n);
    } while ((0U >= n));
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_sub_per_hash___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

bool Vtb_sub_per_hash___024root___eval_phase__act(Vtb_sub_per_hash___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_sub_per_hash___024root___eval_phase__act\n"); );
    Vtb_sub_per_hash__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VactExecute;
    // Body
    Vtb_sub_per_hash___024root___eval_triggers_vec__act(vlSelf);
    Vtb_sub_per_hash___024root___trigger_orInto__act_vec_vec(vlSelfRef.__VactTriggered, vlSelfRef.__VactTriggeredAcc);
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtb_sub_per_hash___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
    }
#endif
    Vtb_sub_per_hash___024root___trigger_orInto__act_vec_vec(vlSelfRef.__VnbaTriggered, vlSelfRef.__VactTriggered);
    __VactExecute = Vtb_sub_per_hash___024root___trigger_anySet__act(vlSelfRef.__VactTriggered);
    if (__VactExecute) {
        vlSelfRef.__VactTriggeredAcc.fill(0ULL);
        Vtb_sub_per_hash___024root___timing_resume(vlSelf);
        Vtb_sub_per_hash___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vtb_sub_per_hash___024root___eval_phase__inact(Vtb_sub_per_hash___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_sub_per_hash___024root___eval_phase__inact\n"); );
    Vtb_sub_per_hash__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VinactExecute;
    // Body
    __VinactExecute = vlSelfRef.__VdlySched.awaitingZeroDelay();
    if (__VinactExecute) {
        VL_FATAL_MT("sv/tb_sub_per_hash.sv", 3, "", "ZERODLY: Design Verilated with '--no-sched-zero-delay', but #0 delay executed at runtime");
    }
    return (__VinactExecute);
}

void Vtb_sub_per_hash___024root___trigger_clear__act(VlUnpacked<QData/*63:0*/, 1> &out) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_sub_per_hash___024root___trigger_clear__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = 0ULL;
        n = ((IData)(1U) + n);
    } while ((1U > n));
}

bool Vtb_sub_per_hash___024root___eval_phase__nba(Vtb_sub_per_hash___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_sub_per_hash___024root___eval_phase__nba\n"); );
    Vtb_sub_per_hash__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = Vtb_sub_per_hash___024root___trigger_anySet__act(vlSelfRef.__VnbaTriggered);
    if (__VnbaExecute) {
        Vtb_sub_per_hash___024root___eval_nba(vlSelf);
        Vtb_sub_per_hash___024root___trigger_clear__act(vlSelfRef.__VnbaTriggered);
    }
    return (__VnbaExecute);
}

void Vtb_sub_per_hash___024root___eval(Vtb_sub_per_hash___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_sub_per_hash___024root___eval\n"); );
    Vtb_sub_per_hash__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VnbaIterCount;
    // Body
    __VnbaIterCount = 0U;
    do {
        if (VL_UNLIKELY(((0x00002710U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            Vtb_sub_per_hash___024root___dump_triggers__act(vlSelfRef.__VnbaTriggered, "nba"s);
#endif
            VL_FATAL_MT("sv/tb_sub_per_hash.sv", 3, "", "DIDNOTCONVERGE: NBA region did not converge after '--converge-limit' of 10000 tries");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        vlSelfRef.__VinactIterCount = 0U;
        do {
            if (VL_UNLIKELY(((0x00002710U < vlSelfRef.__VinactIterCount)))) {
                VL_FATAL_MT("sv/tb_sub_per_hash.sv", 3, "", "DIDNOTCONVERGE: Inactive region did not converge after '--converge-limit' of 10000 tries");
            }
            vlSelfRef.__VinactIterCount = ((IData)(1U) 
                                           + vlSelfRef.__VinactIterCount);
            vlSelfRef.__VactIterCount = 0U;
            do {
                if (VL_UNLIKELY(((0x00002710U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                    Vtb_sub_per_hash___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
#endif
                    VL_FATAL_MT("sv/tb_sub_per_hash.sv", 3, "", "DIDNOTCONVERGE: Active region did not converge after '--converge-limit' of 10000 tries");
                }
                vlSelfRef.__VactIterCount = ((IData)(1U) 
                                             + vlSelfRef.__VactIterCount);
                vlSelfRef.__VactPhaseResult = Vtb_sub_per_hash___024root___eval_phase__act(vlSelf);
            } while (vlSelfRef.__VactPhaseResult);
            vlSelfRef.__VinactPhaseResult = Vtb_sub_per_hash___024root___eval_phase__inact(vlSelf);
        } while (vlSelfRef.__VinactPhaseResult);
        vlSelfRef.__VnbaPhaseResult = Vtb_sub_per_hash___024root___eval_phase__nba(vlSelf);
    } while (vlSelfRef.__VnbaPhaseResult);
}

#ifdef VL_DEBUG
void Vtb_sub_per_hash___024root___eval_debug_assertions(Vtb_sub_per_hash___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_sub_per_hash___024root___eval_debug_assertions\n"); );
    Vtb_sub_per_hash__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}
#endif  // VL_DEBUG
