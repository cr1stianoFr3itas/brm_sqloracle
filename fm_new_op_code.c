/*
   Dev. Cristiano Freitas
   email: junior.brown.eda@gmail.com
   Data de inicio do projeto: 20/05/2021
   Data de "Final" do projeto: 13/06/2021
   CREATE CLIENT NEW CODE WRITE
*/


#ifndef lint
static	char	Sccs_id[] = "@(#)%Portal Version: fm_new_op_code.c:BillingVelocityInt:2:2006-Sep-05 04:27:08 %";
#endif

/*******************************************************************
 * Contains the AC_OP_CUST_WRITE  operation. 
 *******************************************************************/


#include <stdio.h> 
#include <string.h> 
 
#include "pcm.h"
#include "ops/inv.h"
#include "cm_fm.h"
#include "pin_errs.h"
#include "pinlog.h"
#include "custom_ops.h"
#include "custom_flds.h"

/*******************************************************************
 * Routines contained within.
 *******************************************************************/
EXPORT_OP void
op_new_op_code(
	cm_nap_connection_t	*connp,
	int32			opcode,
	int32			flags,
	pin_flist_t		*i_flistp,
	pin_flist_t		**o_flistpp,
	pin_errbuf_t		*ebufp);

static void
fm_new_op_code(
	pcm_context_t		*ctxp,
	int32			flags,
	pin_flist_t		*i_flistp,
	pin_flist_t		**ret_flistpp,
	pin_errbuf_t		*ebufp);

/*******************************************************************
 * Main routine for the AC_OP_CUST_WRITE operation.
 *******************************************************************/
void
op_new_op_code(
	cm_nap_connection_t	*connp,
	int32			opcode,
	int32			flags,
	pin_flist_t		*i_flistp,
	pin_flist_t		**o_flistpp,
	pin_errbuf_t		*ebufp)
{
	pcm_context_t		*ctxp = connp->dm_ctx;
	pin_flist_t		*r_flistp = NULL;


	if (PIN_ERR_IS_ERR(ebufp)) {
		return;
	}
	PIN_ERR_CLEAR_ERR(ebufp);

	/***********************************************************
	 * Invalid call
	 ***********************************************************/
	if (opcode != AC_OP_CUST_WRITE) {
		pin_set_err(ebufp, PIN_ERRLOC_FM,
			PIN_ERRCLASS_SYSTEM_DETERMINATE,
			PIN_ERR_BAD_OPCODE, 0, 0, opcode);
		PIN_ERR_LOG_EBUF(PIN_ERR_LEVEL_ERROR,
			"fm_new_op_code opcode error", ebufp);
		return;
	}

	/***********************************************************
	 * Debug: What we got.
	 ***********************************************************/
	PIN_ERR_LOG_FLIST(PIN_ERR_LEVEL_DEBUG,
		"fm_new_op_code input flist", i_flistp);

	/***********************************************************
	 * Implementation
	 ***********************************************************/
	fm_new_op_code(ctxp, flags, i_flistp, &r_flistp, ebufp);

	/***********************************************************
	 * Results.
	 ***********************************************************/
	if (PIN_ERR_IS_ERR(ebufp)) {

		/***************************************************
		 * Log errors
		 ***************************************************/
		PIN_ERR_LOG_EBUF(PIN_ERR_LEVEL_ERROR,
			"fm_new_op_code error", ebufp);

		PIN_FLIST_DESTROY_EX(&r_flistp, NULL);

		*o_flistpp = NULL;

	} else {

		/***************************************************
		 * Point the real return flist to the right thing.
		 ***************************************************/
		*o_flistpp = r_flistp;

		/***************************************************
		 * Return flist log
		 ***************************************************/
		PIN_ERR_LOG_FLIST(PIN_ERR_LEVEL_DEBUG,
			"op_new_op_code return flist", r_flistp);

	}

	return;
}

/*******************************************************************
 * fm_new_op_code():
 *
 *******************************************************************/
static void
fm_new_op_code(
	pcm_context_t		*ctxp,
	int32			flags,
	pin_flist_t		*i_flistp,
	pin_flist_t		**ret_flistpp,
	pin_errbuf_t		*ebufp)
{
	

	if (PIN_ERR_IS_ERR(ebufp)) {
		return;
	}
	PIN_ERR_CLEAR_ERR(ebufp);

/***********************************************************
* Include Var. 
***********************************************************/
	
	pin_flist_t		*r_flistp = NULL;
  pin_flist_t		*create_out_flistp = NULL;
  
  
 
  
  
  poid_t        *client_pdp = NULL;
  poid_t        *account_pdp = NULL;
  
  int           database = 1;
  int           search_flag = 0;
  
 
 
	/***********************************************************
	 * Prepare the return flist.
	 ***********************************************************/

	*ret_flistpp = (pin_flist_t *)NULL;
  
   
  
  PIN_ERR_LOG_FLIST(PIN_ERR_LEVEL_DEBUG, "fm_new_op_code: search flist in", i_flistp);
  PCM_OP (ctxp, PCM_OP_WRITE_FLDS, 0, i_flistp, &create_out_flistp, ebufp);
  PIN_ERR_LOG_FLIST(PIN_ERR_LEVEL_DEBUG, "fm_new_op_code: search flist out", create_out_flistp);
  
 
  r_flistp = PIN_FLIST_COPY (create_out_flistp, ebufp);
  
  


  
  //PIN_FLIST_FLD_SET(r_flistp, PIN_FLD_FIRST_NAME, (void *)name, ebufp);
        

	/***********************************************************
	 * Empty policy
	 ***********************************************************/

	/***********************************************************
	 * Error?
	 ***********************************************************/
	if (PIN_ERR_IS_ERR(ebufp)) {
		PIN_ERR_LOG_EBUF(PIN_ERR_LEVEL_ERROR, 
			"fm_new_op_code: error", ebufp);
	}else {
		*ret_flistpp = r_flistp;
	}

	PIN_FLIST_DESTROY_EX(&i_flistp, ebufp);
  PIN_FLIST_DESTROY_EX(&create_out_flistp, ebufp);
  


	return;
}


