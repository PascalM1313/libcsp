#pragma once

/**
   @file

   Posix ETH driver

   Using this driver require user elevation. Guideline for doung this is given at run-time
*/

#include <csp/interfaces/csp_if_eth.h>

/**
   Open CAN socket and add CSP interface.

   @param[in] device CAN device name (Linux device).
   @param[in] ifname CSP interface name.
   @param[in] mtu MTU for the transmitted ethernet frames.
   @param[in] node_id CSP address of the interface.
   @param[in] promisc if \a true, receive all CAN frames. If \a false a filter is set before forwarding packets to the router
   @param[out] return_iface the added interface.
   @return #CSP_ERR_NONE on success, otherwise an error code.
*/
int csp_eth_init(const char * device, const char * ifname, int mtu, unsigned int node_id, bool promisc, csp_iface_t ** return_iface);

/**
   Transmit an CSP ethernet frame

   @param[in] iface Ethernet interface to use.
   @param[in] eth_frame The CSP ethernet frame to transmit.
   @return #CSP_ERR_NONE on success, otherwise an error code.
*/
int csp_eth_tx_frame(csp_iface_t * iface, csp_eth_header_t * eth_frame);

/**
   Posix ethernet RX thread

   @param[in] param Ethernet CSP interface to use.
   @return #CSP_ERR_NONE on success, otherwise an error code.
*/
void * csp_eth_rx_loop(void * param);
