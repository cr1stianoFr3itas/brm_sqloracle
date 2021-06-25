/*
   Dev. Cristiano Freitas
   email: junior.brown.eda@gmail.com
   Data de inicio do projeto: 20/05/2021
   Data de "Final" do projeto: 13/06/2021
   CUST CUSTOM MYCUSTCUSTOM
*/


#ifndef lint
static	char	Sccs_id[] = "@(#)%Portal Version: fm_inv_pol_mycustomop.c:BillingVelocityInt:2:2006-Sep-05 04:27:08 %";
#endif

/*******************************************************************
 * Contains the PCM_OP_INV_POL_MYCUSTOMOP operation. 
 *******************************************************************/


#include <stdio.h> 
#include <string.h> 
 
#include "pcm.h"
#include "ops/inv.h"
#include "cm_fm.h"
#include "pin_errs.h"
#include "pinlog.h"
#include "custom_ops.h"

/*******************************************************************
 * Routines contained within.
 *******************************************************************/
EXPORT_OP void
op_inv_pol_mycustomop(
	cm_nap_connection_t	*connp,
	int32			opcode,
	int32			flags,
	pin_flist_t		*i_flistp,
	pin_flist_t		**o_flistpp,
	pin_errbuf_t		*ebufp);

static void
fm_custon(
	pcm_context_t		*ctxp,
	int32			flags,
	pin_flist_t		*i_flistp,
	pin_flist_t		**ret_flistpp,
	pin_errbuf_t		*ebufp);

/*******************************************************************
 * Main routine for the PCM_OP_INV_POL_MYCUSTOMOP operation.
 *******************************************************************/
void
op_inv_pol_mycustomop(
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
	if (opcode != AC_OP_CUST_SEARCH_NAME) {
		pin_set_err(ebufp, PIN_ERRLOC_FM,
			PIN_ERRCLASS_SYSTEM_DETERMINATE,
			PIN_ERR_BAD_OPCODE, 0, 0, opcode);
		PIN_ERR_LOG_EBUF(PIN_ERR_LEVEL_ERROR,
			"op_inv_pol_mycustomop opcode error", ebufp);
		return;
	}

	/***********************************************************
	 * Debug: What we got.
	 ***********************************************************/
	PIN_ERR_LOG_FLIST(PIN_ERR_LEVEL_DEBUG,
		"op_inv_pol_mycustomop input flist", i_flistp);

	/***********************************************************
	 * Implementation
	 ***********************************************************/
	fm_custon(ctxp, flags, i_flistp, &r_flistp, ebufp);

	/***********************************************************
	 * Results.
	 ***********************************************************/
	if (PIN_ERR_IS_ERR(ebufp)) {

		/***************************************************
		 * Log errors
		 ***************************************************/
		PIN_ERR_LOG_EBUF(PIN_ERR_LEVEL_ERROR,
			"op_inv_pol_mycustomop error", ebufp);

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
			"op_inv_pol_mycustomop return flist", r_flistp);

	}

	return;
}

/*******************************************************************
 * fm_inv_pol_mycustomop():
 *
 *******************************************************************/
static void
fm_custon(
	pcm_context_t		*ctxp,
	int32			flags,
	pin_flist_t		*i_flistp,
	pin_flist_t		**ret_flistpp,
	pin_errbuf_t		*ebufp)
{
	pin_flist_t		*r_flistp = NULL;
	char            name[100]="My Custom Op Name";

	if (PIN_ERR_IS_ERR(ebufp)) {
		return;
	}
	PIN_ERR_CLEAR_ERR(ebufp);

	/***********************************************************
	 * Prepare the return flist.
	 ***********************************************************/
	*ret_flistpp = (pin_flist_t *)NULL;

	r_flistp = PIN_FLIST_COPY(i_flistp, ebufp);
	PIN_FLIST_FLD_SET(r_flistp, PIN_FLD_FIRST_NAME, (void *)name, ebufp);
        

	/***********************************************************
	 * Empty policy
	 ***********************************************************/

	/***********************************************************
	 * Error?
	 ***********************************************************/
	if (PIN_ERR_IS_ERR(ebufp)) {
		PIN_ERR_LOG_EBUF(PIN_ERR_LEVEL_ERROR, 
			"fm_inv_pol_mycustomop: error", ebufp);
	}else {
		*ret_flistpp = r_flistp;
	}

	return;
}


