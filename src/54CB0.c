#include "common.h"

#include "game/data.h"
#include "game/malloc.h"

/* Board spaces and chains. C from MP1 src/engine/spaces.c (BoardSpace there is MP2's SpaceData,
   ChainData MP3's LinkData) and MP3 ovl_80_shared_board FA250.c (MBMasu*); the rest have no
   reference or differ (near) and stay asm. */

#define SPACE_TYPE_TOTAL 18
#define SPACE_INDEX_INVALID -1

typedef struct LinkData {
    /* 0x00 */ s16 chainIndicies;
    /* 0x02 */ s16 unk2;
    /* 0x04 */ s16* spaces;
} LinkData; // size 0x8

typedef struct EventTableEntry {
    s16 spaceIndex;
    void* eventList;
} EventTableEntry;

extern u16 gTotalSpaces; //total current board spaces
extern void* D_800CC280_CCE80;
extern u16 D_800E18D2_E24D2;
extern SpaceData* D_800E18D4_E24D4;
extern LinkData* D_800E18D8_E24D8;
extern void* D_800E18E0_E24E0[];
extern void* D_800E192C_E252C;
extern void* D_800E1930_E2530;
extern void* D_800E1934_E2534;
extern void* D_800E1938_E2538;
extern f32 D_800E1940_E2540[];
extern s32 D_800E1960_E2560;
extern u16 D_800FCE90_FDA90;
extern u8 D_800CC570_CD170[];
extern s16 D_800E1B66_E2766;
extern s16 D_800E1B88_E2788; //total blue spaces hidden blocks cannot spawn on
extern s16 D_800E1B68_E2768[];
extern s16 D_800E1968_E2568[];
SpaceData* GetSpaceData(s16);
s32 MBRand(f32 arg0);
void LoadSpaceTextures(s16 type);
void MBMasuDraw(void);
f32 MBDBackMdlScaleGet(void);
u16* func_8005484C_5544C(void*, s32);
void func_8002D018_2DC18(s32, void* func);
void SetPlayerOntoChain(s16 player, s16 chain_index, s16 space_index);
void func_800552E8_55EE8(void);
void func_800553EC_55FEC(void);
void func_800554EC_560EC(void);
void func_800555EC_561EC(s16 arg0, void* arg1);

INCLUDE_ASM("asm/nonmatchings/54CB0", LoadSpaceTextures);

void FreeSpaceTextures(void) {
   s32 i;
   for (i = 0; i < SPACE_TYPE_TOTAL; i++) {
      if (D_800E18E0_E24E0[i] != NULL) {
         DataClose(D_800E18E0_E24E0[i]);
      }
      D_800E18E0_E24E0[i] = NULL;
   }
}

INCLUDE_ASM("asm/nonmatchings/54CB0", func_80054228_54E28);

void MBMasuArrowAngleAdd(f32 arg0) {
    if (D_800E1960_E2560 != 8) {
        D_800E1940_E2540[D_800E1960_E2560++] = arg0;
    }
}

void func_8005429C_54E9C(void) {
    FreeSpaceTextures();
}

void ChangeSpaceTextures(s16 type) {
   FreeSpaceTextures();
   LoadSpaceTextures(type);
}

INCLUDE_ASM("asm/nonmatchings/54CB0", func_800542E8_54EE8);

INCLUDE_ASM("asm/nonmatchings/54CB0", MBMasuDraw);

INCLUDE_ASM("asm/nonmatchings/54CB0", func_8005484C_5544C);

s32 MBMasuCreate(s32 arg0, s32 arg1) {
    f32 sp10[3];
    LinkData* var_s1_2;
    SpaceData* var_s1;
    s16* temp_v0_3;
    u16* var_s0_2;
    s32 var_s2;
    s32 var_v1;
    u16* temp_s3;
    u16* temp_v0_2;
    struct var_s0* var_s0;

    D_800CC280_CCE80 = DataRead((arg0 << 0x10) | (arg1 << 0x10 >> 0x10));
    if (D_800CC280_CCE80 != NULL) {
        D_800E192C_E252C = 0;
        D_800E1930_E2530 = 0;
        D_800E1934_E2534 = 0;
        D_800E1938_E2538 = 0;
        var_s0_2 = D_800CC280_CCE80;
        gTotalSpaces = var_s0_2[0];
        D_800E18D2_E24D2 = var_s0_2[1];
        D_800E18D4_E24D4 = HuMemMemoryAllocTemp(gTotalSpaces * 0x24);
        var_s0_2 = func_8005484C_5544C(D_800CC280_CCE80, 4);
        var_s1 = D_800E18D4_E24D4;
        for (var_s2 = 0; var_s2 < gTotalSpaces; var_s2++) {
            var_s1->unk_00 = 1;
            var_s1->unk_02 = *var_s0_2++;
            var_s1->space_type = *var_s0_2++;
            sp10[0] = var_s1->coords.x = (((f32*)var_s0_2))[0] * 5.0f * MBDBackMdlScaleGet();
            sp10[1] = var_s1->coords.y = (((f32*)var_s0_2))[1] * 5.0f * MBDBackMdlScaleGet();
            sp10[2] = var_s1->coords.z = (((f32*)var_s0_2))[2] * 5.0f * MBDBackMdlScaleGet();
            var_s0_2 += 6;
            var_s1->rot.x = MBDBackMdlScaleGet();
            var_s1->rot.y = MBDBackMdlScaleGet();
            var_s1->rot.z = MBDBackMdlScaleGet();
            var_s1->event_list = NULL;
            var_s1 += 1;
        }
        D_800E18D8_E24D8 = HuMemMemoryAllocTemp(D_800E18D2_E24D2 * 8);
        temp_s3 = func_8005484C_5544C(D_800CC280_CCE80, 6);
        var_s1_2 = D_800E18D8_E24D8;
        for (var_s2 = 0; var_s2 < D_800E18D2_E24D2; var_s2++) {
            var_s0_2 = func_8005484C_5544C(temp_s3, var_s2 * 2);
            var_s1_2->chainIndicies = *var_s0_2++;
            var_s1_2->spaces = HuMemMemoryAllocTemp(((var_s1_2->chainIndicies << 1)));
            temp_v0_3 = var_s1_2->spaces;
            for (var_v1 = 0; var_v1 < var_s1_2->chainIndicies; var_v1++) {
                *temp_v0_3++ = *var_s0_2++;
            }
            var_s1_2 += 1;
        }
        DataClose(D_800CC280_CCE80);
        func_8002D018_2DC18(1, &MBMasuDraw);
        D_800FCE90_FDA90 = 1;
    }
    D_800E1B66_E2766 = 0;
    D_800E1B88_E2788 = 0;

    return 0;
}

INCLUDE_ASM("asm/nonmatchings/54CB0", func_80054AE8_556E8);

SpaceData *GetSpaceData(s16 arg0) {
    return &D_800E18D4_E24D4[arg0];
}

s16 GetAbsSpaceIndexFromChainSpaceIndex(u16 chainIndex, u16 spaceIndex) {
   return D_800E18D8_E24D8[chainIndex].spaces[spaceIndex];
}

s16 BoardGetChainLength(u16 chainIndex) {
   return D_800E18D8_E24D8[chainIndex].chainIndicies;
}

s16 GetChainSpaceIndexFromAbsSpaceIndex(s16 absIndex, s32 chainIndex) {
   s32 i;
   for (i = 0; i < BoardGetChainLength(chainIndex); i++) {
      if (GetAbsSpaceIndexFromChainSpaceIndex(chainIndex, i) == absIndex) {
         return i;
      }
   }
   return SPACE_INDEX_INVALID;
}

INCLUDE_ASM("asm/nonmatchings/54CB0", func_80054C78_55878);

INCLUDE_ASM("asm/nonmatchings/54CB0", func_80054D3C_5593C);

void func_80054DEC_559EC(void) {
    LinkData *chain;
    s16 *space;
    s16 i;
    s16 j;
    s16 k;

    chain = D_800E18D8_E24D8;

    for (i = 0; i < D_800E18D2_E24D2; i++) {
        space = chain->spaces;

        for (j = 0; j < chain->chainIndicies; j++) {
            if (GetSpaceData(*space)->space_type == 0) {
                for (k = 0; k < 4; k++) {
                    SetPlayerOntoChain(k, i, j);
                }
                return;
            }
            space++;
        }
        chain++;
    }

    for (k = 0; k < 4; k++) {
        SetPlayerOntoChain(k, 0, 0);
    }
}

s16 BoardGetRandomSpaceTypeInChain(u16 type, u16 chainIndex) {
   u8 randByte;
   s32 i;
   SpaceData *space;
   s32 chainLen;

   chainLen = BoardGetChainLength(chainIndex);
   randByte = (rand8() % 30) + 1;

   i = 0;
   while (TRUE) {
      s16 absIndex = GetAbsSpaceIndexFromChainSpaceIndex(chainIndex, i);
      space = GetSpaceData(absIndex);

      // Get Nth space in chain of type
      if ((D_800CC570_CD170[space->space_type & 0xf] & type) != 0)
         if (--randByte == 0) {
            break;
      }
      // Wrap around
      if (++i >= chainLen) {
         i = 0;
      }
   }

   return i;
}

s16 func_80055008_55C08(u16 arg0, u8 arg1) {
    u8 var_s1;
    SpaceData* space;
    s32 i, j;
    var_s1 = 0;

    for (i = 0; i < gTotalSpaces; i++) {
        space = GetSpaceData(i);
        if (D_800CC570_CD170[space->space_type & 0xF] & arg0) {
            var_s1++;
        }
    }

    var_s1 -= D_800E1B88_E2788;
    if (arg1 < 5) {
        var_s1 -= D_800E1B66_E2766;
    }

    var_s1 = MBRand(var_s1);

    for (i = 0;; i = (++i < gTotalSpaces) ? i : 0) {
        space = GetSpaceData(i);
        for (j = 0; j < D_800E1B88_E2788; j++) {
            if (D_800E1B68_E2768[j] == i) {
                break;
            }
        }

        if (j == D_800E1B88_E2788) {
            if (arg1 < 5) {
                for (j = 0; j < D_800E1B66_E2766; j++) {
                    if (D_800E1968_E2568[j] == i) {
                        break;
                    }
                }

                if (j == D_800E1B66_E2766) {
                    if (D_800CC570_CD170[space->space_type & 0xF] & arg0) {
                        if (var_s1 == 0) {
                            break;
                        }
                        var_s1--;
                    }
                }
            } else {
                if (D_800CC570_CD170[space->space_type & 0xF] & arg0) {
                    if (var_s1 == 0) {
                        break;
                    }
                    var_s1--;
                }
            }
        }
    }
    return i;
}


void BoardSpaceTypeSet(s16 spaceIndex, u8 spaceType) {
   SpaceData *space;

   space = GetSpaceData(spaceIndex);
   space->space_type = spaceType;
}

void BoardSetSpaceTypeInChain(u16 chainIndex, u16 oldType, u8 newType) {
   s32 chainLen;
   s16 absIndex;
   SpaceData *space;
   s32 i;

   chainLen = BoardGetChainLength(chainIndex);
   for (i = 0; i < chainLen; i++) {
      absIndex = GetAbsSpaceIndexFromChainSpaceIndex(chainIndex, i);
      space = GetSpaceData(absIndex);
      if (space->space_type == oldType) {
         space->space_type = newType;
      }
   }
}

void func_800552E8_55EE8(void) {
    SpaceData* temp_v0;
    f32 temp_f22;
    f32 var_f20;
    Process* proc =  HuPrcCurrentGet();

    temp_v0 = GetSpaceData((s16)proc->user_data);
    temp_f22 = temp_v0->rot.x;
    var_f20 = temp_f22 + 0.03f;
    if (D_800CC280_CCE80 != 0) {
        while (1) {
            HuPrcVSleep();
            
            var_f20 -= 0.005f;
            if (var_f20 <= temp_f22) {
                var_f20 = temp_f22;
            }
            
            temp_v0->rot.x = var_f20;
            temp_v0->rot.z = var_f20;
            if ((var_f20 <= temp_f22) || (D_800CC280_CCE80 == 0)) {
                break;
            }            
        }

    }
    omDelPrcObj(NULL);
}

void func_800553A8_55FA8(s16 spaceIndex) {
   Process *process;
   process = omAddPrcObj(func_800552E8_55EE8, 0xEF00, 0, 0);
   process->user_data = (void *)(s32)spaceIndex;
}

void func_800553EC_55FEC(void) {
   Process *process;
   SpaceData *space;
   f32 fval;

   process = HuPrcCurrentGet();
   space = GetSpaceData((s32)process->user_data);

   fval = 1.0f;
   if (D_800CC280_CCE80 != NULL) {
      do {
         HuPrcVSleep();
         fval -= 0.1f;
         if (fval <= 0.0f) {
            fval = 0.0f;
         }

         space->rot.x = fval;
         space->rot.z = fval;
      }
      while (!(fval <= 0.0f) && D_800CC280_CCE80 != NULL);
   }

    omDelPrcObj(NULL);
}

void func_800554A8_560A8(s16 spaceIndex) {
   Process *process;
   process = omAddPrcObj(func_800553EC_55FEC, 0xEF00, 0, 0);
   process->user_data = (void *)(s32)spaceIndex;
}

void func_800554EC_560EC(void) {
   Process *process;
   SpaceData *space;
   f32 fval;

   process = HuPrcCurrentGet();
   space = GetSpaceData((s32)process->user_data);

   fval = 0.0f;
   if (D_800CC280_CCE80 != NULL) {
      do {
         HuPrcVSleep();

         fval += 0.1f;
         if (fval >= 1.0f) {
            fval = 1.0f;
         }

         space->rot.x = fval;
         space->rot.z = fval;
      } while (!(fval >= 1.0f) && D_800CC280_CCE80 != NULL);
   }

   omDelPrcObj(NULL);
}

void func_800555A8_561A8(s16 spaceIndex) {
   Process *process;
   process = omAddPrcObj(func_800554EC_560EC, 0xEF00, 0, 0);
   process->user_data = (void *)(s32)spaceIndex;
}

void func_800555EC_561EC(s16 arg0, void *arg1) {
    switch (arg0) {
        case -2:
            D_800E192C_E252C = arg1;
            break;
        case -3:
            D_800E1930_E2530 = arg1;
            break;
        case -4:
            D_800E1934_E2534 = arg1;
            break;
        case -5:
            D_800E1938_E2538 = arg1;
            break;
        default:
            GetSpaceData(arg0)->event_list = arg1;
            break;
    }
}

void EventTableHydrate(EventTableEntry *table) {
   while (table->spaceIndex != -1) {
      func_800555EC_561EC(table->spaceIndex, table->eventList);
      table++;
   }
}

INCLUDE_ASM("asm/nonmatchings/54CB0", func_800556F4_562F4);

INCLUDE_ASM("asm/nonmatchings/54CB0", func_800558DC_564DC);

INCLUDE_ASM("asm/nonmatchings/54CB0", func_800558E8_564E8);

INCLUDE_ASM("asm/nonmatchings/54CB0", func_800558F4_564F4);

s16 func_80055900_56500(u8 arg0) {
    return func_80055008_55C08(2, arg0);
}

void func_80055928_56528(s16 *arg0) {
    s32 i;

    for (i = 0; *arg0 != -1; i++) {
        D_800E1968_E2568[i] = *arg0++;
    }
    
    D_800E1B66_E2766 = i;
}

void func_80055980_56580(s16 *arg0) {
    s32 i;

    for (i = 0; *arg0 != -1; i++) {
        D_800E1B68_E2768[i] = *arg0++;
    }
    
    D_800E1B88_E2788 = i;
}
