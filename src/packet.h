/*******************************************************************************
 * Copyright (c) 2014 IBM Corp.
 *
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * and Eclipse Distribution License v1.0 which accompany this distribution.
 *
 * The Eclipse Public License is available at
 *    http://www.eclipse.org/legal/epl-v10.html
 * and the Eclipse Distribution License is available at
 *   http://www.eclipse.org/org/documents/edl-v10.php.
 *******************************************************************************/

#ifndef LWMQTT_PACKET_H
#define LWMQTT_PACKET_H

// TODO: What to do with those?
enum { LWMQTT_BUFFER_TOO_SHORT_ERROR = -2, LWMQTT_HEADER_DECODE_ERROR = -1 };

typedef enum { LWMQTT_QOS0, LWMQTT_QOS1, LWMQTT_QOS2 } lwmqtt_qos_t;

typedef enum {
  LWMQTT_CONNECT_PACKET = 1,
  LWMQTT_CONNACK_PACKET,
  LWMQTT_PUBLISH_PACKET,
  LWMQTT_PUBACK_PACKET,
  LWMQTT_PUBREC_PACKET,
  LWMQTT_PUBREL_PACKET,
  LWMQTT_PUBCOMP_PACKET,
  LWMQTT_SUBSCRIBE_PACKET,
  LWMQTT_SUBACK_PACKET,
  LWMQTT_UNSUBSCRIBE_PACKET,
  LWMQTT_UNSUBACK_PACKET,
  LWMQTT_PINGREQ_PACKET,
  LWMQTT_PINGRESP_PACKET,
  LWMQTT_DISCONNECT_PACKET,
} lwmqtt_packet_type_t;

/**
 * Bitfields for the MQTT header byte.
 */
typedef union {
  unsigned char byte;
  struct {
    unsigned int retain : 1;
    unsigned int qos : 2;
    unsigned int dup : 1;
    unsigned int type : 4;
  } bits;
} lwmqtt_header_t;

int lwmqtt_header_len(int rem_len);

/**
 * Encodes the message length according to the MQTT algorithm
 *
 * @param buf the buffer into which the encoded data is written
 * @param rem_len the length to be encoded
 * @return the number of bytes written to buffer
 */
int lwmqtt_header_encode(unsigned char *buf, int rem_len);

int lwmqtt_header_decode(unsigned char *buf, int *rem_len);

#endif  // LWMQTT_PACKET_H
