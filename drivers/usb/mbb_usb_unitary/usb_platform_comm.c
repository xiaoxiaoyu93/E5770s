
#include "usb_platform_comm.h"
#ifdef MBB_USB_UNITARY_B  
#include "bsp_nvim.h"
#include "drv_nvim.h"
/* 巴龙平台接口*/
//extern USB_ULONG NVM_Read(USB_ULONG  ulid, USB_PVOID pdata, USB_UINT16 usdatalen);

#endif


/*****************************************************************************
* 函 数 名  : usb_read_nv
*
* 功能描述  : A核读NV接口函数
*
* 输入参数  : usID -> NV ID
              *pItem -> Save NV data buffer
              ulLength -> buffer length
* 输出参数  : 无
*
* 返 回 值  : 0:    操作成功
*                       -1: 操作失败
*
* 其它说明  : 无
*
*****************************************************************************/
USB_INT usb_read_nv(USB_UINT16 usID, USB_PVOID pItem, USB_UINT ulLength)
{
    /*巴龙平台 */
#ifdef MBB_USB_UNITARY_B    
    return NVM_Read(usID, pItem, ulLength);
#else
    /*高通平台不支持内核读取NV*/
    return -1;
#endif
}