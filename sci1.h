#ifndef __SCI1_H__
#define __SCI1_H__

// ボーレート設定リスト
#ifdef SYS_CLOCK_14_7456
// クロック14.7456MHz時
typedef enum {
  br2400   = 191,
  br4800   = 95,
  br9600   = 47,
  br19200  = 23,
  br31250  = 14,
  br38400  = 11,
  br57600  = 7
} TBaudRate;
#else
#ifdef SYS_CLOCK_24_576
typedef enum {
  br4800  = 159,
  br9600  = 79,
  br19200 = 39,
  br31250 = 24,
  br38400 = 19,
  br57600 = 12
} TBaudRate;
#else
// クロック16MHz時
typedef enum {
  br2400   = 207,
  br4800   = 103,
  br9600   = 51,
  br19200  = 25,
  br31250  = 15,
  br38400  = 12,
  br57600  = 8
} TBaudRate;
#endif
#endif

// SCI初期化
void rs_init (TBaudRate b, unsigned char *tbuf, short txl, unsigned char *rbuf, short rxl);

// 1文字送信
void rs_putc (unsigned char c);

// 1文字受信
unsigned char rs_getc (void);

// 受信バッファチェック
short rs_rx_buff (void);

// 送信バッファチェック
short rs_tx_buff (void);

// 受信バッファクリア
void rs_rx_purge (void);

// 送信バッファクリア
void rs_tx_purge (void);

#endif
