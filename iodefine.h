#ifndef __3048_H__
#define __3048_H__

#ifdef __cplusplus
extern "C" {
#endif

typedef unsigned long int _LONG;
typedef unsigned int      _WORD;
typedef unsigned char     _BYTE;

struct st_sam {                                         // struct DMAC
              void             *MAR;                    // MAR
              unsigned int      ETCR;                   // ETCR
              unsigned char     IOAR;                   // IOAR
              union {                                   // DTCR
                    unsigned char BYTE;                 //  Byte Access
                    struct {                            //  Bit  Access
                           unsigned char DTE :1;        //    DTE
                           unsigned char DTSZ:1;        //    DTSZ
                           unsigned char DTID:1;        //    DTID
                           unsigned char RPE :1;        //    RPE
                           unsigned char DTIE:1;        //    DTIE
                           unsigned char DTS :3;        //    DTS
                           }      BIT;                  //
                    }           DTCR;                   //
};                                                      //
struct st_fam {                                         // struct DMAC
              void             *MARA;                   // MARA
              unsigned int      ETCRA;                  // ETCRA
              char              wk1;                    //
              union {                                   // DTCRA
                    unsigned char BYTE;                 //  Byte Access
                    struct {                            //  Bit  Access
                           unsigned char DTE  :1;       //    DTE
                           unsigned char DTSZ :1;       //    DTSZ
                           unsigned char SAID :1;       //    SAID
                           unsigned char SAIDE:1;       //    SAIDE
                           unsigned char DTIE :1;       //    DTIE
                           unsigned char DTS  :3;       //    DTS
                           }      BIT;                  //
                    }           DTCRA;                  //
              void             *MARB;                   // MARB
              unsigned int      ETCRB;                  // ETCRB
              char              wk2;                    //
              union {                                   // DTCRB
                    unsigned char BYTE;                 //  Byte Access
                    struct {                            //  Bit  Access
                           unsigned char DTME :1;       //    DTME
                           unsigned char      :1;       //
                           unsigned char DAID :1;       //    DAID
                           unsigned char DAIDE:1;       //    DAIDE
                           unsigned char TMS  :1;       //    TMS
                           unsigned char DTS  :3;       //    DTS
                           }      BIT;                  //
                    }           DTCRB;                  //
};                                                      //
struct st_flash {                                       // struct FLASH
                union {                                 // FLMCR
                      unsigned char BYTE;               //  Byte Access
                      struct {                          //  Bit  Access
                             unsigned char VPP :1;      //    VPP
                             unsigned char VPPE:1;      //    VPPE
                             unsigned char     :2;      //
                             unsigned char EV  :1;      //    EV
                             unsigned char PV  :1;      //    PV
                             unsigned char E   :1;      //    E
                             unsigned char P   :1;      //    P
                             }      BIT;                //
                      }         FLMCR;                  //
                char            wk1;                    //
                union {                                 // EBR1
                      unsigned char BYTE;               //  Byte Access
                      struct {                          //  Bit  Access
                             unsigned char LB7:1;       //    LB7
                             unsigned char LB6:1;       //    LB6
                             unsigned char LB5:1;       //    LB5
                             unsigned char LB4:1;       //    LB4
                             unsigned char LB3:1;       //    LB3
                             unsigned char LB2:1;       //    LB2
                             unsigned char LB1:1;       //    LB1
                             unsigned char LB0:1;       //    LB0
                             }      BIT;                //
                      }         EBR1;                   //
                union {                                 // EBR2
                      unsigned char BYTE;               //  Byte Access
                      struct {                          //  Bit  Access
                             unsigned char SB7:1;       //    SB7
                             unsigned char SB6:1;       //    SB6
                             unsigned char SB5:1;       //    SB5
                             unsigned char SB4:1;       //    SB4
                             unsigned char SB3:1;       //    SB3
                             unsigned char SB2:1;       //    SB2
                             unsigned char SB1:1;       //    SB1
                             unsigned char SB0:1;       //    SB0
                             }      BIT;                //
                      }         EBR2;                   //
                char            wk2[4];                 //
                union {                                 // RAMCR
                      unsigned char BYTE;               //  Byte Access
                      struct {                          //  Bit  Access
                             unsigned char FLER:1;      //    FLER
                             unsigned char     :3;      //
                             unsigned char RAMS:1;      //    RAMS
                             unsigned char RAM :3;      //    RAM
                             }      BIT;                //
                      }         RAMCR;                  //
};                                                      //
struct st_itu {                                         // struct ITU
              union {                                   // TSTR
                    unsigned char BYTE;                 //  Byte Access
                    struct {                            //  Bit  Access
                           unsigned char     :3;        //
                           unsigned char STR4:1;        //    STR4
                           unsigned char STR3:1;        //    STR3
                           unsigned char STR2:1;        //    STR2
                           unsigned char STR1:1;        //    STR1
                           unsigned char STR0:1;        //    STR0
                           }      BIT;                  //
                    }           TSTR;                   //
              union {                                   // TSNC
                    unsigned char BYTE;                 //  Byte Access
                    struct {                            //  Bit  Access
                           unsigned char      :3;       //
                           unsigned char SYNC4:1;       //    SYNC4
                           unsigned char SYNC3:1;       //    SYNC3
                           unsigned char SYNC2:1;       //    SYNC2
                           unsigned char SYNC1:1;       //    SYNC1
                           unsigned char SYNC0:1;       //    SYNC0
                           }      BIT;                  //
                    }           TSNC;                   //
              union {                                   // TMDR
                    unsigned char BYTE;                 //  Byte Access
                    struct {                            //  Bit  Access
                           unsigned char     :1;        //
                           unsigned char MDF :1;        //    MDF
                           unsigned char FDIR:1;        //    FDIR
                           unsigned char PWM4:1;        //    PWM4
                           unsigned char PWM3:1;        //    PWM3
                           unsigned char PWM2:1;        //    PWM2
                           unsigned char PWM1:1;        //    PWM1
                           unsigned char PWM0:1;        //    PWM0
                           }      BIT;                  //
                    }           TMDR;                   //
              union {                                   // TFCR
                    unsigned char BYTE;                 //  Byte Access
                    struct {                            //  Bit  Access
                           unsigned char     :2;        //
                           unsigned char CMD :2;        //    CMD
                           unsigned char BFB4:1;        //    BFB4
                           unsigned char BFA4:1;        //    BFA4
                           unsigned char BFB3:1;        //    BFB3
                           unsigned char BFA3:1;        //    BFA3
                           }      BIT;                  //
                    }           TFCR;                   //
              char              wk[44];                 //
              union {                                   // TOER
                    unsigned char BYTE;                 //  Byte Access
                    struct {                            //  Bit  Access
                           unsigned char     :2;        //
                           unsigned char EXB4:1;        //    EXB4
                           unsigned char EXA4:1;        //    EXA4
                           unsigned char EB3 :1;        //    EB3
                           unsigned char EB4 :1;        //    EB4
                           unsigned char EA4 :1;        //    EA4
                           unsigned char EA3 :1;        //    EA3
                           }      BIT;                  //
                    }           TOER;                   //
              union {                                   // TOCR
                    unsigned char BYTE;                 //  Byte Access
                    struct {                            //  Bit  Access
                           unsigned char     :3;        //
                           unsigned char XTGD:1;        //    XTGD
                           unsigned char     :2;        //
                           unsigned char OLS4:1;        //    OLS4
                           unsigned char OLS3:1;        //    OLS3
                           }      BIT;                  //
                    }           TOCR;                   //
};                                                      //
struct st_itu0 {                                        // struct ITU0
               union {                                  // TCR
                     unsigned char BYTE;                //  Byte Access
                     struct {                           //  Bit  Access
                            unsigned char     :1;       //
                            unsigned char CCLR:2;       //    CCLR
                            unsigned char CKEG:2;       //    CKEG
                            unsigned char TPSC:3;       //    TPSC
                            }      BIT;                 //
                     }          TCR;                    //
               union {                                  // TIOR
                     unsigned char BYTE;                //  Byte Access
                     struct {                           //  Bit  Access
                            unsigned char    :1;        //
                            unsigned char IOB:3;        //    IOB
                            unsigned char    :1;        //
                            unsigned char IOA:3;        //    IOA
                            }      BIT;                 //
                     }          TIOR;                   //
               union {                                  // TIER
                     unsigned char BYTE;                //  Byte Access
                     struct {                           //  Bit  Access
                            unsigned char      :5;      //
                            unsigned char OVIE :1;      //    OVIE
                            unsigned char IMIEB:1;      //    IMIEB
                            unsigned char IMIEA:1;      //    IMIEA
                            }      BIT;                 //
                     }          TIER;                   //
               union {                                  // TSR
                     unsigned char BYTE;                //  Byte Access
                     struct {                           //  Bit  Access
                            unsigned char     :5;       //
                            unsigned char OVF :1;       //    OVF
                            unsigned char IMFB:1;       //    IMFB
                            unsigned char IMFA:1;       //    IMFA
                            }      BIT;                 //
                     }          TSR;                    //
               unsigned int     TCNT;                   // TCNT
               unsigned int     GRA;                    // GRA
               unsigned int     GRB;                    // GRB
};                                                      //
struct st_itu3 {                                        // struct ITU3
               union {                                  // TCR
                     unsigned char BYTE;                //  Byte Access
                     struct {                           //  Bit  Access
                            unsigned char     :1;       //
                            unsigned char CCLR:2;       //    CCLR
                            unsigned char CKEG:2;       //    CKEG
                            unsigned char TPSC:3;       //    TPSC
                            }      BIT;                 //
                     }          TCR;                    //
               union {                                  // TIOR
                     unsigned char BYTE;                //  Byte Access
                     struct {                           //  Bit  Access
                            unsigned char    :1;        //
                            unsigned char IOB:3;        //    IOB
                            unsigned char    :1;        //
                            unsigned char IOA:3;        //    IOA
                            }      BIT;                 //
                     }          TIOR;                   //
               union {                                  // TIER
                     unsigned char BYTE;                //  Byte Access
                     struct {                           //  Bit  Access
                            unsigned char      :5;      //
                            unsigned char OVIE :1;      //    OVIE
                            unsigned char IMIEB:1;      //    IMIEB
                            unsigned char IMIEA:1;      //    IMIEA
                            }      BIT;                 //
                     }          TIER;                   //
               union {                                  // TSR
                     unsigned char BYTE;                //  Byte Access
                     struct {                           //  Bit  Access
                            unsigned char     :5;       //
                            unsigned char OVF :1;       //    OVF
                            unsigned char IMFB:1;       //    IMFB
                            unsigned char IMFA:1;       //    IMFA
                            }      BIT;                 //
                     }          TSR;                    //
               unsigned int     TCNT;                   // TCNT
               unsigned int     GRA;                    // GRA
               unsigned int     GRB;                    // GRB
               unsigned int     BRA;                    // BRA
               unsigned int     BRB;                    // BRB
};                                                      //
struct st_tpc {                                         // struct TPC
              union {                                   // TPMR
                    unsigned char BYTE;                 //  Byte Access
                    struct {                            //  Bit  Access
                           unsigned char      :4;       //
                           unsigned char G3NOV:1;       //    G3NOV
                           unsigned char G2NOV:1;       //    G2NOV
                           unsigned char G1NOV:1;       //    G1NOV
                           unsigned char G0NOV:1;       //    G0NOV
                           }      BIT;                  //
                    }           TPMR;                   //
              union {                                   // TPCR
                    unsigned char BYTE;                 //  Byte Access
                    struct {                            //  Bit  Access
                           unsigned char G3CMS:2;       //    G3CMS
                           unsigned char G2CMS:2;       //    G2CMS
                           unsigned char G1CMS:2;       //    G1CMS
                           unsigned char G0CMS:2;       //    G0CMS
                           }      BIT;                  //
                    }           TPCR;                   //
              union {                                   // NDERB
                    unsigned char BYTE;                 //  Byte Access
                    struct {                            //  Bit  Access
                           unsigned char B15:1;         //    NDER15
                           unsigned char B14:1;         //    NDER14
                           unsigned char B13:1;         //    NDER13
                           unsigned char B12:1;         //    NDER12
                           unsigned char B11:1;         //    NDER11
                           unsigned char B10:1;         //    NDER10
                           unsigned char B9 :1;         //    NDER9
                           unsigned char B8 :1;         //    NDER8
                           }      BIT;                  //
                    }           NDERB;                  //
              union {                                   // NDERA
                    unsigned char BYTE;                 //  Byte Access
                    struct {                            //  Bit  Access
                           unsigned char B7:1;          //    NDER7
                           unsigned char B6:1;          //    NDER6
                           unsigned char B5:1;          //    NDER5
                           unsigned char B4:1;          //    NDER4
                           unsigned char B3:1;          //    NDER3
                           unsigned char B2:1;          //    NDER2
                           unsigned char B1:1;          //    NDER1
                           unsigned char B0:1;          //    NDER0
                           }      BIT;                  //
                    }           NDERA;                  //
              union {                                   // NDRB (H'A4)
                    unsigned char BYTE;                 //  Byte Access
                    struct {                            //  Bit  Access
                           unsigned char B15:1;         //    NDR15
                           unsigned char B14:1;         //    NDR14
                           unsigned char B13:1;         //    NDR13
                           unsigned char B12:1;         //    NDR12
                           unsigned char B11:1;         //    NDR11
                           unsigned char B10:1;         //    NDR10
                           unsigned char B9 :1;         //    NDR9
                           unsigned char B8 :1;         //    NDR8
                           }      BIT;                  //
                    }           NDRB1;                  //
              union {                                   // NDRA (H'A5)
                    unsigned char BYTE;                 //  Byte Access
                    struct {                            //  Bit  Access
                           unsigned char B7:1;          //    NDR7
                           unsigned char B6:1;          //    NDR6
                           unsigned char B5:1;          //    NDR5
                           unsigned char B4:1;          //    NDR4
                           unsigned char B3:1;          //    NDR3
                           unsigned char B2:1;          //    NDR2
                           unsigned char B1:1;          //    NDR1
                           unsigned char B0:1;          //    NDR0
                           }      BIT;                  //
                    }           NDRA1;                  //
              union {                                   // NDRB (H'A6)
                    unsigned char BYTE;                 //  Byte Access
                    struct {                            //  Bit  Access
                           unsigned char    :4;         //
                           unsigned char B11:1;         //    NDR11
                           unsigned char B10:1;         //    NDR10
                           unsigned char B9 :1;         //    NDR9
                           unsigned char B8 :1;         //    NDR8
                           }      BIT;                  //
                    }           NDRB2;                  //
              union {                                   // NDRA (H'A7)
                    unsigned char BYTE;                 //  Byte Access
                    struct {                            //  Bit  Access
                           unsigned char   :4;          //
                           unsigned char B3:1;          //    NDR3
                           unsigned char B2:1;          //    NDR2
                           unsigned char B1:1;          //    NDR1
                           unsigned char B0:1;          //    NDR0
                           }      BIT;                  //
                    }           NDRA2;                  //
};                                                      //
union un_wdt {                                          // union WDT
             struct {                                   // Read  Access
                    union {                             // TCSR
                          unsigned char BYTE;           //  Byte Access
                          struct {                      //  Bit  Access
                                 unsigned char OVF :1;  //    OVF
                                 unsigned char WTIT:1;  //    WT/IT
                                 unsigned char TME :1;  //    TME
                                 unsigned char     :2;  //
                                 unsigned char CKS :3;  //    CKS
                                 }      BIT;            //
                          }       TCSR;                 //
                    unsigned char TCNT;                 // TCNT
                    char          wk;                   //
                    union {                             // RSTCSR
                          unsigned char BYTE;           //  Byte Access
                          struct {                      //
                                 unsigned char WRST :1; //    WSRT
                                 unsigned char RSTOE:1; //    RSTOE
                                 }      BIT;            //
                          }       RSTCSR;               //
                    } READ;                             //
             struct {                                   // Write Access
                    unsigned int  TCSR;                 // TCSR/TCNT
                    unsigned int  RSTCSR;               // RSTCSR
                    } WRITE;                            //
};                                                      //
struct st_rfshc {                                       // struct RFSHC
                union {                                 // RFSHCR
                      unsigned char BYTE;               //  Byte Access
                      struct {                          //  Bit  Access
                             unsigned char SRFMD :1;    //    SRFMD
                             unsigned char PSRAME:1;    //    PSRAME
                             unsigned char DRAME :1;    //    DRAME
                             unsigned char CASWE :1;    //    CASWE
                             unsigned char M9M8  :1;    //    M9M8
                             unsigned char RFSHE :1;    //    RFSHE
                             unsigned char       :1;    //
                             unsigned char RCYCE :1;    //    RCYCE
                             }      BIT;                //
                      }         RFSHCR;                 //
                union {                                 // RTMCSR
                      unsigned char BYTE;               //  Byte Access
                      struct {                          //  Bit  Access
                             unsigned char CMF :1;      //    CMF
                             unsigned char CMIE:1;      //    CMIE
                             unsigned char CKS :3;      //    CKS
                             }      BIT;                //
                      }         RTMCSR;                 //
                unsigned char   RTCNT;                  // RTCNT
                unsigned char   RTCOR;                  // RTCOR
};                                                      //
struct st_sci0 {                                        // struct SCI0
               union {                                  // SMR
                     unsigned char BYTE;                //  Byte Access
                     struct {                           //  Bit  Access
                            unsigned char CA  :1;       //    C/A
                            unsigned char CHR :1;       //    CHR
                            unsigned char PE  :1;       //    PE
                            unsigned char OE  :1;       //    O/E
                            unsigned char STOP:1;       //    STOP
                            unsigned char MP  :1;       //    MP
                            unsigned char CKS :2;       //    CKS
                            }      BIT;                 //
                     }          SMR;                    //
               unsigned char    BRR;                    // BRR
               union {                                  // SCR
                     unsigned char BYTE;                //  Byte Access
                     struct {                           //  Bit  Access
                            unsigned char TIE :1;       //    TIE
                            unsigned char RIE :1;       //    RIE
                            unsigned char TE  :1;       //    TE
                            unsigned char RE  :1;       //    RE
                            unsigned char MPIE:1;       //    MPIE
                            unsigned char TEIE:1;       //    TEIE
                            unsigned char CKE :2;       //    CKE
                            }      BIT;                 //
                     }          SCR;                    //
               unsigned char    TDR;                    // TDR
               union {                                  // SSR
                     unsigned char BYTE;                //  Byte Access
                     struct {                           //  Bit  Access
                            unsigned char TDRE:1;       //    TDRE
                            unsigned char RDRF:1;       //    RDRF
                            unsigned char ORER:1;       //    ORER
                            unsigned char FER :1;       //    FER
                            unsigned char PER :1;       //    PER
                            unsigned char TEND:1;       //    TEND
                            unsigned char MPB :1;       //    MPB
                            unsigned char MPBT:1;       //    MPBT
                            }      BIT;                 //
                     }          SSR;                    //
               unsigned char    RDR;                    // RDR
               union {                                  // SCMR
                     unsigned char BYTE;                //  Byte Access
                     struct {                           //  Bit  Access
                            unsigned char     :4;       //
                            unsigned char SDIR:1;       //    SDIR
                            unsigned char SINV:1;       //    SINV
                            unsigned char     :1;       //
                            unsigned char SMIF:1;       //    SMIF
                            }      BIT;                 //
                     }          SCMR;                   //
};                                                      //
struct st_sci1 {                                        // struct SCI1
               union {                                  // SMR
                     unsigned char BYTE;                //  Byte Access
                     struct {                           //  Bit  Access
                            unsigned char CA  :1;       //    C/A
                            unsigned char CHR :1;       //    CHR
                            unsigned char PE  :1;       //    PE
                            unsigned char OE  :1;       //    O/E
                            unsigned char STOP:1;       //    STOP
                            unsigned char MP  :1;       //    MP
                            unsigned char CKS :2;       //    CKS
                            }      BIT;                 //
                     }          SMR;                    //
               unsigned char    BRR;                    // BRR
               union {                                  // SCR
                     unsigned char BYTE;                //  Byte Access
                     struct {                           //  Bit  Access
                            unsigned char TIE :1;       //    TIE
                            unsigned char RIE :1;       //    RIE
                            unsigned char TE  :1;       //    TE
                            unsigned char RE  :1;       //    RE
                            unsigned char MPIE:1;       //    MPIE
                            unsigned char TEIE:1;       //    TEIE
                            unsigned char CKE :2;       //    CKE
                            }      BIT;                 //
                     }          SCR;                    //
               unsigned char    TDR;                    // TDR
               union {                                  // SSR
                     unsigned char BYTE;                //  Byte Access
                     struct {                           //  Bit  Access
                            unsigned char TDRE:1;       //    TDRE
                            unsigned char RDRF:1;       //    RDRF
                            unsigned char ORER:1;       //    ORER
                            unsigned char FER :1;       //    FER
                            unsigned char PER :1;       //    PER
                            unsigned char TEND:1;       //    TEND
                            unsigned char MPB :1;       //    MPB
                            unsigned char MPBT:1;       //    MPBT
                            }      BIT;                 //
                     }          SSR;                    //
               unsigned char    RDR;                    // RDR
};                                                      //
struct st_smci {                                        // struct SMCI
               union {                                  // SMR
                     unsigned char BYTE;                //  Byte Access
                     struct {                           //  Bit  Access
                            unsigned char GM  :1;       //    GM
                            unsigned char CHR :1;       //    CHR
                            unsigned char PE  :1;       //    PE
                            unsigned char OE  :1;       //    O/E
                            unsigned char STOP:1;       //    STOP
                            unsigned char MP  :1;       //    MP
                            unsigned char CKS :2;       //    CKS
                            }      BIT;                 //
                     }          SMR;                    //
               unsigned char    BRR;                    // BRR
               union {                                  // SCR
                     unsigned char BYTE;                //  Byte Access
                     struct {                           //  Bit  Access
                            unsigned char TIE :1;       //    TIE
                            unsigned char RIE :1;       //    RIE
                            unsigned char TE  :1;       //    TE
                            unsigned char RE  :1;       //    RE
                            unsigned char MPIE:1;       //    MPIE
                            unsigned char TEIE:1;       //    TEIE
                            unsigned char CKE :2;       //    CKE
                            }      BIT;                 //
                     }          SCR;                    //
               unsigned char    TDR;                    // TDR
               union {                                  // SSR
                     unsigned char BYTE;                //  Byte Access
                     struct {                           //  Bit  Access
                            unsigned char TDRE:1;       //    TDRE
                            unsigned char RDRF:1;       //    RDRF
                            unsigned char ORER:1;       //    ORER
                            unsigned char ERS :1;       //    ERS
                            unsigned char PER :1;       //    PER
                            unsigned char TEND:1;       //    TEND
                            unsigned char MPB :1;       //    MPB
                            unsigned char MPBT:1;       //    MPBT
                            }      BIT;                 //
                     }          SSR;                    //
               unsigned char    RDR;                    // RDR
               union {                                  // SCMR
                     unsigned char BYTE;                //  Byte Access
                     struct {                           //  Bit  Access
                            unsigned char     :4;       //
                            unsigned char SDIR:1;       //    SDIR
                            unsigned char SINV:1;       //    SINV
                            unsigned char     :1;       //
                            unsigned char SMIF:1;       //    SMIF
                            }      BIT;                 //
                     }          SCMR;                   //
};                                                      //
struct st_p1 {                                          // struct P1
             unsigned char      DDR;                    // P1DDR
             char               wk;                     //
             union {                                    // P1DR
                   unsigned char BYTE;                  //  Byte Access
                   struct {                             //  Bit  Access
                          unsigned char B7:1;           //    Bit 7
                          unsigned char B6:1;           //    Bit 6
                          unsigned char B5:1;           //    Bit 5
                          unsigned char B4:1;           //    Bit 4
                          unsigned char B3:1;           //    Bit 3
                          unsigned char B2:1;           //    Bit 2
                          unsigned char B1:1;           //    Bit 1
                          unsigned char B0:1;           //    Bit 0
                          }      BIT;                   //
                   }            DR;                     //
};                                                      //
struct st_p2 {                                          // struct P2
             unsigned char      DDR;                    // P2DDR
             char               wk1;                    //
             union {                                    // P2DR
                   unsigned char BYTE;                  //  Byte Access
                   struct {                             //  Bit  Access
                          unsigned char B7:1;           //    Bit 7
                          unsigned char B6:1;           //    Bit 6
                          unsigned char B5:1;           //    Bit 5
                          unsigned char B4:1;           //    Bit 4
                          unsigned char B3:1;           //    Bit 3
                          unsigned char B2:1;           //    Bit 2
                          unsigned char B1:1;           //    Bit 1
                          unsigned char B0:1;           //    Bit 0
                          }      BIT;                   //
                   }            DR;                     //
             char               wk2[20];                //
             union {                                    // P2PCR
                   unsigned char BYTE;                  //  Byte Access
                   struct {                             //  Bit  Access
                          unsigned char B7:1;           //    Bit 7
                          unsigned char B6:1;           //    Bit 6
                          unsigned char B5:1;           //    Bit 5
                          unsigned char B4:1;           //    Bit 4
                          unsigned char B3:1;           //    Bit 3
                          unsigned char B2:1;           //    Bit 2
                          unsigned char B1:1;           //    Bit 1
                          unsigned char B0:1;           //    Bit 0
                          }      BIT;                   //
                   }            PCR;                    //
};                                                      //
struct st_p3 {                                          // struct P3
             unsigned char      DDR;                    // P3DDR
             char               wk;                     //
             union {                                    // P3DR
                   unsigned char BYTE;                  //  Byte Access
                   struct {                             //  Bit  Access
                          unsigned char B7:1;           //    Bit 7
                          unsigned char B6:1;           //    Bit 6
                          unsigned char B5:1;           //    Bit 5
                          unsigned char B4:1;           //    Bit 4
                          unsigned char B3:1;           //    Bit 3
                          unsigned char B2:1;           //    Bit 2
                          unsigned char B1:1;           //    Bit 1
                          unsigned char B0:1;           //    Bit 0
                          }      BIT;                   //
                   }            DR;                     //
};                                                      //
struct st_p4 {                                          // struct P4
             unsigned char      DDR;                    // P4DDR
             char               wk1;                    //
             union {                                    // P4DR
                   unsigned char BYTE;                  //  Byte Access
                   struct {                             //  Bit  Access
                          unsigned char B7:1;           //    Bit 7
                          unsigned char B6:1;           //    Bit 6
                          unsigned char B5:1;           //    Bit 5
                          unsigned char B4:1;           //    Bit 4
                          unsigned char B3:1;           //    Bit 3
                          unsigned char B2:1;           //    Bit 2
                          unsigned char B1:1;           //    Bit 1
                          unsigned char B0:1;           //    Bit 0
                          }      BIT;                   //
                   }            DR;                     //
             char               wk2[18];                //
             union {                                    // P4PCR
                   unsigned char BYTE;                  //  Byte Access
                   struct {                             //  Bit  Access
                          unsigned char B7:1;           //    Bit 7
                          unsigned char B6:1;           //    Bit 6
                          unsigned char B5:1;           //    Bit 5
                          unsigned char B4:1;           //    Bit 4
                          unsigned char B3:1;           //    Bit 3
                          unsigned char B2:1;           //    Bit 2
                          unsigned char B1:1;           //    Bit 1
                          unsigned char B0:1;           //    Bit 0
                          }      BIT;                   //
                   }            PCR;                    //
};                                                      //
struct st_p5 {                                          // struct P5
             unsigned char      DDR;                    // P5DDR
             char               wk1;                    //
             union {                                    // P5DR
                   unsigned char BYTE;                  //  Byte Access
                   struct {                             //  Bit  Access
                          unsigned char   :4;           //
                          unsigned char B3:1;           //    Bit 3
                          unsigned char B2:1;           //    Bit 2
                          unsigned char B1:1;           //    Bit 1
                          unsigned char B0:1;           //    Bit 0
                          }      BIT;                   //
                   }            DR;                     //
             char               wk2[16];                //
             union {                                    // P5PCR
                   unsigned char BYTE;                  //  Byte Access
                   struct {                             //  Bit  Access
                          unsigned char   :4;           //
                          unsigned char B3:1;           //    Bit 3
                          unsigned char B2:1;           //    Bit 2
                          unsigned char B1:1;           //    Bit 1
                          unsigned char B0:1;           //    Bit 0
                          }      BIT;                   //
                   }            PCR;                    //
};                                                      //
struct st_p6 {                                          // struct P6
             unsigned char      DDR;                    // P6DDR
             char               wk;                     //
             union {                                    // P6DR
                   unsigned char BYTE;                  //  Byte Access
                   struct {                             //  Bit  Access
                          unsigned char   :1;           //
                          unsigned char B6:1;           //    Bit 6
                          unsigned char B5:1;           //    Bit 5
                          unsigned char B4:1;           //    Bit 4
                          unsigned char B3:1;           //    Bit 3
                          unsigned char B2:1;           //    Bit 2
                          unsigned char B1:1;           //    Bit 1
                          unsigned char B0:1;           //    Bit 0
                          }      BIT;                   //
                   }            DR;                     //
};                                                      //
struct st_p7 {                                          // struct P7
             union {                                    // P7DR
                   unsigned char BYTE;                  //  Byte Access
                   struct {                             //  Bit  Access
                          unsigned char B7:1;           //    Bit 7
                          unsigned char B6:1;           //    Bit 6
                          unsigned char B5:1;           //    Bit 5
                          unsigned char B4:1;           //    Bit 4
                          unsigned char B3:1;           //    Bit 3
                          unsigned char B2:1;           //    Bit 2
                          unsigned char B1:1;           //    Bit 1
                          unsigned char B0:1;           //    Bit 0
                          }      BIT;                   //
                   }            DR;                     //
};                                                      //
struct st_p8 {                                          // struct P8
             unsigned char      DDR;                    // P8DDR
             char               wk;                     //
             union {                                    // P8DR
                   unsigned char BYTE;                  //  Byte Access
                   struct {                             //  Bit  Access
                          unsigned char   :3;           //
                          unsigned char B4:1;           //    Bit 4
                          unsigned char B3:1;           //    Bit 3
                          unsigned char B2:1;           //    Bit 2
                          unsigned char B1:1;           //    Bit 1
                          unsigned char B0:1;           //    Bit 0
                          }      BIT;                   //
                   }            DR;                     //
};                                                      //
struct st_p9 {                                          // struct P9
             unsigned char      DDR;                    // P9DDR
             char               wk;                     //
             union {                                    // P9DR
                   unsigned char BYTE;                  //  Byte Access
                   struct {                             //  Bit  Access
                          unsigned char   :2;           //
                          unsigned char B5:1;           //    Bit 5
                          unsigned char B4:1;           //    Bit 4
                          unsigned char B3:1;           //    Bit 3
                          unsigned char B2:1;           //    Bit 2
                          unsigned char B1:1;           //    Bit 1
                          unsigned char B0:1;           //    Bit 0
                          }      BIT;                   //
                   }            DR;                     //
};                                                      //
struct st_pa {                                          // struct PA
             unsigned char      DDR;                    // PADDR
             char               wk;                     //
             union {                                    // PADR
                   unsigned char BYTE;                  //  Byte Access
                   struct {                             //  Bit  Access
                          unsigned char B7:1;           //    Bit 7
                          unsigned char B6:1;           //    Bit 6
                          unsigned char B5:1;           //    Bit 5
                          unsigned char B4:1;           //    Bit 4
                          unsigned char B3:1;           //    Bit 3
                          unsigned char B2:1;           //    Bit 2
                          unsigned char B1:1;           //    Bit 1
                          unsigned char B0:1;           //    Bit 0
                          }      BIT;                   //
                   }            DR;                     //
};                                                      //
struct st_pb {                                          // struct PB
             unsigned char      DDR;                    // PBDDR
             char               wk;                     //
             union {                                    // PBDR
                   unsigned char BYTE;                  //  Byte Access
                   struct {                             //  Bit  Access
                          unsigned char B7:1;           //    Bit 7
                          unsigned char B6:1;           //    Bit 6
                          unsigned char B5:1;           //    Bit 5
                          unsigned char B4:1;           //    Bit 4
                          unsigned char B3:1;           //    Bit 3
                          unsigned char B2:1;           //    Bit 2
                          unsigned char B1:1;           //    Bit 1
                          unsigned char B0:1;           //    Bit 0
                          }      BIT;                   //
                   }            DR;                     //
};                                                      //
struct st_da {                                          // struct D/A
             union {                                    // DASTCR
                   unsigned char BYTE;                  //  Byte Access
                   struct {                             //  Bit  Access
                          unsigned char      :7;        //
                          unsigned char DASTE:1;        //    DASTE
                          }      BIT;                   //
                   }            DASTCR;                 //
             char               wk[127];                //
             unsigned char      DADR0;                  // DADR0
             unsigned char      DADR1;                  // DADR1
             union {                                    // DACR
                   unsigned char BYTE;                  //  Byte Access
                   struct {                             //  Bit  Access
                          unsigned char DAOE1:1;        //    DAOE1
                          unsigned char DAOE0:1;        //    DAOE0
                          unsigned char DAE  :1;        //    DAE
                          }      BIT;                   //
                   }            DACR;                   //
};                                                      //
struct st_ad {                                          // struct A/D
             unsigned int       ADDRA;                  // ADDRA
             unsigned int       ADDRB;                  // ADDRB
             unsigned int       ADDRC;                  // ADDRC
             unsigned int       ADDRD;                  // ADDRD
             union {                                    // ADCSR
                   unsigned char BYTE;                  //  Byte Access
                   struct {                             //  Bit  Access
                          unsigned char ADF :1;         //    ADF
                          unsigned char ADIE:1;         //    ADIE
                          unsigned char ADST:1;         //    ADST
                          unsigned char SCAN:1;         //    SCAN
                          unsigned char CKS :1;         //    CKS
                          unsigned char CH  :3;         //    CH
                          }      BIT;                   //
                   }            ADCSR;                  //
             union {                                    // ADCR
                   unsigned char BYTE;                  //  Byte Access
                   struct {                             //  Bit  Access
                          unsigned char TRGE:1;         //    TRGE
                          }      BIT;                   //
                   }            ADCR;                   //
};                                                      //
struct st_bsc {                                         // struct BSC
              union {                                   // CSCR
                    unsigned char BYTE;                 //  Byte Access
                    struct {                            //  Bit  Access
                           unsigned char CS7E:1;        //    CS7E
                           unsigned char CS6E:1;        //    CS6E
                           unsigned char CS5E:1;        //    CS5E
                           unsigned char CS4E:1;        //    CS4E
                           }      BIT;                  //
                    }           CSCR;                   //
              char              wk1[140];               //
              union {                                   // ABWCR
                    unsigned char BYTE;                 //  Byte Access
                    struct {                            //  Bit  Access
                           unsigned char ABW7:1;        //    ABW7
                           unsigned char ABW6:1;        //    ABW6
                           unsigned char ABW5:1;        //    ABW5
                           unsigned char ABW4:1;        //    ABW4
                           unsigned char ABW3:1;        //    ABW3
                           unsigned char ABW2:1;        //    ABW2
                           unsigned char ABW1:1;        //    ABW1
                           unsigned char ABW0:1;        //    ABW0
                           }      BIT;                  //
                    }           ABWCR;                  //
              union {                                   // ASTCR
                    unsigned char BYTE;                 //  Byte Access
                    struct {                            //  Bit  Access
                           unsigned char AST7:1;        //    AST7
                           unsigned char AST6:1;        //    AST6
                           unsigned char AST5:1;        //    AST5
                           unsigned char AST4:1;        //    AST4
                           unsigned char AST3:1;        //    AST3
                           unsigned char AST2:1;        //    AST2
                           unsigned char AST1:1;        //    AST1
                           unsigned char AST0:1;        //    AST0
                           }      BIT;                  //
                    }           ASTCR;                  //
              union {                                   // WCR
                    unsigned char BYTE;                 //  Byte Access
                    struct {                            //  Bit  Access
                           unsigned char    :4;         //
                           unsigned char WMS:2;         //    WMS
                           unsigned char WC :2;         //    WC
                           }      BIT;                  //
                    }           WCR;                    //
              union {                                   // WCER
                    unsigned char BYTE;                 //  Byte Access
                    struct {                            //  Bit  Access
                           unsigned char WCE7:1;        //    WCE7
                           unsigned char WCE6:1;        //    WCE6
                           unsigned char WCE5:1;        //    WCE5
                           unsigned char WCE4:1;        //    WCE4
                           unsigned char WCE3:1;        //    WCE3
                           unsigned char WCE2:1;        //    WCE2
                           unsigned char WCE1:1;        //    WCE1
                           unsigned char WCE0:1;        //    WCE0
                           }      BIT;                  //
                    }           WCER;                   //
              char              wk2[3];                 //
              union {                                   // BRCR
                    unsigned char BYTE;                 //  Byte Access
                    struct {                            //  Bit  Access
                           unsigned char A23E:1;        //    A23E
                           unsigned char A22E:1;        //    A22E
                           unsigned char A21E:1;        //    A21E
                           unsigned char     :4;        //
                           unsigned char BRLE:1;        //    BRLE
                           }      BIT;                  //
                    }           BRCR;                   //
};                                                      //
union un_divcr {                                        // union DIVCR
               unsigned char BYTE;                      //  Byte Access
               struct {                                 //  Bit  Access
                      unsigned char    :6;              //
                      unsigned char DIV:2;              //    DIV
                      }      BIT;                       //
};                                                      //
union un_mstcr {                                        // union MSTCR
               unsigned char BYTE;                      //  Byte Access
               struct {                                 //  Bit  Access
                      unsigned char PSTOP :1;           //    PSTOP
                      unsigned char       :1;           //
                      unsigned char _ITU  :1;           //    MSTOP5
                      unsigned char _SCI0 :1;           //    MSTOP4
                      unsigned char _SCI1 :1;           //    MSTOP3
                      unsigned char _DMAC :1;           //    MSTOP2
                      unsigned char _RFSHC:1;           //    MSTOP1
                      unsigned char _AD   :1;           //    MSTOP0
                      }      BIT;                       //
};                                                      //
union un_mdcr {                                         // union MDCR
              unsigned char BYTE;                       //  Byte Access
              struct {                                  //  Bit  Access
                     unsigned char    :5;               //
                     unsigned char MDS:3;               //    MDS
                     }      BIT;                        //
};                                                      //
union un_syscr {                                        // union SYSCR
               unsigned char BYTE;                      //  Byte Access
               struct {                                 //  Bit  Access
                      unsigned char SSBY :1;            //    SSBY
                      unsigned char STS  :3;            //    STS
                      unsigned char UE   :1;            //    UE
                      unsigned char NMIEG:1;            //    NMIEG
                      unsigned char      :1;            //
                      unsigned char RAME :1;            //    RAME
                      }      BIT;                       //
};                                                      //
struct st_intc {                                        // struct INTC
               union {                                  // ISCR
                     unsigned char BYTE;                //  Byte Access
                     struct {                           //  Bit  Access
                            unsigned char       :2;     //
                            unsigned char IRQ5SC:1;     //    IRQ5SC
                            unsigned char IRQ4SC:1;     //    IRQ4SC
                            unsigned char IRQ3SC:1;     //    IRQ3SC
                            unsigned char IRQ2SC:1;     //    IRQ2SC
                            unsigned char IRQ1SC:1;     //    IRQ1SC
                            unsigned char IRQ0SC:1;     //    IRQ0SC
                            }      BIT;                 //
                     }          ISCR;                   //
               union {                                  // IER
                     unsigned char BYTE;                //  Byte Access
                     struct {                           //  Bit  Access
                            unsigned char      :2;      //
                            unsigned char IRQ5E:1;      //    IRQ5E
                            unsigned char IRQ4E:1;      //    IRQ4E
                            unsigned char IRQ3E:1;      //    IRQ3E
                            unsigned char IRQ2E:1;      //    IRQ2E
                            unsigned char IRQ1E:1;      //    IRQ1E
                            unsigned char IRQ0E:1;      //    IRQ0E
                            }      BIT;                 //
                     }          IER;                    //
               union {                                  // ISR
                     unsigned char BYTE;                //  Byte Access
                     struct {                           //  Bit  Access
                            unsigned char      :2;      //
                            unsigned char IRQ5F:1;      //    IRQ5F
                            unsigned char IRQ4F:1;      //    IRQ4F
                            unsigned char IRQ3F:1;      //    IRQ3F
                            unsigned char IRQ2F:1;      //    IRQ2F
                            unsigned char IRQ1F:1;      //    IRQ1F
                            unsigned char IRQ0F:1;      //    IRQ0F
                            }      BIT;                 //
                     }          ISR;                    //
               char             wk;                     //
               union {                                  // IPRA
                     unsigned char BYTE;                //  Byte Access
                     struct {                           //  Bit  Access
                            unsigned char _IRQ0 :1;     //    IRQ0
                            unsigned char _IRQ1 :1;     //    IRQ1
                            unsigned char _IRQ23:1;     //    IRQ2,IRQ3
                            unsigned char _IRQ45:1;     //    IRQ4,IRQ5
                            unsigned char _WDT  :1;     //    WDT,RFSHC
                            unsigned char _ITU0 :1;     //    ITU0
                            unsigned char _ITU1 :1;     //    ITU1
                            unsigned char _ITU2 :1;     //    ITU2
                            }      BIT;                 //
                     }          IPRA;                   //
               union {                                  // IPRB
                     unsigned char BYTE;                //  Byte Access
                     struct {                           //  Bit  Access
                            unsigned char _ITU3:1;      //    ITU3
                            unsigned char _ITU4:1;      //    ITU4
                            unsigned char _DMAC:1;      //    DMAC
                            unsigned char      :1;      //
                            unsigned char _SCI0:1;      //    SCI0
                            unsigned char _SCI1:1;      //    SCI1
                            unsigned char _AD  :1;      //    A/D
                            }      BIT;                 //
                     }          IPRB;                   //
};                                                      //
#define DMAC0A  (*(volatile struct st_sam   *)0xFFFF20) // DMAC 0A Addr
#define DMAC0B  (*(volatile struct st_sam   *)0xFFFF28) // DMAC 0B Addr
#define DMAC1A  (*(volatile struct st_sam   *)0xFFFF30) // DMAC 1A Addr
#define DMAC1B  (*(volatile struct st_sam   *)0xFFFF38) // DMAC 1B Addr
#define DMAC0   (*(volatile struct st_fam   *)0xFFFF20) // DMAC 0  Addr
#define DMAC1   (*(volatile struct st_fam   *)0xFFFF30) // DMAC 1  Addr
#define ITU     (*(volatile struct st_itu   *)0xFFFF60) // ITU   Address
#define ITU0    (*(volatile struct st_itu0  *)0xFFFF64) // ITU0  Address
#define ITU1    (*(volatile struct st_itu0  *)0xFFFF6E) // ITU1  Address
#define ITU2    (*(volatile struct st_itu0  *)0xFFFF78) // ITU2  Address
#define ITU3    (*(volatile struct st_itu3  *)0xFFFF82) // ITU3  Address
#define ITU4    (*(volatile struct st_itu3  *)0xFFFF92) // ITU4  Address
#define TPC     (*(volatile struct st_tpc   *)0xFFFFA0) // TPC   Address
#define WDT     (*(volatile union  un_wdt   *)0xFFFFA8) // WDT   Address
#define RFSHC   (*(volatile struct st_rfshc *)0xFFFFAC) // RFSHC Address
#define SCI0    (*(volatile struct st_sci0  *)0xFFFFB0) // SCI0  Address
#define SCI1    (*(volatile struct st_sci1  *)0xFFFFB8) // SCI1  Address
#define SMCI0   (*(volatile struct st_smci  *)0xFFFFB0) // SMCI0 Address
#define P1      (*(volatile struct st_p1    *)0xFFFFC0) // P1    Address
#define P2      (*(volatile struct st_p2    *)0xFFFFC1) // P2    Address
#define P3      (*(volatile struct st_p3    *)0xFFFFC4) // P3    Address
#define P4      (*(volatile struct st_p4    *)0xFFFFC5) // P4    Address
#define P5      (*(volatile struct st_p5    *)0xFFFFC8) // P5    Address
#define P6      (*(volatile struct st_p6    *)0xFFFFC9) // P6    Address
#define P7      (*(volatile struct st_p7    *)0xFFFFCE) // P7    Address
#define P8      (*(volatile struct st_p8    *)0xFFFFCD) // P8    Address
#define P9      (*(volatile struct st_p9    *)0xFFFFD0) // P9    Address
#define PA      (*(volatile struct st_pa    *)0xFFFFD1) // PA    Address
#define PB      (*(volatile struct st_pb    *)0xFFFFD4) // PB    Address
#define DA      (*(volatile struct st_da    *)0xFFFF5C) // D/A   Address
#define AD      (*(volatile struct st_ad    *)0xFFFFE0) // A/D   Address
#define BSC     (*(volatile struct st_bsc   *)0xFFFF5F) // BSC   Address
#define FLASH   (*(volatile struct st_flash *)0xFFFF40) // FLASH Address
#define DIVCR   (*(volatile union  un_divcr *)0xFFFF5D) // DIVCR Address
#define MSTCR   (*(volatile union  un_mstcr *)0xFFFF5E) // MSTCR Address
#define MDCR    (*(volatile union  un_mdcr  *)0xFFFFF1) // MDCR  Address
#define SYSCR   (*(volatile union  un_syscr *)0xFFFFF2) // SYSCR Address
#define INTC    (*(volatile struct st_intc  *)0xFFFFF4) // INTC  Address

#define DI  asm("orc.b #0xc0,ccr")
#define EI  asm("andc.b #0x3f,ccr")

/*--------------------------------------------------------------*/
/* 割り込み関数プロトタイプ宣言                                 */
/*--------------------------------------------------------------*/
// NMI割り込み
extern void int_nmi (void)    asm ("_int_nmi")    __attribute__((interrupt_handler));
/*
// トラップ命令
extern void int_trap0 (void) asm ("_int_trap0") __attribute__((function_vector));
extern void int_trap1 (void) asm ("_int_trap1") __attribute__((function_vector));
extern void int_trap2 (void) asm ("_int_trap2") __attribute__((function_vector));
extern void int_trap3 (void) asm ("_int_trap3") __attribute__((function_vector));
*/
// IRQ0〜5外部割り込み
extern void int_irq0 (void)   asm ("_int_irq0")   __attribute__((interrupt_handler));
extern void int_irq1 (void)   asm ("_int_irq1")   __attribute__((interrupt_handler));
extern void int_irq2 (void)   asm ("_int_irq2")   __attribute__((interrupt_handler));
extern void int_irq3 (void)   asm ("_int_irq3")   __attribute__((interrupt_handler));
extern void int_irq4 (void)   asm ("_int_irq4")   __attribute__((interrupt_handler));
extern void int_irq5 (void)   asm ("_int_irq5")   __attribute__((interrupt_handler));
// ウォッチドッグタイマ (インターバルタイマ)
extern void int_wovi (void)   asm ("_int_wovi")   __attribute__((interrupt_handler));
// リフレッシュコントローラ (コンペアマッチ)
extern void int_cmi (void)    asm ("_int_cmi")    __attribute__((interrupt_handler));

// ITU0 (コンペアマッチ/インプットキャプチャA0)
extern void int_imia0 (void)  asm ("_int_imia0")  __attribute__((interrupt_handler));
// ITU0 (コンペアマッチ/インプットキャプチャB0)
extern void int_imib0 (void)  asm ("_int_imib0")  __attribute__((interrupt_handler));
// ITU0 (オーバフロー0)
extern void int_ovi0 (void)   asm ("_int_ovi0")   __attribute__((interrupt_handler));

// ITU1 (コンペアマッチ/インプットキャプチャA1)
extern void int_imia1 (void)  asm ("_int_imia1")  __attribute__((interrupt_handler));
// ITU1 (コンペアマッチ/インプットキャプチャB1)
extern void int_imib1 (void)  asm ("_int_imib1")  __attribute__((interrupt_handler));
// ITU1 (オーバフロー1)
extern void int_ovi1 (void)   asm ("_int_ovi1")   __attribute__((interrupt_handler));

// ITU2 (コンペアマッチ/インプットキャプチャA2)
extern void int_imia2 (void)  asm ("_int_imia2")  __attribute__((interrupt_handler));
// ITU2 (コンペアマッチ/インプットキャプチャB2)
extern void int_imib2 (void)  asm ("_int_imib2")  __attribute__((interrupt_handler));
// ITU2 (オーバフロー2)
extern void int_ovi2 (void)   asm ("_int_ovi2")   __attribute__((interrupt_handler));

// ITU3 (コンペアマッチ/インプットキャプチャA3)
extern void int_imia3 (void)  asm ("_int_imia3")  __attribute__((interrupt_handler));
// ITU3 (コンペアマッチ/インプットキャプチャB3)
extern void int_imib3 (void)  asm ("_int_imib3")  __attribute__((interrupt_handler));
// ITU3 (オーバフロー3)
extern void int_ovi3 (void)   asm ("_int_ovi3")   __attribute__((interrupt_handler));

// ITU4 (コンペアマッチ/インプットキャプチャA4)
extern void int_imia4 (void)  asm ("_int_imia4")  __attribute__((interrupt_handler));
// ITU4 (コンペアマッチ/インプットキャプチャB4)
extern void int_imib4 (void)  asm ("_int_imib4")  __attribute__((interrupt_handler));
// ITU4 (オーバフロー4)
extern void int_ovi4 (void)   asm ("_int_ovi4")   __attribute__((interrupt_handler));

// DMAC0 (DMAC0/DMAC0A転送完了)
extern void int_dend0a (void) asm ("_int_dend0a") __attribute__((interrupt_handler));
// DMAC0 (DMAC0B転送完了)
extern void int_dend0b (void) asm ("_int_dend0b") __attribute__((interrupt_handler));
// DMAC1 (DMAC1/DMAC1A転送完了)
extern void int_dend1a (void) asm ("_int_dend1a") __attribute__((interrupt_handler));
// DMAC1 (DMAC1B転送完了)
extern void int_dend1b (void) asm ("_int_dend1b") __attribute__((interrupt_handler));

// SCI0 (受信エラー0)
extern void int_eri0 (void)   asm ("_int_eri0")   __attribute__((interrupt_handler));
// SCI0 (受信データフル0)
extern void int_rxi0 (void)   asm ("_int_rxi0")   __attribute__((interrupt_handler));
// SCI0 (送信データエンプティ0)
extern void int_txi0 (void)   asm ("_int_txi0")   __attribute__((interrupt_handler));
// SCI0 (送信終了0)
extern void int_tei0 (void)   asm ("_int_tei0")   __attribute__((interrupt_handler));

// SCI1 (受信エラー1)
extern void int_eri1 (void)   asm ("_int_eri1")   __attribute__((interrupt_handler));
// SCI1 (受信データフル1)
extern void int_rxi1 (void)   asm ("_int_rxi1")   __attribute__((interrupt_handler));
// SCI1 (送信データエンプティ1)
extern void int_txi1 (void)   asm ("_int_txi1")   __attribute__((interrupt_handler));
// SCI1 (送信終了1)
extern void int_tei1 (void)   asm ("_int_tei1")   __attribute__((interrupt_handler));

// A/D (A/D完了)
extern void int_adi (void)    asm ("_int_adi")    __attribute__((interrupt_handler));

/*--------------------------------------------------------------*/
/* インライン命令                                               */
/*--------------------------------------------------------------*/
#ifdef DEFINE_INLINE

extern __inline__ void sleep (void) __attribute__ ((always_inline));
extern __inline__ void nop (void) __attribute__ ((always_inline));
extern __inline__ void set_ccr (unsigned char mask) __attribute__ ((always_inline));
extern __inline__ unsigned char get_ccr (void) __attribute__ ((always_inline));

extern __inline__ void sleep (void)
{
  asm ("sleep");
}

extern __inline__ void nop (void)
{
  asm ("nop");
}

extern __inline__ void set_ccr (unsigned char mask)
{
  asm ("ldc %0l,ccr"::"r"(mask));
}

extern __inline__ unsigned char get_ccr (void)
{
  unsigned char value;
  asm ("stc ccr,%0l":"=g"(value):);
  return(value);
}

#endif

#ifdef __cplusplus
}
#endif

#endif /* _3048_H_ */
