/*
 * main tracker software
 *
 * Stefan Biereigel
 *
 */

#ifndef MAIN_H_
#define MAIN_H_

/* payload name */
#define PAYLOAD_NAME "DK3SB"
#define TLM_INTERVAL 30

/* number of idle bits to transmit before beginning tlm string tx */
#define NUM_IDLE_BITS	32
/* length of non-GPS-telemetry fields */
#define VOLT_LENGTH	4
#define TEMP_LENGTH	2
#define SENT_ID_LENGTH	5
/* telemetry string prefix for RX syncronisation */
#define SYNC_PREFIX		"   "
/* offset from buffer start to telemetry data */
#define TX_BUF_START_OFFSET 	sizeof(SYNC_PREFIX "$$" PAYLOAD_NAME ",") - 1
#define TX_BUF_SENT_ID_START	TX_BUF_START_OFFSET
#define TX_BUF_TIME_START	TX_BUF_SENT_ID_START + SENT_ID_LENGTH + 1
#define TX_BUF_LAT_START	TX_BUF_TIME_START + TIME_LENGTH + 1
/* lat and lon fields are one char longer for +/- */
#define TX_BUF_LON_START	TX_BUF_LAT_START + LAT_LENGTH + 1 + 1
#define TX_BUF_ALT_START	TX_BUF_LON_START + LON_LENGTH + 1 + 1
#define TX_BUF_SAT_START	TX_BUF_ALT_START + ALT_LENGTH + 1
#define TX_BUF_VOLT_START	TX_BUF_SAT_START + SAT_LENGTH + 1
/* temperature field is one char longer for +/- */
#define TX_BUF_TEMP_START	TX_BUF_VOLT_START + VOLT_LENGTH + 1
#define TX_BUF_CHECKSUM_START	TX_BUF_TEMP_START + TEMP_LENGTH + 1 + 1
/* checksum parameters */
#define TX_BUF_CHECKSUM_BEGIN	sizeof(SYNC_PREFIX "$$") - 1
#define TX_BUF_CHECKSUM_END	TX_BUF_CHECKSUM_START - 1


/* buffer sizes */
#define NMEA_BUF_SIZE	83

/* Port 1 */
#define ADC_IN	BIT0
#define SI_SHDN	BIT1
#define SI_DATA	BIT2
#define CS	BIT3
#define MOSI	BIT6
#define MISO	BIT7

/* Port 2 */
#define RXD	BIT1
#define TXD	BIT0
#define SCLK	BIT2

/* ADC calibration locations */
#define CALADC10_15V_30C  *((unsigned int *)0x1A1A)   // Temperature Sensor Calibration-30 C
#define CALADC10_15V_85C  *((unsigned int *)0x1A1C)   // Temperature Sensor Calibration-85 C

#endif
