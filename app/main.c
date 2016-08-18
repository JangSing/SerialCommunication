#include <stdlib.h>
#include "stm32f4xx_conf.h"
#include "stm32f4xx.h"
#include "usbd_cdc_core.h"
#include "usbd_usr.h"
#include "usbd_desc.h"
#include "usbd_cdc_vcp.h"
#include "usb_dcd_int.h"

USB_OTG_CORE_HANDLE	USB_OTG_dev;

#define noOfTlv 10

int main(void) {
  //USB initializing
  SystemInit();
  USBD_Init(  &USB_OTG_dev,
              USB_OTG_HS_CORE_ID,
              &USR_desc,
              &USBD_CDC_cb,
              &USR_cb);

  uint8_t buffChar[]={0x11,'e','l','l','o'};
  uint8_t byteReceive;
  while(1){
	  if(VCP_get_char(&byteReceive)){
		  VCP_send_buffer(buffChar, 1);
	  }
  }
}


