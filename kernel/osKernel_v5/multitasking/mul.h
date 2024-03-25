

/******************************************************************************/
/*! @addtogroup Group2
    @brief      
    
******************************************************************************/

#ifndef _MUL_H_
#define _MUL_H_
#ifdef __cplusplus
extern "C"
{
#endif

/* CODE */
extern uint32_t *activate(uint32_t *stack);
extern void init_kernel(uint32_t *stack);
extern void syscall(void);

#ifdef __cplusplus
}
#endif
#endif


