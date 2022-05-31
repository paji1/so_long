/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 05:01:42 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/05/30 05:07:53 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/***********************************************************
Copyright 1987, 1994, 1998  The Open Group

Permission to use, copy, modify, distribute, and sell this software and its
documentation for any purpose is hereby granted without fee, provided that
the above copyright notice appear in all copies and that both that
copyright notice and this permission notice appear in supporting
documentation.

The above copyright notice and this permission notice shall be included
in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE OPEN GROUP BE LIABLE FOR ANY CLAIM, DAMAGES OR
OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
OTHER DEALINGS IN THE SOFTWARE.

Except as contained in this notice, the name of The Open Group shall
not be used in advertising or otherwise to promote the sale, use or
other dealings in this Software without prior written authorization
from The Open Group.


Copyright 1987 by Digital Equipment Corporation, Maynard, Massachusetts

                        All Rights Reserved

Permission to use, copy, modify, and distribute this software and its
documentation for any purpose and without fee is hereby granted,
provided that the above copyright notice appear in all copies and that
both that copyright notice and this permission notice appear in
supporting documentation, and that the name of Digital not be
used in advertising or publicity pertaining to distribution of the
software without specific, written prior permission.

DIGITAL DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING
ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL
DIGITAL BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR
ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS,
WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION,
ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS
SOFTWARE.

******************************************************************/

/*
 * The "X11 Window System Protocol" standard defines in Appendix A the
 * keysym codes. These 29-bit integer values identify characters or
 * functions associated with each key (e.g., via the visible
 * engraving) of a keyboard layout. This file assigns mnemonic macro
 * names for these keysyms.
 *
 * This file is also compiled (by src/util/makekeys.c in libX11) into
 * hash tables that can be accessed with X11 library functions such as
 * XStringToKeysym() and XKeysymToString().
 *
 * Where a keysym corresponds one-to-one to an ISO 10646 / Unicode
 * character, this is noted in a comment that provides both the U+xxxx
 * Unicode position, as well as the official Unicode name of the
 * character.
 *
 * Where the correspondence is either not one-to-one or semantically
 * unclear, the Unicode position and name are enclosed in
 * parentheses. Such legacy keysyms should be considered deprecated
 * and are not recommended for use in future keyboard mappings.
 *
 * For any future extension of the keysyms with characters already
 * found in ISO 10646 / Unicode, the following algorithm shall be
 * used. The new keysym code position will simply be the character's
 * Unicode number plus 0x01000000. The keysym values in the range
 * 0x01000100 to 0x0110ffff are reserved to represent Unicode
 * characters in the range U+0100 to U+10FFFF.
 * 
 * While most newer Unicode-based X11 clients do already accept
 * Unicode-mapped keysyms in the range 0x01000100 to 0x0110ffff, it
 * will remain necessary for clients -- in the interest of
 * compatibility with existing servers -- to also understand the
 * existing legacy keysym values in the range 0x0100 to 0x20ff.
 *
 * Where several mnemonic names are defined for the same keysym in this
 * file, all but the first one listed should be considered deprecated.
 *
 * Mnemonic names for keysyms are defined in this file with lines
 * that match one of these Perl regular expressions:
 *
 *    /^\#define XK_([a-zA-Z_0-9]+)\s+0x([0-9a-f]+)\s*\/\* U+([0-9A-F]{4,6}) (.*) \*\/\s*$/
 *    /^\#define XK_([a-zA-Z_0-9]+)\s+0x([0-9a-f]+)\s*\/\*\(U+([0-9A-F]{4,6}) (.*)\)\*\/\s*$/
 *    /^\#define XK_([a-zA-Z_0-9]+)\s+0x([0-9a-f]+)\s*(\/\*\s*(.*)\s*\*\/)?\s*$/
 *
 * Before adding new keysyms, please do consider the following: In
 * addition to the keysym names defined in this file, the
 * XStringToKeysym() and XKeysymToString() functions will also handle
 * any keysym string of the form "U0020" to "U007E" and "U00A0" to
 * "U10FFFF" for all possible Unicode characters. In other words,
 * every possible Unicode character has already a keysym string
 * defined algorithmically, even if it is not listed here. Therefore,
 * defining an additional keysym macro is only necessary where a
 * non-hexadecimal mnemonic name is needed, or where the new keysym
 * does not represent any existing Unicode character.
 *
 * When adding new keysyms to this file, do not forget to also update the
 * following as needed:
 *
 *   - the mappings in src/KeyBind.c in the repo
 *     git://anongit.freedesktop.org/xorg/lib/libX11.git
 *
 *   - the protocol specification in specs/keysyms.xml
 *     in the repo git://anongit.freedesktop.org/xorg/proto/x11proto.git
 *
 */


/*
 * TTY function keys, cleverly chosen to map to ASCII, for convenience of
 * programming, but could have been arbitrary (at the cost of lookup
 * tables in client code).
 */

#define XK_BackSpace                     0xff08  /* Back space, back char */
#define XK_Tab                           0xff09
#define XK_Linefeed                      0xff0a  /* Linefeed, LF */
#define XK_Clear                         0xff0b
#define XK_Return                        0xff0d  /* Return, enter */
#define XK_Pause                         0xff13  /* Pause, hold */
#define XK_Scroll_Lock                   0xff14
#define XK_Sys_Req                       0xff15
#define XK_Escape                        0xff1b
#define XK_Delete                        0xffff  /* Delete, rubout */



/* International & multi-key character composition */

#define XK_Multi_key                     0xff20  /* Multi-key character compose */
#define XK_Codeinput                     0xff37
#define XK_SingleCandidate               0xff3c
#define XK_MultipleCandidate             0xff3d
#define XK_PreviousCandidate             0xff3e

/* Japanese keyboard support */

#define XK_Kanji                         0xff21  /* Kanji, Kanji convert */
#define XK_Muhenkan                      0xff22  /* Cancel Conversion */
#define XK_Henkan_Mode                   0xff23  /* Start/Stop Conversion */
#define XK_Henkan                        0xff23  /* Alias for Henkan_Mode */
#define XK_Romaji                        0xff24  /* to Romaji */
#define XK_Hiragana                      0xff25  /* to Hiragana */
#define XK_Katakana                      0xff26  /* to Katakana */
#define XK_Hiragana_Katakana             0xff27  /* Hiragana/Katakana toggle */
#define XK_Zenkaku                       0xff28  /* to Zenkaku */
#define XK_Hankaku                       0xff29  /* to Hankaku */
#define XK_Zenkaku_Hankaku               0xff2a  /* Zenkaku/Hankaku toggle */
#define XK_Touroku                       0xff2b  /* Add to Dictionary */
#define XK_Massyo                        0xff2c  /* Delete from Dictionary */
#define XK_Kana_Lock                     0xff2d  /* Kana Lock */
#define XK_Kana_Shift                    0xff2e  /* Kana Shift */
#define XK_Eisu_Shift                    0xff2f  /* Alphanumeric Shift */
#define XK_Eisu_toggle                   0xff30  /* Alphanumeric toggle */
#define XK_Kanji_Bangou                  0xff37  /* Codeinput */
#define XK_Zen_Koho                      0xff3d  /* Multiple/All Candidate(s) */
#define XK_Mae_Koho                      0xff3e  /* Previous Candidate */

/* 0xff31 thru 0xff3f are under XK_KOREAN */

/* Cursor control & motion */

#define XK_Home                          0xff50
#define XK_Left                          0xff51  /* Move left, left arrow */
#define XK_Up                            0xff52  /* Move up, up arrow */
#define XK_Right                         0xff53  /* Move right, right arrow */
#define XK_Down                          0xff54  /* Move down, down arrow */
#define XK_Prior                         0xff55  /* Prior, previous */
#define XK_Page_Up                       0xff55
#define XK_Next                          0xff56  /* Next */
#define XK_Page_Down                     0xff56
#define XK_End                           0xff57  /* EOL */
#define XK_Begin                         0xff58  /* BOL */


/* Misc functions */

#define XK_Select                        0xff60  /* Select, mark */
#define XK_Print                         0xff61
#define XK_Execute                       0xff62  /* Execute, run, do */
#define XK_Insert                        0xff63  /* Insert, insert here */
#define XK_Undo                          0xff65
#define XK_Redo                          0xff66  /* Redo, again */
#define XK_Menu                          0xff67
#define XK_Find                          0xff68  /* Find, search */
#define XK_Cancel                        0xff69  /* Cancel, stop, abort, exit */
#define XK_Help                          0xff6a  /* Help */
#define XK_Break                         0xff6b
#define XK_Mode_switch                   0xff7e  /* Character set switch */
#define XK_script_switch                 0xff7e  /* Alias for mode_switch */
#define XK_Num_Lock                      0xff7f

/* Keypad functions, keypad numbers cleverly chosen to map to ASCII */

#define XK_KP_Space                      0xff80  /* Space */
#define XK_KP_Tab                        0xff89
#define XK_KP_Enter                      0xff8d  /* Enter */
#define XK_KP_F1                         0xff91  /* PF1, KP_A, ... */
#define XK_KP_F2                         0xff92
#define XK_KP_F3                         0xff93
#define XK_KP_F4                         0xff94
#define XK_KP_Home                       0xff95
#define XK_KP_Left                       0xff96
#define XK_KP_Up                         0xff97
#define XK_KP_Right                      0xff98
#define XK_KP_Down                       0xff99
#define XK_KP_Prior                      0xff9a
#define XK_KP_Page_Up                    0xff9a
#define XK_KP_Next                       0xff9b
#define XK_KP_Page_Down                  0xff9b
#define XK_KP_End                        0xff9c
#define XK_KP_Begin                      0xff9d
#define XK_KP_Insert                     0xff9e
#define XK_KP_Delete                     0xff9f
#define XK_KP_Equal                      0xffbd  /* Equals */
#define XK_KP_Multiply                   0xffaa
#define XK_KP_Add                        0xffab
#define XK_KP_Separator                  0xffac  /* Separator, often comma */
#define XK_KP_Subtract                   0xffad
#define XK_KP_Decimal                    0xffae
#define XK_KP_Divide                     0xffaf

#define XK_KP_0                          0xffb0
#define XK_KP_1                          0xffb1
#define XK_KP_2                          0xffb2
#define XK_KP_3                          0xffb3
#define XK_KP_4                          0xffb4
#define XK_KP_5                          0xffb5
#define XK_KP_6                          0xffb6
#define XK_KP_7                          0xffb7
#define XK_KP_8                          0xffb8
#define XK_KP_9                          0xffb9



/*
 * Auxiliary functions; note the duplicate definitions for left and right
 * function keys;  Sun keyboards and a few other manufacturers have such
 * function key groups on the left and/or right sides of the keyboard.
 * We've not found a keyboard with more than 35 function keys total.
 */

#define XK_F1                            0xffbe
#define XK_F2                            0xffbf
#define XK_F3                            0xffc0
#define XK_F4                            0xffc1
#define XK_F5                            0xffc2
#define XK_F6                            0xffc3
#define XK_F7                            0xffc4
#define XK_F8                            0xffc5
#define XK_F9                            0xffc6
#define XK_F10                           0xffc7
#define XK_F11                           0xffc8
#define XK_L1                            0xffc8
#define XK_F12                           0xffc9
#define XK_L2                            0xffc9
#define XK_F13                           0xffca
#define XK_L3                            0xffca
#define XK_F14                           0xffcb
#define XK_L4                            0xffcb
#define XK_F15                           0xffcc
#define XK_L5                            0xffcc
#define XK_F16                           0xffcd
#define XK_L6                            0xffcd
#define XK_F17                           0xffce
#define XK_L7                            0xffce
#define XK_F18                           0xffcf
#define XK_L8                            0xffcf
#define XK_F19                           0xffd0
#define XK_L9                            0xffd0
#define XK_F20                           0xffd1
#define XK_L10                           0xffd1
#define XK_F21                           0xffd2
#define XK_R1                            0xffd2
#define XK_F22                           0xffd3
#define XK_R2                            0xffd3
#define XK_F23                           0xffd4
#define XK_R3                            0xffd4
#define XK_F24                           0xffd5
#define XK_R4                            0xffd5
#define XK_F25                           0xffd6
#define XK_R5                            0xffd6
#define XK_F26                           0xffd7
#define XK_R6                            0xffd7
#define XK_F27                           0xffd8
#define XK_R7                            0xffd8
#define XK_F28                           0xffd9
#define XK_R8                            0xffd9
#define XK_F29                           0xffda
#define XK_R9                            0xffda
#define XK_F30                           0xffdb
#define XK_R10                           0xffdb
#define XK_F31                           0xffdc
#define XK_R11                           0xffdc
#define XK_F32                           0xffdd
#define XK_R12                           0xffdd
#define XK_F33                           0xffde
#define XK_R13                           0xffde
#define XK_F34                           0xffdf
#define XK_R14                           0xffdf
#define XK_F35                           0xffe0
#define XK_R15                           0xffe0

/* Modifiers */

#define XK_Shift_L                       0xffe1  /* Left shift */
#define XK_Shift_R                       0xffe2  /* Right shift */
#define XK_Control_L                     0xffe3  /* Left control */
#define XK_Control_R                     0xffe4  /* Right control */
#define XK_Caps_Lock                     0xffe5  /* Caps lock */
#define XK_Shift_Lock                    0xffe6  /* Shift lock */

#define XK_Meta_L                        0xffe7  /* Left meta */
#define XK_Meta_R                        0xffe8  /* Right meta */
#define XK_Alt_L                         0xffe9  /* Left alt */
#define XK_Alt_R                         0xffea  /* Right alt */
#define XK_Super_L                       0xffeb  /* Left super */
#define XK_Super_R                       0xffec  /* Right super */
#define XK_Hyper_L                       0xffed  /* Left hyper */
#define XK_Hyper_R                       0xffee  /* Right hyper */
#define XK_ISO_Lock                      0xfe01
#define XK_ISO_Level2_Latch              0xfe02
#define XK_ISO_Level3_Shift              0xfe03
#define XK_ISO_Level3_Latch              0xfe04
#define XK_ISO_Level3_Lock               0xfe05
#define XK_ISO_Level5_Shift              0xfe11
#define XK_ISO_Level5_Latch              0xfe12
#define XK_ISO_Level5_Lock               0xfe13
#define XK_ISO_Group_Shift               0xff7e  /* Alias for mode_switch */
#define XK_ISO_Group_Latch               0xfe06
#define XK_ISO_Group_Lock                0xfe07
#define XK_ISO_Next_Group                0xfe08
#define XK_ISO_Next_Group_Lock           0xfe09
#define XK_ISO_Prev_Group                0xfe0a
#define XK_ISO_Prev_Group_Lock           0xfe0b
#define XK_ISO_First_Group               0xfe0c
#define XK_ISO_First_Group_Lock          0xfe0d
#define XK_ISO_Last_Group                0xfe0e
#define XK_ISO_Last_Group_Lock           0xfe0f

#define XK_ISO_Left_Tab                  0xfe20
#define XK_ISO_Move_Line_Up              0xfe21
#define XK_ISO_Move_Line_Down            0xfe22
#define XK_ISO_Partial_Line_Up           0xfe23
#define XK_ISO_Partial_Line_Down         0xfe24
#define XK_ISO_Partial_Space_Left        0xfe25
#define XK_ISO_Partial_Space_Right       0xfe26
#define XK_ISO_Set_Margin_Left           0xfe27
#define XK_ISO_Set_Margin_Right          0xfe28
#define XK_ISO_Release_Margin_Left       0xfe29
#define XK_ISO_Release_Margin_Right      0xfe2a
#define XK_ISO_Release_Both_Margins      0xfe2b
#define XK_ISO_Fast_Cursor_Left          0xfe2c
#define XK_ISO_Fast_Cursor_Right         0xfe2d
#define XK_ISO_Fast_Cursor_Up            0xfe2e
#define XK_ISO_Fast_Cursor_Down          0xfe2f
#define XK_ISO_Continuous_Underline      0xfe30
#define XK_ISO_Discontinuous_Underline   0xfe31
#define XK_ISO_Emphasize                 0xfe32
#define XK_ISO_Center_Object             0xfe33
#define XK_ISO_Enter                     0xfe34

#define XK_dead_grave                    0xfe50
#define XK_dead_acute                    0xfe51
#define XK_dead_circumflex               0xfe52
#define XK_dead_tilde                    0xfe53
#define XK_dead_perispomeni              0xfe53  /* alias for dead_tilde */
#define XK_dead_macron                   0xfe54
#define XK_dead_breve                    0xfe55
#define XK_dead_abovedot                 0xfe56
#define XK_dead_diaeresis                0xfe57
#define XK_dead_abovering                0xfe58
#define XK_dead_doubleacute              0xfe59
#define XK_dead_caron                    0xfe5a
#define XK_dead_cedilla                  0xfe5b
#define XK_dead_ogonek                   0xfe5c
#define XK_dead_iota                     0xfe5d
#define XK_dead_voiced_sound             0xfe5e
#define XK_dead_semivoiced_sound         0xfe5f
#define XK_dead_belowdot                 0xfe60
#define XK_dead_hook                     0xfe61
#define XK_dead_horn                     0xfe62
#define XK_dead_stroke                   0xfe63
#define XK_dead_abovecomma               0xfe64
#define XK_dead_psili                    0xfe64  /* alias for dead_abovecomma */
#define XK_dead_abovereversedcomma       0xfe65
#define XK_dead_dasia                    0xfe65  /* alias for dead_abovereversedcomma */
#define XK_dead_doublegrave              0xfe66
#define XK_dead_belowring                0xfe67
#define XK_dead_belowmacron              0xfe68
#define XK_dead_belowcircumflex          0xfe69
#define XK_dead_belowtilde               0xfe6a
#define XK_dead_belowbreve               0xfe6b
#define XK_dead_belowdiaeresis           0xfe6c
#define XK_dead_invertedbreve            0xfe6d
#define XK_dead_belowcomma               0xfe6e
#define XK_dead_currency                 0xfe6f

/* extra dead elements for German T3 layout */
#define XK_dead_lowline                  0xfe90
#define XK_dead_aboveverticalline        0xfe91
#define XK_dead_belowverticalline        0xfe92
#define XK_dead_longsolidusoverlay       0xfe93

/* dead vowels for universal syllable entry */
#define XK_dead_a                        0xfe80
#define XK_dead_A                        0xfe81
#define XK_dead_e                        0xfe82
#define XK_dead_E                        0xfe83
#define XK_dead_i                        0xfe84
#define XK_dead_I                        0xfe85
#define XK_dead_o                        0xfe86
#define XK_dead_O                        0xfe87
#define XK_dead_u                        0xfe88
#define XK_dead_U                        0xfe89
#define XK_dead_small_schwa              0xfe8a
#define XK_dead_capital_schwa            0xfe8b

#define XK_dead_greek                    0xfe8c

#define XK_First_Virtual_Screen          0xfed0
#define XK_Prev_Virtual_Screen           0xfed1
#define XK_Next_Virtual_Screen           0xfed2
#define XK_Last_Virtual_Screen           0xfed4
#define XK_Terminate_Server              0xfed5

#define XK_AccessX_Enable                0xfe70
#define XK_AccessX_Feedback_Enable       0xfe71
#define XK_RepeatKeys_Enable             0xfe72
#define XK_SlowKeys_Enable               0xfe73
#define XK_BounceKeys_Enable             0xfe74
#define XK_StickyKeys_Enable             0xfe75
#define XK_MouseKeys_Enable              0xfe76
#define XK_MouseKeys_Accel_Enable        0xfe77
#define XK_Overlay1_Enable               0xfe78
#define XK_Overlay2_Enable               0xfe79
#define XK_AudibleBell_Enable            0xfe7a

#define XK_Pointer_Left                  0xfee0
#define XK_Pointer_Right                 0xfee1
#define XK_Pointer_Up                    0xfee2
#define XK_Pointer_Down                  0xfee3
#define XK_Pointer_UpLeft                0xfee4
#define XK_Pointer_UpRight               0xfee5
#define XK_Pointer_DownLeft              0xfee6
#define XK_Pointer_DownRight             0xfee7
#define XK_Pointer_Button_Dflt           0xfee8
#define XK_Pointer_Button1               0xfee9
#define XK_Pointer_Button2               0xfeea
#define XK_Pointer_Button3               0xfeeb
#define XK_Pointer_Button4               0xfeec
#define XK_Pointer_Button5               0xfeed
#define XK_Pointer_DblClick_Dflt         0xfeee
#define XK_Pointer_DblClick1             0xfeef
#define XK_Pointer_DblClick2             0xfef0
#define XK_Pointer_DblClick3             0xfef1
#define XK_Pointer_DblClick4             0xfef2
#define XK_Pointer_DblClick5             0xfef3
#define XK_Pointer_Drag_Dflt             0xfef4
#define XK_Pointer_Drag1                 0xfef5
#define XK_Pointer_Drag2                 0xfef6
#define XK_Pointer_Drag3                 0xfef7
#define XK_Pointer_Drag4                 0xfef8
#define XK_Pointer_Drag5                 0xfefd

#define XK_Pointer_EnableKeys            0xfef9
#define XK_Pointer_Accelerate            0xfefa
#define XK_Pointer_DfltBtnNext           0xfefb
#define XK_Pointer_DfltBtnPrev           0xfefc

/* Single-Stroke Multiple-Character N-Graph Keysyms For The X Input Method */

#define XK_ch                            0xfea0
#define XK_Ch                            0xfea1
#define XK_CH                            0xfea2
#define XK_c_h                           0xfea3
#define XK_C_h                           0xfea4
#define XK_C_H                           0xfea5



#define XK_3270_Duplicate                0xfd01
#define XK_3270_FieldMark                0xfd02
#define XK_3270_Right2                   0xfd03
#define XK_3270_Left2                    0xfd04
#define XK_3270_BackTab                  0xfd05
#define XK_3270_EraseEOF                 0xfd06
#define XK_3270_EraseInput               0xfd07
#define XK_3270_Reset                    0xfd08
#define XK_3270_Quit                     0xfd09
#define XK_3270_PA1                      0xfd0a
#define XK_3270_PA2                      0xfd0b
#define XK_3270_PA3                      0xfd0c
#define XK_3270_Test                     0xfd0d
#define XK_3270_Attn                     0xfd0e
#define XK_3270_CursorBlink              0xfd0f
#define XK_3270_AltCursor                0xfd10
#define XK_3270_KeyClick                 0xfd11
#define XK_3270_Jump                     0xfd12
#define XK_3270_Ident                    0xfd13
#define XK_3270_Rule                     0xfd14
#define XK_3270_Copy                     0xfd15
#define XK_3270_Play                     0xfd16
#define XK_3270_Setup                    0xfd17
#define XK_3270_Record                   0xfd18
#define XK_3270_ChangeScreen             0xfd19
#define XK_3270_DeleteWord               0xfd1a
#define XK_3270_ExSelect                 0xfd1b
#define XK_3270_CursorSelect             0xfd1c
#define XK_3270_PrintScreen              0xfd1d
#define XK_3270_Enter                    0xfd1e


/*
 * Latin 1
 * (ISO/IEC 8859-1 = Unicode U+0020..U+00FF)
 * Byte 3 = 0
 */

#define XK_space                         0x0020  /* U+0020 SPACE */
#define XK_exclam                        0x0021  /* U+0021 EXCLAMATION MARK */
#define XK_quotedbl                      0x0022  /* U+0022 QUOTATION MARK */
#define XK_numbersign                    0x0023  /* U+0023 NUMBER SIGN */
#define XK_dollar                        0x0024  /* U+0024 DOLLAR SIGN */
#define XK_percent                       0x0025  /* U+0025 PERCENT SIGN */
#define XK_ampersand                     0x0026  /* U+0026 AMPERSAND */
#define XK_apostrophe                    0x0027  /* U+0027 APOSTROPHE */
#define XK_quoteright                    0x0027  /* deprecated */
#define XK_parenleft                     0x0028  /* U+0028 LEFT PARENTHESIS */
#define XK_parenright                    0x0029  /* U+0029 RIGHT PARENTHESIS */
#define XK_asterisk                      0x002a  /* U+002A ASTERISK */
#define XK_plus                          0x002b  /* U+002B PLUS SIGN */
#define XK_comma                         0x002c  /* U+002C COMMA */
#define XK_minus                         0x002d  /* U+002D HYPHEN-MINUS */
#define XK_period                        0x002e  /* U+002E FULL STOP */
#define XK_slash                         0x002f  /* U+002F SOLIDUS */
#define XK_0                             0x0030  /* U+0030 DIGIT ZERO */
#define XK_1                             0x0031  /* U+0031 DIGIT ONE */
#define XK_2                             0x0032  /* U+0032 DIGIT TWO */
#define XK_3                             0x0033  /* U+0033 DIGIT THREE */
#define XK_4                             0x0034  /* U+0034 DIGIT FOUR */
#define XK_5                             0x0035  /* U+0035 DIGIT FIVE */
#define XK_6                             0x0036  /* U+0036 DIGIT SIX */
#define XK_7                             0x0037  /* U+0037 DIGIT SEVEN */
#define XK_8                             0x0038  /* U+0038 DIGIT EIGHT */
#define XK_9                             0x0039  /* U+0039 DIGIT NINE */
#define XK_colon                         0x003a  /* U+003A COLON */
#define XK_semicolon                     0x003b  /* U+003B SEMICOLON */
#define XK_less                          0x003c  /* U+003C LESS-THAN SIGN */
#define XK_equal                         0x003d  /* U+003D EQUALS SIGN */
#define XK_greater                       0x003e  /* U+003E GREATER-THAN SIGN */
#define XK_question                      0x003f  /* U+003F QUESTION MARK */
#define XK_at                            0x0040  /* U+0040 COMMERCIAL AT */
#define XK_A                             0x0041  /* U+0041 LATIN CAPITAL LETTER A */
#define XK_B                             0x0042  /* U+0042 LATIN CAPITAL LETTER B */
#define XK_C                             0x0043  /* U+0043 LATIN CAPITAL LETTER C */
#define XK_D                             0x0044  /* U+0044 LATIN CAPITAL LETTER D */
#define XK_E                             0x0045  /* U+0045 LATIN CAPITAL LETTER E */
#define XK_F                             0x0046  /* U+0046 LATIN CAPITAL LETTER F */
#define XK_G                             0x0047  /* U+0047 LATIN CAPITAL LETTER G */
#define XK_H                             0x0048  /* U+0048 LATIN CAPITAL LETTER H */
#define XK_I                             0x0049  /* U+0049 LATIN CAPITAL LETTER I */
#define XK_J                             0x004a  /* U+004A LATIN CAPITAL LETTER J */
#define XK_K                             0x004b  /* U+004B LATIN CAPITAL LETTER K */
#define XK_L                             0x004c  /* U+004C LATIN CAPITAL LETTER L */
#define XK_M                             0x004d  /* U+004D LATIN CAPITAL LETTER M */
#define XK_N                             0x004e  /* U+004E LATIN CAPITAL LETTER N */
#define XK_O                             0x004f  /* U+004F LATIN CAPITAL LETTER O */
#define XK_P                             0x0050  /* U+0050 LATIN CAPITAL LETTER P */
#define XK_Q                             0x0051  /* U+0051 LATIN CAPITAL LETTER Q */
#define XK_R                             0x0052  /* U+0052 LATIN CAPITAL LETTER R */
#define XK_S                             0x0053  /* U+0053 LATIN CAPITAL LETTER S */
#define XK_T                             0x0054  /* U+0054 LATIN CAPITAL LETTER T */
#define XK_U                             0x0055  /* U+0055 LATIN CAPITAL LETTER U */
#define XK_V                             0x0056  /* U+0056 LATIN CAPITAL LETTER V */
#define XK_W                             0x0057  /* U+0057 LATIN CAPITAL LETTER W */
#define XK_X                             0x0058  /* U+0058 LATIN CAPITAL LETTER X */
#define XK_Y                             0x0059  /* U+0059 LATIN CAPITAL LETTER Y */
#define XK_Z                             0x005a  /* U+005A LATIN CAPITAL LETTER Z */
#define XK_bracketleft                   0x005b  /* U+005B LEFT SQUARE BRACKET */
#define XK_backslash                     0x005c  /* U+005C REVERSE SOLIDUS */
#define XK_bracketright                  0x005d  /* U+005D RIGHT SQUARE BRACKET */
#define XK_asciicircum                   0x005e  /* U+005E CIRCUMFLEX ACCENT */
#define XK_underscore                    0x005f  /* U+005F LOW LINE */
#define XK_grave                         0x0060  /* U+0060 GRAVE ACCENT */
#define XK_quoteleft                     0x0060  /* deprecated */
#define XK_a                             0x0061  /* U+0061 LATIN SMALL LETTER A */
#define XK_b                             0x0062  /* U+0062 LATIN SMALL LETTER B */
#define XK_c                             0x0063  /* U+0063 LATIN SMALL LETTER C */
#define XK_d                             0x0064  /* U+0064 LATIN SMALL LETTER D */
#define XK_e                             0x0065  /* U+0065 LATIN SMALL LETTER E */
#define XK_f                             0x0066  /* U+0066 LATIN SMALL LETTER F */
#define XK_g                             0x0067  /* U+0067 LATIN SMALL LETTER G */
#define XK_h                             0x0068  /* U+0068 LATIN SMALL LETTER H */
#define XK_i                             0x0069  /* U+0069 LATIN SMALL LETTER I */
#define XK_j                             0x006a  /* U+006A LATIN SMALL LETTER J */
#define XK_k                             0x006b  /* U+006B LATIN SMALL LETTER K */
#define XK_l                             0x006c  /* U+006C LATIN SMALL LETTER L */
#define XK_m                             0x006d  /* U+006D LATIN SMALL LETTER M */
#define XK_n                             0x006e  /* U+006E LATIN SMALL LETTER N */
#define XK_o                             0x006f  /* U+006F LATIN SMALL LETTER O */
#define XK_p                             0x0070  /* U+0070 LATIN SMALL LETTER P */
#define XK_q                             0x0071  /* U+0071 LATIN SMALL LETTER Q */
#define XK_r                             0x0072  /* U+0072 LATIN SMALL LETTER R */
#define XK_s                             0x0073  /* U+0073 LATIN SMALL LETTER S */
#define XK_t                             0x0074  /* U+0074 LATIN SMALL LETTER T */
#define XK_u                             0x0075  /* U+0075 LATIN SMALL LETTER U */
#define XK_v                             0x0076  /* U+0076 LATIN SMALL LETTER V */
#define XK_w                             0x0077  /* U+0077 LATIN SMALL LETTER W */
#define XK_x                             0x0078  /* U+0078 LATIN SMALL LETTER X */
#define XK_y                             0x0079  /* U+0079 LATIN SMALL LETTER Y */
#define XK_z                             0x007a  /* U+007A LATIN SMALL LETTER Z */
#define XK_braceleft                     0x007b  /* U+007B LEFT CURLY BRACKET */
#define XK_bar                           0x007c  /* U+007C VERTICAL LINE */
#define XK_braceright                    0x007d  /* U+007D RIGHT CURLY BRACKET */
#define XK_asciitilde                    0x007e  /* U+007E TILDE */

#define XK_nobreakspace                  0x00a0  /* U+00A0 NO-BREAK SPACE */
#define XK_exclamdown                    0x00a1  /* U+00A1 INVERTED EXCLAMATION MARK */
#define XK_cent                          0x00a2  /* U+00A2 CENT SIGN */
#define XK_sterling                      0x00a3  /* U+00A3 POUND SIGN */
#define XK_currency                      0x00a4  /* U+00A4 CURRENCY SIGN */
#define XK_yen                           0x00a5  /* U+00A5 YEN SIGN */
#define XK_brokenbar                     0x00a6  /* U+00A6 BROKEN BAR */
#define XK_section                       0x00a7  /* U+00A7 SECTION SIGN */
#define XK_diaeresis                     0x00a8  /* U+00A8 DIAERESIS */
#define XK_copyright                     0x00a9  /* U+00A9 COPYRIGHT SIGN */
#define XK_ordfeminine                   0x00aa  /* U+00AA FEMININE ORDINAL INDICATOR */
#define XK_guillemotleft                 0x00ab  /* U+00AB LEFT-POINTING DOUBLE ANGLE QUOTATION MARK */
#define XK_notsign                       0x00ac  /* U+00AC NOT SIGN */
#define XK_hyphen                        0x00ad  /* U+00AD SOFT HYPHEN */
#define XK_registered                    0x00ae  /* U+00AE REGISTERED SIGN */
#define XK_macron                        0x00af  /* U+00AF MACRON */
#define XK_degree                        0x00b0  /* U+00B0 DEGREE SIGN */
#define XK_plusminus                     0x00b1  /* U+00B1 PLUS-MINUS SIGN */
#define XK_twosuperior                   0x00b2  /* U+00B2 SUPERSCRIPT TWO */
#define XK_threesuperior                 0x00b3  /* U+00B3 SUPERSCRIPT THREE */
#define XK_acute                         0x00b4  /* U+00B4 ACUTE ACCENT */
#define XK_mu                            0x00b5  /* U+00B5 MICRO SIGN */
#define XK_paragraph                     0x00b6  /* U+00B6 PILCROW SIGN */
#define XK_periodcentered                0x00b7  /* U+00B7 MIDDLE DOT */
#define XK_cedilla                       0x00b8  /* U+00B8 CEDILLA */
#define XK_onesuperior                   0x00b9  /* U+00B9 SUPERSCRIPT ONE */
#define XK_masculine                     0x00ba  /* U+00BA MASCULINE ORDINAL INDICATOR */
#define XK_guillemotright                0x00bb  /* U+00BB RIGHT-POINTING DOUBLE ANGLE QUOTATION MARK */
#define XK_onequarter                    0x00bc  /* U+00BC VULGAR FRACTION ONE QUARTER */
#define XK_onehalf                       0x00bd  /* U+00BD VULGAR FRACTION ONE HALF */
#define XK_threequarters                 0x00be  /* U+00BE VULGAR FRACTION THREE QUARTERS */
#define XK_questiondown                  0x00bf  /* U+00BF INVERTED QUESTION MARK */
#define XK_Agrave                        0x00c0  /* U+00C0 LATIN CAPITAL LETTER A WITH GRAVE */
#define XK_Aacute                        0x00c1  /* U+00C1 LATIN CAPITAL LETTER A WITH ACUTE */
#define XK_Acircumflex                   0x00c2  /* U+00C2 LATIN CAPITAL LETTER A WITH CIRCUMFLEX */
#define XK_Atilde                        0x00c3  /* U+00C3 LATIN CAPITAL LETTER A WITH TILDE */
#define XK_Adiaeresis                    0x00c4  /* U+00C4 LATIN CAPITAL LETTER A WITH DIAERESIS */
#define XK_Aring                         0x00c5  /* U+00C5 LATIN CAPITAL LETTER A WITH RING ABOVE */
#define XK_AE                            0x00c6  /* U+00C6 LATIN CAPITAL LETTER AE */
#define XK_Ccedilla                      0x00c7  /* U+00C7 LATIN CAPITAL LETTER C WITH CEDILLA */
#define XK_Egrave                        0x00c8  /* U+00C8 LATIN CAPITAL LETTER E WITH GRAVE */
#define XK_Eacute                        0x00c9  /* U+00C9 LATIN CAPITAL LETTER E WITH ACUTE */
#define XK_Ecircumflex                   0x00ca  /* U+00CA LATIN CAPITAL LETTER E WITH CIRCUMFLEX */
#define XK_Ediaeresis                    0x00cb  /* U+00CB LATIN CAPITAL LETTER E WITH DIAERESIS */
#define XK_Igrave                        0x00cc  /* U+00CC LATIN CAPITAL LETTER I WITH GRAVE */
#define XK_Iacute                        0x00cd  /* U+00CD LATIN CAPITAL LETTER I WITH ACUTE */
#define XK_Icircumflex                   0x00ce  /* U+00CE LATIN CAPITAL LETTER I WITH CIRCUMFLEX */
#define XK_Idiaeresis                    0x00cf  /* U+00CF LATIN CAPITAL LETTER I WITH DIAERESIS */
#define XK_ETH                           0x00d0  /* U+00D0 LATIN CAPITAL LETTER ETH */
#define XK_Eth                           0x00d0  /* deprecated */
#define XK_Ntilde                        0x00d1  /* U+00D1 LATIN CAPITAL LETTER N WITH TILDE */
#define XK_Ograve                        0x00d2  /* U+00D2 LATIN CAPITAL LETTER O WITH GRAVE */
#define XK_Oacute                        0x00d3  /* U+00D3 LATIN CAPITAL LETTER O WITH ACUTE */
#define XK_Ocircumflex                   0x00d4  /* U+00D4 LATIN CAPITAL LETTER O WITH CIRCUMFLEX */
#define XK_Otilde                        0x00d5  /* U+00D5 LATIN CAPITAL LETTER O WITH TILDE */
#define XK_Odiaeresis                    0x00d6  /* U+00D6 LATIN CAPITAL LETTER O WITH DIAERESIS */
#define XK_multiply                      0x00d7  /* U+00D7 MULTIPLICATION SIGN */
#define XK_Oslash                        0x00d8  /* U+00D8 LATIN CAPITAL LETTER O WITH STROKE */
#define XK_Ooblique                      0x00d8  /* U+00D8 LATIN CAPITAL LETTER O WITH STROKE */
#define XK_Ugrave                        0x00d9  /* U+00D9 LATIN CAPITAL LETTER U WITH GRAVE */
#define XK_Uacute                        0x00da  /* U+00DA LATIN CAPITAL LETTER U WITH ACUTE */
#define XK_Ucircumflex                   0x00db  /* U+00DB LATIN CAPITAL LETTER U WITH CIRCUMFLEX */
#define XK_Udiaeresis                    0x00dc  /* U+00DC LATIN CAPITAL LETTER U WITH DIAERESIS */
#define XK_Yacute                        0x00dd  /* U+00DD LATIN CAPITAL LETTER Y WITH ACUTE */
#define XK_THORN                         0x00de  /* U+00DE LATIN CAPITAL LETTER THORN */
#define XK_Thorn                         0x00de  /* deprecated */
#define XK_ssharp                        0x00df  /* U+00DF LATIN SMALL LETTER SHARP S */
#define XK_agrave                        0x00e0  /* U+00E0 LATIN SMALL LETTER A WITH GRAVE */
#define XK_aacute                        0x00e1  /* U+00E1 LATIN SMALL LETTER A WITH ACUTE */
#define XK_acircumflex                   0x00e2  /* U+00E2 LATIN SMALL LETTER A WITH CIRCUMFLEX */
#define XK_atilde                        0x00e3  /* U+00E3 LATIN SMALL LETTER A WITH TILDE */
#define XK_adiaeresis                    0x00e4  /* U+00E4 LATIN SMALL LETTER A WITH DIAERESIS */
#define XK_aring                         0x00e5  /* U+00E5 LATIN SMALL LETTER A WITH RING ABOVE */
#define XK_ae                            0x00e6  /* U+00E6 LATIN SMALL LETTER AE */
#define XK_ccedilla                      0x00e7  /* U+00E7 LATIN SMALL LETTER C WITH CEDILLA */
#define XK_egrave                        0x00e8  /* U+00E8 LATIN SMALL LETTER E WITH GRAVE */
#define XK_eacute                        0x00e9  /* U+00E9 LATIN SMALL LETTER E WITH ACUTE */
#define XK_ecircumflex                   0x00ea  /* U+00EA LATIN SMALL LETTER E WITH CIRCUMFLEX */
#define XK_ediaeresis                    0x00eb  /* U+00EB LATIN SMALL LETTER E WITH DIAERESIS */
#define XK_igrave                        0x00ec  /* U+00EC LATIN SMALL LETTER I WITH GRAVE */
#define XK_iacute                        0x00ed  /* U+00ED LATIN SMALL LETTER I WITH ACUTE */
#define XK_icircumflex                   0x00ee  /* U+00EE LATIN SMALL LETTER I WITH CIRCUMFLEX */
#define XK_idiaeresis                    0x00ef  /* U+00EF LATIN SMALL LETTER I WITH DIAERESIS */
#define XK_eth                           0x00f0  /* U+00F0 LATIN SMALL LETTER ETH */
#define XK_ntilde                        0x00f1  /* U+00F1 LATIN SMALL LETTER N WITH TILDE */
#define XK_ograve                        0x00f2  /* U+00F2 LATIN SMALL LETTER O WITH GRAVE */
#define XK_oacute                        0x00f3  /* U+00F3 LATIN SMALL LETTER O WITH ACUTE */
#define XK_ocircumflex                   0x00f4  /* U+00F4 LATIN SMALL LETTER O WITH CIRCUMFLEX */
#define XK_otilde                        0x00f5  /* U+00F5 LATIN SMALL LETTER O WITH TILDE */
#define XK_odiaeresis                    0x00f6  /* U+00F6 LATIN SMALL LETTER O WITH DIAERESIS */
#define XK_division                      0x00f7  /* U+00F7 DIVISION SIGN */
#define XK_oslash                        0x00f8  /* U+00F8 LATIN SMALL LETTER O WITH STROKE */
#define XK_ooblique                      0x00f8  /* U+00F8 LATIN SMALL LETTER O WITH STROKE */
#define XK_ugrave                        0x00f9  /* U+00F9 LATIN SMALL LETTER U WITH GRAVE */
#define XK_uacute                        0x00fa  /* U+00FA LATIN SMALL LETTER U WITH ACUTE */
#define XK_ucircumflex                   0x00fb  /* U+00FB LATIN SMALL LETTER U WITH CIRCUMFLEX */
#define XK_udiaeresis                    0x00fc  /* U+00FC LATIN SMALL LETTER U WITH DIAERESIS */
#define XK_yacute                        0x00fd  /* U+00FD LATIN SMALL LETTER Y WITH ACUTE */
#define XK_thorn                         0x00fe  /* U+00FE LATIN SMALL LETTER THORN */
#define XK_ydiaeresis                    0x00ff  /* U+00FF LATIN SMALL LETTER Y WITH DIAERESIS */



#define XK_Aogonek                       0x01a1  /* U+0104 LATIN CAPITAL LETTER A WITH OGONEK */
#define XK_breve                         0x01a2  /* U+02D8 BREVE */
#define XK_Lstroke                       0x01a3  /* U+0141 LATIN CAPITAL LETTER L WITH STROKE */
#define XK_Lcaron                        0x01a5  /* U+013D LATIN CAPITAL LETTER L WITH CARON */
#define XK_Sacute                        0x01a6  /* U+015A LATIN CAPITAL LETTER S WITH ACUTE */
#define XK_Scaron                        0x01a9  /* U+0160 LATIN CAPITAL LETTER S WITH CARON */
#define XK_Scedilla                      0x01aa  /* U+015E LATIN CAPITAL LETTER S WITH CEDILLA */
#define XK_Tcaron                        0x01ab  /* U+0164 LATIN CAPITAL LETTER T WITH CARON */
#define XK_Zacute                        0x01ac  /* U+0179 LATIN CAPITAL LETTER Z WITH ACUTE */
#define XK_Zcaron                        0x01ae  /* U+017D LATIN CAPITAL LETTER Z WITH CARON */
#define XK_Zabovedot                     0x01af  /* U+017B LATIN CAPITAL LETTER Z WITH DOT ABOVE */
#define XK_aogonek                       0x01b1  /* U+0105 LATIN SMALL LETTER A WITH OGONEK */
#define XK_ogonek                        0x01b2  /* U+02DB OGONEK */
#define XK_lstroke                       0x01b3  /* U+0142 LATIN SMALL LETTER L WITH STROKE */
#define XK_lcaron                        0x01b5  /* U+013E LATIN SMALL LETTER L WITH CARON */
#define XK_sacute                        0x01b6  /* U+015B LATIN SMALL LETTER S WITH ACUTE */
#define XK_caron                         0x01b7  /* U+02C7 CARON */
#define XK_scaron                        0x01b9  /* U+0161 LATIN SMALL LETTER S WITH CARON */
#define XK_scedilla                      0x01ba  /* U+015F LATIN SMALL LETTER S WITH CEDILLA */
#define XK_tcaron                        0x01bb  /* U+0165 LATIN SMALL LETTER T WITH CARON */
#define XK_zacute                        0x01bc  /* U+017A LATIN SMALL LETTER Z WITH ACUTE */
#define XK_doubleacute                   0x01bd  /* U+02DD DOUBLE ACUTE ACCENT */
#define XK_zcaron                        0x01be  /* U+017E LATIN SMALL LETTER Z WITH CARON */
#define XK_zabovedot                     0x01bf  /* U+017C LATIN SMALL LETTER Z WITH DOT ABOVE */
#define XK_Racute                        0x01c0  /* U+0154 LATIN CAPITAL LETTER R WITH ACUTE */
#define XK_Abreve                        0x01c3  /* U+0102 LATIN CAPITAL LETTER A WITH BREVE */
#define XK_Lacute                        0x01c5  /* U+0139 LATIN CAPITAL LETTER L WITH ACUTE */
#define XK_Cacute                        0x01c6  /* U+0106 LATIN CAPITAL LETTER C WITH ACUTE */
#define XK_Ccaron                        0x01c8  /* U+010C LATIN CAPITAL LETTER C WITH CARON */
#define XK_Eogonek                       0x01ca  /* U+0118 LATIN CAPITAL LETTER E WITH OGONEK */
#define XK_Ecaron                        0x01cc  /* U+011A LATIN CAPITAL LETTER E WITH CARON */
#define XK_Dcaron                        0x01cf  /* U+010E LATIN CAPITAL LETTER D WITH CARON */
#define XK_Dstroke                       0x01d0  /* U+0110 LATIN CAPITAL LETTER D WITH STROKE */
#define XK_Nacute                        0x01d1  /* U+0143 LATIN CAPITAL LETTER N WITH ACUTE */
#define XK_Ncaron                        0x01d2  /* U+0147 LATIN CAPITAL LETTER N WITH CARON */
#define XK_Odoubleacute                  0x01d5  /* U+0150 LATIN CAPITAL LETTER O WITH DOUBLE ACUTE */
#define XK_Rcaron                        0x01d8  /* U+0158 LATIN CAPITAL LETTER R WITH CARON */
#define XK_Uring                         0x01d9  /* U+016E LATIN CAPITAL LETTER U WITH RING ABOVE */
#define XK_Udoubleacute                  0x01db  /* U+0170 LATIN CAPITAL LETTER U WITH DOUBLE ACUTE */
#define XK_Tcedilla                      0x01de  /* U+0162 LATIN CAPITAL LETTER T WITH CEDILLA */
#define XK_racute                        0x01e0  /* U+0155 LATIN SMALL LETTER R WITH ACUTE */
#define XK_abreve                        0x01e3  /* U+0103 LATIN SMALL LETTER A WITH BREVE */
#define XK_lacute                        0x01e5  /* U+013A LATIN SMALL LETTER L WITH ACUTE */
#define XK_cacute                        0x01e6  /* U+0107 LATIN SMALL LETTER C WITH ACUTE */
#define XK_ccaron                        0x01e8  /* U+010D LATIN SMALL LETTER C WITH CARON */
#define XK_eogonek                       0x01ea  /* U+0119 LATIN SMALL LETTER E WITH OGONEK */
#define XK_ecaron                        0x01ec  /* U+011B LATIN SMALL LETTER E WITH CARON */
#define XK_dcaron                        0x01ef  /* U+010F LATIN SMALL LETTER D WITH CARON */
#define XK_dstroke                       0x01f0  /* U+0111 LATIN SMALL LETTER D WITH STROKE */
#define XK_nacute                        0x01f1  /* U+0144 LATIN SMALL LETTER N WITH ACUTE */
#define XK_ncaron                        0x01f2  /* U+0148 LATIN SMALL LETTER N WITH CARON */
#define XK_odoubleacute                  0x01f5  /* U+0151 LATIN SMALL LETTER O WITH DOUBLE ACUTE */
#define XK_rcaron                        0x01f8  /* U+0159 LATIN SMALL LETTER R WITH CARON */
#define XK_uring                         0x01f9  /* U+016F LATIN SMALL LETTER U WITH RING ABOVE */
#define XK_udoubleacute                  0x01fb  /* U+0171 LATIN SMALL LETTER U WITH DOUBLE ACUTE */
#define XK_tcedilla                      0x01fe  /* U+0163 LATIN SMALL LETTER T WITH CEDILLA */
#define XK_abovedot                      0x01ff  /* U+02D9 DOT ABOVE */


/*
 * Latin 3
 * Byte 3 = 2
 */


#define XK_leftradical                   0x08a1  /* U+23B7 RADICAL SYMBOL BOTTOM */
#define XK_topleftradical                0x08a2  /*(U+250C BOX DRAWINGS LIGHT DOWN AND RIGHT)*/
#define XK_horizconnector                0x08a3  /*(U+2500 BOX DRAWINGS LIGHT HORIZONTAL)*/
#define XK_topintegral                   0x08a4  /* U+2320 TOP HALF INTEGRAL */
#define XK_botintegral                   0x08a5  /* U+2321 BOTTOM HALF INTEGRAL */
#define XK_vertconnector                 0x08a6  /*(U+2502 BOX DRAWINGS LIGHT VERTICAL)*/
#define XK_topleftsqbracket              0x08a7  /* U+23A1 LEFT SQUARE BRACKET UPPER CORNER */
#define XK_botleftsqbracket              0x08a8  /* U+23A3 LEFT SQUARE BRACKET LOWER CORNER */
#define XK_toprightsqbracket             0x08a9  /* U+23A4 RIGHT SQUARE BRACKET UPPER CORNER */
#define XK_botrightsqbracket             0x08aa  /* U+23A6 RIGHT SQUARE BRACKET LOWER CORNER */
#define XK_topleftparens                 0x08ab  /* U+239B LEFT PARENTHESIS UPPER HOOK */
#define XK_botleftparens                 0x08ac  /* U+239D LEFT PARENTHESIS LOWER HOOK */
#define XK_toprightparens                0x08ad  /* U+239E RIGHT PARENTHESIS UPPER HOOK */
#define XK_botrightparens                0x08ae  /* U+23A0 RIGHT PARENTHESIS LOWER HOOK */
#define XK_leftmiddlecurlybrace          0x08af  /* U+23A8 LEFT CURLY BRACKET MIDDLE PIECE */
#define XK_rightmiddlecurlybrace         0x08b0  /* U+23AC RIGHT CURLY BRACKET MIDDLE PIECE */
#define XK_topleftsummation              0x08b1
#define XK_botleftsummation              0x08b2
#define XK_topvertsummationconnector     0x08b3
#define XK_botvertsummationconnector     0x08b4
#define XK_toprightsummation             0x08b5
#define XK_botrightsummation             0x08b6
#define XK_rightmiddlesummation          0x08b7
#define XK_lessthanequal                 0x08bc  /* U+2264 LESS-THAN OR EQUAL TO */
#define XK_notequal                      0x08bd  /* U+2260 NOT EQUAL TO */
#define XK_greaterthanequal              0x08be  /* U+2265 GREATER-THAN OR EQUAL TO */
#define XK_integral                      0x08bf  /* U+222B INTEGRAL */
#define XK_therefore                     0x08c0  /* U+2234 THEREFORE */
#define XK_variation                     0x08c1  /* U+221D PROPORTIONAL TO */
#define XK_infinity                      0x08c2  /* U+221E INFINITY */
#define XK_nabla                         0x08c5  /* U+2207 NABLA */
#define XK_approximate                   0x08c8  /* U+223C TILDE OPERATOR */
#define XK_similarequal                  0x08c9  /* U+2243 ASYMPTOTICALLY EQUAL TO */
#define XK_ifonlyif                      0x08cd  /* U+21D4 LEFT RIGHT DOUBLE ARROW */
#define XK_implies                       0x08ce  /* U+21D2 RIGHTWARDS DOUBLE ARROW */
#define XK_identical                     0x08cf  /* U+2261 IDENTICAL TO */
#define XK_radical                       0x08d6  /* U+221A SQUARE ROOT */
#define XK_includedin                    0x08da  /* U+2282 SUBSET OF */
#define XK_includes                      0x08db  /* U+2283 SUPERSET OF */
#define XK_intersection                  0x08dc  /* U+2229 INTERSECTION */
#define XK_union                         0x08dd  /* U+222A UNION */
#define XK_logicaland                    0x08de  /* U+2227 LOGICAL AND */
#define XK_logicalor                     0x08df  /* U+2228 LOGICAL OR */
#define XK_partialderivative             0x08ef  /* U+2202 PARTIAL DIFFERENTIAL */
#define XK_function                      0x08f6  /* U+0192 LATIN SMALL LETTER F WITH HOOK */
#define XK_leftarrow                     0x08fb  /* U+2190 LEFTWARDS ARROW */
#define XK_uparrow                       0x08fc  /* U+2191 UPWARDS ARROW */
#define XK_rightarrow                    0x08fd  /* U+2192 RIGHTWARDS ARROW */
#define XK_downarrow                     0x08fe  /* U+2193 DOWNWARDS ARROW */


/*
 * Special
 * (from the DEC VT100 Special Graphics Character Set)
 * Byte 3 = 9
 */


#define XK_blank                         0x09df
#define XK_soliddiamond                  0x09e0  /* U+25C6 BLACK DIAMOND */
#define XK_checkerboard                  0x09e1  /* U+2592 MEDIUM SHADE */
#define XK_ht                            0x09e2  /* U+2409 SYMBOL FOR HORIZONTAL TABULATION */
#define XK_ff                            0x09e3  /* U+240C SYMBOL FOR FORM FEED */
#define XK_cr                            0x09e4  /* U+240D SYMBOL FOR CARRIAGE RETURN */
#define XK_lf                            0x09e5  /* U+240A SYMBOL FOR LINE FEED */
#define XK_nl                            0x09e8  /* U+2424 SYMBOL FOR NEWLINE */
#define XK_vt                            0x09e9  /* U+240B SYMBOL FOR VERTICAL TABULATION */
#define XK_lowrightcorner                0x09ea  /* U+2518 BOX DRAWINGS LIGHT UP AND LEFT */
#define XK_uprightcorner                 0x09eb  /* U+2510 BOX DRAWINGS LIGHT DOWN AND LEFT */
#define XK_upleftcorner                  0x09ec  /* U+250C BOX DRAWINGS LIGHT DOWN AND RIGHT */
#define XK_lowleftcorner                 0x09ed  /* U+2514 BOX DRAWINGS LIGHT UP AND RIGHT */
#define XK_crossinglines                 0x09ee  /* U+253C BOX DRAWINGS LIGHT VERTICAL AND HORIZONTAL */
#define XK_horizlinescan1                0x09ef  /* U+23BA HORIZONTAL SCAN LINE-1 */
#define XK_horizlinescan3                0x09f0  /* U+23BB HORIZONTAL SCAN LINE-3 */
#define XK_horizlinescan5                0x09f1  /* U+2500 BOX DRAWINGS LIGHT HORIZONTAL */
#define XK_horizlinescan7                0x09f2  /* U+23BC HORIZONTAL SCAN LINE-7 */
#define XK_horizlinescan9                0x09f3  /* U+23BD HORIZONTAL SCAN LINE-9 */
#define XK_leftt                         0x09f4  /* U+251C BOX DRAWINGS LIGHT VERTICAL AND RIGHT */
#define XK_rightt                        0x09f5  /* U+2524 BOX DRAWINGS LIGHT VERTICAL AND LEFT */
#define XK_bott                          0x09f6  /* U+2534 BOX DRAWINGS LIGHT UP AND HORIZONTAL */
#define XK_topt                          0x09f7  /* U+252C BOX DRAWINGS LIGHT DOWN AND HORIZONTAL */
#define XK_vertbar                       0x09f8  /* U+2502 BOX DRAWINGS LIGHT VERTICAL */


