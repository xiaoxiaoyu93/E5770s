

#include "bsp_om_api.h"
#include "bsp_om.h"
#include "drv_comm.h"
#include "osl_irq.h"



/*****************************************************************************
* 函 数 名  : DRV_OM_SET_HSO_CONN_FLAG
*
* 功能描述  : flag :连接标志，1表示连接，0表示断开
*
* 输入参数  :无
*
*
* 输出参数  :无
*
* 返 回 值  :无
*****************************************************************************/

BSP_VOID DRV_OM_SET_HSO_CONN_FLAG(BSP_U32 flag)
{
    bsp_om_set_hso_conn_flag(flag);
}

/*****************************************************************************
* 函 数 名  : DRV_SYSVIEW_SWT_SET
*
* 功能描述  :sysview上报开关设置，封装函数，提供给MSP使用
*
* 输入参数  :tarce_type :trace类型
*                        set_swt  :开关值
*                       period  :上报周期
*
* 输出参数  : 无
*
* 返 回 值  : BSP_OK
*****************************************************************************/

BSP_U32 DRV_SYSVIEW_SWT_SET(BSP_U32 set_type,BSP_U32 set_swt,BSP_U32 period)
{
    return bsp_sysview_swt_set(set_type,set_swt,period);
}

/*****************************************************************************
* 函 数 名  : DRV_GET_ALL_TASK_ID_NAME
*
* 功能描述  :获取当前所有任务的ID和名称
*
* 输入参数  :p_task_stru:任务名称和ID输出的结构体
*                       param_len:参数1的长度，单位字节
*
*
* 输出参数  : 无
*
* 返 回 值  : BSP_OK
*****************************************************************************/
BSP_U32 DRV_GET_ALL_TASK_ID_NAME(BSP_VOID *p_task_stru,u32 param_len)
{
      return sysview_get_all_task_name((void *)p_task_stru,param_len );
}

/*****************************************************************************
* 函 数 名  : DRV_INT_LOCK
*
* 功能描述  :锁中断接口，用于锁中断统计
*
* 输入参数  :无
*
* 输出参数  : 无
*
* 返 回 值  : 锁中断后获得的key
*****************************************************************************/
BSP_S32 DRV_INT_LOCK(BSP_VOID)
{
    unsigned long flags;

    local_irq_save(flags);

    bsp_int_lock_enter();
    return (BSP_S32)flags;
}

/*****************************************************************************
* 函 数 名  : DRV_INT_UNLOCK
*
* 功能描述  : 解锁中断接口，用于锁中断统计
*
* 输入参数  : 锁中断后获得的key
*
* 输出参数  : 无
*
* 返 回 值  : 无
*****************************************************************************/
BSP_VOID DRV_INT_UNLOCK(BSP_S32 LockKey)
{
    unsigned long lock_key;

    lock_key = (unsigned long)LockKey;
    
    bsp_int_lock_out();

    local_irq_restore(lock_key);
}


/*****************************************************************************
* 函 数 名  : DRV_SOCP_CHAN_ENABLE
*
* 功能描述  : 底软SOCP通道使能操作
*
* 输入参数  : 无
*
*
* 输出参数  :无
*
* 返 回 值  :无
*****************************************************************************/

BSP_VOID DRV_SOCP_CHAN_ENABLE(BSP_VOID)
{
    bsp_socp_chan_enable();
}





