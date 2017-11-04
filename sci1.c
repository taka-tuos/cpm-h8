#include "iodefine.h"
#include "sci1.h"

#define rs_txi      int_txi1
#define rs_rxi      int_rxi1
#define rs_eri      int_eri1

#define FIFO        sci1fifo
#define SCI         SCI1

typedef struct {
  struct {
    unsigned char  *buf;
    short wp;
    short rp;
    short maxlen;
  } tx;
  struct {
    unsigned char  *buf;
    short wp;
    short rp;
    short maxlen;
  } rx;
} SCIFIFO;

volatile SCIFIFO FIFO;

// SCI初期化
void rs_init (TBaudRate b, unsigned char *tbuf, short txl, unsigned char *rbuf, short rxl)
{
  volatile int i;

  SCI.SCR.BYTE = SCI.SMR.BYTE = 0;

  FIFO.tx.buf = tbuf;
  FIFO.rx.buf = rbuf;
  FIFO.tx.maxlen = txl;
  FIFO.rx.maxlen = rxl;

  // 受信データ用変数初期化
  FIFO.tx.wp = FIFO.tx.rp = 0;
  FIFO.rx.wp = FIFO.rx.rp = 0;

  SCI.BRR = b;                    // ボーレート
  for (i = 0; i < 3000; i++) ;    // 待つ
  SCI.SCR.BYTE = 0xf0;            // 送受信許可
  //SCI.SSR.BYTE;
  SCI.SSR.BYTE &= 0x80;               // フラグクリア
}

// 送信バッファチェック
short rs_tx_buff (void)
{
  short s;
  if ((s = (FIFO.tx.rp - FIFO.tx.wp)) <= 0)
    s += FIFO.tx.maxlen;
  return s - 1;
}

// 受信バッファチェック
short rs_rx_buff (void)
{
  short s;
  if ((s = (FIFO.rx.wp - FIFO.rx.rp)) < 0) s += FIFO.rx.maxlen;
  return s;
}

// 受信バッファクリア
void rs_rx_purge (void)
{
  SCI.SCR.BIT.RIE = 0;
  FIFO.rx.wp = FIFO.rx.rp = 0;
  SCI.SCR.BIT.RIE = 1;
}

// 送信バッファクリア
void rs_tx_purge (void)
{
  SCI.SCR.BIT.TIE = 0;
  FIFO.tx.wp = FIFO.tx.rp = 0;
}

// 1文字送信
void rs_putc (unsigned char c)
{
  volatile short t;

  t = (FIFO.tx.wp + 1) % FIFO.tx.maxlen;
  while (t == FIFO.tx.rp) ;
  FIFO.tx.buf[FIFO.tx.wp] = c;
  FIFO.tx.wp = t;
  SCI.SCR.BIT.TIE = 1;
}

// 1文字受信
unsigned char rs_getc (void)
{
  unsigned char c;

  while (FIFO.rx.rp == FIFO.rx.wp) ;
  c = FIFO.rx.buf[FIFO.rx.rp++];
  FIFO.rx.rp %= FIFO.rx.maxlen;
  return c;
}

// 受信割り込み
void rs_rxi (void)
{
  volatile short t;
  _BYTE c = SCI.RDR;

  SCI.SSR.BIT.RDRF = 0;
  t = (FIFO.rx.wp + 1) % FIFO.rx.maxlen;
  FIFO.rx.buf[FIFO.rx.wp] = c;
  if (t != FIFO.rx.rp) FIFO.rx.wp = t;
}

// 送信割り込み
void rs_txi (void)
{
  if (FIFO.tx.wp != FIFO.tx.rp) {
    SCI.TDR = FIFO.tx.buf[FIFO.tx.rp++];
    FIFO.tx.rp %= FIFO.tx.maxlen;
    SCI.SSR.BIT.TDRE = 0;
  } else
    SCI.SCR.BIT.TIE = 0;
}

// 受信エラー割り込み
void rs_eri (void)
{
  SCI.SSR.BYTE &= ~0x38;
}
