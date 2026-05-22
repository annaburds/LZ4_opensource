// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_sub_per_hash.h for the primary calling header

#include "Vtb_sub_per_hash__pch.h"

VL_ATTR_COLD void Vtb_sub_per_hash___024root___eval_static(Vtb_sub_per_hash___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_sub_per_hash___024root___eval_static\n"); );
    Vtb_sub_per_hash__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    do {
        vlSelfRef.__VactTriggeredAcc[vlSelfRef.__Vi] 
            = vlSelfRef.__VactTriggered[vlSelfRef.__Vi];
        vlSelfRef.__Vi = ((IData)(1U) + vlSelfRef.__Vi);
    } while ((0U >= vlSelfRef.__Vi));
}

VL_ATTR_COLD void Vtb_sub_per_hash___024root___eval_initial__TOP(Vtb_sub_per_hash___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_sub_per_hash___024root___eval_initial__TOP\n"); );
    Vtb_sub_per_hash__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    VlUnpacked<VlUnpacked<IData/*31:0*/, 32>, 1> __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0__Vfuncout;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 32; ++__Vi1) {
            __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0__Vfuncout[__Vi0][__Vi1] = 0;
        }
    }
    IData/*31:0*/ __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0____Vlvbound_hd428b41f__0;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0____Vlvbound_hd428b41f__0 = 0;
    IData/*31:0*/ __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0____Vlvbound_h12946a50__0;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0____Vlvbound_h12946a50__0 = 0;
    VlUnpacked<VlUnpacked<IData/*31:0*/, 32>, 1> __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0__indices;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 32; ++__Vi1) {
            __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0__indices[__Vi0][__Vi1] = 0;
        }
    }
    VlUnpacked<VlUnpacked<IData/*31:0*/, 32>, 1> __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0__perm_array;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 32; ++__Vi1) {
            __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0__perm_array[__Vi0][__Vi1] = 0;
        }
    }
    VlUnpacked<VlUnpacked<VlUnpacked<IData/*31:0*/, 3>, 32>, 1> __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_xor_stages__1__Vfuncout;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 32; ++__Vi1) {
            for (int __Vi2 = 0; __Vi2 < 3; ++__Vi2) {
                __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_xor_stages__1__Vfuncout[__Vi0][__Vi1][__Vi2] = 0;
            }
        }
    }
    VlUnpacked<VlUnpacked<VlUnpacked<IData/*31:0*/, 3>, 32>, 1> __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_xor_stages__1__xor_array;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 32; ++__Vi1) {
            for (int __Vi2 = 0; __Vi2 < 3; ++__Vi2) {
                __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_xor_stages__1__xor_array[__Vi0][__Vi1][__Vi2] = 0;
            }
        }
    }
    // Body
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 32; ++__Vi1) {
            __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0__indices[__Vi0][__Vi1] = 0;
        }
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 32; ++__Vi1) {
            __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0__perm_array[__Vi0][__Vi1] = 0;
        }
    }
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0__indices[0U][0U] = 0U;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0__indices[0U][1U] = 1U;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0__indices[0U][2U] = 2U;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0__indices[0U][3U] = 3U;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0__indices[0U][4U] = 4U;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0__indices[0U][5U] = 5U;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0__indices[0U][6U] = 6U;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0__indices[0U][7U] = 7U;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0__indices[0U][8U] = 8U;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0__indices[0U][9U] = 9U;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0__indices[0U][10U] = 0x0000000aU;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0__indices[0U][11U] = 0x0000000bU;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0__indices[0U][12U] = 0x0000000cU;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0__indices[0U][13U] = 0x0000000dU;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0__indices[0U][14U] = 0x0000000eU;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0__indices[0U][15U] = 0x0000000fU;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0__indices[0U][16U] = 0x00000010U;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0__indices[0U][17U] = 0x00000011U;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0__indices[0U][18U] = 0x00000012U;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0__indices[0U][19U] = 0x00000013U;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0__indices[0U][20U] = 0x00000014U;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0__indices[0U][21U] = 0x00000015U;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0__indices[0U][22U] = 0x00000016U;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0__indices[0U][23U] = 0x00000017U;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0__indices[0U][24U] = 0x00000018U;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0__indices[0U][25U] = 0x00000019U;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0__indices[0U][26U] = 0x0000001aU;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0__indices[0U][27U] = 0x0000001bU;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0__indices[0U][28U] = 0x0000001cU;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0__indices[0U][29U] = 0x0000001dU;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0__indices[0U][30U] = 0x0000001eU;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0__indices[0U][31U] = 0x0000001fU;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0____Vlvbound_h12946a50__0 
        = __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0__perm_array[0U][0U];
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0__perm_array[0U][1U] 
        = __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0____Vlvbound_h12946a50__0;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0____Vlvbound_hd428b41f__0 
        = __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0__indices[0U][1U];
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0__perm_array[0U][0U] 
        = __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0____Vlvbound_hd428b41f__0;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0____Vlvbound_h12946a50__0 
        = __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0__perm_array[0U][1U];
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0__perm_array[0U][2U] 
        = __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0____Vlvbound_h12946a50__0;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0____Vlvbound_hd428b41f__0 
        = __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0__indices[0U][2U];
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0__perm_array[0U][1U] 
        = __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0____Vlvbound_hd428b41f__0;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0____Vlvbound_h12946a50__0 
        = __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0__perm_array[0U][2U];
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0__perm_array[0U][3U] 
        = __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0____Vlvbound_h12946a50__0;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0____Vlvbound_hd428b41f__0 
        = __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0__indices[0U][3U];
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0__perm_array[0U][2U] 
        = __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0____Vlvbound_hd428b41f__0;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0____Vlvbound_h12946a50__0 
        = __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0__perm_array[0U][3U];
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0__perm_array[0U][4U] 
        = __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0____Vlvbound_h12946a50__0;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0____Vlvbound_hd428b41f__0 
        = __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0__indices[0U][4U];
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0__perm_array[0U][3U] 
        = __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0____Vlvbound_hd428b41f__0;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0____Vlvbound_h12946a50__0 
        = __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0__perm_array[0U][2U];
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0__perm_array[0U][5U] 
        = __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0____Vlvbound_h12946a50__0;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0____Vlvbound_hd428b41f__0 
        = __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0__indices[0U][5U];
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0__perm_array[0U][2U] 
        = __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0____Vlvbound_hd428b41f__0;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0____Vlvbound_h12946a50__0 
        = __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0__perm_array[0U][2U];
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0__perm_array[0U][6U] 
        = __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0____Vlvbound_h12946a50__0;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0____Vlvbound_hd428b41f__0 
        = __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0__indices[0U][6U];
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0__perm_array[0U][2U] 
        = __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0____Vlvbound_hd428b41f__0;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0____Vlvbound_h12946a50__0 
        = __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0__perm_array[0U][6U];
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0__perm_array[0U][7U] 
        = __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0____Vlvbound_h12946a50__0;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0____Vlvbound_hd428b41f__0 
        = __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0__indices[0U][7U];
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0__perm_array[0U][6U] 
        = __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0____Vlvbound_hd428b41f__0;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0____Vlvbound_h12946a50__0 
        = __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0__perm_array[0U][5U];
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0__perm_array[0U][8U] 
        = __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0____Vlvbound_h12946a50__0;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0____Vlvbound_hd428b41f__0 
        = __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0__indices[0U][8U];
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0__perm_array[0U][5U] 
        = __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0____Vlvbound_hd428b41f__0;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0____Vlvbound_h12946a50__0 
        = __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0__perm_array[0U][8U];
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0__perm_array[0U][9U] 
        = __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0____Vlvbound_h12946a50__0;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0____Vlvbound_hd428b41f__0 
        = __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0__indices[0U][9U];
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0__perm_array[0U][8U] 
        = __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0____Vlvbound_hd428b41f__0;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0____Vlvbound_h12946a50__0 
        = __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0__perm_array[0U][2U];
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0__perm_array[0U][10U] 
        = __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0____Vlvbound_h12946a50__0;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0____Vlvbound_hd428b41f__0 
        = __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0__indices[0U][10U];
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0__perm_array[0U][2U] 
        = __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0____Vlvbound_hd428b41f__0;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0____Vlvbound_h12946a50__0 
        = __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0__perm_array[0U][9U];
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0__perm_array[0U][11U] 
        = __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0____Vlvbound_h12946a50__0;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0____Vlvbound_hd428b41f__0 
        = __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0__indices[0U][11U];
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0__perm_array[0U][9U] 
        = __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0____Vlvbound_hd428b41f__0;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0____Vlvbound_h12946a50__0 
        = __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0__perm_array[0U][8U];
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0__perm_array[0U][12U] 
        = __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0____Vlvbound_h12946a50__0;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0____Vlvbound_hd428b41f__0 
        = __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0__indices[0U][12U];
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0__perm_array[0U][8U] 
        = __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0____Vlvbound_hd428b41f__0;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0____Vlvbound_h12946a50__0 
        = __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0__perm_array[0U][0U];
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0__perm_array[0U][13U] 
        = __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0____Vlvbound_h12946a50__0;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0____Vlvbound_hd428b41f__0 
        = __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0__indices[0U][13U];
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0__perm_array[0U][0U] 
        = __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0____Vlvbound_hd428b41f__0;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0____Vlvbound_h12946a50__0 
        = __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0__perm_array[0U][1U];
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0__perm_array[0U][14U] 
        = __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0____Vlvbound_h12946a50__0;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0____Vlvbound_hd428b41f__0 
        = __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0__indices[0U][14U];
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0__perm_array[0U][1U] 
        = __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0____Vlvbound_hd428b41f__0;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0____Vlvbound_h12946a50__0 
        = __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0__perm_array[0U][7U];
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0__perm_array[0U][15U] 
        = __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0____Vlvbound_h12946a50__0;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0____Vlvbound_hd428b41f__0 
        = __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0__indices[0U][15U];
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0__perm_array[0U][7U] 
        = __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0____Vlvbound_hd428b41f__0;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0____Vlvbound_h12946a50__0 
        = __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0__perm_array[0U][14U];
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0__perm_array[0U][16U] 
        = __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0____Vlvbound_h12946a50__0;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0____Vlvbound_hd428b41f__0 
        = __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0__indices[0U][16U];
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0__perm_array[0U][14U] 
        = __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0____Vlvbound_hd428b41f__0;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0____Vlvbound_h12946a50__0 
        = __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0__perm_array[0U][6U];
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0__perm_array[0U][17U] 
        = __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0____Vlvbound_h12946a50__0;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0____Vlvbound_hd428b41f__0 
        = __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0__indices[0U][17U];
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0__perm_array[0U][6U] 
        = __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0____Vlvbound_hd428b41f__0;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0____Vlvbound_h12946a50__0 
        = __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0__perm_array[0U][17U];
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0__perm_array[0U][18U] 
        = __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0____Vlvbound_h12946a50__0;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0____Vlvbound_hd428b41f__0 
        = __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0__indices[0U][18U];
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0__perm_array[0U][17U] 
        = __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0____Vlvbound_hd428b41f__0;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0____Vlvbound_h12946a50__0 
        = __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0__perm_array[0U][4U];
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0__perm_array[0U][19U] 
        = __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0____Vlvbound_h12946a50__0;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0____Vlvbound_hd428b41f__0 
        = __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0__indices[0U][19U];
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0__perm_array[0U][4U] 
        = __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0____Vlvbound_hd428b41f__0;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0____Vlvbound_h12946a50__0 
        = __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0__perm_array[0U][13U];
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0__perm_array[0U][20U] 
        = __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0____Vlvbound_h12946a50__0;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0____Vlvbound_hd428b41f__0 
        = __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0__indices[0U][20U];
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0__perm_array[0U][13U] 
        = __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0____Vlvbound_hd428b41f__0;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0____Vlvbound_h12946a50__0 
        = __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0__perm_array[0U][20U];
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0__perm_array[0U][21U] 
        = __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0____Vlvbound_h12946a50__0;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0____Vlvbound_hd428b41f__0 
        = __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0__indices[0U][21U];
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0__perm_array[0U][20U] 
        = __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0____Vlvbound_hd428b41f__0;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0____Vlvbound_h12946a50__0 
        = __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0__perm_array[0U][17U];
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0__perm_array[0U][22U] 
        = __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0____Vlvbound_h12946a50__0;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0____Vlvbound_hd428b41f__0 
        = __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0__indices[0U][22U];
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0__perm_array[0U][17U] 
        = __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0____Vlvbound_hd428b41f__0;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0____Vlvbound_h12946a50__0 
        = __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0__perm_array[0U][10U];
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0__perm_array[0U][23U] 
        = __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0____Vlvbound_h12946a50__0;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0____Vlvbound_hd428b41f__0 
        = __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0__indices[0U][23U];
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0__perm_array[0U][10U] 
        = __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0____Vlvbound_hd428b41f__0;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0____Vlvbound_h12946a50__0 
        = __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0__perm_array[0U][21U];
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0__perm_array[0U][24U] 
        = __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0____Vlvbound_h12946a50__0;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0____Vlvbound_hd428b41f__0 
        = __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0__indices[0U][24U];
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0__perm_array[0U][21U] 
        = __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0____Vlvbound_hd428b41f__0;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0____Vlvbound_h12946a50__0 
        = __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0__perm_array[0U][5U];
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0__perm_array[0U][25U] 
        = __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0____Vlvbound_h12946a50__0;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0____Vlvbound_hd428b41f__0 
        = __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0__indices[0U][25U];
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0__perm_array[0U][5U] 
        = __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0____Vlvbound_hd428b41f__0;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0____Vlvbound_h12946a50__0 
        = __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0__perm_array[0U][2U];
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0__perm_array[0U][26U] 
        = __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0____Vlvbound_h12946a50__0;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0____Vlvbound_hd428b41f__0 
        = __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0__indices[0U][26U];
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0__perm_array[0U][2U] 
        = __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0____Vlvbound_hd428b41f__0;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0____Vlvbound_h12946a50__0 
        = __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0__perm_array[0U][11U];
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0__perm_array[0U][27U] 
        = __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0____Vlvbound_h12946a50__0;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0____Vlvbound_hd428b41f__0 
        = __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0__indices[0U][27U];
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0__perm_array[0U][11U] 
        = __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0____Vlvbound_hd428b41f__0;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0____Vlvbound_h12946a50__0 
        = __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0__perm_array[0U][23U];
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0__perm_array[0U][28U] 
        = __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0____Vlvbound_h12946a50__0;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0____Vlvbound_hd428b41f__0 
        = __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0__indices[0U][28U];
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0__perm_array[0U][23U] 
        = __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0____Vlvbound_hd428b41f__0;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0____Vlvbound_h12946a50__0 
        = __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0__perm_array[0U][0U];
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0__perm_array[0U][29U] 
        = __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0____Vlvbound_h12946a50__0;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0____Vlvbound_hd428b41f__0 
        = __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0__indices[0U][29U];
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0__perm_array[0U][0U] 
        = __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0____Vlvbound_hd428b41f__0;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0____Vlvbound_h12946a50__0 
        = __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0__perm_array[0U][15U];
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0__perm_array[0U][30U] 
        = __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0____Vlvbound_h12946a50__0;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0____Vlvbound_hd428b41f__0 
        = __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0__indices[0U][30U];
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0__perm_array[0U][15U] 
        = __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0____Vlvbound_hd428b41f__0;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0____Vlvbound_h12946a50__0 
        = __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0__perm_array[0U][17U];
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0__perm_array[0U][31U] 
        = __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0____Vlvbound_h12946a50__0;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0____Vlvbound_hd428b41f__0 
        = __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0__indices[0U][31U];
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0__perm_array[0U][17U] 
        = __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0____Vlvbound_hd428b41f__0;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0__Vfuncout 
        = __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0__perm_array;
    vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__Permutations 
        = __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_permutations__0__Vfuncout;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 32; ++__Vi1) {
            for (int __Vi2 = 0; __Vi2 < 3; ++__Vi2) {
                __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_xor_stages__1__xor_array[__Vi0][__Vi1][__Vi2] = 0;
            }
        }
    }
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_xor_stages__1__xor_array[0U][0U][0U] = 3U;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_xor_stages__1__xor_array[0U][0U][1U] = 6U;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_xor_stages__1__xor_array[0U][0U][2U] = 0x0000000dU;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_xor_stages__1__xor_array[0U][1U][0U] = 7U;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_xor_stages__1__xor_array[0U][1U][1U] = 0x0000001aU;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_xor_stages__1__xor_array[0U][1U][2U] = 0x00000011U;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_xor_stages__1__xor_array[0U][2U][0U] = 0x0000000bU;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_xor_stages__1__xor_array[0U][2U][1U] = 0x0000000eU;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_xor_stages__1__xor_array[0U][2U][2U] = 0x00000015U;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_xor_stages__1__xor_array[0U][3U][0U] = 0x0000000fU;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_xor_stages__1__xor_array[0U][3U][1U] = 2U;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_xor_stages__1__xor_array[0U][3U][2U] = 0x00000019U;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_xor_stages__1__xor_array[0U][4U][0U] = 0x00000013U;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_xor_stages__1__xor_array[0U][4U][1U] = 0x00000016U;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_xor_stages__1__xor_array[0U][4U][2U] = 0x0000001dU;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_xor_stages__1__xor_array[0U][5U][0U] = 0x00000017U;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_xor_stages__1__xor_array[0U][5U][1U] = 0x0000000aU;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_xor_stages__1__xor_array[0U][5U][2U] = 1U;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_xor_stages__1__xor_array[0U][6U][0U] = 0x0000001bU;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_xor_stages__1__xor_array[0U][6U][1U] = 0x0000001eU;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_xor_stages__1__xor_array[0U][6U][2U] = 5U;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_xor_stages__1__xor_array[0U][7U][0U] = 0x0000001fU;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_xor_stages__1__xor_array[0U][7U][1U] = 0x00000012U;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_xor_stages__1__xor_array[0U][7U][2U] = 9U;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_xor_stages__1__xor_array[0U][8U][0U] = 3U;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_xor_stages__1__xor_array[0U][8U][1U] = 6U;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_xor_stages__1__xor_array[0U][8U][2U] = 0x0000000dU;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_xor_stages__1__xor_array[0U][9U][0U] = 7U;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_xor_stages__1__xor_array[0U][9U][1U] = 0x0000001aU;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_xor_stages__1__xor_array[0U][9U][2U] = 0x00000011U;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_xor_stages__1__xor_array[0U][10U][0U] = 0x0000000bU;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_xor_stages__1__xor_array[0U][10U][1U] = 0x0000000eU;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_xor_stages__1__xor_array[0U][10U][2U] = 0x00000015U;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_xor_stages__1__xor_array[0U][11U][0U] = 0x0000000fU;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_xor_stages__1__xor_array[0U][11U][1U] = 2U;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_xor_stages__1__xor_array[0U][11U][2U] = 0x00000019U;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_xor_stages__1__xor_array[0U][12U][0U] = 0x00000013U;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_xor_stages__1__xor_array[0U][12U][1U] = 0x00000016U;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_xor_stages__1__xor_array[0U][12U][2U] = 0x0000001dU;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_xor_stages__1__xor_array[0U][13U][0U] = 0x00000017U;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_xor_stages__1__xor_array[0U][13U][1U] = 0x0000000aU;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_xor_stages__1__xor_array[0U][13U][2U] = 1U;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_xor_stages__1__xor_array[0U][14U][0U] = 0x0000001bU;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_xor_stages__1__xor_array[0U][14U][1U] = 0x0000001eU;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_xor_stages__1__xor_array[0U][14U][2U] = 5U;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_xor_stages__1__xor_array[0U][15U][0U] = 0x0000001fU;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_xor_stages__1__xor_array[0U][15U][1U] = 0x00000012U;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_xor_stages__1__xor_array[0U][15U][2U] = 9U;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_xor_stages__1__xor_array[0U][16U][0U] = 3U;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_xor_stages__1__xor_array[0U][16U][1U] = 6U;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_xor_stages__1__xor_array[0U][16U][2U] = 0x0000000dU;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_xor_stages__1__xor_array[0U][17U][0U] = 7U;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_xor_stages__1__xor_array[0U][17U][1U] = 0x0000001aU;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_xor_stages__1__xor_array[0U][17U][2U] = 0x00000011U;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_xor_stages__1__xor_array[0U][18U][0U] = 0x0000000bU;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_xor_stages__1__xor_array[0U][18U][1U] = 0x0000000eU;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_xor_stages__1__xor_array[0U][18U][2U] = 0x00000015U;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_xor_stages__1__xor_array[0U][19U][0U] = 0x0000000fU;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_xor_stages__1__xor_array[0U][19U][1U] = 2U;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_xor_stages__1__xor_array[0U][19U][2U] = 0x00000019U;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_xor_stages__1__xor_array[0U][20U][0U] = 0x00000013U;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_xor_stages__1__xor_array[0U][20U][1U] = 0x00000016U;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_xor_stages__1__xor_array[0U][20U][2U] = 0x0000001dU;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_xor_stages__1__xor_array[0U][21U][0U] = 0x00000017U;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_xor_stages__1__xor_array[0U][21U][1U] = 0x0000000aU;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_xor_stages__1__xor_array[0U][21U][2U] = 1U;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_xor_stages__1__xor_array[0U][22U][0U] = 0x0000001bU;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_xor_stages__1__xor_array[0U][22U][1U] = 0x0000001eU;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_xor_stages__1__xor_array[0U][22U][2U] = 5U;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_xor_stages__1__xor_array[0U][23U][0U] = 0x0000001fU;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_xor_stages__1__xor_array[0U][23U][1U] = 0x00000012U;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_xor_stages__1__xor_array[0U][23U][2U] = 9U;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_xor_stages__1__xor_array[0U][24U][0U] = 3U;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_xor_stages__1__xor_array[0U][24U][1U] = 6U;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_xor_stages__1__xor_array[0U][24U][2U] = 0x0000000dU;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_xor_stages__1__xor_array[0U][25U][0U] = 7U;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_xor_stages__1__xor_array[0U][25U][1U] = 0x0000001aU;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_xor_stages__1__xor_array[0U][25U][2U] = 0x00000011U;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_xor_stages__1__xor_array[0U][26U][0U] = 0x0000000bU;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_xor_stages__1__xor_array[0U][26U][1U] = 0x0000000eU;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_xor_stages__1__xor_array[0U][26U][2U] = 0x00000015U;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_xor_stages__1__xor_array[0U][27U][0U] = 0x0000000fU;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_xor_stages__1__xor_array[0U][27U][1U] = 2U;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_xor_stages__1__xor_array[0U][27U][2U] = 0x00000019U;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_xor_stages__1__xor_array[0U][28U][0U] = 0x00000013U;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_xor_stages__1__xor_array[0U][28U][1U] = 0x00000016U;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_xor_stages__1__xor_array[0U][28U][2U] = 0x0000001dU;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_xor_stages__1__xor_array[0U][29U][0U] = 0x00000017U;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_xor_stages__1__xor_array[0U][29U][1U] = 0x0000000aU;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_xor_stages__1__xor_array[0U][29U][2U] = 1U;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_xor_stages__1__xor_array[0U][30U][0U] = 0x0000001bU;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_xor_stages__1__xor_array[0U][30U][1U] = 0x0000001eU;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_xor_stages__1__xor_array[0U][30U][2U] = 5U;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_xor_stages__1__xor_array[0U][31U][0U] = 0x0000001fU;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_xor_stages__1__xor_array[0U][31U][1U] = 0x00000012U;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_xor_stages__1__xor_array[0U][31U][2U] = 9U;
    __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_xor_stages__1__Vfuncout 
        = __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_xor_stages__1__xor_array;
    vlSelfRef.tb_sub_per_hash__DOT__DUT__DOT__XorStages 
        = __Vfunc_tb_sub_per_hash__DOT__DUT__DOT__get_xor_stages__1__Vfuncout;
}

VL_ATTR_COLD void Vtb_sub_per_hash___024root___eval_final(Vtb_sub_per_hash___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_sub_per_hash___024root___eval_final\n"); );
    Vtb_sub_per_hash__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_sub_per_hash___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vtb_sub_per_hash___024root___eval_phase__stl(Vtb_sub_per_hash___024root* vlSelf);

VL_ATTR_COLD void Vtb_sub_per_hash___024root___eval_settle(Vtb_sub_per_hash___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_sub_per_hash___024root___eval_settle\n"); );
    Vtb_sub_per_hash__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VstlIterCount;
    // Body
    __VstlIterCount = 0U;
    vlSelfRef.__VstlFirstIteration = 1U;
    do {
        if (VL_UNLIKELY(((0x00002710U < __VstlIterCount)))) {
#ifdef VL_DEBUG
            Vtb_sub_per_hash___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
#endif
            VL_FATAL_MT("sv/tb_sub_per_hash.sv", 3, "", "DIDNOTCONVERGE: Settle region did not converge after '--converge-limit' of 10000 tries");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        vlSelfRef.__VstlPhaseResult = Vtb_sub_per_hash___024root___eval_phase__stl(vlSelf);
        vlSelfRef.__VstlFirstIteration = 0U;
    } while (vlSelfRef.__VstlPhaseResult);
}

VL_ATTR_COLD void Vtb_sub_per_hash___024root___eval_triggers_vec__stl(Vtb_sub_per_hash___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_sub_per_hash___024root___eval_triggers_vec__stl\n"); );
    Vtb_sub_per_hash__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VstlTriggered[0U] = ((0xfffffffffffffffeULL 
                                      & vlSelfRef.__VstlTriggered[0U]) 
                                     | (IData)((IData)(vlSelfRef.__VstlFirstIteration)));
}

VL_ATTR_COLD bool Vtb_sub_per_hash___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_sub_per_hash___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_sub_per_hash___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(Vtb_sub_per_hash___024root___trigger_anySet__stl(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD bool Vtb_sub_per_hash___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_sub_per_hash___024root___trigger_anySet__stl\n"); );
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

void Vtb_sub_per_hash___024root___act_sequent__TOP__0(Vtb_sub_per_hash___024root* vlSelf);

VL_ATTR_COLD void Vtb_sub_per_hash___024root___eval_stl(Vtb_sub_per_hash___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_sub_per_hash___024root___eval_stl\n"); );
    Vtb_sub_per_hash__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered[0U])) {
        Vtb_sub_per_hash___024root___act_sequent__TOP__0(vlSelf);
    }
}

VL_ATTR_COLD bool Vtb_sub_per_hash___024root___eval_phase__stl(Vtb_sub_per_hash___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_sub_per_hash___024root___eval_phase__stl\n"); );
    Vtb_sub_per_hash__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VstlExecute;
    // Body
    Vtb_sub_per_hash___024root___eval_triggers_vec__stl(vlSelf);
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtb_sub_per_hash___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
    }
#endif
    __VstlExecute = Vtb_sub_per_hash___024root___trigger_anySet__stl(vlSelfRef.__VstlTriggered);
    if (__VstlExecute) {
        Vtb_sub_per_hash___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

bool Vtb_sub_per_hash___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_sub_per_hash___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_sub_per_hash___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(Vtb_sub_per_hash___024root___trigger_anySet__act(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtb_sub_per_hash___024root___ctor_var_reset(Vtb_sub_per_hash___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_sub_per_hash___024root___ctor_var_reset\n"); );
    Vtb_sub_per_hash__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->vlNamep);
    vlSelf->tb_sub_per_hash__DOT__data_i = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7793947921687710028ull);
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 32; ++__Vi1) {
            vlSelf->tb_sub_per_hash__DOT__DUT__DOT__Permutations[__Vi0][__Vi1] = 0;
        }
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 32; ++__Vi1) {
            for (int __Vi2 = 0; __Vi2 < 3; ++__Vi2) {
                vlSelf->tb_sub_per_hash__DOT__DUT__DOT__XorStages[__Vi0][__Vi1][__Vi2] = 0;
            }
        }
    }
    vlSelf->tb_sub_per_hash__DOT__DUT__DOT__permuted = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 156272012501909754ull);
    vlSelf->tb_sub_per_hash__DOT__DUT__DOT__xored = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14961117270591935805ull);
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VstlTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VactTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VactTriggeredAcc[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VnbaTriggered[__Vi0] = 0;
    }
    vlSelf->__Vi = 0;
}
